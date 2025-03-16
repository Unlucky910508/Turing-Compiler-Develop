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
int yylex();

struct table* T;
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
// store return value of lookup function, -1: not exist
int lookup_return;
// call ID type --> 0:const, 1:var, 2:array, 3:function, 4:procedure
int ID_call_type;
// Type of the value from ID
int ID_value_type;


#line 104 "y.tab.c" /* yacc.c:339  */

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
#line 52 "main.y" /* yacc.c:355  */

    char ival[256];
    char dval[256];
    char sval[256];
    char bval[256];
    char id_name[256];

#line 273 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 290 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

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
       0,    68,    68,    70,    71,    74,    75,    76,    80,   117,
     161,   192,   231,   244,   260,   291,   323,   324,   327,   328,
     329,   330,   331,   334,   368,   382,   383,   384,   385,   386,
     389,   394,   401,   406,   413,   420,   422,   423,   426,   429,
     433,   436,   441,   443,   444,   445,   448,   451,   452,   455,
     456,   459,   460,   463,   464,   467,   468,   471,   472,   475,
     476,   479,   480,   481,   482,   483,   492,   497,   502,   507,
     511,   515,   519,   523,   527,   532,   536,   541,   545,   549,
     554,   559,   564,   569,   576,   583,   590,   604,   612,   626,
     640,   646,   691,   697,   702,   718,   723,   724,   727,   728,
     731,   742,   757,   760,   761,   764,   765,   768,   771,   774,
     775,   776,   777,   780,   793,   806,   819,   834,   835,   838
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
  "Declarations", "Declaration", "const_declaration", "var_declaration",
  "funtion_declaration", "Statements", "Statement", "simple_statement",
  "conditional_statement", "loop_statement", "block_statement",
  "get_statement", "exit_statement", "loop_loop", "for_loop",
  "for_statement", "no_function_program", "variableDeclarations", "exp",
  "or_exp", "and_exp", "not_exp", "compare_exp", "add_exp", "multi_exp",
  "unary_exp", "all_value", "or_op", "and_op", "not_op", "compare_op",
  "add_op", "multi_op", "unary_op", "const_token", "var_token",
  "function_token", "procedure_token", "assign_token", "if_token",
  "else_token", "loop_token", "for_token", "begin_token", "ID_token",
  "LP_token", "RP_token", "LB_token", "RB_token", "Arguments",
  "R_Arguments", "F_Argument", "R_Argument", "input_Arguments", "R_inputs",
  "F_input", "R_input", "Type", "const_value", "booling", "Eplision", YY_NULLPTR
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

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-153)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,  -153,  -153,  -153,  -153,    54,   133,   -16,  -153,  -153,
    -153,    -7,    -7,    -7,    -7,  -153,  -153,  -153,  -153,  -153,
    -153,    30,  -153,  -153,    -7,  -153,  -153,    53,    53,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   133,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,    67,    72,  -153,   110,
      52,    12,  -153,  -153,    17,    89,    53,   -15,    70,   -15,
      44,    53,  -153,  -153,  -153,  -153,     4,    45,    93,    97,
      53,  -153,  -153,  -153,  -153,    81,  -153,  -153,  -153,    53,
    -153,    53,  -153,  -153,  -153,  -153,  -153,  -153,    17,  -153,
    -153,    17,  -153,  -153,  -153,    17,   110,  -153,    51,   -15,
     -15,    73,   133,  -153,    50,   102,    57,    80,  -153,  -153,
      53,    53,    53,   112,    15,    53,   -10,    53,    63,    63,
    -153,    72,  -153,    52,    12,  -153,   -15,  -153,  -153,    78,
    -153,  -153,    53,  -153,  -153,  -153,  -153,   112,   121,  -153,
     116,  -153,  -153,  -153,  -153,  -153,  -153,   109,  -153,    76,
     109,  -153,   132,   131,   142,  -153,   144,    33,  -153,   150,
    -153,    53,  -153,   121,  -153,  -153,  -153,    53,   152,    53,
     -11,   151,    63,  -153,   142,  -153,   -15,  -153,   114,   -15,
     155,  -153,  -153,  -153,   156,  -153,   158,  -153,    15,  -153,
    -153,   127,  -153,   128,    53,   106,   164,   -15,   111,   114,
     -15,   123,   117,   145,  -153,  -153,   149,    15,   135,   120,
     147,  -153,    15,  -153,  -153,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     119,    81,    83,    84,    82,     0,   119,   119,     5,     6,
       7,     0,     0,     0,     0,     4,     1,    92,    80,    68,
      90,   119,   118,    89,     0,    86,    88,     0,     0,    26,
      28,   117,    91,   113,   114,   115,     2,   119,    18,    20,
      21,    22,    24,    32,    33,    19,    46,    47,    49,    51,
      53,    55,    57,    59,     0,     0,     0,   119,   119,   119,
      61,     0,    62,   116,    17,     3,     0,     0,     0,     0,
       0,    29,    36,    35,    25,    61,    27,    16,    66,     0,
      67,     0,    69,    70,    71,    72,    73,    74,     0,    76,
      75,     0,    77,    78,    79,     0,    52,    60,     0,   119,
     119,     0,   119,    45,     0,     0,     0,     0,    94,    85,
       0,   119,     0,     0,     0,     0,     0,     0,   119,   119,
      37,    48,    50,    54,    56,    58,   119,    44,    43,     0,
      42,    40,     0,    41,    34,    23,   107,     0,   119,   104,
       0,    93,    64,   112,   109,   110,   111,     0,     8,     0,
      12,    10,     0,     0,   119,    97,     0,     0,    38,     0,
      63,     0,   103,   119,   106,    95,    65,     0,     0,     0,
       0,     0,     0,    96,   119,    99,   119,    87,     0,   119,
       0,   108,   105,     9,     0,    11,     0,   100,     0,   102,
      98,     0,    31,     0,     0,     0,     0,   119,     0,     0,
     119,     0,     0,     0,    15,    30,     0,     0,     0,     0,
       0,    13,     0,    14,    39,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   182,  -153,    48,    74,  -153,   -29,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   -55,   -17,
     -26,  -153,   118,   115,   136,   103,   107,   104,   146,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
     -52,  -152,  -153,    71,    -8,  -153,    -1,   -14,    66,  -153,
    -153,    85,    31,    34,  -153,  -153,    46,  -153,  -153,  -113,
    -153,  -153,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    99,   100,    10,    36,    37,    38,
      39,    40,    41,    42,    71,    43,    44,   105,   101,   102,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    79,
      81,    54,    88,    91,    95,    55,    11,    12,    13,    14,
     110,    56,   179,    57,    58,    59,    75,    61,   142,   112,
     166,   153,   173,   154,   174,   137,   162,   138,   163,   147,
      62,    63,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    74,    76,   150,   107,    60,    64,    15,    77,   114,
      66,    67,    68,    69,   115,   117,     1,     1,   149,   143,
     143,    72,   109,    73,    17,     2,   192,    92,    93,    94,
      98,    18,     3,   144,   144,   113,    60,    64,   145,   145,
       4,     4,   146,   146,   120,   143,   111,   205,     8,   186,
     116,    17,    32,   108,    16,     8,    22,   187,   106,   144,
      17,   111,   109,   109,   145,    89,    90,    18,   146,   177,
     178,   157,    31,   130,     9,   197,    32,    33,    34,    35,
      19,     9,   127,   128,   135,   136,   140,    70,    17,   148,
     108,   151,    22,    78,   211,   167,    17,    80,   169,   215,
     118,    60,    64,   104,   119,   126,   159,   132,    31,   131,
     129,   139,    32,    33,    34,    35,   133,   134,   155,   155,
     141,   191,   152,    26,   193,   161,   165,   109,    22,    82,
      83,    84,    85,    86,    87,   181,   168,   170,   164,   171,
      17,   183,   203,   185,    31,   206,   172,    18,    32,    33,
      34,    35,   176,   180,   175,   184,   188,    25,   194,   195,
      19,   196,    20,   164,   198,   199,   201,   202,   200,   207,
     204,    21,    22,    23,   175,    24,    25,   208,    26,   213,
      27,   212,   209,    28,    29,    30,   210,    23,    31,    65,
      96,   123,    32,    33,    34,    35,   122,   121,   124,   125,
     158,    97,   214,   160,   156,   190,   189,     0,     0,   182
};

