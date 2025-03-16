%{
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

%}

/* tokens */
%token PERIOD COMMA COLON SEMICOLON LP RP LB RB LC RC PLUS
%token MINUS MULTIPLY DIVISION MOD ASSIGN LT NMT NLT MT 
%token EQUAL NEQUAL AND OR NOT ARRAY BBEGIN BOOL CHAR CONST
%token DECREASING DEFAULT DO ELSE END EXIT FFALSE FOR FUNCTION
%token GET IF INT LOOP OF PUT PROCEDURE REAL RESULT RETURN
%token SKIP STRING THEN TTRUE VAR WHEN

%left LT NMT NLT MT EQUAL NEQUAL
%left PLUS MINUS
%left MULTIPLY DIVISION MOD
%nonassoc UMINUS

%union{
    char ival[256];
    char dval[256];
    char sval[256];
    char bval[256];
    char id_name[256];
}

%token <id_name> ID
%token <ival> INTEGER
%token <dval> FLOAT
%token <sval> SSTRING
%type <bval> booling
%type <id_name> ID_token

%%
program:        Declarations Statements 

Declarations:   Declaration Declarations
            |   Eplision
            ;

Declaration:    const_declaration
            |   var_declaration
            |   funtion_declaration
            ;
               

const_declaration:      const_token ID_token assign_token exp 
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
                                                        strcpy(insert_data.name, $2);
                                                        insert_data.type = value_type;
                                                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                                                        insert_data.is_function = 0;
                                                        insert_data.is_argument = false;
                                                        insert(tail->current, insert_data);
                                                        tail->max_name_length = max(tail->max_name_length, strlen($2));
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
                |       const_token ID_token COLON Type assign_token exp   
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
                                                strcpy(insert_data.name, $2);
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
                                                        tail->max_name_length = max(tail->max_name_length, strlen($2));
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
                ;

var_declaration:        var_token ID_token assign_token exp
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
                                                strcpy(insert_data.name, $2);
                                                insert_data.type = value_type;
                                                insert_data.is_function = 1;
                                                insert_data.is_argument = false;
                                                insert(tail->current, insert_data);
                                                tail->max_name_length = max(tail->max_name_length, strlen($2));
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
                |       var_token ID_token COLON Type assign_token exp
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
                                                        strcpy(insert_data.name, $2);
                                                        insert_data.type = ID_type;
                                                        insert_data.is_function = 1;
                                                        insert_data.is_argument = false;
                                                        insert(tail->current, insert_data);
                                                        tail->max_name_length = max(tail->max_name_length, strlen($2));
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
                |       var_token ID_token COLON Type
                {
                        strcpy(insert_data.name, $2);
                        insert_data.type = ID_type;
                        insert_data.is_function = 1;
                        insert_data.is_argument = false;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                        reset_exp();
                }
                // check range    
                |       var_token ID_token COLON ARRAY INTEGER PERIOD PERIOD INTEGER OF Type
                {
                        strcpy(insert_data.name, $2);
                        insert_data.type = ID_type;
                        insert_data.array_start = atoi($5);
                        insert_data.array_end = atoi($8);
                        insert_data.is_function = 2;
                        insert_data.is_argument = false;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                        reset_exp();
                }
                ;
                        // check wether result
