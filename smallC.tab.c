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

// @author : Shen Bingyu
// @date : 2015.11.01
// The syntax analysis part.

#include "node.h"
#include "includes.h"
using namespace std;

void yyerror(const char *s);
extern int yylex(void);
extern int yylineno; // get the line number
extern char* yytext; // get the token

Node* root;

#line 83 "smallC.tab.c" /* yacc.c:339  */

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
   by #include "smallC.tab.h".  */
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
#line 18 "smallC.y" /* yacc.c:355  */

	Node* node;
	char* string;

#line 185 "smallC.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SMALLC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "smallC.tab.c" /* yacc.c:358  */

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
#define YYLAST   666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    58,    59,    61,    62,    64,    65,    67,
      68,    70,    71,    73,    74,    76,    77,    79,    80,    82,
      84,    85,    87,    88,    90,    92,    94,    95,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   107,   108,   110,
     111,   113,   115,   116,   118,   119,   121,   122,   124,   125,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   167,   168,
     170,   171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "SEMI", "COMMA", "TYPE",
  "STRUCT", "RETURN", "IF", "ELSE", "BREAK", "CONT", "FOR", "READ",
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -142

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-142)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,  -142,     1,     7,  -142,     2,     8,  -142,    -6,    -4,
    -142,  -142,   -28,    20,  -142,   -17,     9,    25,     2,     2,
    -142,   236,    30,     2,  -142,    34,    34,    26,     2,    34,
     -12,  -142,    67,  -142,   -47,    39,    39,    39,    39,    39,
      39,    39,  -142,   491,    23,   221,  -142,  -142,    69,    73,
    -142,  -142,    28,  -142,     2,    39,    39,  -142,   177,    66,
      37,    37,    37,    37,    37,   269,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    81,  -142,    39,    42,   117,   118,
      74,    87,    88,  -142,   108,   221,    75,  -142,    34,  -142,
      90,   306,    39,  -142,  -142,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   517,   542,   566,   589,   611,
     205,   205,    91,    91,    91,    91,   212,   212,   -16,   -16,
      37,    37,    37,  -142,   136,    39,  -142,  -142,    39,    39,
      39,  -142,  -142,  -142,  -142,  -142,    94,  -142,  -142,   343,
     135,   491,   380,   417,  -142,   221,    39,   138,   139,   137,
     144,  -142,  -142,   221,  -142,    39,  -142,   454,   221,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    11,    16,     0,     2,     4,     8,    12,    14,     0,
       1,     3,    17,     0,     7,    44,     0,     9,    40,    21,
       5,     0,     0,    40,     6,     0,     0,     0,    40,     0,
       0,    20,    23,    87,    89,     0,     0,     0,     0,     0,
       0,     0,    45,    46,     0,    27,    17,    10,     0,    43,
      13,    39,    24,    19,     0,     0,     0,    85,    91,     0,
      78,    79,    82,    81,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    27,     0,    41,     0,    22,
       0,     0,     0,    47,    83,    68,    69,    70,    71,    72,
      73,    74,    75,    77,    76,    67,    66,    64,    65,    63,
      61,    62,    57,    58,    59,    60,    55,    56,    53,    54,
      50,    51,    52,    86,     0,     0,    34,    33,    49,     0,
       0,    25,    26,    28,    42,    84,    89,    90,    30,     0,
       0,    48,     0,     0,    88,     0,    49,     0,     0,    38,
       0,    35,    36,     0,    31,     0,    37,     0,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   145,  -142,  -142,   126,    22,  -142,  -142,   123,
    -142,  -142,    99,  -142,   168,    80,  -141,  -142,   -20,  -142,
      78,   -25,  -142,    21,   -21,    32,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    14,    26,     7,     9,    15,
      16,    30,    31,    32,   103,   104,   105,   174,    27,    28,
      48,    17,    42,   160,   106,    57,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    49,    21,    45,    55,     8,    56,    10,    51,     1,
       2,   -15,    12,    18,    58,    60,    61,    62,    63,    64,
      65,   110,     6,    19,   169,    20,    23,     6,    91,    92,
      93,    25,   176,    44,    58,   111,    22,   179,    46,    94,
      53,    29,    33,    34,    50,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    54,   107,   144,    29,    95,   157,   108,
     153,    22,    36,    49,   113,   143,    37,    38,    39,    40,
      41,    58,    94,   145,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   146,   147,   159,   148,   151,   161,   162,   163,
      94,    87,    88,    89,    90,    91,    92,    93,   149,   150,
     166,   158,   155,   171,   172,   161,    94,    56,   173,   175,
      11,    47,    52,   109,   177,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   112,    24,   152,   154,   170,   164,     0,
       0,    94,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    33,    34,     0,     0,     0,     0,
      96,    97,    94,    98,    99,   100,   101,   102,    23,    33,
      34,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    35,    89,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    36,     0,     0,    94,    37,    38,
      39,    40,    41,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,    37,    38,    39,    40,    41,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,   114,     0,     0,    94,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
     156,    94,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,     0,   165,     0,     0,    94,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,     0,     0,
       0,     0,   167,     0,     0,    94,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,   168,
       0,     0,    94,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,     0,   178,     0,     0,    94,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    94
};

