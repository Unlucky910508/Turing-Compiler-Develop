#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define table_size 256

// Warning define
#define WARNING_ID_ALREADY_EXIST printf("[WARNING] The declaring ID already exist\n")
#define WARNING_ID_NOT_EXIST printf("[warning]The ID used isn't exist\n")
#define WARNING_NOT_CONST printf("[warning] Value of Assignment is not const\n")
#define WARNING_TYPE_INCOMPATIBLE printf("[warning] Type of assigning values is not match!\n")
#define WARNING_CANNOT_ASSIGN printf("[warning] This ID cannot be assign\n")
#define WARNING_CANNOT_GET printf("[warning] This ID cannot get value\n")
#define WARNNIG_NOT_FUNCTION printf("[warning] This ID is not a function name\n")

// store value
typedef union TYPE
{
    int integer_value;
    double float_value;
    char string_value[256];
    bool boolean_value;
} TYPE;

// expression
typedef struct exp_table
{
    char exp[256];
} exp_table;
struct exp_table *creat_exp_table();
void exp_push_back(struct exp_table *, char[]);
void exp_head_insert(struct exp_table *, char[]);
void exp_clear(struct exp_table *);
// expression

// symbol table
typedef struct table
{
    char name[256];
    // 0: int, 1: real, 2: string, 3: bool, 4: no type
    int type;
    TYPE my_type;
    int array_start;
    int array_end;
    // 0: const, 1: variable, 2: array, 3: function, 4: procedure
    int is_function;
    struct exp_table exp_tab;
    int counter;
} table;
// table use function
int insert(table *, table);
// return a sequence of number, first digit is value type, second one is assign type;
// first: 0:int, 1:float, 2:string, 3:bool, 4:no_type; second: 0:const, 1:var, 2:array, 3:func, 4:proce
// if number < 0, not exist
int lookup(table *, char[]);
table *creat();
// symbol table

// to link all symbol table
typedef struct table_node
{
    char name[256];
    // current table pointer
    struct table *current;
    // only function use this, store argument
    struct table *function_argument;
    // next node pointer
    struct table_node *next;
    // parent node pointer
    struct table_node *parent;
    // next function pointer
    struct table_node *next_function;
    char table_name[256];
    int max_name_length;
    int max_value_length;
} table_node;
table_node *creat_table_node();
table_node *insert_table(struct table_node *);
table_node *insert_function_table(struct table_node *);
table_node *delete_node(struct table_node *);
// return a sequence of number, first digit is value type, second one is assign type;
// first: 0:int, 1:float, 2:string, 3:bool, 4:no_type; second: 0:const, 1:var, 2:array, 3:func, 4:proce
// if number < 0, not exist
int lookup_all(table_node *, char[]);
char *getValue(table_node *, char[]);
int getCounter(table_node *, char[]);
bool getGlobal(table_node *, table_node *, char[]);
table *getfunction();
// return index of function name
table *find_function(table_node *, char[]);
void dump(table_node *, char[], char[]);
void dump_argument(table_node *, char[], char[]);
void dump_all_table(table_node *);
// table node

// help function
bool check_name_the_same(char[], char[]);
int max(int, int);