funtion_declaration:    function_token ID_token LP Arguments RP COLON Type no_function_program END ID
                {
                        if(!is_already_exist)
                        {
                        //printf("[TEST] %s %s\n", $2, $10);
                                if(check_name_the_same($2, $10))
                                {
                                        char temp_name[20];
                                        strcpy(temp_name, ": ");
                                        strcat(temp_name, $2);
                                        dump(tail, "FUNCTION", temp_name);
                                        tail = head;
                                        //tail = delete_node(tail);

                                        strcpy(insert_data.name, $2);
                                        insert_data.type = ID_type;
                                        insert_data.is_function = 3;
                                        insert_data.is_argument = false;

                                        insert(head->current, insert_data);
                                        head->max_name_length = max(head->max_name_length, strlen($2));
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
                |       procedure_token ID_token LP Arguments RP no_function_program END ID
                {
                        if(!is_already_exist)
                        {
                                if(check_name_the_same($2, $8) && !is_already_exist)
                                {
                                        char temp_name[20];
                                        strcpy(temp_name, ": ");
                                        strcat(temp_name, $2);
                                        dump(tail, "PROCEDURE", temp_name);
                                        tail = head;
                                        //tail = delete_node(tail);

                                        strcpy(insert_data.name, $2);
                                        insert_data.type = 4;
                                        insert_data.is_function = 4;
                                        insert_data.is_argument = false;

                                        insert(head->current, insert_data);
                                        head->max_name_length = max(head->max_name_length, strlen($2));
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
                ;

Statements: Statement Statements
        |   Eplision
        ;

Statement:  simple_statement
        |   exp
        |   conditional_statement
        |   loop_statement
        |   block_statement
        ;

simple_statement:       ID_token assign_token exp
                {
                        int tmp1 = lookup_all(tail, $1);
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
                |       get_statement
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
                |       PUT exp     
                |       RETURN
                |       RESULT exp
                |       SKIP
                |       EXIT exit_statement
                ;

conditional_statement:  if_token exp THEN no_function_program else_token no_function_program END if_token
                {
                        dump(tail, "ELSE", "");
                        tail = delete_node(tail);
                }
                |       if_token exp THEN no_function_program END if_token
                {
                        dump(tail, "IF", "");
                        tail = delete_node(tail);
                }
                ;

loop_statement: loop_loop
        {
                dump(tail, "LOOP", "");
                tail = delete_node(tail);
        }
        |       for_loop
        {
                dump(tail, "FOR", "");
                tail = delete_node(tail);
        }
        ;

block_statement:        begin_token no_function_program END
                {
                        dump(tail, "BLOCK", "");
                        tail = delete_node(tail);
                }
                ;

get_statement:  GET ID_token

exit_statement: Eplision
            |   WHEN exp
            ;

loop_loop:  loop_token no_function_program END loop_token
        ;

for_loop:       for_token for_statement COLON exp PERIOD PERIOD exp no_function_program END for_token
        ;


for_statement:  DECREASING ID   
        {
        }
        |       Eplision ID
        {
        }
        ;

no_function_program:    variableDeclarations Statements;

variableDeclarations:   var_declaration variableDeclarations
                |       const_declaration variableDeclarations
                |       Eplision
                ;

exp:    or_exp
    ;

or_exp: and_exp
    |   or_exp or_op and_exp
    ;

and_exp:    not_exp
        |   and_exp and_op not_exp
        ;

not_exp:    compare_exp
        |   not_op compare_exp
        ;

compare_exp:    add_exp
        |       compare_exp compare_op add_exp
        ;

add_exp:    multi_exp
        |   add_exp add_op multi_exp
        ;

multi_exp:  unary_exp
        |   multi_exp multi_op unary_exp
        ;

unary_exp:  all_value
        |   unary_op all_value %prec UMINUS
        ;

all_value:  ID_token
        |   const_value
        |   ID_token LP_token input_Arguments RP_token
        |   LP_token exp RP_token
        |   ID_token LB_token exp RB_token
        {
                if(!is_exist)
                {
                        WARNING_NOT_CONST;
                }
        }
        ;

or_op:          OR
        {
                exp_push_back(&exp_data, " or ");
        }

and_op:         AND
        {
                exp_push_back(&exp_data, " and ");
        }

not_op:         NOT
        {
                exp_push_back(&exp_data, "not ");
        }

compare_op:     LT 
        {
                exp_push_back(&exp_data, " < ");
        }
        |       NMT
        {
                exp_push_back(&exp_data, " <= ");
        }
        |       NLT
        {
                exp_push_back(&exp_data, " >= ");
        }
        |       MT 
        {
                exp_push_back(&exp_data, " > ");
        }
        |       EQUAL
        {
                exp_push_back(&exp_data, " = ");
        }
        |       NEQUAL
        {
                exp_push_back(&exp_data, " not= ");
        }

add_op:         MINUS
        {
                exp_push_back(&exp_data, " - ");
        }
        |       PLUS
        {
                exp_push_back(&exp_data, " + ");
        }

multi_op:       MULTIPLY
        {
                exp_push_back(&exp_data, " * ");
        }
        |       DIVISION
        {
                exp_push_back(&exp_data, " / ");
        }
        |       MOD
        {
                exp_push_back(&exp_data, " mod ");
        }

unary_op:       MINUS
        {
                exp_push_back(&exp_data, "-");
        }

const_token:    CONST
        {
                is_declare = true;
        }

var_token:      VAR
        {
                is_declare = true;
        }

function_token:     FUNCTION
                {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, true);
                        is_declare = true;
                }
        
procedure_token:    PROCEDURE
                {
                        struct table *temp = creat();
                        tail = insert_table(tail, temp, true);
                        is_declare = true;
                }

assign_token:   ASSIGN
        {
                reset_exp();
                is_declare = false;
                //printf("[ASSIGN!]\n");
        }

if_token:       IF
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

else_token:     ELSE
        {
                dump(tail, "IF", "");
                tail = delete_node(tail);
                struct table *temp = creat();
                tail = insert_table(tail, temp, false);
        }

loop_token:     LOOP
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

for_token:      FOR
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

begin_token:    BBEGIN
        {
                struct table *temp = creat();
                tail = insert_table(tail, temp, false);
        }

ID_token:       ID
        {
                strcpy($$, $1);
                exp_push_back(&exp_data, $1);
                if(is_declare == true)
                {
                        lookup_return = lookup(tail->current, $1);
                        if(lookup_return != -1)
                        {
                                is_already_exist = true;
                                WARNING_ID_ALREADY_EXIST;
                        }
                }
                else
                {
                        lookup_return = lookup_all(tail, $1);
                        printf("%s: %d\n", $1, lookup_return);
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

LP_token:       LP
        {
                exp_push_back(&exp_data, "(");
                is_declare = false;
        }

RP_token:       RP
        {
                exp_push_back(&exp_data, ")");
        }

LB_token:       LB
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

RB_token:       RB
        {
                exp_push_back(&exp_data, "]");
        }

Arguments:  F_Argument R_Arguments
        |   Eplision
        ;

R_Arguments:    R_Argument R_Arguments
        |       Eplision
        ;

F_Argument:     ID COLON Type
        {
                strcpy(insert_data.name, $1);
                insert_data.type = ID_type;
                insert_data.is_function = 1;
                insert_data.is_argument = true;

                insert(tail->current, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen($1));
                strcpy(exp_data.exp, "");
        }
        |       ID COLON INTEGER PERIOD PERIOD INTEGER OF Type
        {
                strcpy(insert_data.name, $1);
                insert_data.type = ID_type;
                insert_data.array_start = atoi($3);
                insert_data.array_end = atoi($6);
                insert_data.is_function = 2;
                insert_data.is_argument = true;

                insert(tail->current, insert_data);
                tail->max_name_length = max(tail->max_name_length, strlen($1));
                strcpy(exp_data.exp, "");
        }
        ;

R_Argument: COMMA F_Argument
;

input_Arguments:    F_input R_inputs
                |   Eplision
                ;

R_inputs:   R_input R_inputs
        |   Eplision
        ;

F_input:    exp
        ;

R_input:    COMMA exp
        ;

Type:   INT     {ID_type = 0;}
    |   REAL    {ID_type = 1;}
    |   STRING  {ID_type = 2;}
    |   BOOL    {ID_type = 3;}
    ;

const_value:    INTEGER {exp_push_back(&exp_data, yylval.ival);
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
        |       FLOAT   {exp_push_back(&exp_data, yylval.dval);
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
        |       SSTRING {exp_push_back(&exp_data, yylval.sval);
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
        |       booling {exp_push_back(&exp_data, yylval.bval);
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
        ;

booling:        TTRUE
        |       FFALSE
        ;

Eplision:   ;



%%
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