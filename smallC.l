%{
/*
/ Filename : smallC.l
/ Output File : lex.yy.c
/ @author : Shen Bingyu
/ @date : 2015.11.1	
*/

//#include <yy.tab.h>
#include "includes.h"
extern int yylineno;

#define YY_USER_ACTION update_loc();
%}

%x comment

%option yylineno 


%%
"/*"		BEGIN(comment);
<comment>{
[^*\n]*  	/* anything but '*' */
"*"+[^*/\n]* 	/* '*' not followed by '/' */
\n		//{yylineno++;}
"*"+"/" 	BEGIN(INITIAL);
}

 /* reserved type name */ 
read			{return READ;}
write			{return WRITE;}
struct 			{return STRUCT;}
return	 		{return RETURN;}
if 			{return IF;}
else 			{return ELSE;}
break	 		{return BREAK;}
continue 		{return CONT;}
for			{return FOR;}
int 			{return TYPE;} // ONLY int
0[xX][0-9a-fA-F]+ 	{return INT;} // hex integer
0[0-7]*			{return INT;} // oct integer 
[1-9][0-9]* 		{return INT;} // comman integer  
[a-zA-Z_][a-zA-Z0-9_]*	{return ID;}


";" 			{return SEMI;}
"," 			{return COMMA;}
 /* 1 */
"."			{return DOT;} 
 /* 2 */
"-" 			{return MINUS;} // binary  4 or unary 2
"!" 			{return LOGNOT;}
"++" 			{return PLUSPLUS;}
"--" 			{return MINUSMINUS;}
"~" 			{return BITNOT;}
 /* 3 */
"*" 			{return MUL;}
"/" 			{return DIV;}
"%" 			{return MOD;}
 /* 4 */ 
"+" 			{return PLUS;}
 /* 5 */
"<<" 			{return SHL;}
">>" 			{return SHR;}
 /* 6 */
">" 			{return GT;}
"<" 			{return LT;}
">=" 			{return GE;}
"<=" 			{return LE;}
 /* 7 */
"==" 			{return EQU;}
"!=" 			{return NEQ;}
 /* 8 */
"&" 			{return BITAND;}
 /* 9 */
"^" 			{return BITXOR;}
 /* 10 */
"|" 			{return BITOR;}
 /* 11 */
"&&" 			{return LOGAND;};
 /* 12 */
"||" 			{return LOGOR;}
 /* 13 */
"="  			{return ASSIGNOP
;}
"+=" 			{return PLUS_ASSIGN;}
"-=" 			{return MINUS_ASSIGN;}
"*=" 			{return MUL_ASSIGN;}
"/=" 			{return DIV_ASSIGN;}
"&=" 			{return AND_ASSIGN;}
"^=" 			{return XOR_ASSIGN;}
"|=" 			{return OR_ASSIGN;}
"<<=" 			{return SHL_ASSIGN;}
">>=" 			{return SHR_ASSIGN;}
 /* brances */
"(" 			{return LP;}
")" 			{return RP;}
"[" 			{return LB;}
"]"		 	{return RB;}
"{" 			p{return LC;}
"}" 			{return RC;}
[\n]			{yylineno++;/*printf("\n%d",linecount);*/}
[ \t\r] ; 		// SKIPPING
"//"(.)*		{}/*comment for one line*/
.			{yyerror("ERROR");}
%%
yywrap()
{

}
int main(int argc, char** argv) 
{
    yylex();
    //ffloush(yyout);
    exit(0);
}
