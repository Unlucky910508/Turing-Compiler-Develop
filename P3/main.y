%{
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
program:        Declarations
                {
                        fprintf(file, "method public static void main(java.lang.String[])\n");
                        fprintf(file, "max_stack 15\n");
                        fprintf(file, "max_locals 15\n{\n");
                        is_global = false;
                } Statements 
                {
                        fprintf(file, "return\n}\n}\n");
                }

Declarations:   Declaration Declarations
            |   Eplision
            ;

Declaration:    const_declaration
            |   var_declaration
            |   funtion_declaration
            ;
               

const_declaration:      const_token ID assign_token exp 
                {
                        strcpy(insert_data.name, $2);
                        insert_data.type = value_type;
                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                        insert_data.is_function = 0;
                        insert_data.counter = -1;
                        
                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                        strcpy(exp_data.exp, "");
                        is_assign = false;

                }
                |       const_token ID COLON Type assign_token exp   
                {
                        strcpy(insert_data.name, $2);
                        insert_data.type = ID_type;
                        strcpy(insert_data.exp_tab.exp, exp_data.exp);
                        insert_data.is_function = 0;
                        insert_data.counter = -1;

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        tail->max_value_length = max(tail->max_value_length, strlen(exp_data.exp));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
                ;

var_declaration:        var_token ID assign_token exp
                {
                        strcpy(insert_data.name, $2);
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
                                fprintf(file, "%s = %s\n", $2, exp_data.exp);
                                insert_data.counter = -1;
                        }
                        else
                        {
                                insert_data.counter = next_counter;
                                fprintf(file, "istore %d\n", next_counter);
                                next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
                |       var_token ID COLON Type assign_token exp
                {
                        strcpy(insert_data.name, $2);
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
                                fprintf(file, "%s = %s\n", $2, exp_data.exp);
                                insert_data.counter = -1;
                        }
                        else
                        {
                                insert_data.counter = next_counter;
                                fprintf(file, "istore %d\n", next_counter);
                                next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                        is_assign = false;
                }
                |       var_token ID COLON Type
                {
                        strcpy(insert_data.name, $2);
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
                                fprintf(file, "%s\n", $2);
                        }
                        else
                        {
                                insert_data.counter = next_counter++;
                        }

                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                }
                |       var_token ID COLON ARRAY INTEGER PERIOD PERIOD INTEGER OF Type
                {
                        strcpy(insert_data.name, $2);
                        insert_data.type = ID_type;
                        insert_data.array_start = atoi($5);
                        insert_data.array_end = atoi($8);
                        insert_data.is_function = 2;
                        
                        insert(tail->current, insert_data);
                        tail->max_name_length = max(tail->max_name_length, strlen($2));
                        strcpy(exp_data.exp, "");
                }
                ;
                        // check wether result
funtion_declaration:    function_token ID LP Arguments_token RP COLON Type 
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
                        fprintf(file, "%s(", $2);
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
                }no_function_programs END ID
                {
                        if(check_name_the_same($2, $11))
                        {
                                fprintf(file, "}\n");
                                char temp_name[20];
                                strcpy(temp_name, ": ");
                                strcat(temp_name, $2);
                                dump_argument(tail, "FUNCTION", temp_name);
                                dump(tail, "FUNCTION", temp_name);
                                tail = head;
                                //tail = delete_node(tail);
                                strcpy(insert_data.name, $2);
                                insert_data.type = ID_type;
                                insert_data.is_function = 3;
                                insert_data.counter = -1;

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
                |       procedure_token ID LP Arguments RP 
                {
                        fprintf(file, "method public static void ");
                        fprintf(file, "%s(", $2);
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
                }no_function_programs END ID
                {
                        if(check_name_the_same($2, $9) && !is_already_exist)
                        {
                                fprintf(file, "}\n");
                                char temp_name[20];
                                strcpy(temp_name, ": ");
                                strcat(temp_name, $2);
                                dump_argument(tail, "PROCEDURE", temp_name);
                                dump(tail, "PROCEDURE", temp_name);
                                tail = head;
                                //tail = delete_node(tail);
                                strcpy(insert_data.name, $2);
                                insert_data.type = 4;
                                insert_data.is_function = 4;
                                insert_data.counter = -1;

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

simple_statement:       ID assign_token exp
                {
                        if(getGlobal(head, tail, $1))
                        {
                                int type = lookup_all(tail, $1);
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
                                fprintf(file, "%s.%s\n", fileName, $1);
                        }
                        else
                        {
                                fprintf(file, "istore %d\n", getCounter(tail, $1));
                        }
                        is_assign = false;
                }
                |       get_statement
                |       PUT
                {
                        is_put = true;
                        fprintf(file, "getstatic java.io.PrintStream java.lang.System.out\n");

                } exp     
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
                |       RETURN
                |       RESULT exp
                {
                        fprintf(file, "ireturn\n");
                }
                |       SKIP
                {
                        fprintf(file, "getstatic java.io.PrintStream java.lang.System.out\n");
                        fprintf(file, "invokevirtual void java.io.PrintStream.println()\n");
                }
                |       EXIT exit_statement
                {
                        fprintf(file, "iconst_0\n");
                        fprintf(file, "goto L%d\n", gotoCounter + 2);
                        fprintf(file, "L%d:\n", gotoCounter + 1);
                        fprintf(file, "iconst_1\n");
                        fprintf(file, "L%d:\n", gotoCounter + 2);
                        fprintf(file, "ifne L%d\n", gotoCounter + 3);
                }
                |       EXIT
                ;

conditional_statement:  if_token exp THEN 
                {
                        fprintf(file, "goto L%d\n", gotoCounter + 2);
                        fprintf(file, "L%d:\n", gotoCounter + 1);
                }no_function_programs 
                {
                        {
                                fprintf(file, "goto L%d\n", gotoCounter+3);
                                fprintf(file, "L%d:\n", gotoCounter + 2);
                                fprintf(file, "iconst_0\n");
                                fprintf(file, "ifne L%d\n", gotoCounter+3);
                        }
                }if_Statement END if_token
                {
                        dump(tail, "ELSE", "");
                        tail = delete_node(tail);

                        fprintf(file, "L%d:\n", gotoCounter + 3);
                }
                /*
                |       if_Statement no_function_programs END if_token
                {
                        dump(tail, "IF", "");
                        tail = delete_node(tail);
                }
                */
                ;
        
if_Statement:   else_token no_function_program
        |       

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

block_statement:        begin_token no_function_programs END
                {
                        dump(tail, "BLOCK", "");
                        tail = delete_node(tail);
                }
                ;

get_statement:  GET ID_token

exit_statement: Eplision
            |   WHEN exp
            ;

loop_loop:  loop_token no_function_programs END LOOP
        {
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
        }
        ;

for_loop:       for_token ID COLON exp 
        {
                if(getGlobal(head, tail, $2))
                {
                        int type = lookup_all(tail, $2);
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
                        fprintf(file, "%s.%s\n", fileName, $2);
                }
                else
                {
                        fprintf(file, "istore%d\n", getCounter(tail, $2));
                }

                fprintf(file, "L%d:\n", gotoCounter);

                if(getGlobal(head, tail, $2))
                {
                        int type = lookup_all(tail, $2);
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
                        fprintf(file, "%s.%s\n", fileName, $2);
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, $2));
                }
        }PERIOD PERIOD exp 
        {
                fprintf(file, "isub\n");
                fprintf(file, "ifgt L%d\n", gotoCounter + 1);
                fprintf(file, "iconst_0\n");
                fprintf(file, "goto L%d\n", gotoCounter + 2);
                fprintf(file, "L%d:\n", gotoCounter + 1);
                fprintf(file, "iconst_1\n");
                fprintf(file, "L%d:\n", gotoCounter + 2);
                fprintf(file, "ifne L%d\n", gotoCounter + 3);
        }no_function_programs END for_token
        {
                if(getGlobal(head, tail, $2))
                {
                        int type = lookup_all(tail, $2);
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
                        fprintf(file, "%s.%s\n", fileName, $2);
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
                        fprintf(file, "%s.%s\n", fileName, $2);
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, $2));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "iadd\n");
                        fprintf(file, "istore%d\n", getCounter(tail, $2));
                }
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
                gotoCounter += 6;
        }
        |       for_token DECREASING ID COLON exp 
        {
                if(getGlobal(head, tail, $3))
                {
                        int type = lookup_all(tail, $3);
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
                        fprintf(file, "%s.%s\n", fileName, $3);
                }
                else
                {
                        fprintf(file, "istore%d\n", getCounter(tail, $3));
                }

                fprintf(file, "L%d:\n", gotoCounter);

                if(getGlobal(head, tail, $3))
                {
                        int type = lookup_all(tail, $3);
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
                        fprintf(file, "%s.%s\n", fileName, $3);
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, $3));
                }
        }PERIOD PERIOD exp 
        {
                fprintf(file, "isub\n");
                fprintf(file, "iflt L%d\n", gotoCounter + 1);
                fprintf(file, "iconst_0\n");
                fprintf(file, "goto L%d\n", gotoCounter + 2);
                fprintf(file, "L%d:\n", gotoCounter + 1);
                fprintf(file, "iconst_1\n");
                fprintf(file, "L%d:\n", gotoCounter + 2);
                fprintf(file, "ifne L%d\n", gotoCounter + 3);
        }no_function_programs END for_token
        {
                if(getGlobal(head, tail, $3))
                {
                        int type = lookup_all(tail, $3);
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
                        fprintf(file, "%s.%s\n", fileName, $3);
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
                        fprintf(file, "%s.%s\n", fileName, $3);
                }
                else
                {
                        fprintf(file, "iload%d\n", getCounter(tail, $3));
                        fprintf(file, "sipush 1\n");
                        fprintf(file, "isub\n");
                        fprintf(file, "istore%d\n", getCounter(tail, $3));
                }
                fprintf(file, "goto L%d\n", gotoCounter);
                fprintf(file, "L%d:\n", gotoCounter + 3);
                gotoCounter += 6;
        }
        ;

