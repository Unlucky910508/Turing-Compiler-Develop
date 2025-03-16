/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "main.y" /* yacc.c:339  */

#include "table.h"
#define Trace(t)        printf(t)
#define YYDEBUG 1
extern int yydebug;
extern FILE* yyin;
int yylex();

struct table_node* head;
struct table_node* tail;

int value_type;
int ID_type;
bool create_table = true;
struct table insert_data;

// about expression
struct exp_table exp_data;
void reset_exp();
// true: type not compatible
bool type_incompatible;
// true: is const
bool is_const;
// true: is exist
bool is_exist;
// true: is already
bool is_already_exist;
// true: the following ID is delaration
bool is_declare;
// true: the following ID is assignment
bool is_assign;
// true: the following ID is put
bool is_put;
// store return value of lookup function, -1: not exist
int lookup_return;
// call ID type --> 0:const, 1:var, 2:array, 3:function, 4:procedure
int ID_call_type;
// Type of the value from ID
int ID_value_type;
int gotoCounter = 0;
int countGoto = 0;

bool is_global;
int next_counter = 0;
FILE* file;
char fileName[30];


#line 115 "y.tab.c" /* yacc.c:339  */

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
    PERIOD = 258,
    COMMA = 259,
    COLON = 260,
    SEMICOLON = 261,
    LP = 262,
    RP = 263,
    LB = 264,
    RB = 265,
    LC = 266,
    RC = 267,
    PLUS = 268,
    MINUS = 269,
    MULTIPLY = 270,
    DIVISION = 271,
    MOD = 272,
    ASSIGN = 273,
    LT = 274,
    NMT = 275,
    NLT = 276,
    MT = 277,
    EQUAL = 278,
    NEQUAL = 279,
    AND = 280,
    OR = 281,
    NOT = 282,
    ARRAY = 283,
    BBEGIN = 284,
    BOOL = 285,
    CHAR = 286,
    CONST = 287,
    DECREASING = 288,
    DEFAULT = 289,
    DO = 290,
    ELSE = 291,
    END = 292,
    EXIT = 293,
    FFALSE = 294,
    FOR = 295,
    FUNCTION = 296,
    GET = 297,
    IF = 298,
    INT = 299,
    LOOP = 300,
    OF = 301,
    PUT = 302,
    PROCEDURE = 303,
    REAL = 304,
    RESULT = 305,
    RETURN = 306,
    SKIP = 307,
    STRING = 308,
    THEN = 309,
    TTRUE = 310,
    VAR = 311,
    WHEN = 312,
    UMINUS = 313,
    ID = 314,
    INTEGER = 315,
    FLOAT = 316,
    SSTRING = 317
  };
#endif
/* Tokens.  */
#define PERIOD 258
#define COMMA 259
#define COLON 260
#define SEMICOLON 261
#define LP 262
#define RP 263
#define LB 264
#define RB 265
#define LC 266
#define RC 267
#define PLUS 268
#define MINUS 269
#define MULTIPLY 270
#define DIVISION 271
#define MOD 272
#define ASSIGN 273
#define LT 274
#define NMT 275
#define NLT 276
#define MT 277
#define EQUAL 278
#define NEQUAL 279
#define AND 280
#define OR 281
#define NOT 282
#define ARRAY 283
#define BBEGIN 284
#define BOOL 285
#define CHAR 286
#define CONST 287
#define DECREASING 288
#define DEFAULT 289
#define DO 290
#define ELSE 291
#define END 292
#define EXIT 293
#define FFALSE 294
#define FOR 295
#define FUNCTION 296
#define GET 297
#define IF 298
#define INT 299
#define LOOP 300
#define OF 301
#define PUT 302
#define PROCEDURE 303
#define REAL 304
#define RESULT 305
#define RETURN 306
#define SKIP 307
#define STRING 308
#define THEN 309
#define TTRUE 310
#define VAR 311
#define WHEN 312
#define UMINUS 313
#define ID 314
#define INTEGER 315
#define FLOAT 316
#define SSTRING 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "main.y" /* yacc.c:355  */

    char ival[256];
    char dval[256];
    char sval[256];
    char bval[256];
    char id_name[256];

