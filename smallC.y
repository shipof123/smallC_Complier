%{
// @author : Shen Bingyu
// @date : 2015.11.01
// The syntax analysis part.

#include <stdio.h>
#include <stdlib.h>
extern FILE *fp;
%}
%token ID COMINT HEXINT OCTINT
%token STRUCT RETURN 
 /* operators in precedence*/
%token DOT  ARRSUB
%token MINUS LOGNOT PREINC PREDEC BITNOT
%token MUL DIV MOD
%token PLUS
%token LEFT RIGHT
%token GR_OP LE_OP NL_OP NG_OP
%token EQU NEQ
%token BITAND
%token BITXOR
%token BITOR
%token LOGAND
%token LOGOR
%token ASSIGNOP PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN XOR_ASSIGN OR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%token STRUCT
%token RETURN IF ELSE BREAK CONT FOR TYPE
%token LP RP LB RB LC RC


%right
%left


%start PROGRAM

%%
INT 	: COMINT
	| HEXINT
	| OCTINT
;
UNARYOP : BITAND
	| MUL
	| PLUS
	| MINUS
	| LOGNOT
	| BITNOT
;
BINARYOP: 
;
 /*   */
PROGRAM : EXTDEFS
;

EXTDEFS : EXTDEF EXTEDFS
	| epsilon
;
EXTDEF	: SPEC EXTVARS SEMI
	|
;
EXTVARS : DEC
;
EXTVARS : VAR
	| VAR ASSIGN INIT
;
epsilon : 
;
%%