no_function_programs:   no_function_program no_function_programs
                |       Eplision    

no_function_program:    var_declaration
                |       const_declaration
                |       Statement;

exp:    or_exp
    ;

or_exp:         and_exp
        |       or_exp OR and_exp
        {
                exp_push_back(&exp_data, " or ");
                fprintf(file, "ior\n");
        }
    ;

and_exp:        not_exp
        |       and_exp AND not_exp
        {
                exp_push_back(&exp_data, " and ");
                fprintf(file, "iand\n");
        }
        ;

not_exp:    compare_exp
        |   NOT compare_exp
        {
                exp_push_back(&exp_data, "not ");
                fprintf(file, "ixor\n");
        }
        ;

compare_exp:    add_exp
        |       compare_exp LT add_exp
        {
                exp_push_back(&exp_data, " < ");

                fprintf(file, "isub\n");
                fprintf(file, "iflt L%d\n", gotoCounter + 1);
        }
        |       compare_exp NMT add_exp
        {
                exp_push_back(&exp_data, " <= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifle L%d\n", gotoCounter + 1);
        }
        |       compare_exp NLT add_exp
        {
                exp_push_back(&exp_data, " >= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifge L%d\n", gotoCounter + 1);
        }
        |       compare_exp MT add_exp
        {
                exp_push_back(&exp_data, " > ");

                fprintf(file, "isub\n");
                fprintf(file, "ifgt L%d\n", gotoCounter + 1);
        }
        |       compare_exp EQUAL add_exp
        {
                exp_push_back(&exp_data, " = ");

                fprintf(file, "isub\n");
                fprintf(file, "ifeq L%d\n", gotoCounter + 1);
        }
        |       compare_exp NEQUAL add_exp
        {
                exp_push_back(&exp_data, " not= ");

                fprintf(file, "isub\n");
                fprintf(file, "ifne L%d\n", gotoCounter + 1);
        }
        ;