#line 284 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 301 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    79,    90,    91,    94,    95,    96,   100,
     115,   131,   169,   207,   242,   257,   256,   328,   327,   388,
     389,   392,   393,   394,   395,   396,   399,   427,   429,   428,
     445,   446,   450,   455,   464,   468,   472,   467,   495,   496,
     498,   503,   510,   517,   519,   520,   523,   531,   584,   530,
     643,   696,   642,   756,   757,   759,   760,   761,   763,   766,
     767,   774,   775,   782,   783,   790,   791,   798,   805,   812,
     819,   826,   835,   836,   841,   848,   849,   854,   859,   866,
     867,   873,   874,   875,   931,   932,   941,   946,   952,   958,
     964,   970,   978,   992,  1004,  1012,  1026,  1032,  1092,  1098,
    1103,  1119,  1124,  1126,  1127,  1130,  1131,  1134,  1146,  1161,
    1164,  1165,  1168,  1169,  1172,  1175,  1178,  1179,  1180,  1181,
    1184,  1193,  1202,  1211,  1229,  1230,  1233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PERIOD", "COMMA", "COLON", "SEMICOLON",
  "LP", "RP", "LB", "RB", "LC", "RC", "PLUS", "MINUS", "MULTIPLY",
  "DIVISION", "MOD", "ASSIGN", "LT", "NMT", "NLT", "MT", "EQUAL", "NEQUAL",
  "AND", "OR", "NOT", "ARRAY", "BBEGIN", "BOOL", "CHAR", "CONST",
  "DECREASING", "DEFAULT", "DO", "ELSE", "END", "EXIT", "FFALSE", "FOR",
  "FUNCTION", "GET", "IF", "INT", "LOOP", "OF", "PUT", "PROCEDURE", "REAL",
  "RESULT", "RETURN", "SKIP", "STRING", "THEN", "TTRUE", "VAR", "WHEN",
  "UMINUS", "ID", "INTEGER", "FLOAT", "SSTRING", "$accept", "program",
  "$@1", "Declarations", "Declaration", "const_declaration",
  "var_declaration", "funtion_declaration", "$@2", "$@3", "Statements",
  "Statement", "simple_statement", "$@4", "conditional_statement", "$@5",
  "$@6", "if_Statement", "loop_statement", "block_statement",
  "get_statement", "exit_statement", "loop_loop", "for_loop", "$@7", "$@8",
  "$@9", "$@10", "no_function_programs", "no_function_program", "exp",
  "or_exp", "and_exp", "not_exp", "compare_exp", "add_exp", "multi_exp",
  "unary_exp", "all_value", "unary_op", "const_token", "var_token",
  "function_token", "procedure_token", "assign_token", "if_token",
  "else_token", "loop_token", "for_token", "begin_token", "ID_token",
  "LP_token", "RP_token", "LB_token", "RB_token", "Arguments_token",
  "Arguments", "R_Arguments", "F_Argument", "R_Argument",
  "input_Arguments", "R_inputs", "F_input", "R_input", "Type",
  "const_value", "booling", "Eplision", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,  -121,  -121,  -121,  -121,    19,  -121,    68,  -121,  -121,
    -121,   -31,   -20,    -8,    -5,  -121,  -121,    17,  -121,     0,
       7,    29,    36,  -121,  -121,   151,  -121,     1,  -121,  -121,
       2,  -121,  -121,  -121,    92,  -121,  -121,  -121,     4,  -121,
    -121,  -121,  -121,    17,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,    37,    48,  -121,   195,    52,    -1,  -121,  -121,
      35,    92,   142,   -24,   142,    66,    92,  -121,  -121,  -121,
      74,  -121,    92,    59,    92,    27,    27,    81,   195,    92,
    -121,  -121,  -121,  -121,    92,  -121,    92,    92,  -121,    92,
      92,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,  -121,    38,  -121,  -121,  -121,    61,   142,  -121,
      42,   102,    76,  -121,    92,   109,  -121,  -121,  -121,  -121,
     104,  -121,    60,   104,  -121,   120,   122,  -121,   128,  -121,
     125,  -121,  -121,  -121,  -121,   109,   131,  -121,    48,  -121,
      52,    52,    52,    52,    52,    52,    -1,    -1,  -121,  -121,
    -121,  -121,    91,  -121,   133,    92,  -121,   130,  -121,  -121,
      92,   138,    92,   -23,   140,    27,  -121,   128,  -121,  -121,
    -121,    92,  -121,   131,  -121,   142,  -121,    92,  -121,  -121,
    -121,  -121,   143,  -121,   147,  -121,    74,  -121,  -121,   142,
    -121,  -121,  -121,  -121,   152,    97,   156,  -121,   123,   126,
     158,   160,   124,   106,   142,   113,  -121,   141,   142,   165,
      92,    74,   145,   149,  -121,   132,  -121,    92,  -121,  -121,
      74,   118,  -121,  -121,   142,  -121,  -121,   142,   159,   162,
     148,   148,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     126,    87,    89,    90,    88,     0,     2,   126,     6,     7,
       8,     0,     0,     0,     0,     5,     1,   126,     4,     0,
       0,     0,     0,    98,    86,     0,    96,    34,   125,    95,
       0,    92,    94,    28,     0,    30,    32,   124,    97,   120,
     121,   122,     3,   126,    21,    23,    24,    25,    27,    40,
      41,    22,    58,    59,    61,    63,    65,    72,    75,    79,
       0,     0,   126,     0,   126,    81,     0,    82,   123,    20,
       0,    91,     0,     0,     0,   126,   126,    97,    64,     0,
      33,    44,    97,    43,     0,    31,     0,   126,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,    56,    55,    57,     0,   126,    54,
       0,     0,     0,   100,     0,     0,   119,   116,   117,   118,
       0,     9,     0,    13,    11,     0,     0,   102,   126,   104,
       0,    45,    29,    26,   114,     0,   126,   111,    60,    62,
      66,    67,    68,    69,    70,    71,    74,    73,    76,    77,
      78,    35,     0,    53,     0,     0,    42,     0,    99,    84,
       0,     0,     0,     0,     0,     0,   103,   126,   106,    17,
      83,     0,   110,   126,   113,   126,    46,     0,    47,   101,
      85,    10,     0,    12,     0,   107,     0,   109,   105,   126,
     115,   112,    36,    50,     0,     0,     0,    15,     0,    39,
       0,     0,     0,     0,   126,     0,    93,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    38,     0,    48,    14,
       0,     0,    37,    51,   126,   108,    16,   126,     0,     0,
       0,     0,    49,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,   188,  -121,    10,    34,  -121,  -121,  -121,
     157,   -14,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -60,    -3,
     -34,  -121,   119,   117,   184,   129,   -27,   -16,   166,  -121,
    -121,  -121,  -121,  -121,   -18,    12,  -121,  -121,  -120,  -121,
     198,   -30,    94,  -121,  -121,  -121,   154,    64,    67,  -121,
    -121,    62,  -121,  -121,   -72,  -121,  -121,     6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    17,     6,     7,   104,   105,    10,   204,   189,
      42,   106,    44,    84,    45,   175,   199,   207,    46,    47,
      48,    80,    49,    50,   194,   224,   200,   227,   107,   108,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      11,    12,    13,    14,    72,    61,   208,    62,    63,    64,
      65,    66,   159,   114,   180,   126,   127,   166,   128,   167,
     135,   172,   136,   173,   120,    67,    68,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,   123,    74,    43,   112,    70,    15,   116,    87,   110,
       8,    23,    73,    15,    99,   100,   101,     8,    71,    16,
      86,   117,    71,    69,    23,    71,   118,   103,    19,    43,
     119,    24,   115,    81,     9,   111,    75,   184,   121,    20,
     124,     9,    23,    76,    25,   131,    26,    87,   153,    69,
     132,    21,   133,   134,    22,    27,    28,    29,    79,    30,
      31,    82,    32,    89,    33,    97,    98,    34,    35,    36,
     146,   147,    37,    90,    28,   113,    38,    39,    40,    41,
     157,   129,   129,   148,   149,   150,   125,   122,    23,   116,
      37,   185,   151,   137,    77,    39,    40,    41,   152,    23,
       1,   154,   160,   117,   116,   162,    24,   155,   118,     2,
     232,   233,   119,   156,   197,   192,     3,   158,   117,    25,
     161,   178,    71,   118,     4,   163,   181,   119,   183,   198,
     164,    28,   165,   169,   168,   171,   176,   190,   177,   219,
     179,   182,   174,   193,   213,   186,   195,    37,   225,    23,
     196,    77,    39,    40,    41,   201,    24,   202,    23,   203,
     205,   209,   206,   210,   228,    24,   212,   229,   217,    25,
     211,    26,   214,   168,     1,    31,   218,   226,   215,   174,
      27,    28,    29,   223,    30,    31,   221,    32,    29,    33,
      28,   220,    34,    35,    36,    18,   230,    37,     4,   231,
      88,    38,    39,    40,    41,   216,    37,   139,   138,    78,
      77,    39,    40,    41,    91,    92,    93,    94,    95,    96,
     140,   141,   142,   143,   144,   145,   102,   222,    83,   170,
     130,   188,   187,     0,     0,   191
};

