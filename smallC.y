%{
// @author : Shen Bingyu
// @date : 2015.11.01
// The syntax analysis part.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
//#include <string>

//Node* syntax_tree;

union{
	int node;
}
void yyerror(const char *s);

FILE* yyin;
FILE* yyout;

%}

%type <node> PROGRAM EXTDEFS EXTDEF EXTVARS SPEC STSPEC OPTTAG VAR FUNC PARAS PARA STMTBLOCK STMTS STMT ESTMT DEFS DEF DECS DEC INIT EXP ARRS ARGS


%token INT 
%token ID
%token SEMI COMMA
%token TYPE
%token STRUCT
%token RETURN
%token IF ELSE
%token BREAK CONT
%token FOR
%token LC RC
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN LOGOR LOGAND BITOR BITXOR BITAND EQU NEQ GT LT GE LE SHL SHR PLUS MINUS MUL DIV MOD LOGNOT MINUSMINUS PLUSPLUS BITNOT LP RP LB RB DOT

%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN
%left LOGOR
%left LOGAND
%left BITOR
%left BITXOR
%left BITAND
%left EQU NEQ
%left GT LT GE LE
%left SHL SHR
%left PLUS MINUS
%left MUL DIV MOD
%right LOGNOT MINUSMINUS PLUSPLUS BITNOT
%left LP RP LB RB DOT



%start PROGRAM

%%
PROGRAM		: EXTDEFS
		;
EXTDEFS		: EXTDEF EXTDEFS
		| /* empty */
		;
EXTDEF		: SPEC EXTVARS SEMI
		| SPEC FUNC STMTBLOCK
		;
EXTVARS		: DEC
		| DEC COMMA EXTVARS
		| /* empty */
		;
SPEC 		: TYPE
		| STSPEC
		;
STSPEC		: STRUCT OPTTAG LC DEFS RC
		| STRUCT ID
		;
OPTTAG		: ID
		| /* empty */
		;
VAR 		: ID
		| VAR LB INT RB
		;
FUNC		: ID LP PARAS RP
		;
PARAS		: PARA COMMA PARAS
		| PARA
		| /* empty */		
		;
PARA		: SPEC VAR
		;
STMTBLOCK	: LC DEFS STMTS RC
		;
STMTS		: STMT STMTS
		| /* empty */
		;
STMT		: EXP SEMI
		| STMTBLOCK
		| RETURN EXP SEMI
		| IF LP EXP RP STMT ESTMT
		| FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT
		| CONT SEMI
		| BREAK SEMI
		;
ESTMT		: ELSE STMT
		| /* empty */
		;
DEFS		: DEF DEFS
		| /* empty */
		;
DEF		: SPEC DECS SEMI
		;
DECS		: DEC COMMA DECS
		| DEC
		;
DEC 		: VAR
		| VAR ASSIGN INIT
		;
INIT 		: EXP
		| LC ARGS RC
		;
FEXP:		:EXP
		| /* empty */
		;
EXP 		: EXP MUL EXP
		| EXP DIV EXP
		| EXP MOD EXP
		| EXP PLUS EXP
		| EXP MINUS EXP
		| EXP SHL EXP
		| EXP SHR EXP
		| EXP GT EXP
		| EXP LT EXP
		| EXP GE EXP
		| EXP LE EXP
		| EXP EQU EXP
		| EXP NEQ EXP
		| EXP BITAND EXP
		| EXP BITOR EXP
		| EXP BITXOR EXP
		| EXP LOGAND EXP
		| EXP LOGOR EXP
		| EXP ASSGIN EXP
		| EXP PLUS_ASSIGN EXP
		| EXP MINUS_ASSIGN EXP
		| EXP MUL_ASSIGN EXP
		| EXP DIV_ASSIGN EXP
		| EXP AND_ASSIGN EXP
		| EXP XOR_ASSIGN EXP
		| EXP OR_ASSIGN EXP
		| EXP SHR_ASSIGN EXP
		| EXP SHL_ASSIGN EXP
////////////// UNARYOP    //////////
		| MINUS EXP %prec LOGNOT
		| LOGNOT EXP
		| BITNOT EXP
		| PLUSPLUS EXP
		| MINUSMINUS EXP
		| LP EXP RP
		| ID LP ARGS RP
		| ID ARRS
		| EXP DOT ID
		| INT
		;
ARRS 		: LB EXP RB ARRS
		| /* empty */
		;
ARGS		: EXP COMMA ARGS
		| EXP
		; 
%%
void yyerror(const char *s) {
	fprintf(stderr, "[error] : %s. \n",s);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Parameter must be like <infile> <outfile>. \n";
		return -1;	
	}
		
	yyin = fopen(argv[1],"r");
	if(!yyin) {
		perror(argv[1]);
		return -2;
	}
	yyout = freopen(argv[2], "w+", stdout);
	yyparse();
	fclose(yyin);
	fclose(yyout);
	return 0;
}
