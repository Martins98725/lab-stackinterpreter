#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#include "interpret.h"

static Stack *stack = NULL;

void interpret(const char *source)
{

    if (stack == NULL)
    {
        stack = new_stack(100);
    }

    char op[10];
    char arg[10];

     sscanf(source, "%s%s", op, arg);

   
    if (strcmp(op, "push") == 0)
    {
        int value = atoi(arg);
        stack_push(stack, value);
    }
    else if (strcmp(op, "add") == 0)
    {
        int numero1 = stack_pop(stack);
        int numero2 = stack_pop(stack);

        if (numero1 == -1 || numero2 == -1)
        {
            printf("Erro: pilha com menos de 2 elementos.\n");

            return;
        }
        int resultado = numero1 + numero2;

        stack_push(stack, resultado);
    }

    else if (strcmp(op, "sub") == 0)
    {
        int numero1 = stack_pop(stack);
        int numero2 = stack_pop(stack);

        if (numero1 == -1 || numero2 == -1)
        {
            printf("Erro: pilha com menos de 2 elementos.\n");

            return;
        }
        int resultado = numero2 - numero1;
        stack_push(stack, resultado);
    }
    else if (strcmp(op, "mul") == 0)
    {
        int numero1 = stack_pop(stack);
        int numero2 = stack_pop(stack);

        if (numero1 == -1 || numero2 == -1)
        {
            printf("Erro: pilha com menos de 2 elementos.\n");

            return;
        }
        int resultado = numero1 * numero2;

        stack_push(stack, resultado);
    }
    else if (strcmp(op, "pop") == 0)
    {
        int value = stack_pop(stack);
        if (value != -1)
            printf("Valor desempilhado: %d\n", value);
    }
    else if (strcmp(op, "print") == 0)
    {

        stack_print(stack);
    }
    else
    {
        printf("Operação desconhecida: %s\n", op);
        return;
    }
}