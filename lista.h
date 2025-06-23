#ifndef lista_h
#define lista_h

struct node
{
    char key[15];
    int value;
    struct node *next;
};

struct list
{
    struct node *first;
};

void set_variable(struct list *l, const char *key, int value);

int get_variable(struct list *l, const char *key, int *found_value);
void print_variables(struct list *l);

#endif