static const yytype_int16 yycheck[] =
{
      34,    73,    20,    17,    64,     5,     0,    30,    38,    33,
       0,     7,     5,     7,    15,    16,    17,     7,    18,     0,
      38,    44,    18,    17,     7,    18,    49,    61,    59,    43,
      53,    14,    66,    27,     0,    59,     7,    60,    72,    59,
      74,     7,     7,     7,    27,    79,    29,    77,   108,    43,
      84,    59,    86,    87,    59,    38,    39,    40,    57,    42,
      43,    59,    45,    26,    47,    13,    14,    50,    51,    52,
      97,    98,    55,    25,    39,     9,    59,    60,    61,    62,
     114,    75,    76,    99,   100,   101,    59,    28,     7,    30,
      55,   163,    54,    87,    59,    60,    61,    62,    37,     7,
      32,    59,   120,    44,    30,   123,    14,     5,    49,    41,
     230,   231,    53,    37,   186,   175,    48,     8,    44,    27,
      60,   155,    18,    49,    56,     5,   160,    53,   162,   189,
       8,    39,     4,     8,   128,     4,    45,   171,     5,   211,
      10,     3,   136,   177,   204,     5,     3,    55,   220,     7,
       3,    59,    60,    61,    62,     3,    14,    60,     7,     3,
      37,     3,    36,     3,   224,    14,    60,   227,     3,    27,
      46,    29,    59,   167,    32,    43,   210,    59,    37,   173,
      38,    39,    40,   217,    42,    43,    37,    45,    40,    47,
      39,    46,    50,    51,    52,     7,    37,    55,    56,    37,
      43,    59,    60,    61,    62,   208,    55,    90,    89,    25,
      59,    60,    61,    62,    19,    20,    21,    22,    23,    24,
      91,    92,    93,    94,    95,    96,    60,   215,    30,   135,
      76,   167,   165,    -1,    -1,   173
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    41,    48,    56,    64,    66,    67,    68,    69,
      70,   103,   104,   105,   106,   130,     0,    65,    66,    59,
      59,    59,    59,     7,    14,    27,    29,    38,    39,    40,
      42,    43,    45,    47,    50,    51,    52,    55,    59,    60,
      61,    62,    73,    74,    75,    77,    81,    82,    83,    85,
      86,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   108,   110,   111,   112,   113,   114,   128,   129,   130,
       5,    18,   107,     5,   107,     7,     7,    59,    97,    57,
      84,   130,    59,   113,    76,    93,   107,   114,    73,    26,
      25,    19,    20,    21,    22,    23,    24,    13,    14,    15,
      16,    17,   101,    93,    68,    69,    74,    91,    92,   130,
      33,    59,    91,     9,   116,    93,    30,    44,    49,    53,
     127,    93,    28,   127,    93,    59,   118,   119,   121,   130,
     119,    93,    93,    93,    93,   123,   125,   130,    95,    96,
      98,    98,    98,    98,    98,    98,    99,    99,   100,   100,
     100,    54,    37,    91,    59,     5,    37,    93,     8,   115,
     107,    60,   107,     5,     8,     4,   120,   122,   130,     8,
     115,     4,   124,   126,   130,    78,    45,     5,    93,    10,
     117,    93,     3,    93,    60,   127,     5,   121,   120,    72,
      93,   124,    91,    93,    87,     3,     3,   127,    91,    79,
      89,     3,    60,     3,    71,    37,    36,    80,   109,     3,
       3,    46,    60,    91,    59,    37,    92,     3,    93,   127,
      46,    37,   108,    93,    88,   127,    59,    90,    91,    91,
      37,    37,   111,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    65,    64,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    71,    70,    72,    70,    73,
      73,    74,    74,    74,    74,    74,    75,    75,    76,    75,
      75,    75,    75,    75,    75,    78,    79,    77,    80,    80,
      81,    81,    82,    83,    84,    84,    85,    87,    88,    86,
      89,    90,    86,    91,    91,    92,    92,    92,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    99,    99,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   125,   126,   127,   127,   127,   127,
     128,   128,   128,   128,   129,   129,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     1,     1,     1,     4,
       6,     4,     6,     4,    10,     0,    11,     0,     9,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     2,     1,     2,     1,     0,     0,     9,     2,     0,
       1,     1,     3,     2,     1,     2,     4,     0,     0,    12,
       0,     0,    13,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     1,     4,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     8,     2,
       2,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0
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
#line 80 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "method public static void main(java.lang.String[])\n");
                        fprintf(file, "max_stack 15\n");
                        fprintf(file, "max_locals 15\n{\n");
                        is_global = false;
                }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "return\n}\n}\n");
                }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-2].id_name));
                        insert_data.type = value_type;
                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                        insert_data.is_function = 0;
                        insert_data.counter = -1;
                        
                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                        strcpy(exp_data.exp, "");
                        is_assign = false;

                }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-4].id_name));
                        insert_data.type = ID_type;
                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                        insert_data.is_function = 0;
                        insert_data.counter = -1;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-4].id_name)));
                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 132 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-2].id_name));
                        insert_data.type = value_type;
                        insert_data.is_function = 1;
                        if(head == tail)
                        {
                                fprintf(file, "field static ");
                                switch(value_type)
                                {
                                case 0:
                                        fprintf(file, "int ");
                                        break;
                                case 1:
                                        fprintf(file, "float ");
                                        break;
                                case 2:
                                        fprintf(file, "string ");
                                        break;
                                case 3:
                                        fprintf(file, "bool ");
                                        break;
                                }
                                fprintf(file, "%s = %s\n", (yyvsp[-2].id_name), exp_data.exp);
                                insert_data.counter = -1;
                        }
                        else
                        {
                                insert_data.counter = next_counter;
                                fprintf(file, "istore %d\n", next_counter);
                                next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-4].id_name));
                        insert_data.type = ID_type;
                        insert_data.is_function = 1;
                        if(head == tail)
                        {
                                fprintf(file, "field static ");
                                switch(ID_type)
                                {
                                case 0:
                                        fprintf(file, "int ");
                                        break;
                                case 1:
                                        fprintf(file, "float ");
                                        break;
                                case 2:
                                        fprintf(file, "string ");
                                        break;
                                case 3:
                                        fprintf(file, "bool ");
                                        break;
                                }
                                fprintf(file, "%s = %s\n", (yyvsp[-4].id_name), exp_data.exp);
                                insert_data.counter = -1;
                        }
                        else
                        {
                                insert_data.counter = next_counter;
                                fprintf(file, "istore %d\n", next_counter);
                                next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-4].id_name)));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 208 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-2].id_name));
                        insert_data.type = ID_type;
                        insert_data.is_function = 1;
                        if(head == tail)
                        {
                                fprintf(file, "field static ");
                                switch(value_type)
                                {
                                case 0:
                                        fprintf(file, "int ");
                                        break;
                                case 1:
                                        fprintf(file, "float ");
                                        break;
                                case 2:
                                        fprintf(file, "string ");
                                        break;
                                case 3:
                                        fprintf(file, "bool ");
                                        break;
                                }
                                insert_data.counter = -1;
                                fprintf(file, "%s\n", (yyvsp[-2].id_name));
                        }
                        else
                        {
                                insert_data.counter = next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                        strcpy(exp_data.exp, "");
                }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 243 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-8].id_name));
                        insert_data.type = ID_type;
                        insert_data.array_start = atoi((yyvsp[-5].ival));
                        insert_data.array_end = atoi((yyvsp[-2].ival));
                        insert_data.is_function = 2;
                        
                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-8].id_name)));
                        strcpy(exp_data.exp, "");
                }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 257 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "method public static ");
                        switch (ID_type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s(", (yyvsp[-5].id_name));
                        for(int i = 0; i < table_size; ++i)
                        {
                                if(tail->function_argument[i].name[0] != '\0')
                                {
                                        if(i != 0)
                                        {
                                                fprintf(file, ", ");
                                        }
                                        switch (tail->function_argument[i].type)
                                        {
                                        case 0:
                                                fprintf(file, "int");
                                                break;
                                        case 2:
                                                fprintf(file, "string");
                                                break;
                                        case 3:
                                                fprintf(file, "bool");
                                                break;
                                        }
                                }
                                else
                                {
                                        break;
                                }
                        }
                        fprintf(file, ")\n");
                        fprintf(file, "max_stack 15\nmax_locals 15\n{\n");
                }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 301 "main.y" /* yacc.c:1646  */
    {
                        if(check_name_the_same((yyvsp[-9].id_name), (yyvsp[0].id_name)))
                        {
                                fprintf(file, "}\n");
                                char temp_name[20];
                                strcpy(temp_name, ": ");
                                strcat(temp_name, (yyvsp[-9].id_name));
                                dump_argument(tail, "FUNCTION", temp_name);
                                dump(tail, "FUNCTION", temp_name);
                                tail = head;
                                //tail = delete_node(tail);
                                strcpy(insert_data.name, (yyvsp[-9].id_name));
                                insert_data.type = ID_type;
                                insert_data.is_function = 3;
                                insert_data.counter = -1;

                                insert(head->current, insert_data);
                                head->max_name_length = max(head->max_name_length, strlen((yyvsp[-9].id_name)));
                                strcpy(exp_data.exp, "");
                        }
                        else
                        {
                                Trace("[WARNING] Inconsistent function ID before and after\n");
                                tail = delete_node(tail);
                        }
                }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 328 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "method public static void ");
                        fprintf(file, "%s(", (yyvsp[-3].id_name));
                        for(int i = 0; i < table_size; ++i)
                        {
                                if(tail->function_argument[i].name[0] != '\0')
                                {
                                        if(i != 0)
                                        {
                                                fprintf(file, ", ");
                                        }
                                        switch (tail->function_argument[i].type)
                                        {
                                        case 0:
                                                fprintf(file, "int");
                                                break;
                                        case 2:
                                                fprintf(file, "string");
                                                break;
                                        case 3:
                                                fprintf(file, "bool");
                                                break;
                                        }
                                }
                                else
                                {
                                        break;
                                }
                        }
                        fprintf(file, ")\n");
                        fprintf(file, "max_stack 15\nmax_locals 15\n{\n");
                }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 360 "main.y" /* yacc.c:1646  */
    {
                        if(check_name_the_same((yyvsp[-7].id_name), (yyvsp[0].id_name)) && !is_already_exist)
                        {
                                fprintf(file, "}\n");
                                char temp_name[20];
                                strcpy(temp_name, ": ");
                                strcat(temp_name, (yyvsp[-7].id_name));
                                dump_argument(tail, "PROCEDURE", temp_name);
                                dump(tail, "PROCEDURE", temp_name);
                                tail = head;
                                //tail = delete_node(tail);
                                strcpy(insert_data.name, (yyvsp[-7].id_name));
                                insert_data.type = 4;
                                insert_data.is_function = 4;
                                insert_data.counter = -1;

                                insert(head->current, insert_data);
                                head->max_name_length = max(head->max_name_length, strlen((yyvsp[-7].id_name)));
                                strcpy(exp_data.exp, "");
                        }
                        else
                        {
                                Trace("[WARNING] Inconsistent procedure ID before and after\n");
                                tail = delete_node(tail);
                        }
                }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 400 "main.y" /* yacc.c:1646  */
    {
                        if(getGlobal(head, tail, (yyvsp[-2].id_name)))
                        {
                                int type = lookup_all(tail, (yyvsp[-2].id_name));
                                type /= 10;
                                type %= 10;
                                fprintf(file, "putstatic ");
                                switch (type)
                                {
                                case 0:
                                        fprintf(file, "int ");
                                        break;
                                case 2:
                                        fprintf(file, "string ");
                                        break;
                                case 3:
                                        fprintf(file, "bool ");
                                        break;
                                }
                                fprintf(file, "%s.%s\n", fileName, (yyvsp[-2].id_name));
                        }
                        else
                        {
                                fprintf(file, "istore %d\n", getCounter(tail, (yyvsp[-2].id_name)));
                        }
                        is_assign = false;
                }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 429 "main.y" /* yacc.c:1646  */
    {
                        is_put = true;
                        fprintf(file, "getstatic java.io.PrintStream java.lang.System.out\n");

                }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 434 "main.y" /* yacc.c:1646  */
    {
                        if(value_type == 0 || value_type == 3)
                        {
                                fprintf(file, "invokevirtual void java.io.PrintStream.print(int)\n");
                        }
                        else
                        {
                                fprintf(file, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
                        }
                        is_put = false;
                }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 447 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "ireturn\n");
                }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 451 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "getstatic java.io.PrintStream java.lang.System.out\n");
                        fprintf(file, "invokevirtual void java.io.PrintStream.println()\n");
                }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 456 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "iconst_0\n");
                        fprintf(file, "goto L%d\n", gotoCounter + 2);
                        fprintf(file, "L%d:\n", gotoCounter + 1);
                        fprintf(file, "iconst_1\n");
                        fprintf(file, "L%d:\n", gotoCounter + 2);
                        fprintf(file, "ifne L%d\n", gotoCounter + 3);
                }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 468 "main.y" /* yacc.c:1646  */
    {
                        fprintf(file, "goto L%d\n", gotoCounter + 2);
                        fprintf(file, "L%d:\n", gotoCounter + 1);
                }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 472 "main.y" /* yacc.c:1646  */
    {
                        {
                                fprintf(file, "goto L%d\n", gotoCounter+3);
                                fprintf(file, "L%d:\n", gotoCounter + 2);
                                fprintf(file, "iconst_0\n");
                                fprintf(file, "ifne L%d\n", gotoCounter+3);
                        }
                }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 480 "main.y" /* yacc.c:1646  */
    {
                        dump(tail, "ELSE", "");
                        tail = delete_node(tail);

                        fprintf(file, "L%d:\n", gotoCounter + 3);
                }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 499 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "LOOP", "");
                tail = delete_node(tail);
        }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 504 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "FOR", "");
                tail = delete_node(tail);
        }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 511 "main.y" /* yacc.c:1646  */
    {
                        dump(tail, "BLOCK", "");
                        tail = delete_node(tail);
                }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 524 "main.y" /* yacc.c:1646  */
    {
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
        }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 531 "main.y" /* yacc.c:1646  */
    {
                if(getGlobal(head, tail, (yyvsp[-2].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-2].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "putstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-2].id_name));
                }
                else
                {
                        fprintf(file, "istore%d\n", getCounter(tail, (yyvsp[-2].id_name)));
                }

                fprintf(file, "L%d:\n", gotoCounter);

                if(getGlobal(head, tail, (yyvsp[-2].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-2].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "getstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-2].id_name));
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, (yyvsp[-2].id_name)));
                }
        }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 584 "main.y" /* yacc.c:1646  */
    {
                fprintf(file, "isub\n");
                fprintf(file, "ifgt L%d\n", gotoCounter + 1);
                fprintf(file, "iconst_0\n");
                fprintf(file, "goto L%d\n", gotoCounter + 2);
                fprintf(file, "L%d:\n", gotoCounter + 1);
                fprintf(file, "iconst_1\n");
                fprintf(file, "L%d:\n", gotoCounter + 2);
                fprintf(file, "ifne L%d\n", gotoCounter + 3);
        }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 594 "main.y" /* yacc.c:1646  */
    {
                if(getGlobal(head, tail, (yyvsp[-10].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-10].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "getstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-10].id_name));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "iadd\n");
                        fprintf(file, "putstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-10].id_name));
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, (yyvsp[-10].id_name)));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "iadd\n");
                        fprintf(file, "istore%d\n", getCounter(tail, (yyvsp[-10].id_name)));
                }
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
                gotoCounter += 6;
        }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 643 "main.y" /* yacc.c:1646  */
    {
                if(getGlobal(head, tail, (yyvsp[-2].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-2].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "putstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-2].id_name));
                }
                else
                {
                        fprintf(file, "istore%d\n", getCounter(tail, (yyvsp[-2].id_name)));
                }

                fprintf(file, "L%d:\n", gotoCounter);

                if(getGlobal(head, tail, (yyvsp[-2].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-2].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "getstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-2].id_name));
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, (yyvsp[-2].id_name)));
                }
        }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 696 "main.y" /* yacc.c:1646  */
    {
                fprintf(file, "isub\n");
                fprintf(file, "iflt L%d\n", gotoCounter + 1);
                fprintf(file, "iconst_0\n");
                fprintf(file, "goto L%d\n", gotoCounter + 2);
                fprintf(file, "L%d:\n", gotoCounter + 1);
                fprintf(file, "iconst_1\n");
                fprintf(file, "L%d:\n", gotoCounter + 2);
                fprintf(file, "ifne L%d\n", gotoCounter + 3);
        }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 706 "main.y" /* yacc.c:1646  */
    {
                if(getGlobal(head, tail, (yyvsp[-10].id_name)))
                {
                        int type = lookup_all(tail, (yyvsp[-10].id_name));
                        type /= 10;
                        type %= 10;
                        fprintf(file, "getstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-10].id_name));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "isub\n");
                        fprintf(file, "putstatic ");
                        switch (type)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                        fprintf(file, "%s.%s\n", fileName, (yyvsp[-10].id_name));
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, (yyvsp[-10].id_name)));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "isub\n");
                        fprintf(file, "istore%d\n", getCounter(tail, (yyvsp[-10].id_name)));
                }
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
                gotoCounter += 6;
        }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 768 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " or ");
                fprintf(file, "ior\n");
        }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 776 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " and ");
                fprintf(file, "iand\n");
        }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 784 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "not ");
                fprintf(file, "ixor\n");
        }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 792 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " < ");

                fprintf(file, "isub\n");
                fprintf(file, "iflt L%d\n", gotoCounter + 1);
        }
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 799 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " <= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifle L%d\n", gotoCounter + 1);
        }
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 806 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " >= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifge L%d\n", gotoCounter + 1);
        }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 813 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " > ");

                fprintf(file, "isub\n");
                fprintf(file, "ifgt L%d\n", gotoCounter + 1);
        }
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 820 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " = ");

                fprintf(file, "isub\n");
                fprintf(file, "ifeq L%d\n", gotoCounter + 1);
        }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 827 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " not= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifne L%d\n", gotoCounter + 1);
        }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 837 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " - ");
                fprintf(file, "isub\n");
        }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 842 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " + ");
                fprintf(file, "iadd\n");
        }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 850 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " * ");
                fprintf(file, "imul\n");
        }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 855 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " / ");
                fprintf(file, "idiv\n");
        }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 860 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " mod ");
                fprintf(file, "imod\n");
        }
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 868 "main.y" /* yacc.c:1646  */
    {
                fprintf(file, "ineg\n");
        }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 876 "main.y" /* yacc.c:1646  */
    {
                fprintf(file, "invokestatic "); 
                lookup_return = lookup_all(head, (yyvsp[-3].id_name));
                int category = lookup_return % 10;
                if(category == 3)
                {
                        lookup_return /= 10;
                        switch (lookup_return % 10)
                        {
                        case 0:
                                fprintf(file, "int ");
                                break;
                        case 2:
                                fprintf(file, "string ");
                                break;
                        case 3:
                                fprintf(file, "bool ");
                                break;
                        }
                }
                else if(category == 4)
                {
                        fprintf(file, "void ");
                }
                fprintf(file, "%s.%s(", fileName, (yyvsp[-3].id_name));
                struct table* temp= creat();
                temp = find_function(head, (yyvsp[-3].id_name));
                for(int i = 0; i < table_size; ++i)
                {
                        if(temp[i].name[0] != '\0')
                        {
                                if(i != 0)
                                {
                                        fprintf(file, ", ");
                                }
                                switch (temp[i].type)
                                {
                                case 0:
                                        fprintf(file, "int");
                                        break;
                                case 2:
                                        fprintf(file, "string");
                                        break;
                                case 3:
                                        fprintf(file, "bool");
                                        break;
                                }
                        }
                        else
                        {
                                break;
                        }
                }
                fprintf(file, ")\n");
        }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 933 "main.y" /* yacc.c:1646  */
    {
                if(!is_exist)
                {
                        WARNING_NOT_CONST;
                }
        }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 942 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "-");
        }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 947 "main.y" /* yacc.c:1646  */
    {
                is_declare = true;
                is_assign = false;
        }
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 953 "main.y" /* yacc.c:1646  */
    {
                is_declare = true;
                is_assign = false;
        }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 959 "main.y" /* yacc.c:1646  */
    {
                        is_declare = true;
                        tail = insert_function_table(tail);
                }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 965 "main.y" /* yacc.c:1646  */
    {
                        is_declare = true;
                        tail = insert_function_table(tail);
                }
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 971 "main.y" /* yacc.c:1646  */
    {
                is_declare = false;
                is_assign = true;
                strcpy(exp_data.exp, "");
                //reset_exp();
        }
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 979 "main.y" /* yacc.c:1646  */
    {
                if(create_table)
                {
                        struct table *temp = creat();
                        tail = insert_table(tail);
                        create_table = false;
                }
                else
                {
                        create_table = true;
                }
        }
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 993 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "IF", "");
                tail = delete_node(tail);
                struct table *temp = creat();
                tail = insert_table(tail);

                //fprintf(file, "goto L%d\n", gotoCounter+3);
                //fprintf(file, "L%d:\n", gotoCounter + 2);

        }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1005 "main.y" /* yacc.c:1646  */
    {
                struct table *temp = creat();
                tail = insert_table(tail);

                fprintf(file, "L%d:\n", gotoCounter);
        }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1013 "main.y" /* yacc.c:1646  */
    {
                if(create_table)
                {
                        struct table *temp = creat();
                        tail = insert_table(tail);
                        create_table = false;
                }
                else
                {
                        create_table = true;
                }
        }
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1027 "main.y" /* yacc.c:1646  */
    {
                struct table *temp = creat();
                tail = insert_table(tail);
        }
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1033 "main.y" /* yacc.c:1646  */
    {
                lookup_return = lookup_all(tail, (yyvsp[0].id_name));
                int category = lookup_return % 10;
                lookup_return /= 10;
                int type = lookup_return % 10;
                // const
                if(category == 0)
                {
                        value_type = type;
                        switch(type)
                        {
                        case 0:
                                fprintf(file, "sipush %s\n", getValue(tail, (yyvsp[0].id_name)));
                                break;
                        case 2:
                                fprintf(file, "ldc \"%s\"\n", getValue(tail, (yyvsp[0].id_name)));
                                break;
                        case 3:
                        if(strcmp(getValue(tail, (yyvsp[0].id_name)), "true") == 0)
                                {
                                        fprintf(file, "iconst_1\n");
                                }
                                else
                                {
                                        fprintf(file, "iconst_0\n");
                                }
                                break;
                        }
                }
                else if(category == 1)
                {
                        value_type = type;
                        if(getGlobal(head, tail, (yyvsp[0].id_name)))
                        {
                                int type = lookup_all(tail, (yyvsp[0].id_name));
                                type /= 10;
                                type %= 10;
                                fprintf(file, "getstatic ");
                                switch (type)
                                {
                                case 0:
                                        fprintf(file, "int ");
                                        break;
                                case 2:
                                        fprintf(file, "string ");
                                        break;
                                case 3:
                                        fprintf(file, "bool ");
                                        break;
                                }
                                fprintf(file, "%s.%s\n", fileName, (yyvsp[0].id_name));
                        }
                        else
                        {
                                fprintf(file, "iload %d\n", getCounter(tail, (yyvsp[0].id_name)));
                        }
                }
        }
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1093 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "(");
                is_declare = false;
        }
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1099 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, ")");
        }
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1104 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "[");
                if(lookup_return != -1)
                {
                        if(ID_call_type == 2)
                        {

                        }
                        else
                        {
                                Trace("[warning] The ID is'nt an array\n");
                        }
                }
        }
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1120 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "]");
        }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1135 "main.y" /* yacc.c:1646  */
    {
                strcpy(insert_data.name, (yyvsp[-2].id_name));
                insert_data.type = ID_type;
                insert_data.is_function = 1;
                insert_data.counter = next_counter;
                next_counter++;

                insert(tail->function_argument, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                strcpy(exp_data.exp, "");
        }
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1147 "main.y" /* yacc.c:1646  */
    {
                strcpy(insert_data.name, (yyvsp[-7].id_name));
                insert_data.type = ID_type;
                insert_data.array_start = atoi((yyvsp[-5].ival));
                insert_data.array_end = atoi((yyvsp[-2].ival));
                insert_data.is_function = 2;
                insert_data.counter = next_counter++;

                insert(tail->function_argument, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-7].id_name)));
                strcpy(exp_data.exp, "");
        }
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1178 "main.y" /* yacc.c:1646  */
    {ID_type = 0;}
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1179 "main.y" /* yacc.c:1646  */
    {ID_type = 1;}
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1180 "main.y" /* yacc.c:1646  */
    {ID_type = 2;}
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1181 "main.y" /* yacc.c:1646  */
    {ID_type = 3;}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1185 "main.y" /* yacc.c:1646  */
    {       
                value_type = 0;
                exp_push_back(&exp_data, yylval.ival);
                if(head != tail || !is_global)
                {
                        fprintf(file, "sipush %s\n", yylval.ival);
                }
        }
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1194 "main.y" /* yacc.c:1646  */
    {
                value_type = 1;
                exp_push_back(&exp_data, yylval.dval);
                if(head != tail|| !is_global)
                {
                        fprintf(file, "sipush %s\n", yylval.ival);
                }
        }
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1203 "main.y" /* yacc.c:1646  */
    {
                value_type = 2;
                exp_push_back(&exp_data, yylval.sval);
                if(head != tail|| !is_global)
                {
                        fprintf(file, "ldc \"%s\"\n", yylval.sval);
                }
        }
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1212 "main.y" /* yacc.c:1646  */
    {
                value_type = 3;
                exp_push_back(&exp_data, yylval.bval);
                if(head != tail|| !is_global)
                {
                        if(yylval.bval[0] == 't')
                        {
                                fprintf(file, "iconst_1\n");
                        }
                        else
                        {
                                fprintf(file, "iconst_0\n");
                        }
                }
        }
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2875 "y.tab.c" /* yacc.c:1646  */
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
#line 1237 "main.y" /* yacc.c:1906  */

yyerror(msg)    
char *msg;
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]){
        // initial
        {
                if(argc > 0){
                        yyin = fopen(argv[1],"r");
                }
                strcpy(fileName, argv[1]);
                for(int i = 0; i < strlen(fileName); ++i)
                {
                        if(fileName[i] == '.')
                        {
                                fileName[i] = '\0';
                                break;
                        }
                }
                strcat(fileName, ".jasm");
                file = fopen(fileName, "w");
                for(int i = 0; i < strlen(fileName); ++i)
                {
                        if(fileName[i] == '.')
                        {
                                fileName[i] = '\0';
                                break;
                        }
                }
                fprintf(file, "class %s\n{\n", fileName);
                is_global = true;
        }

        head = creat_table_node();
        tail = creat_table_node();
        head = tail;
        yyparse();
        dump(head, "GLOBAL", "");

        fclose(file);
        //dump_all_table(head);
        //free(T);
        //free(head);
        //free(tail);
}

void reset_exp()
{
        strcpy(exp_data.exp, "");
        value_type = -1;
        type_incompatible = false;
        is_const = true;
        is_exist = true;
        is_already_exist = false;
        lookup_return = 0;
        is_declare = false; 
}
