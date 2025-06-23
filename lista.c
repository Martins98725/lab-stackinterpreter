#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_variable(struct list *l, const char *key, int value)
{
    struct node *current = l->first;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    struct node *new_node = malloc(sizeof(struct node));

    strncpy(new_node->key, key, sizeof(new_node->key));

    new_node->key[sizeof(new_node->key) - 1] = '\0';
    new_node->value = value;
    new_node->next = l->first;
    l->first = new_node;
};

int get_variable(struct list *l, const char *key, int *found)
{
    struct node* current = l->first;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            *found = current->value;
            return 1;
        }
        current = current->next;
    }

    return 0;
};


void print_variables(struct list* l) {
    struct node* current = l->first;
    if (!current) {
        printf("Nenhuma variável armazenada.\n");
        return;
    }
    printf("Variáveis armazenadas:\n");
    while (current) {
        printf("%s = %d\n", current->key, current->value);
        current = current->next;
    }
}