add_exp:    multi_exp
        |   add_exp MINUS multi_exp
        {
                exp_push_back(&exp_data, " - ");
                fprintf(file, "isub\n");
        }
        |   add_exp PLUS multi_exp
        {
                exp_push_back(&exp_data, " + ");
                fprintf(file, "iadd\n");
        }
        ;

multi_exp:  unary_exp
        |   multi_exp MULTIPLY unary_exp
        {
                exp_push_back(&exp_data, " * ");
                fprintf(file, "imul\n");
        }
        |   multi_exp DIVISION unary_exp
        {
                exp_push_back(&exp_data, " / ");
                fprintf(file, "idiv\n");
        }
        |   multi_exp MOD unary_exp
        {
                exp_push_back(&exp_data, " mod ");
                fprintf(file, "imod\n");
        }
        ;

unary_exp:  all_value
        |   unary_op all_value %prec UMINUS
        {
                fprintf(file, "ineg\n");
        }
        ;

all_value:  ID_token
        |   const_value
        |   ID LP_token input_Arguments RP_token
        {
                fprintf(file, "invokestatic "); 
                lookup_return = lookup_all(head, $1);
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
                fprintf(file, "%s.%s(", fileName, $1);
                struct table* temp= creat();
                temp = find_function(head, $1);
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
        |   LP_token exp RP_token
        |   ID_token LB_token exp RB_token
        {
                if(!is_exist)
                {
                        WARNING_NOT_CONST;
                }
        };


unary_op:       MINUS
        {
                exp_push_back(&exp_data, "-");
        }

const_token:    CONST
        {
                is_declare = true;
                is_assign = false;
        }

var_token:      VAR
        {
                is_declare = true;
                is_assign = false;
        }

function_token:     FUNCTION
                {
                        is_declare = true;
                        tail = insert_function_table(tail);
                }
        
procedure_token:    PROCEDURE
                {
                        is_declare = true;
                        tail = insert_function_table(tail);
                }

assign_token:   ASSIGN
        {
                is_declare = false;
                is_assign = true;
                strcpy(exp_data.exp, "");
                //reset_exp();
        }

if_token:       IF
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

else_token:     ELSE
        {
                dump(tail, "IF", "");
                tail = delete_node(tail);
                struct table *temp = creat();
                tail = insert_table(tail);

                //fprintf(file, "goto L%d\n", gotoCounter+3);
                //fprintf(file, "L%d:\n", gotoCounter + 2);

        }

loop_token:     LOOP
        {
                struct table *temp = creat();
                tail = insert_table(tail);

                fprintf(file, "L%d:\n", gotoCounter);
        }

for_token:      FOR
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

begin_token:    BBEGIN
        {
                struct table *temp = creat();
                tail = insert_table(tail);
        }

ID_token:       ID
        {
                lookup_return = lookup_all(tail, $1);
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
                                fprintf(file, "sipush %s\n", getValue(tail, $1));
                                break;
                        case 2:
                                fprintf(file, "ldc \"%s\"\n", getValue(tail, $1));
                                break;
                        case 3:
                        if(strcmp(getValue(tail, $1), "true") == 0)
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
                        if(getGlobal(head, tail, $1))
                        {
                                int type = lookup_all(tail, $1);
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
                                fprintf(file, "%s.%s\n", fileName, $1);
                        }
                        else
                        {
                                fprintf(file, "iload %d\n", getCounter(tail, $1));
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

Arguments_token:        Arguments

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
                insert_data.counter = next_counter;
                next_counter++;

                insert(tail->function_argument, insert_data);
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
                insert_data.counter = next_counter++;

                insert(tail->function_argument, insert_data);
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

const_value:    INTEGER 
        {       
                value_type = 0;
                exp_push_back(&exp_data, yylval.ival);
                if(head != tail || !is_global)
                {
                        fprintf(file, "sipush %s\n", yylval.ival);
                }
        }
        |       FLOAT   
        {
                value_type = 1;
                exp_push_back(&exp_data, yylval.dval);
                if(head != tail|| !is_global)
                {
                        fprintf(file, "sipush %s\n", yylval.ival);
                }
        }
        |       SSTRING 
        {
                value_type = 2;
                exp_push_back(&exp_data, yylval.sval);
                if(head != tail|| !is_global)
                {
                        fprintf(file, "ldc \"%s\"\n", yylval.sval);
                }
        }
        |       booling 
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