static const yytype_int16 yycheck[] =
{
      21,    26,    19,    23,    51,     4,    53,     0,    28,     7,
       8,    17,     4,    17,    35,    36,    37,    38,    39,    40,
      41,    55,     0,    51,   165,     5,    17,     5,    44,    45,
      46,     6,   173,     3,    55,    56,    53,   178,     4,    55,
      52,    19,     3,     4,    18,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     6,     5,    96,    54,    54,   112,     6,
       5,    53,    43,   108,    18,     4,    47,    48,    49,    50,
      51,   112,    55,    51,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     5,     5,   145,    51,    18,   148,   149,   150,
      55,    40,    41,    42,    43,    44,    45,    46,    51,    51,
       5,     5,    52,     5,     5,   166,    55,    53,    11,     5,
       5,    25,    29,    54,   175,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     6,    16,   105,   108,   166,   156,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    55,    12,    13,    14,    15,    16,    17,     3,
       4,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    17,    42,    43,    44,    45,    46,    -1,
      55,    -1,    -1,    -1,    43,    -1,    -1,    55,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    58,    59,    60,    63,    64,     4,    65,
       0,    59,     4,    61,    62,    66,    67,    78,    17,    51,
       5,    19,    53,    17,    71,     6,    63,    75,    76,    63,
      68,    69,    70,     3,     4,    17,    43,    47,    48,    49,
      50,    51,    79,    81,     3,    75,     4,    62,    77,    78,
      18,    75,    66,    52,     6,    51,    53,    82,    81,    83,
      81,    81,    81,    81,    81,    81,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    55,    54,     9,    10,    12,    13,
      14,    15,    16,    71,    72,    73,    81,     5,     6,    69,
      83,    81,     6,    18,    52,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,     4,    81,    51,     5,     5,    51,    51,
      51,    18,    72,     5,    77,    52,    54,    83,     5,    81,
      80,    81,    81,    81,    82,    52,     5,    52,    52,    73,
      80,     5,     5,    11,    74,     5,    73,    81,    52,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     0,     1,
       3,     1,     1,     5,     2,     1,     0,     1,     4,     4,
       1,     0,     3,     1,     2,     4,     2,     0,     2,     1,
       3,     6,     9,     2,     2,     5,     5,     2,     0,     2,
       0,     3,     3,     1,     1,     3,     1,     3,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     3,     4,     2,     3,     1,     4,     0,
       3,     1
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
#line 56 "smallC.y" /* yacc.c:1646  */
    {root = (yyval.node) = new Node(yylineno, Program, "PROGRAM",1, (yyvsp[0].node));}
#line 1500 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdefs, "EXTDEFS", 2, (yyvsp[-1].node),(yyvsp[0].node));}
#line 1506 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1512 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdef, "EXTDEF", 2,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1518 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extdef, "EXTDEF", 3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1524 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvars, "EXTVARS", 1, (yyvsp[0].node));}
#line 1530 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1536 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvar, "EXTVAR", 1, (yyvsp[0].node));}
#line 1542 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 68 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Extvar, "EXTVAR", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1548 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Spec, "SPEC", 1, new Node(yylineno, Type, (yyvsp[0].string),0));}
#line 1554 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Spec, "SPEC", 1,(yyvsp[0].node));}
#line 1560 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stspec, "STSPEC", 3,new Node(yylineno, Keyword, (yyvsp[-4].string), 0), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1566 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 74 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stspec, "STSPEC", 2,new Node(yylineno, Keyword, (yyvsp[-1].string), 0), new Node(yylineno, Id, (yyvsp[0].string),0));}
#line 1572 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 76 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Opttag, "OPTTAG", 1,new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 1578 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1584 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Var, "VAR", 1, new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 1590 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 80 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Var, "VAR", 2, (yyvsp[-3].node), new Node(yylineno, Int, (yyvsp[-1].string), 0));}
#line 1596 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Func, "FUNC", 2, new Node(yylineno, Id, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 1602 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 84 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Paras, "PARAS", 1，(yyvsp[0].node));}
#line 1608 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 85 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1614 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Parasf, "PARASF", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1620 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Parasf, "PARASF", 1, (yyvsp[0].node));}
#line 1626 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 90 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Para, "PARA", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1632 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 92 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmtblock, "STMTBLOCK", 2, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1638 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmts, "STMTS", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1644 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1650 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 97 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, (yyvsp[-1].node));}
#line 1656 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, (yyvsp[0].node));}
#line 1662 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 99 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, (yyvsp[-2].string), 0), (yyvsp[-1].node));}
#line 1668 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 100 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 4, new Node(yylineno, Keyword, (yyvsp[-5].string), 0), (yyvsp[-4].string), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1674 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 5, new Node(yylineno, Keyword, (yyvsp[-8].string), 0), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1680 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 102 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, (yyvsp[-1].string), 0));}
#line 1686 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 103 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 1, new Node(yylineno, Keyword, (yyvsp[-1].string), 0));}
#line 1692 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 104 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, (yyvsp[-4].string), 0), (yyvsp[-2].node));}
#line 1698 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Stmt, "STMT", 2, new Node(yylineno, Keyword, (yyvsp[-4].string), 0), (yyvsp[-2].node));}
#line 1704 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Estmt, "ESTMT", 2, new Node(yylineno, Keyword, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1710 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 108 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1716 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Defs, "DEFS", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1722 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1728 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 113 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Def, "DEF", 2, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1734 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Decs, "DECS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1740 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 116 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Decs, "DECS", 1, (yyvsp[0].node));}
#line 1746 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 118 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Dec, "DEC", 1, (yyvsp[0].node));}
#line 1752 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 119 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Dec, "DEC", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1758 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 121 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Init, "INIT", 1, (yyvsp[0].node));}
#line 1764 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 122 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Init, "INIT", 1, (yyvsp[-1].node));}
#line 1770 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 124 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Fexp, "Fexp", 1, (yyvsp[0].node));}
#line 1776 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 125 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 1782 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 127 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1788 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1794 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1800 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1806 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 131 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1812 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1818 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1824 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1830 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1836 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 136 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1842 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 137 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1848 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 138 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1854 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 139 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1860 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 140 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1866 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 141 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1872 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 142 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1878 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 143 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1884 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 144 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1890 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 145 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1896 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 146 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1902 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 147 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1908 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 148 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1914 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 149 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1920 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 150 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1926 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 151 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1932 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 152 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1938 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 153 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1944 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 154 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1950 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 156 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1956 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 157 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1962 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 158 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1968 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 159 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1974 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 160 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, UnaryOp, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1980 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 161 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 1, (yyvsp[-1].node));}
#line 1986 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 162 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, (yyvsp[-3].string), 0), (yyvsp[-1].node));}
#line 1992 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 163 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 2, new Node(yylineno, Id, (yyvsp[-1].string), 0), (yyvsp[0].node));}
#line 1998 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 164 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 3, (yyvsp[-2].node), new Node(yylineno, Operator, (yyvsp[-1].string), 0), new Node(yylineno, Id, (yyvsp[0].string), 0));}
#line 2004 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 165 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Exp, "EXP", 1, new Node(yylineno, Int, (yyvsp[0].string), 0));}
#line 2010 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 167 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Arrs, "ARRS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2016 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 168 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Null, "NULL", 0);}
#line 2022 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 170 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Args, "ARGS", 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2028 "smallC.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 171 "smallC.y" /* yacc.c:1646  */
    {(yyval.node) = new Node(yylineno, Args, "ARGS", 1, (yyvsp[0].node));}
#line 2034 "smallC.tab.c" /* yacc.c:1646  */
    break;


#line 2038 "smallC.tab.c" /* yacc.c:1646  */
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
#line 173 "smallC.y" /* yacc.c:1906  */

void yyerror(const char *s) {
	fprintf(stderr, "[error] at line [%d] %s %s.\n", yylineno, s, yytext);
}
int yywrap() { return 1;}
int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Parameter must be like <infile> <outfile>. \n";
		return -1;	
	}
		
	freopen(argv[1],"r",stdin);
	freopen(argv[2], "w+", stdout);
	yyparse();
	return 0;
}
