%{
/* 
*  File name : smallC.y
*  Output file: y.tab.h y.tab.c y.output
*  The syntax analysis part.
*
*/

#include "node.h"
#include "includes.h"
#include "ast.h"
#include "lex.yy.c"

using namespace std;

void yyerror(const char *s);
extern int yylex(void);
extern int yylineno; // get the line number
extern char* yytext; // get the token
Node* root;
%}

%union{
	Node* node;
	char* string;
}
%type <node> PROGRAM EXTDEFS EXTDEF EXTVARS EXTVAR SPEC STSPEC OPTTAG VAR FUNC PARAS PARASF PARA
%type <node> STMTBLOCK STMTS STMT ESTMT DEFS DEF DECS DEC INIT FEXP EXP ARRS ARGS

%token <string> INT 
%token <string> ID
%token SEMI COMMA
%token <string> TYPE
%token <string> STRUCT
%token <string> RETURN IF ELSE BREAK CONT FOR READ WRITE
%token LC RC
%token <string> ASSIGNOP PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN LOGOR LOGAND BITOR BITXOR BITAND EQU NEQ GT LT GE LE SHL SHR PLUS MINUS MUL DIV MOD LOGNOT MINUSMINUS PLUSPLUS BITNOT LP RP LB RB DOT

%nonassoc LOWER_ELSE
%nonassoc ELSE

%right ASSIGNOP PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN
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
PROGRAM		: EXTDEFS 			{root = $$ = new Node(yylineno, Program, "PROGRAM",1, $1);}
		;
EXTDEFS		: EXTDEF EXTDEFS		{$$ = new Node(yylineno, Extdefs, "EXTDEFS", 2, $1,$2);}
		| /* empty */  			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
EXTDEF		: SPEC EXTVARS SEMI		{$$ = new Node(yylineno, Extdef, "EXTDEF", 2,$1,$2);}
		| SPEC FUNC STMTBLOCK		{$$ = new Node(yylineno, Extdef, "EXTDEF", 3,$1,$2,$3);}
		;
EXTVARS		: EXTVAR			{$$ = new Node(yylineno, Extvars, "EXTVARS", 1, $1);}
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
EXTVAR		: DEC				{$$ = new Node(yylineno, Extvar, "EXTVAR", 1, $1);}
		| DEC COMMA EXTVAR		{$$ = new Node(yylineno, Extvar, "EXTVAR", 2, $1, $3);}
		;
SPEC 		: TYPE				{$$ = new Node(yylineno, Spec, "SPEC", 1, new Node(yylineno, Type, $1,0));}
		| STSPEC			{$$ = new Node(yylineno, Spec, "SPEC", 1, $1);}
		;
STSPEC		: STRUCT OPTTAG LC DEFS RC	{$$ = new Node(yylineno, Stspec, "STSPEC", 3, new Node(yylineno, Keyword, $1, 0), $2, $4);}
		| STRUCT ID			{$$ = new Node(yylineno, Stspec, "STSPEC", 2, new Node(yylineno, Keyword, $1, 0), new Node(yylineno, Id, $2,0));}
		;
OPTTAG		: ID				{$$ = new Node(yylineno, Opttag, "OPTTAG", 1, new Node(yylineno, Id, $1, 0));}	
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
VAR 		: ID				{$$ = new Node(yylineno, Var, "VAR", 1, new Node(yylineno, Id, $1, 0));}	
		| VAR LB INT RB			{$$ = new Node(yylineno, Var, "VAR", 2, $1, new Node(yylineno, Int, $3, 0));}	
		;
FUNC		: ID LP PARAS RP		{$$ = new Node(yylineno, Func, "FUNC", 2, new Node(yylineno, Id, $1, 0), $3);}
		;
PARAS		: PARASF			{$$ = new Node(yylineno, Paras, "PARAS", 1, $1);}
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
PARASF		: PARA COMMA PARASF		{$$ = new Node(yylineno, Parasf, "PARASF", 2, $1, $3);}	
		| PARA				{$$ = new Node(yylineno, Parasf, "PARASF", 1, $1);}	
		;
PARA		: SPEC VAR			{$$ = new Node(yylineno, Para, "PARA", 2, $1, $2);}	
		;
STMTBLOCK	: LC DEFS STMTS RC		{$$ = new Node(yylineno, Stmtblock, "STMTBLOCK", 2, $2, $3);}	
		;
