/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "smallC.y" /* yacc.c:339  */

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
#include "semantic.h"
#include "llvm.h"
using namespace std;

void yyerror(const char *s);
extern void trans_Program(Node* root);
extern int yylex(void);
extern int yylineno; // get the line number
extern char* yytext; // get the token
Node* root;

#line 90 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 25 "smallC.y" /* yacc.c:355  */

	Node* node;
	char* string;

#line 249 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    66,    67,    69,    70,    72,    73,    75,
      76,    78,    79,    81,    82,    84,    85,    87,    88,    90,
      92,    93,    95,    96,    98,   100,   102,   103,   105,   106,
     107,   108,   109,   110,   111,   113,   114,   116,   117,   119,
     121,   122,   124,   125,   127,   128,   130,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     177,   178,   180,   181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "NEGINT", "ID", "SEMI", "COMMA",
  "TYPE", "STRUCT", "RETURN", "IF", "ELSE", "BREAK", "CONT", "FOR", "READ",
  "WRITE", "LC", "RC", "ASSIGNOP", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "SHL_ASSIGN", "SHR_ASSIGN", "LOGOR", "LOGAND", "BITOR", "BITXOR",
  "BITAND", "EQU", "NEQ", "GT", "LT", "GE", "LE", "SHL", "SHR", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "LOGNOT", "MINUSMINUS", "PLUSPLUS",
  "BITNOT", "LP", "RP", "LB", "RB", "DOT", "LOWER_ELSE", "$accept",
  "PROGRAM", "EXTDEFS", "EXTDEF", "EXTVARS", "EXTVAR", "SPEC", "STSPEC",
  "OPTTAG", "VAR", "FUNC", "PARAS", "PARASF", "PARA", "STMTBLOCK", "STMTS",
  "STMT", "ESTMT", "DEFS", "DEF", "DECS", "DEC", "INIT", "FEXP", "EXP",
  "ARRS", "ARGS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -147,     2,    14,  -147,     4,    22,  -147,    11,    15,
    -147,  -147,   -20,    28,  -147,   -15,    17,    29,     4,     4,
    -147,   674,    39,     4,  -147,    41,    41,    25,     4,    41,
      36,  -147,    74,  -147,  -147,   -44,    40,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  -147,   444,    38,   658,  -147,
    -147,    85,    90,  -147,  -147,    45,  -147,     4,    -1,    -1,
    -147,    -1,    -1,  -147,    80,   109,    24,    24,    24,    24,
      24,   136,  -147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,  -147,    -1,    78,   126,   127,    83,  -147,   122,
     658,   180,  -147,    41,  -147,    89,   224,   268,   312,    -1,
    -147,  -147,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   488,   513,   537,   560,   582,   604,   604,   611,
     611,   611,   611,   186,   186,    92,    92,    24,    24,    24,
    -147,   356,    -1,  -147,  -147,    -1,  -147,  -147,  -147,  -147,
    -147,    91,  -147,  -147,  -147,  -147,   400,   137,   444,  -147,
     658,    -1,   132,   140,   658,  -147,    -1,  -147,    94,   658,
    -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    11,    16,     0,     2,     4,     8,    12,    14,     0,
       1,     3,    17,     0,     7,    42,     0,     9,    38,    21,
       5,     0,     0,    38,     6,     0,     0,     0,    38,     0,
       0,    20,    23,    85,    88,    91,     0,     0,    47,     0,
       0,     0,     0,     0,     0,    43,    44,     0,    27,    17,
      10,     0,    41,    13,    37,    24,    19,     0,    47,     0,
      83,     0,     0,    93,    46,     0,    76,    77,    80,    79,
      78,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    29,     0,
      27,     0,    39,     0,    22,     0,     0,     0,     0,    47,
      45,    81,    66,    67,    68,    69,    70,    71,    72,    73,
      75,    74,    65,    64,    62,    63,    61,    59,    60,    55,
      56,    57,    58,    53,    54,    51,    52,    48,    49,    50,
      84,     0,     0,    34,    33,    47,    25,    26,    28,    40,
      82,    91,    86,    87,    92,    30,     0,     0,    46,    90,
       0,    47,    36,     0,     0,    31,    47,    35,     0,     0,
      32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   144,  -147,  -147,   128,    26,  -147,  -147,   123,
    -147,  -147,    97,  -147,   135,    75,   -84,  -147,   -17,  -147,
      81,   -25,  -147,  -146,   -21,    27,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    14,    26,     7,     9,    15,
      16,    30,    31,    32,   108,   109,   110,   175,    27,    28,
      51,    17,    45,    63,   111,    60,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    52,    33,    34,    35,    21,    48,     8,    58,   167,
      59,    54,     1,     2,    10,    36,    37,    64,    66,    67,
      68,    69,    70,    71,   115,   173,     6,    12,    72,   -15,
     178,     6,    19,    18,    20,    23,    25,    64,   116,    22,
     117,   118,    47,    39,    53,    29,    49,    40,    41,    42,
      43,    44,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     101,    57,   151,    29,    72,   164,   172,   119,    52,    56,
     177,   112,    61,   102,    62,   180,    72,   113,    64,    22,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   120,   150,
     152,   166,   153,   154,   168,   155,   101,    98,    99,   100,
      72,   156,   160,   171,   174,    59,   176,   179,   101,    11,
     168,    24,    55,    50,   114,   168,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    72,   157,   158,     0,   169,   121,
      72,     0,   101,     0,   159,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    72,    96,
      97,    98,    99,   100,     0,     0,   101,     0,     0,     0,
       0,     0,   101,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    72,     0,     0,     0,     0,     0,     0,   161,
     101,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    72,     0,     0,     0,
       0,   162,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      72,     0,   165,     0,     0,   163,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    72,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    72,     0,
       0,     0,     0,   170,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    72,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,    72,     0,     0,   101,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,    72,     0,     0,     0,     0,   101,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,    72,     0,     0,     0,
       0,     0,     0,   101,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    72,     0,
       0,     0,     0,     0,     0,    72,   101,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    94,    95,    96,    97,    98,    99,   100,     0,
     101,    33,    34,    35,     0,     0,     0,   101,   103,   104,
       0,   105,   106,   107,    36,    37,    23,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,    40,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      21,    26,     3,     4,     5,    20,    23,     5,    52,   155,
      54,    28,     8,     9,     0,    16,    17,    38,    39,    40,
      41,    42,    43,    44,    58,   171,     0,     5,     4,    18,
     176,     5,    52,    18,     6,    18,     7,    58,    59,    54,
      61,    62,     3,    44,    19,    19,     5,    48,    49,    50,
      51,    52,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      56,     7,   103,    57,     4,   119,   170,     7,   113,    53,
     174,     6,    52,    55,    52,   179,     4,     7,   119,    54,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    19,     5,
      52,   152,     6,     6,   155,    52,    56,    45,    46,    47,
       4,    19,    53,     6,    12,    54,     6,    53,    56,     5,
     171,    16,    29,    25,    57,   176,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     4,   110,     6,    -1,   161,    53,
       4,    -1,    56,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     4,    43,
      44,    45,    46,    47,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     4,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     4,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       4,    -1,     6,    -1,    -1,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     4,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    56,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    56,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     4,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    56,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    41,    42,    43,    44,    45,    46,    47,    -1,
      56,     3,     4,     5,    -1,    -1,    -1,    56,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    59,    60,    61,    64,    65,     5,    66,
       0,    60,     5,    62,    63,    67,    68,    79,    18,    52,
       6,    20,    54,    18,    72,     7,    64,    76,    77,    64,
      69,    70,    71,     3,     4,     5,    16,    17,    18,    44,
      48,    49,    50,    51,    52,    80,    82,     3,    76,     5,
      63,    78,    79,    19,    76,    67,    53,     7,    52,    54,
      83,    52,    52,    81,    82,    84,    82,    82,    82,    82,
      82,    82,     4,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    56,    55,    10,    11,    13,    14,    15,    72,    73,
      74,    82,     6,     7,    70,    84,    82,    82,    82,     7,
      19,    53,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
       5,    82,    52,     6,     6,    52,    19,    73,     6,    78,
      53,    55,    53,    53,    84,     6,    82,    81,    82,    83,
      53,     6,    74,    81,    12,    75,     6,    74,    81,    53,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    71,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     0,     1,
       3,     1,     1,     5,     2,     1,     0,     1,     4,     4,
       1,     0,     3,     1,     2,     4,     2,     0,     2,     1,
       3,     6,     9,     2,     2,     2,     0,     2,     0,     3,
       3,     1,     1,     3,     1,     3,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     4,     2,     3,     1,     4,     4,     1,     2,
       4,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 64 "smallC.y" /* yacc.c:1646  */
    {root = (yyval.node) = new Node(yylineno, Program, "PROGRAM",1, (yyvsp[0].node));}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdefs, "EXTDEFS", 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdef, "EXTDEF", 2,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdef, "EXTDEF", 3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvars, "EXTVARS", 1, (yyvsp[0].node));}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 75 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvar, "EXTVAR", 1, (yyvsp[0].node));}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvar, "EXTVAR", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Spec, "SPEC", 1, new Node(yylineno, Type, (yyvsp[0].string),0));}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Spec, "SPEC", 1, (yyvsp[0].node));}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 81 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stspec, "STSPEC", 3, new Node(yylineno, Keyword, (yyvsp[-4].string), 0), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 82 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stspec, "STSPEC", 2, new Node(yylineno, Keyword, (yyvsp[-1].string), 0), new Node(yylineno, Id, (yyvsp[0].string),0));}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 84 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Opttag, "OPTTAG", 1, new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 85 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 87 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Var, "VAR", 1, new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 88 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Var, "VAR", 2, (yyvsp[-3].node), new Node(yylineno, Int, (yyvsp[-1].string), 0));}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 90 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Func, "FUNC", 2, new Node(yylineno, Id, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 92 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Paras, "PARAS", 1, (yyvsp[0].node));}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 95 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Parasf, "PARASF", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 96 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Parasf, "PARASF", 1, (yyvsp[0].node));}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 98 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Para, "PARA", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 100 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmtblock, "STMTBLOCK", 2, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmts, "STMTS", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, (yyvsp[-1].node));}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 106 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, (yyvsp[0].node));}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 107 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, (yyvsp[-2].string), 0), (yyvsp[-1].node));}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 108 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 4, new Node(yylineno, Keyword, (yyvsp[-5].string), 0), (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 109 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 5, new Node(yylineno, Keyword, (yyvsp[-8].string), 0), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 110 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, (yyvsp[-1].string), 0));}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 111 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, (yyvsp[-1].string), 0));}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Estmt, "ESTMT", 2, new Node(yylineno, Keyword, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Defs, "DEFS", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 119 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Def, "DEF", 2, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 121 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Decs, "DECS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Decs, "DECS", 1, (yyvsp[0].node));}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Dec, "DEC", 1, (yyvsp[0].node));}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Dec, "DEC", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Init, "INIT", 1, (yyvsp[0].node));}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Init, "INIT", 1, (yyvsp[-1].node));}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Fexp, "Fexp", 1, (yyvsp[0].node));}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 135 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 136 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 137 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 138 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 139 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 141 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 142 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 143 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 144 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 145 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 146 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 147 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 148 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 149 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 150 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 151 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 152 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 153 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 154 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 155 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 156 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 157 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 158 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 159 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 160 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 162 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 163 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 164 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 165 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 166 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 167 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 1, (yyvsp[-1].node));}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 168 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 169 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 170 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 171 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 1, new Node(yylineno, Int, (yyvsp[0].string), 0));}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 172 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Keyword, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 173 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Keyword, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 174 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 1, new Node(yylineno, Nint, (yyvsp[0].string), 0));}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 175 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, (yyvsp[-1].node), new Node(yylineno, Nint, (yyvsp[0].string), 0));}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 177 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Arrs, "ARRS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 178 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 180 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Args, "ARGS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 181 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Args, "ARGS", 1, (yyvsp[0].node));}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2129 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 183 "smallC.y" /* yacc.c:1906  */

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
		//print_ast(root, 0);
		trans_Program(root);
		//cout << argv[1] <<"---" << argv[2] <<endl;
	}
	else
	{
		cout << "parsing failed.\n";
	}	
	return 0;
}
