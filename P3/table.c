#include "table.h"

int insert(struct table *self, struct table _data)
{
    if (lookup(self, _data.name) == -1)
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (self[i].name[0] == '\0')
            {
                strcpy(self[i].name, _data.name);
                self[i].type = _data.type;
                // self[i].my_type = _data.my_type;
                strcpy(self[i].exp_tab.exp, _data.exp_tab.exp);
                self[i].array_start = _data.array_start;
                self[i].array_end = _data.array_end;
                self[i].is_function = _data.is_function;
                self[i].counter = _data.counter;
                /*if (self[i].counter == -1)
                {
                    printf("[TEST] X\n");
                }
                else
                {
                    printf("[TEST] %d\n", self[i].counter);
                }*/
                return i;
            }
        }
    }
}

int lookup(struct table *self, char _s[])
{
    int result = 0;
    for (int i = 0; i < table_size; ++i)
    {
        int find = 1;
        if (strlen(_s) == strlen(self[i].name))
        {
            for (int j = 0; j < strlen(_s); ++j)
            {
                if (self[i].name[j] != _s[j])
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
        if (find == 1)
        {
            result += self[i].type;
            result *= 10;
            result += self[i].is_function;
            return result;
        }
    }
    return -1;
}

int lookup_all(struct table_node *_all, char _s[])
{
    int result = 0;
    while (_all != NULL)
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (_all->function_argument[i].name[0] == '\0')
            {
                break;
            }
            int find = 1;
            if (strlen(_s) == strlen(_all->function_argument[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->function_argument[i].name[j] != _s[j])
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
            if (find == 1)
            {
                result += _all->function_argument[i].type;
                result *= 10;
                result += _all->function_argument[i].is_function;
                return result;
            }
        }
        for (int i = 0; i < table_size; ++i)
        {
            int find = 1;
            if (strlen(_s) == strlen(_all->current[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->current[i].name[j] != _s[j])
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
            if (find == 1)
            {
                result += _all->current[i].type;
                result *= 10;
                result += _all->current[i].is_function;
                return result;
            }
        }
        _all = _all->parent;
    }
    return -1;
}

char *getValue(struct table_node *_all, char _s[])
{
    int result = 0;
    while (_all != NULL)
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (_all->function_argument[i].name[0] == '\0')
            {
                break;
            }
            int find = 1;
            if (strlen(_s) == strlen(_all->function_argument[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->function_argument[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return _all->function_argument[i].exp_tab.exp;
            }
        }
        for (int i = 0; i < table_size; ++i)
        {
            int find = 1;
            if (strlen(_s) == strlen(_all->current[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->current[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return _all->current[i].exp_tab.exp;
            }
        }
        _all = _all->parent;
    }
}

int getCounter(struct table_node *_all, char _s[])
{
    while (_all != NULL)
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (_all->function_argument[i].name[0] == '\0')
            {
                break;
            }
            int find = 1;
            if (strlen(_s) == strlen(_all->function_argument[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->function_argument[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return _all->function_argument[i].counter;
            }
        }
        for (int i = 0; i < table_size; ++i)
        {
            int find = 1;
            if (strlen(_s) == strlen(_all->current[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (_all->current[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return _all->current[i].counter;
            }
        }
        _all = _all->parent;
    }
}

bool getGlobal(struct table_node *head, struct table_node *tail, char _s[])
{
    while (tail != NULL)
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (tail->function_argument[i].name[0] == '\0')
            {
                break;
            }
            int find = 1;
            if (strlen(_s) == strlen(tail->function_argument[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (tail->function_argument[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return false;
            }
        }
        for (int i = 0; i < table_size; ++i)
        {
            int find = 1;
            if (strlen(_s) == strlen(tail->current[i].name))
            {
                for (int j = 0; j < strlen(_s); ++j)
                {
                    if (tail->current[i].name[j] != _s[j])
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
            if (find == 1)
            {
                return head == tail ? true : false;
            }
        }
        tail = tail->parent;
    }
}

struct table *find_function(struct table_node *self, char _s[])
{
    int count = 0;
    for (int i = 0; i < table_size; ++i)
    {
        int find = 1;
        if (strlen(_s) == strlen(self->current[i].name))
        {
            if (self->current[i].is_function == 3)
            {
                count++;
            }
            for (int j = 0; j < strlen(_s); ++j)
            {
                if (self->current[i].name[j] != _s[j])
                {
                    find = 0;
                    break;
                }
            }
            if (find == 1)
            {
                break;
            }
        }
        else
        {
            find = 0;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        self = self->next_function;
    }
    return self->function_argument;
}

void dump(struct table_node *self, char token[], char table_name[])
{
    int count1 = self->max_value_length;
    int count2 = self->max_name_length;
    count1 /= 8;
    count2 /= 8;
    printf("\n%s%s symbol table:", token, table_name);
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("index\tname\t");
    for (int i = 0; i < count2; ++i)
    {
        printf("\t");
    }
    printf("type\tis_function\tvalue\t");
    for (int i = 0; i < count1; ++i)
    {
        printf("\t");
    }
    printf("start\tend\tcounter\n");
    for (int i = 0; i < table_size; ++i)
    {
        if (self->current[i].name[0] != '\0')
        {
            printf("%d:\t%s\t", i, self->current[i].name);
            for (int j = 0; j < count2 - ((strlen(self->current[i].name)) / 8); ++j)
            {
                printf("\t");
            }
            switch (self->current[i].type)
            {
            case 0:
                printf("int\t");
                break;
            case 1:
                printf("real\t");
                break;
            case 2:
                printf("string\t");
                break;
            case 3:
                printf("bool\t");
                break;
            case 4:
                printf("X\t");
            default:
                break;
            }

            switch (self->current[i].is_function)
            {
            case 0:
                printf("%s\t", "constant");
                printf("%s\t", self->current[i].exp_tab.exp);
                for (int j = 0; j < count1 - ((strlen(self->current[i].exp_tab.exp)) / 8); ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            case 1:
                printf("%s\t", "variable");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            case 2:
                printf("%s\t\t", "array");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("%d\t%d\t", self->current[i].array_start, self->current[i].array_end);
                break;
            case 3:
            case 4:
                printf("%s\t", self->current[i].is_function == 3 ? "function" : "procedure");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            default:
                break;
            }
            if (self->current[i].counter == -1)
            {
                printf("X\n");
            }
            else
            {
                printf("%d\n", self->current[i].counter);
            }
        }
        else
        {
            break;
        }
    }
    printf("---------------------------------------------------------------------------------------------\n\n");
}

void dump_all_table(struct table_node *self)
{
    printf("ALL table:----------------------------------------------------------------------------\n");
    while (self != NULL)
    {
        dump(self, "", "");
        self = self->next;
    }
}

void dump_argument(struct table_node *self, char token[], char table_name[])
{
    int count1 = self->max_value_length;
    int count2 = self->max_name_length;
    count1 /= 8;
    count2 /= 8;
    printf("\n%s%s argument's symbol table:", token, table_name);
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("index\tname\t");
    for (int i = 0; i < count2; ++i)
    {
        printf("\t");
    }
    printf("type\tis_function\tvalue\t");
    for (int i = 0; i < count1; ++i)
    {
        printf("\t");
    }
    printf("start\tend\tcounter\n");
    for (int i = 0; i < table_size; ++i)
    {
        if (self->function_argument[i].name[0] != '\0')
        {
            printf("%d:\t%s\t", i, self->function_argument[i].name);
            for (int j = 0; j < count2 - ((strlen(self->function_argument[i].name)) / 8); ++j)
            {
                printf("\t");
            }
            switch (self->function_argument[i].type)
            {
            case 0:
                printf("int\t");
                break;
            case 1:
                printf("real\t");
                break;
            case 2:
                printf("string\t");
                break;
            case 3:
                printf("bool\t");
                break;
            case 4:
                printf("X\t");
            default:
                break;
            }

            switch (self->function_argument[i].is_function)
            {
            case 0:
                printf("%s\t", "constant");
                printf("%s\t", self->function_argument[i].exp_tab.exp);
                for (int j = 0; j < count1 - ((strlen(self->function_argument[i].exp_tab.exp)) / 8); ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            case 1:
                printf("%s\t", "variable");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            case 2:
                printf("%s\t\t", "array");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("%d\t%d\t", self->function_argument[i].array_start, self->function_argument[i].array_end);
                break;
            case 3:
            case 4:
                printf("%s\t", self->function_argument[i].is_function == 3 ? "function" : "procedure");
                printf("X\t");
                for (int j = 0; j < count1 - 0; ++j)
                {
                    printf("\t");
                }
                printf("X\tX\t");
                break;
            default:
                break;
            }
            if (self->function_argument[i].counter == -1)
            {
                printf("X\n");
            }
            else
            {
                printf("%d\n", self->function_argument[i].counter);
            }
        }
        else
        {
            break;
        }
    }
    printf("---------------------------------------------------------------------------------------------\n\n");
}

struct table *creat()
{
    struct table *temp = (table *)malloc(table_size * sizeof(table));
    for (int i = 0; i < table_size; ++i)
    {
        temp[i].name[0] = '\0';
        temp[i].type = 4;
        temp[i].array_start = 0;
        temp[i].array_end = 0;
        temp[i].is_function = 0;
        temp[i].counter = -1;
    }
    return temp;
}

struct table_node *creat_table_node()
{
    struct table_node *temp = (struct table_node *)malloc(sizeof(struct table_node));
    temp->current = creat();
    temp->function_argument = creat();
    temp->max_value_length = 0;
    temp->max_name_length = 0;
    temp->next = NULL;
    temp->parent = NULL;
    temp->next_function = NULL;
    return temp;
}

struct table_node *insert_table(struct table_node *_tail)
{
    // current value
    struct table_node *mama = _tail;
    while (mama->next != NULL)
    {
        mama = mama->next;
    }
    struct table_node *next_node = creat_table_node();
    next_node->next = NULL;
    next_node->next_function = NULL;
    next_node->parent = mama;
    mama->next = next_node;
    return next_node;
}

struct table_node *insert_function_table(struct table_node *_tail)
{
    // current value
    struct table_node *mama = _tail;
    while (mama->next != NULL)
    {
        mama = mama->next_function;
    }
    struct table_node *next_node = creat_table_node();
    next_node->next = NULL;
    next_node->next_function = NULL;
    next_node->parent = mama;
    mama->next_function = next_node;
    return next_node;
}

struct table_node *delete_node(struct table_node *_tail)
{
    struct table_node *p_node = _tail->parent;
    p_node->next = NULL;
    free(_tail);
    return p_node;
}

struct exp_table *creat_exp_table()
{
    struct exp_table *temp = (struct exp_table *)malloc(sizeof(struct exp_table));
    strcpy(temp->exp, "");
    return temp;
}

void exp_push_back(struct exp_table *_exp_table, char _s[])
{
    strcat(_exp_table->exp, _s);
}

void exp_head_insert(struct exp_table *_exp_table, char _s[])
{
    // strcat(_s, _exp_table->exp);
    strcpy(_exp_table->exp, _s);
}

void exp_clear(struct exp_table *_exp_table)
{
    strcpy(_exp_table->exp, "");
}

bool check_name_the_same(char a[], char b[])
{
    bool find = true;
    if (strlen(a) == strlen(b))
    {
        for (int j = 0; j < strlen(a); ++j)
        {
            if (a[j] != b[j])
            {
                find = false;
                break;
            }
        }
    }
    else
    {
        find = false;
    }
    return find;
}

int max(int a, int b)
{
    return a >= b ? a : b;
}