STMTS		: STMT STMTS			{$$ = new Node(yylineno, Stmts, "STMTS", 2, $1, $2);}	
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
STMT		: EXP SEMI			{$$ = new Node(yylineno, Stmt, "STMT", 1, $1);}	
		| STMTBLOCK			{$$ = new Node(yylineno, Stmt, "STMT", 1, $1);}
		| RETURN EXP SEMI		{$$ = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, $1, 0), $2);}
		| IF LP EXP RP STMT ESTMT	{$$ = new Node(yylineno, Stmt, "STMT", 4, new Node(yylineno, Keyword, $1, 0), $2, $5, $6);}
		| FOR LP FEXP SEMI FEXP SEMI EXP RP STMT 	{$$ = new Node(yylineno, Stmt, "STMT", 5, new Node(yylineno, Keyword, $1, 0), $3, $5, $7, $9);}
		| CONT SEMI			{$$ = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, $1, 0));}
		| BREAK SEMI			{$$ = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, $1, 0));}
		| READ LP EXP RP SEMI		{$$ = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, $1, 0), $3);}
		| WRITE LP EXP RP SEMI		{$$ = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, $1, 0), $3);}
		;
ESTMT		: ELSE STMT %prec ELSE		{$$ = new Node(yylineno, Estmt, "ESTMT", 2, new Node(yylineno, Keyword, $1, 0), $2);}
		| /* empty */%prec LOWER_ELSE	{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
DEFS		: DEF DEFS			{$$ = new Node(yylineno, Defs, "DEFS", 2, $1, $2);}
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
DEF		: SPEC DECS SEMI		{$$ = new Node(yylineno, Def, "DEF", 2, $1, $2);}
		;
DECS		: DEC COMMA DECS		{$$ = new Node(yylineno, Decs, "DECS", 2, $1, $3);}
		| DEC				{$$ = new Node(yylineno, Decs, "DECS", 1, $1);}
		;
DEC 		: VAR				{$$ = new Node(yylineno, Dec, "DEC", 1, $1);}
		| VAR ASSIGNOP INIT		{$$ = new Node(yylineno, Dec, "DEC", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		;
INIT 		: EXP				{$$ = new Node(yylineno, Init, "INIT", 1, $1);}
		| LC ARGS RC			{$$ = new Node(yylineno, Init, "INIT", 1, $2);}
		;
FEXP		: EXP				{$$ = new Node(yylineno, Fexp, "Fexp", 1, $1);}
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
EXP 		: EXP MUL EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}	
		| EXP DIV EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP MOD EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP PLUS EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP MINUS EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP SHL EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP SHR EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP GT EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP LT EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP GE EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP LE EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP EQU EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP NEQ EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP BITAND EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP BITOR EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP BITXOR EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP LOGAND EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP LOGOR EXP			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP ASSIGNOP EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP PLUS_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP MINUS_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP MUL_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP DIV_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP AND_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP XOR_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP OR_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP SHR_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
		| EXP SHL_ASSIGN EXP		{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), $3);}
////////////// UNARYOP    //////////		
		| MINUS EXP %prec LOGNOT	{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, $1, 0), $2);}
		| LOGNOT EXP			{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, $1, 0), $2);}
		| BITNOT EXP			{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, $1, 0), $2);}
		| PLUSPLUS EXP			{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, $1, 0), $2);}
		| MINUSMINUS EXP		{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, $1, 0), $2);}
		| LP EXP RP			{$$ = new Node(yylineno, Exp, "EXP", 1, $2);}
		| ID LP ARGS RP			{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, $1, 0), $3);}
		| ID ARRS			{$$ = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, $1, 0), $2);}
		| EXP DOT ID			{$$ = new Node(yylineno, Exp, "EXP", 3, $1, new Node(yylineno, Operator, $2, 0), new Node(yylineno, Id, $3, 0));}
		| INT				{$$ = new Node(yylineno, Exp, "EXP", 1, new Node(yylineno, Int, $1, 0));}
		;
ARRS 		: LB EXP RB ARRS		{$$ = new Node(yylineno, Arrs, "ARRS", 2, $2, $4);}
		| /* empty */			{$$ = new Node(yylineno, Null, "NULL", 0);}
		;
ARGS		: EXP COMMA ARGS		{$$ = new Node(yylineno, Args, "ARGS", 2, $1, $3);}
		| EXP				{$$ = new Node(yylineno, Args, "ARGS", 1, $1);}
		; 
%%
void yyerror(const char *s) {
	fflush(stdout);
	fprintf(stderr, "[error] at line [%d] %s %s.\n", yylineno, s, yytext);
}
int yywrap() {return 1;}
int main(int argc, char** argv) {
	if (argc != 3) {
		cout << "Parameter must be like <infile> <outfile>. \n";
		return -1;	
	}
	
	freopen(argv[1],"r",stdin);
	freopen(argv[2], "w+", stdout);
	if(!yyparse())
	{
		print_ast(root, 0);
		//cout << argv[1] <<"---" << argv[2] <<endl;
	}
	else
	{
		cout << "parsing failed.\n";
	}	
	return 0;
}
