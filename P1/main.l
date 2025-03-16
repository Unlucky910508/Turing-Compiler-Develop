%{
    #include <stdio.h>
    #include <string.h>

    #define append              strcat(buf, yytext) 
    #define token(t)            {append; printf("<%s>\n",t);}
    #define tokenID(t,i)        {append; printf("<%s:%s>\n", t, i);}
    #define tokenInteger(t,i)   {append; printf("<%s:%d>\n", t, i);}
    #define tokenFloat(t,f)     {append; printf("<%s:%f>\n", t, f);}
    #define tokenString(t,s)    {append; printf("<%s:%s>\n", t, s);}
    #define printLine           printf("%d: %s\n", countLine++, buf)

    typedef struct sTable
    {
        char name[256];
        int line;
    }sTable;

    sTable T1[256];
    int MAXSIZE = 256;
    int countLine = 1;
    char s[256];
    char buf[256];

    void dump(struct sTable* self)
    {
        for(int i = 0; i < MAXSIZE; ++i)
        {
            if(self[i].name[0] != '\0')
            {
                printf("%d: %s\tlocate in %d\tline\n", i, self[i].name, self[i].line);
            }
        }
    }
    int lookup(struct sTable* self, char _s[]){
        for(int i = 0; i < MAXSIZE; ++i)
        {
            int find = 1;
            if(strlen(_s) == strlen(self[i].name))
            {
                for(int j = 0; j < strlen(_s); ++j)
                {
                    if(self[i].name[j] != _s[j])
                    {
                        find = 0;
                        break;
                    }
                }
            }
            else 
            {
                find = 0;
            }
            if(find == 1)
            {
                return i;
            }
        }
        return -1; // what is nil
    }
    int insert(struct sTable* self, char _i[], int _l)
    {
        if(lookup(self, _i) == -1)
        {
            for(int i = 0; i < MAXSIZE; ++i)
            {
                if(self[i].name[0] == '\0')
                {
                    strcpy(self[i].name, _i);
                    self[i].line = _l;
                    return i;
                }
            }
        }
    }
    sTable* creat(){
        struct sTable* temp = malloc(MAXSIZE * sizeof(sTable));
        for(int i = 0; i < MAXSIZE; ++i)
        {
            temp[i].name[0] = '\0';
            temp[i].line = 0;
        }
        return temp;
    }
%}

digits  [0-9]
letters [a-zA-Z]
LetDig  [a-zA-Z0-9]


%X multiCommentState
%X stringState

%%
"."             {token(".");}      
","             {token(",");}
":"             {token(":");}
";"             {token(";");}
"("             {token("(");}
")"             {token(")");}
"["             {token("[");}
"]"             {token("]");}
"{"             {token("{");}
"}"             {token("}");}

"+"             {token("+");}
"-"             {token("-");}
"*"             {token("*");}
"/"             {token("/");}
"mod"           {token("mod");}
":="            {token(":=");}
"<"             {token("<");}
"<="            {token("<=");}
">="            {token("<=");}
">"             {token(">");}
"="             {token("=");}
"not="          {token("not=");}
"and"           {token("and");}
"or"            {token("or");}
"not"           {token("not");}

"array"         {token("ARRAY");}
"begin"         {token("BEGIN");}
"bool"          {token("BOOL");}
"char"          {token("CHAR");}
"const"         {token("CONST");}
"decreasing"    {token("DECREASING");}
"default"       {token("DEFAULT");}
"do"            {token("DO");}
"else"          {token("ELSE");}
"end"           {token("END");}
"exit"          {token("EXIT");}
"false"         {token("FALSE")}
"for"           {token("FOR");}
"function"      {token("FUNCTION");}
"get"           {token("GET");}
"if"            {token("IF");}
"int"           {token("INT");}
"loop"          {token("LOOP");}
"of"            {token("OF");}
"put"           {token("PUT");}
"procedure"     {token("PROCEDURE");}
"real"          {token("REAL");}
"result"        {token("RESULT");}
"return"        {token("RETURN");}
"skip"          {token("SKIP");}
"string"        {token("STRING");}
"then"          {token("THEN");}
"true"          {token("TRUE");}
"var"           {token("VAR");}
"when"          {token("WHEN");}

{letters}{LetDig}*      {tokenID("ID", yytext); insert(T1, yytext, countLine);}
{digits}+"."{digits}+   {tokenFloat("Float", atof(yytext))}
{digits}*               {tokenInteger("Integer", atoi(yytext))}

\n      {printLine; buf[0] = '\0';}
" "     {append;}

"\""                {append; strcpy(s, ""); BEGIN stringState;}
<stringState>[^"]   {append; strcat(s, yytext);}
<stringState>["]["] {append; strcat(s, "\"");} 
<stringState>["]    {append; printf("<string:%s>\n", s); BEGIN INITIAL;}

[%].*   {append;}
"{%"                    {append; BEGIN multiCommentState;}
<multiCommentState>.    {append; }
<multiCommentState>\n   {printLine; buf[0] = '\0';}
<multiCommentState>"%}" {append; BEGIN INITIAL;}
[ \t]*  {append;}



%%
int yywrap(){return 1;
}
int main()
{
    yylex();
    printLine; buf[0] = '\0';
    printf("\nSymbol Table:\n");
    dump(T1);
    return 0;
}