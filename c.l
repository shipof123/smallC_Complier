%{
/*
/ @author : Shen Bingyu
/ @date : 2015.11.1	
*/
#include <stdio.h>
#include <stdlib.h> 
#include <yy.tab.h>
%}

alpha [_a-zA-Z]
hex [0-9a-fA-F]
oct [0-7]
digit [0-9]

%%

[\n] {yylineno++;}

 /* reserved type name */ 
"struct" {return STRUCT;}
"return" {return RETURN;}
"if" {return IF;}
"else" {return ELSE;}
"break" {return BREAK;}
"continue" {return CONT;}
"for" {return FOR;}
"int" {return TYPE;} // ONLY int
0[xX]({hex})* {return HEXINT;} // hex integer
0({oct})* {return OCTINT;} // oct integer 
[digit]+ {return COMINT;} // comman integer  
{alpha}({alpha}|{digit})* {return ID;}

";" {return SEMI;}
"," {return COMMA;}
 /* 1 */
"." {return DOT;} // element selection, Precedence 1
		// "." is left alone,outside the binary operator
		// "[]", "()" are not used in the grammar
 /* 2 */
"-" {return MINUS;} // binary  4 or unary 2
"!" {return LOGNOT;}
"++" {return PREINC;}
"--" {return PREDEC;}
"~" {return BITNOT;}
 /* 3 */
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
 /* 4 */ 
"+" {return PLUS;}
 /* 5 */
"<<" {return LEFT;}
">>" {return RIGHT;}
 /* 6 */
">" {return GR_OP;}
"<" {return LE_OP;}
">=" {return NL_OP;}
"<=" {return NG_OP;}
 /* 7 */
"==" {return EQU;}
"!=" {return NEQ;}
 /* 8 */
"&" {return BITAND;}
 /* 9 */
"^" {return BITXOR;}
 /* 10 */
"|" {return BITOR;}
 /* 11 */
"&&" {return LOGAND;};
 /* 12 */
"||" {return LOGOR;}
 /* 13 */
"="  {return ASSIGNOP;}
"+=" {return PLUS_ASSIGN;}
"-=" {return MINUS_ASSIGN;}
"*=" {return MUL_ASSIGN;}
"/=" {return DIV_ASSIGN;}
"&=" {return AND_ASSIGN;}
"^=" {return XOR_ASSIGN;}
"|=" {return OR_ASSIGN;}
"<<=" {return LEFT_ASSIGN;}
">>=" {return RIGHT_ASSIGN;}
 /* not operand */
"(" {return LP;}
")" {return RP;}
"[" {return LB;}
"]" {return RB;}
"{" {return LC;}
"}" {return RC;}

[ \t\r] ; // SKIPPING
\/\*(.*\n)*.*\*\/ ; // skip comment

. {
 printf("UNKNOWN CHARCTER %c", yytext[0]);
 return UNKNOWN;	
};/* ignore bad characters */  

%%

int main(int argc, char** argv) {
    yylex();
    ffloush(yyout);
    exit(0);
}
