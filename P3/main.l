%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    #include "table.h"
    #include "y.tab.h"

    #define append              strcat(buf, yytext) 
    #define token(t)            {append; /*printf("<%s>\n","t");       */ return (t);}
    #define tokenID(t,i)        {append; /*printf("<%s:%s>\n", "t", i);*/ return (t);}
    #define tokenInteger(t,i)   {append; /*printf("<%s:%d>\n", "t", i);*/ return (t);}
    #define tokenFloat(t,f)     {append; /*printf("<%s:%f>\n", "t", f);*/ return (t);}
    #define tokenString(t,s)    {append; /*printf("<%s:%s>\n", "t", s);*/ return (t);}
    #define printLine           printf("%d: %s\n", countLine++, buf)

    int MAXSIZE = 256;
    int countLine = 1;
    char s[256];
    char buf[256];
%}

digits  [0-9]
letters [a-zA-Z]
LetDig  [a-zA-Z0-9]


%X multiCommentState
%X stringState

%%
"."             {token(PERIOD);}      
","             {token(COMMA);}
":"             {token(COLON);}
";"             {token(SEMICOLON);}
"("             {token(LP);}
")"             {token(RP);}
"["             {token(LB);}
"]"             {token(RB);}
"{"             {token(LC);}
"}"             {token(RC);}

"+"             {token(PLUS);}
"-"             {token(MINUS);}
"*"             {token(MULTIPLY);}
"/"             {token(DIVISION);}
"mod"           {token(MOD);}
":="            {token(ASSIGN);}
"<"             {token(LT);}
"<="            {token(NMT);}
">="            {token(NLT);}
">"             {token(MT);}
"="             {token(EQUAL);}
"not="          {token(NEQUAL);}
"and"           {token(AND);}
"or"            {token(OR);}
"not"           {token(NOT);}

"array"         {token(ARRAY);}
"begin"         {token(BBEGIN);}
"bool"          {token(BOOL);}
"char"          {token(CHAR);}
"const"         {token(CONST);}
"decreasing"    {token(DECREASING);}
"default"       {token(DEFAULT);}
"do"            {token(DO);}
"else"          {token(ELSE);}
"end"           {token(END);}
"exit"          {token(EXIT);}
"false"         {strcpy(yylval.bval, yytext); token(FFALSE)}
"for"           {token(FOR);}
"function"      {token(FUNCTION);}
"get"           {token(GET);}
"if"            {token(IF);}
"int"           {token(INT);}
"loop"          {token(LOOP);}
"of"            {token(OF);}
"put"           {token(PUT);}
"procedure"     {token(PROCEDURE);}
"real"          {token(REAL);}
"result"        {token(RESULT);}
"return"        {token(RETURN);}
"skip"          {token(SKIP);}
"string"        {token(STRING);}
"then"          {token(THEN);}
"true"          {strcpy(yylval.bval, yytext); token(TTRUE);}
"var"           {token(VAR);}
"when"          {token(WHEN);}

{letters}{LetDig}*      {strcpy(yylval.id_name, yytext); tokenID(ID, yytext);}
{digits}+"."{digits}+   {strcpy(yylval.dval, yytext); tokenFloat(FLOAT, 0.0);}
{digits}*               {strcpy(yylval.ival, yytext); tokenInteger(INTEGER, atoi(yytext));}

\n      {printLine; buf[0] = '\0';}
" "     {append;}

"\""                {append; strcpy(s, ""); BEGIN stringState;}
<stringState>[^"]   {append; strcat(s, yytext);}
<stringState>["]["] {append; strcat(s, "\"");} 
<stringState>["]    {BEGIN INITIAL; append; strcat(s, ""); strcpy(yylval.sval, s); return SSTRING;}

[%].*   {append;}
"{%"                    {append; BEGIN multiCommentState;}
<multiCommentState>.    {append; }
<multiCommentState>\n   {printLine; buf[0] = '\0';}
<multiCommentState>"%}" {append; BEGIN INITIAL;}

[ \t]*  {append;}



%%
int yywrap(){return 1;
}
/*
int main()
{
    yylex();
    printLine; buf[0] = '\0';
    printf("\nSymbol Table:\n");
    dump(T1);
    return 0;
}
*/