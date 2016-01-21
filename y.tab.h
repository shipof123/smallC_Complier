/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    NEGINT = 259,
    ID = 260,
    SEMI = 261,
    COMMA = 262,
    TYPE = 263,
    STRUCT = 264,
    RETURN = 265,
    IF = 266,
    ELSE = 267,
    BREAK = 268,
    CONT = 269,
    FOR = 270,
    READ = 271,
    WRITE = 272,
    LC = 273,
    RC = 274,
    ASSIGNOP = 275,
    PLUS_ASSIGN = 276,
    MINUS_ASSIGN = 277,
    MUL_ASSIGN = 278,
    DIV_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    SHL_ASSIGN = 283,
    SHR_ASSIGN = 284,
    LOGOR = 285,
    LOGAND = 286,
    BITOR = 287,
    BITXOR = 288,
    BITAND = 289,
    EQU = 290,
    NEQ = 291,
    GT = 292,
    LT = 293,
    GE = 294,
    LE = 295,
    SHL = 296,
    SHR = 297,
    PLUS = 298,
    MINUS = 299,
    MUL = 300,
    DIV = 301,
    MOD = 302,
    LOGNOT = 303,
    MINUSMINUS = 304,
    PLUSPLUS = 305,
    BITNOT = 306,
    LP = 307,
    RP = 308,
    LB = 309,
    RB = 310,
    DOT = 311,
    LOWER_ELSE = 312
  };
#endif
/* Tokens.  */
#define INT 258
#define NEGINT 259
#define ID 260
#define SEMI 261
#define COMMA 262
#define TYPE 263
#define STRUCT 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define BREAK 268
#define CONT 269
#define FOR 270
#define READ 271
#define WRITE 272
#define LC 273
#define RC 274
#define ASSIGNOP 275
#define PLUS_ASSIGN 276
#define MINUS_ASSIGN 277
#define MUL_ASSIGN 278
#define DIV_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define SHL_ASSIGN 283
#define SHR_ASSIGN 284
#define LOGOR 285
#define LOGAND 286
#define BITOR 287
#define BITXOR 288
#define BITAND 289
#define EQU 290
#define NEQ 291
#define GT 292
#define LT 293
#define GE 294
#define LE 295
#define SHL 296
#define SHR 297
#define PLUS 298
#define MINUS 299
#define MUL 300
#define DIV 301
#define MOD 302
#define LOGNOT 303
#define MINUSMINUS 304
#define PLUSPLUS 305
#define BITNOT 306
#define LP 307
#define RP 308
#define LB 309
#define RB 310
#define DOT 311
#define LOWER_ELSE 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "smallC.y" /* yacc.c:1909  */

	Node* node;
	char* string;

#line 173 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
