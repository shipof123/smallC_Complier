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

#ifndef YY_YY_SMALLC_TAB_H_INCLUDED
# define YY_YY_SMALLC_TAB_H_INCLUDED
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
    ID = 259,
    SEMI = 260,
    COMMA = 261,
    TYPE = 262,
    STRUCT = 263,
    RETURN = 264,
    IF = 265,
    ELSE = 266,
    BREAK = 267,
    CONT = 268,
    FOR = 269,
    READ = 270,
    WRITE = 271,
    LC = 272,
    RC = 273,
    ASSIGNOP = 274,
    PLUS_ASSIGN = 275,
    MINUS_ASSIGN = 276,
    MUL_ASSIGN = 277,
    DIV_ASSIGN = 278,
    AND_ASSIGN = 279,
    XOR_ASSIGN = 280,
    OR_ASSIGN = 281,
    SHL_ASSIGN = 282,
    SHR_ASSIGN = 283,
    LOGOR = 284,
    LOGAND = 285,
    BITOR = 286,
    BITXOR = 287,
    BITAND = 288,
    EQU = 289,
    NEQ = 290,
    GT = 291,
    LT = 292,
    GE = 293,
    LE = 294,
    SHL = 295,
    SHR = 296,
    PLUS = 297,
    MINUS = 298,
    MUL = 299,
    DIV = 300,
    MOD = 301,
    LOGNOT = 302,
    MINUSMINUS = 303,
    PLUSPLUS = 304,
    BITNOT = 305,
    LP = 306,
    RP = 307,
    LB = 308,
    RB = 309,
    DOT = 310,
    LOWER_ELSE = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "smallC.y" /* yacc.c:1909  */

	Node* node;
	char* string;

#line 116 "smallC.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SMALLC_TAB_H_INCLUDED  */
