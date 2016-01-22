%{
/*
/ Filename : smallC.l
/ Output File : lex.yy.c
/ @author : Shen Bingyu
/ @date : 2016.01.12	
/ add negint case
*/

#include "includes.h"
#include "node.h"
#include "y.tab.h"
void yyerror(const char*);
extern int yyval, yylineno;
%}

%x comment


%%
"/*"		BEGIN(comment);
<comment>{
[^*\n]*  	/* anything but '*' */
"*"+[^*/\n]* 	/* '*' not followed by '/' */
\n		//{yylineno++;}
"*"+"/" 	BEGIN(INITIAL);
}

 /* reserved type name */ 
read			{yylval.string = strdup(yytext);return READ;}
write			{yylval.string = strdup(yytext);return WRITE;}
struct 			{yylval.string = strdup(yytext);return STRUCT;}
return	 		{yylval.string = strdup(yytext);return RETURN;}
if 			{yylval.string = strdup(yytext);return IF;}
else 			{yylval.string = strdup(yytext);return ELSE;}
break	 		{yylval.string = strdup(yytext);return BREAK;}
continue 		{yylval.string = strdup(yytext);return CONT;}
for			{yylval.string = strdup(yytext);return FOR;}
int 			{yylval.string = strdup(yytext);return TYPE;} // ONLY int
0[xX][0-9a-fA-F]+ 	{yylval.string = strdup(yytext);return INT;} // hex integer
0[0-7]*			{yylval.string = strdup(yytext);return INT;} // oct integer 
[1-9][0-9]* 		{yylval.string = strdup(yytext);return INT;} // comman integer
-0[xX][0-9a-fA-F]+ 	{yylval.string = strdup(yytext);return NEGINT;} // hex integer
-0[0-7]*		{yylval.string = strdup(yytext);return NEGINT;} // oct integer 
-[1-9][0-9]* 		{yylval.string = strdup(yytext);return NEGINT;} // comman integer    
[a-zA-Z_][a-zA-Z0-9_]*	{yylval.string = strdup(yytext);return ID;}


";" 			{yylval.string = strdup(yytext);return SEMI;}
"," 			{yylval.string = strdup(yytext);return COMMA;}
 /* 1 */
"."			{yylval.string = strdup(yytext);return DOT;} 
 /* 2 */
"-" 			{yylval.string = strdup(yytext);return MINUS;} // binary  4 or unary 2
"!" 			{yylval.string = strdup(yytext);return LOGNOT;}
"++" 			{yylval.string = strdup(yytext);return PLUSPLUS;}
"--" 			{yylval.string = strdup(yytext);return MINUSMINUS;}
"~" 			{yylval.string = strdup(yytext);return BITNOT;}
 /* 3 */
"*" 			{yylval.string = strdup(yytext);return MUL;}
"/" 			{yylval.string = strdup(yytext);return DIV;}
"%" 			{yylval.string = strdup(yytext);return MOD;}
 /* 4 */ 
"+" 			{yylval.string = strdup(yytext);return PLUS;}
 /* 5 */
"<<" 			{yylval.string = strdup(yytext);return SHL;}
">>" 			{yylval.string = strdup(yytext);return SHR;}
 /* 6 */
">" 			{yylval.string = strdup(yytext);return GT;}
"<" 			{yylval.string = strdup(yytext);return LT;}
">=" 			{yylval.string = strdup(yytext);return GE;}
"<=" 			{yylval.string = strdup(yytext);return LE;}
 /* 7 */
"==" 			{yylval.string = strdup(yytext);return EQU;}
"!=" 			{yylval.string = strdup(yytext);return NEQ;}
 /* 8 */
"&" 			{yylval.string = strdup(yytext);return BITAND;}
 /* 9 */
"^" 			{yylval.string = strdup(yytext);return BITXOR;}
 /* 10 */
"|" 			{yylval.string = strdup(yytext);return BITOR;}
 /* 11 */
"&&" 			{yylval.string = strdup(yytext);return LOGAND;};
 /* 12 */
"||" 			{yylval.string = strdup(yytext);return LOGOR;}
 /* 13 */
"="  			{yylval.string = strdup(yytext);return ASSIGNOP;}
"+=" 			{yylval.string = strdup(yytext);return PLUS_ASSIGN;}
"-=" 			{yylval.string = strdup(yytext);return MINUS_ASSIGN;}
"*=" 			{yylval.string = strdup(yytext);return MUL_ASSIGN;}
"/=" 			{yylval.string = strdup(yytext);return DIV_ASSIGN;}
"&=" 			{yylval.string = strdup(yytext);return AND_ASSIGN;}
"^=" 			{yylval.string = strdup(yytext);return XOR_ASSIGN;}
"|=" 			{yylval.string = strdup(yytext);return OR_ASSIGN;}
"<<=" 			{yylval.string = strdup(yytext);return SHL_ASSIGN;}
">>=" 			{yylval.string = strdup(yytext);return SHR_ASSIGN;}
 /* brances */
"(" 			{yylval.string = strdup(yytext);return LP;}
")" 			{yylval.string = strdup(yytext);return RP;}
"[" 			{yylval.string = strdup(yytext);return LB;}
"]"		 	{yylval.string = strdup(yytext);return RB;}
"{" 			{yylval.string = strdup(yytext);return LC;}
"}" 			{yylval.string = strdup(yytext);return RC;}
[\n]			{yylineno++;/*printf("\n%d",linecount);*/}
[ \t\r] ; 		// SKIPPING
"//"(.)*		{}/*comment for one line*/
.			{yyerror("ERROR");}
%%