static const yytype_int16 yycheck[] =
{
       0,    27,    28,   116,    59,     6,     6,     7,    37,     5,
      11,    12,    13,    14,    66,    67,    32,    32,    28,    30,
      30,    21,    18,    24,     7,    41,   178,    15,    16,    17,
      56,    14,    48,    44,    44,    61,    37,    37,    49,    49,
      56,    56,    53,    53,    70,    30,    60,   199,     0,    60,
       5,     7,    59,     9,     0,     7,    39,   170,    58,    44,
       7,    75,    18,    18,    49,    13,    14,    14,    53,    36,
      37,   126,    55,   102,     0,   188,    59,    60,    61,    62,
      27,     7,    99,   100,   110,   111,   112,    57,     7,   115,
       9,   117,    39,    26,   207,   147,     7,    25,   150,   212,
       7,   102,   102,    33,     7,    54,   132,     5,    55,    59,
      37,   111,    59,    60,    61,    62,    59,    37,   118,   119,
       8,   176,    59,    45,   179,     4,    10,    18,    39,    19,
      20,    21,    22,    23,    24,   161,    60,     5,   138,     8,
       7,   167,   197,   169,    55,   200,     4,    14,    59,    60,
      61,    62,     8,     3,   154,     3,     5,    43,     3,     3,
      27,     3,    29,   163,    37,    37,    60,     3,   194,    46,
      59,    38,    39,    40,   174,    42,    43,    60,    45,    59,
      47,    46,    37,    50,    51,    52,    37,    40,    55,     7,
      54,    88,    59,    60,    61,    62,    81,    79,    91,    95,
     129,    55,   210,   137,   119,   174,   172,    -1,    -1,   163
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    41,    48,    56,    64,    65,    66,    67,    68,
      69,    99,   100,   101,   102,   125,     0,     7,    14,    27,
      29,    38,    39,    40,    42,    43,    45,    47,    50,    51,
      52,    55,    59,    60,    61,    62,    70,    71,    72,    73,
      74,    75,    76,    78,    79,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    94,    98,   104,   106,   107,   108,
     109,   110,   123,   124,   125,    65,   109,   109,   109,   109,
      57,    77,   125,   109,    83,   109,    83,    70,    26,    92,
      25,    93,    19,    20,    21,    22,    23,    24,    95,    13,
      14,    96,    15,    16,    17,    97,    87,    91,    83,    67,
      68,    81,    82,   125,    33,    80,   125,    81,     9,    18,
     103,   110,   112,    83,     5,   103,     5,   103,     7,     7,
      83,    85,    86,    88,    89,    90,    54,    82,    82,    37,
      70,    59,     5,    59,    37,    83,    83,   118,   120,   125,
      83,     8,   111,    30,    44,    49,    53,   122,    83,    28,
     122,    83,    59,   114,   116,   125,   114,    81,   106,    83,
     111,     4,   119,   121,   125,    10,   113,   103,    60,   103,
       5,     8,     4,   115,   117,   125,     8,    36,    37,   105,
       3,    83,   119,    83,     3,    83,    60,   122,     5,   116,
     115,    81,   104,    81,     3,     3,     3,   122,    37,    37,
      83,    60,     3,    81,    59,   104,    81,    46,    60,    37,
      37,   122,    46,    59,   107,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    67,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    76,    77,    77,    78,    79,
      80,    80,    81,    82,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    92,    93,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   114,   115,   115,
     116,   116,   117,   118,   118,   119,   119,   120,   121,   122,
     122,   122,   122,   123,   123,   123,   123,   124,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     4,     6,
       4,     6,     4,    10,    10,     8,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     1,     2,     1,     2,
       8,     6,     1,     1,     3,     2,     1,     2,     4,    10,
       2,     2,     2,     2,     2,     1,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     1,     4,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     8,     2,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
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
        case 8:
#line 81 "main.y" /* yacc.c:1646  */
    {
                        if(!is_already_exist)
                        {
                                if(is_exist)
                                {
                                        if(is_const)
                                        {
                                                if(type_incompatible)
                                                {
                                                        Trace("[warning] Type of assigning values is not match!\n");
                                                }
                                                else
                                                {
                                                        strcpy(insert_data.name, (yyvsp[-2].id_name));
                                                        insert_data.type = value_type;
                                                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                                                        insert_data.is_function = 0;
                                                        insert_data.is_argument = false;
                                                        insert(tail->current, insert_data);
                                                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                                                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                                                        strcpy(exp_data.exp, "");
                                                }
                                        }
                                        else
                                        {
                                                WARNING_NOT_CONST;
                                        }
                                }
                                else
                                {
                                        WARNING_ID_NOT_EXIST;
                                }
                        }
                        reset_exp();
                }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "main.y" /* yacc.c:1646  */
    {
                        if(is_exist)
                        {
                                if(is_const)
                                {
                                        if(type_incompatible)
                                        {
                                                Trace("[warning] Type of assigning values is not match!\n");
                                        }
                                        else
                                        {
                                                strcpy(insert_data.name, (yyvsp[-4].id_name));
                                                insert_data.type = ID_type;
                                                if(value_type != ID_type)
                                                {
                                                        Trace("[warning] Assign type is not match!\n");
                                                        strcpy(insert_data.exp_tab.exp, "");
                                                }
                                                else
                                                {
                                                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                                                        insert_data.is_function = 0;
                                                        insert_data.is_argument = false;
                                                        insert(tail->current, insert_data);
                                                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-4].id_name)));
                                                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                                                        strcpy(exp_data.exp, "");
                                                }
                                        }
                                }
                                else
                                {
                                        WARNING_NOT_CONST;
                                }
                        }
                        else
                        {
                                WARNING_ID_NOT_EXIST;
                        }
                        reset_exp();
                }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "main.y" /* yacc.c:1646  */
    {
                        if(is_exist)
                        {
                                if(is_const)
                                {
                                        if(type_incompatible)
                                        {
                                                Trace("[warning] Type of assigning values is not match!\n");
                                        }
                                        {
                                                strcpy(insert_data.name, (yyvsp[-2].id_name));
                                                insert_data.type = value_type;
                                                insert_data.is_function = 1;
                                                insert_data.is_argument = false;
                                                insert(tail->current, insert_data);
                                                tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                                                strcpy(exp_data.exp, "");
                                        }
                                }
                                else
                                {
                                        WARNING_NOT_CONST;
                                }
                        }
                        else
                        {
                                WARNING_ID_NOT_EXIST;
                        }
                        reset_exp();
                }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 193 "main.y" /* yacc.c:1646  */
    {
                        if(is_exist)
                        {
                                if(is_const)
                                {
                                        if(type_incompatible)
                                        {
                                                Trace("[warning] Type of assigning values is not match!\n");
                                        }
                                        else
                                        {
                                                if(value_type == ID_type)
                                                {
                                                        strcpy(insert_data.name, (yyvsp[-4].id_name));
                                                        insert_data.type = ID_type;
                                                        insert_data.is_function = 1;
                                                        insert_data.is_argument = false;
                                                        insert(tail->current, insert_data);
                                                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-4].id_name)));
                                                        strcpy(exp_data.exp, "");
                                                }
                                                else
                                                {
                                                        Trace("[warning] Assign type is not match!\n");
                                                }
                                        }
                                }
                                else
                                {
                                        WARNING_NOT_CONST;
                                }
                        }
                        else
                        {
                                WARNING_ID_NOT_EXIST;
                        }
                        reset_exp();
                }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 232 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-2].id_name));
                        insert_data.type = ID_type;
                        insert_data.is_function = 1;
                        insert_data.is_argument = false;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                        strcpy(exp_data.exp, "");
                        reset_exp();
                }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 245 "main.y" /* yacc.c:1646  */
    {
                        strcpy(insert_data.name, (yyvsp[-8].id_name));
                        insert_data.type = ID_type;
                        insert_data.array_start = atoi((yyvsp[-5].ival));
                        insert_data.array_end = atoi((yyvsp[-2].ival));
                        insert_data.is_function = 2;
                        insert_data.is_argument = false;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-8].id_name)));
                        strcpy(exp_data.exp, "");
                        reset_exp();
                }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 261 "main.y" /* yacc.c:1646  */
    {
                        if(!is_already_exist)
                        {
                        //printf("[TEST] %s %s\n", $2, $10);
                                if(check_name_the_same((yyvsp[-8].id_name), (yyvsp[0].id_name)))
                                {
                                        char temp_name[20];
                                        strcpy(temp_name, ": ");
                                        strcat(temp_name, (yyvsp[-8].id_name));
                                        dump(tail, "FUNCTION", temp_name);
                                        tail = head;
                                        //tail = delete_node(tail);

                                        strcpy(insert_data.name, (yyvsp[-8].id_name));
                                        insert_data.type = ID_type;
                                        insert_data.is_function = 3;
                                        insert_data.is_argument = false;

                                        insert(head->current, insert_data);
                                        head->max_name_length = max(head->max_name_length, strlen((yyvsp[-8].id_name)));
                                        strcpy(exp_data.exp, "");
                                }
                                else
                                {
                                        Trace("[WARNING] Inconsistent function ID before and after\n");
                                        tail = delete_node(tail);
                                }
                        }
                        reset_exp();
                }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 292 "main.y" /* yacc.c:1646  */
    {
                        if(!is_already_exist)
                        {
                                if(check_name_the_same((yyvsp[-6].id_name), (yyvsp[0].id_name)) && !is_already_exist)
                                {
                                        char temp_name[20];
                                        strcpy(temp_name, ": ");
                                        strcat(temp_name, (yyvsp[-6].id_name));
                                        dump(tail, "PROCEDURE", temp_name);
                                        tail = head;
                                        //tail = delete_node(tail);

                                        strcpy(insert_data.name, (yyvsp[-6].id_name));
                                        insert_data.type = 4;
                                        insert_data.is_function = 4;
                                        insert_data.is_argument = false;

                                        insert(head->current, insert_data);
                                        head->max_name_length = max(head->max_name_length, strlen((yyvsp[-6].id_name)));
                                        strcpy(exp_data.exp, "");
                                }
                                else
                                {
                                        Trace("[WARNING] Inconsistent procedure ID before and after\n");
                                        tail = delete_node(tail);
                                }
                        }
                        reset_exp();
                }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 335 "main.y" /* yacc.c:1646  */
    {
                        int tmp1 = lookup_all(tail, (yyvsp[-2].id_name));
                        if(tmp1 != -1)
                        {
                                int tmp2 = tmp1 % 10;
                                tmp1 /= 10;
                                tmp1 %= 10;
                                if(tmp2 == 1)
                                {
                                        if(!type_incompatible)
                                        {
                                                if(value_type != tmp1)
                                                {
                                                        Trace("[warning] Assign type is not match!\n");
                                                }
                                        }
                                        else
                                        {
                                                WARNING_TYPE_INCOMPATIBLE;
                                        }
                                }
                                else
                                {
                                        WARNING_CANNOT_ASSIGN;
                                }

                        }
                        else
                        {
                             WARNING_ID_NOT_EXIST;   
                        }
                        reset_exp();
                }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 369 "main.y" /* yacc.c:1646  */
    {
                        if(is_exist)
                        {
                                if(ID_call_type != 1)
                                {
                                        WARNING_CANNOT_GET;
                                }
                        }
                        else
                        {
                                WARNING_ID_NOT_EXIST;
                        }
                }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 390 "main.y" /* yacc.c:1646  */
    {
                        dump(tail, "ELSE", "");
                        tail = delete_node(tail);
                }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 395 "main.y" /* yacc.c:1646  */
    {
                        dump(tail, "IF", "");
                        tail = delete_node(tail);
                }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 402 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "LOOP", "");
                tail = delete_node(tail);
        }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 407 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "FOR", "");
                tail = delete_node(tail);
        }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 414 "main.y" /* yacc.c:1646  */
    {
                        dump(tail, "BLOCK", "");
                        tail = delete_node(tail);
                }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 434 "main.y" /* yacc.c:1646  */
    {
        }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 437 "main.y" /* yacc.c:1646  */
    {
        }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 484 "main.y" /* yacc.c:1646  */
    {
                if(!is_exist)
                {
                        WARNING_NOT_CONST;
                }
        }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " or ");
        }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 498 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " and ");
        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 503 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "not ");
        }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 508 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " < ");
        }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 512 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " <= ");
        }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 516 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " >= ");
        }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 520 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " > ");
        }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 524 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " = ");
        }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 528 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " not= ");
        }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 533 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " - ");
        }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 537 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " + ");
        }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 542 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " * ");
        }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 546 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " / ");
        }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 550 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, " mod ");
        }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 555 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "-");
        }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 560 "main.y" /* yacc.c:1646  */
    {
                is_declare = true;
        }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 565 "main.y" /* yacc.c:1646  */
    {
                is_declare = true;
        }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 570 "main.y" /* yacc.c:1646  */
    {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, true);
                        is_declare = true;
                }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 577 "main.y" /* yacc.c:1646  */
    {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, true);
                        is_declare = true;
                }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 584 "main.y" /* yacc.c:1646  */
    {
                reset_exp();
                is_declare = false;
                //printf("[ASSIGN!]\n");
        }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 591 "main.y" /* yacc.c:1646  */
    {
                if(create_table)
                {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, false);
                        create_table = false;
                }
                else
                {
                        create_table = true;
                }
        }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 605 "main.y" /* yacc.c:1646  */
    {
                dump(tail, "IF", "");
                tail = delete_node(tail);
                struct table *temp = creat();
                tail = insert_table(tail, temp, false);
        }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 613 "main.y" /* yacc.c:1646  */
    {
                if(create_table)
                {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, false);
                        create_table = false;
                }
                else
                {
                        create_table = true;
                }
        }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 627 "main.y" /* yacc.c:1646  */
    {
                if(create_table)
                {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, false);
                        create_table = false;
                }
                else
                {
                        create_table = true;
                }
        }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 641 "main.y" /* yacc.c:1646  */
    {
                struct table *temp = creat();
                tail = insert_table(tail, temp, false);
        }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 647 "main.y" /* yacc.c:1646  */
    {
                strcpy((yyval.id_name), (yyvsp[0].id_name));
                exp_push_back(&exp_data, (yyvsp[0].id_name));
                if(is_declare == true)
                {
                        lookup_return = lookup(tail->current, (yyvsp[0].id_name));
                        if(lookup_return != -1)
                        {
                                is_already_exist = true;
                                WARNING_ID_ALREADY_EXIST;
                        }
                }
                else
                {
                        lookup_return = lookup_all(tail, (yyvsp[0].id_name));
                        printf("%s: %d\n", (yyvsp[0].id_name), lookup_return);
                        if(lookup_return == -1 )
                        {
                                is_exist = false;
                        }
                        else
                        {
                                ID_call_type = lookup_return % 10;
                                lookup_return /= 10;
                                ID_value_type = lookup_return % 10;
                                if(ID_call_type != 0)
                                {
                                        is_const = false;
                                }
                                if(value_type == -1)
                                {
                                        value_type = ID_value_type;
                                }
                                else
                                {
                                        if(value_type != ID_value_type)
                                        {
                                                type_incompatible = true;
                                        }
                                }
                        }
                }
        }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 692 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "(");
                is_declare = false;
        }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 698 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, ")");
        }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 703 "main.y" /* yacc.c:1646  */
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
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 719 "main.y" /* yacc.c:1646  */
    {
                exp_push_back(&exp_data, "]");
        }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 732 "main.y" /* yacc.c:1646  */
    {
                strcpy(insert_data.name, (yyvsp[-2].id_name));
                insert_data.type = ID_type;
                insert_data.is_function = 1;
                insert_data.is_argument = true;

                insert(tail->current, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-2].id_name)));
                strcpy(exp_data.exp, "");
        }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 743 "main.y" /* yacc.c:1646  */
    {
                strcpy(insert_data.name, (yyvsp[-7].id_name));
                insert_data.type = ID_type;
                insert_data.array_start = atoi((yyvsp[-5].ival));
                insert_data.array_end = atoi((yyvsp[-2].ival));
                insert_data.is_function = 2;
                insert_data.is_argument = true;

                insert(tail->current, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen((yyvsp[-7].id_name)));
                strcpy(exp_data.exp, "");
        }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 774 "main.y" /* yacc.c:1646  */
    {ID_type = 0;}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 775 "main.y" /* yacc.c:1646  */
    {ID_type = 1;}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 776 "main.y" /* yacc.c:1646  */
    {ID_type = 2;}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 777 "main.y" /* yacc.c:1646  */
    {ID_type = 3;}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 780 "main.y" /* yacc.c:1646  */
    {exp_push_back(&exp_data, yylval.ival);
                if(value_type == -1)
                {
                        value_type = 0;
                }
                else
                {
                        if(value_type != 0)
                        {
                                type_incompatible = true;
                        }
                }
        }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 793 "main.y" /* yacc.c:1646  */
    {exp_push_back(&exp_data, yylval.dval);
                if(value_type == -1)
                {
                        value_type = 1;
                }
                else
                {
                        if(value_type != 1)
                        {
                                type_incompatible = true;
                        }
                }
        }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 806 "main.y" /* yacc.c:1646  */
    {exp_push_back(&exp_data, yylval.sval);
                if(value_type == -1)
                {
                        value_type = 2;
                }
                else
                {
                        if(value_type != 2)
                        {
                                type_incompatible = true;
                        }
                }
        }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 819 "main.y" /* yacc.c:1646  */
    {exp_push_back(&exp_data, yylval.bval);
                if(value_type == -1)
                {
                        value_type = 3;
                }
                else
                {
                        if(value_type != 3)
                        {
                                type_incompatible = true;
                        }
                }
        }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2383 "y.tab.c" /* yacc.c:1646  */
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
#line 842 "main.y" /* yacc.c:1906  */

yyerror(msg)    
char *msg;
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

main(){
        T = creat();
        head = creat_table_node();
        tail = creat_table_node();
        tail->current = T;
        tail->is_function = false;
        head = tail;
        yyparse();
        dump(head, "GLOBAL", "");
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
