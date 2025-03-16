/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 63 "main.y" /* yacc.c:1909  */

    char ival[256];
    char dval[256];
    char sval[256];
    char bval[256];
    char id_name[256];

#line 186 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
