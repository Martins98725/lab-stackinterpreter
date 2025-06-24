#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "interpret.h"

static Stack *stack = NULL;
static struct list variable_list = {NULL};

void interpret(const char *source)
{
    int numero1, numero2;

    if (stack == NULL)
    {
        stack = new_stack(100);
    }

    char op[10];
    char arg[10];

    sscanf(source, "%s%s", op, arg);

    if (strcmp(op, "push") == 0)
    {
        char *endptr;
        int value = strtol(arg, &endptr, 1);

        if (strlen(arg) == 0)
        {
            printf("Uso: push <valor ou nome_variavel>\n");
            return;
        }

        if (*endptr == '\0')
        {
            stack_push(stack, value);
        }
        else
        {
            int val;
            if (get_variable(&variable_list, arg, &val))
            {
                stack_push(stack, val);
            }
            else
            {
                printf("Variável não encontrada: %s\n", arg);
            }
        }
    }
    else if (strcmp(op, "add") == 0)
    {
        numero1 = stack_pop(stack);
        numero2 = stack_pop(stack);

        if (numero1 == -1 || numero2 == -1)
        {
            printf("Erro: pilha com menos de 2 elementos.\n");
            if (numero2 != -1)
                stack_push(stack, numero2);
            if (numero1 != -1)
                stack_push(stack, numero1);
            return;
        }
        int resultado = numero1 + numero2;

        stack_push(stack, resultado);
    }

    else if (strcmp(op, "sub") == 0)
    {
        numero1 = stack_pop(stack);
        numero2 = stack_pop(stack);

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
        numero1 = stack_pop(stack);
        numero2 = stack_pop(stack);

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
        if (arg[0] == '\0')
        {
            printf("Uso: pop <nome_variavel>\n");
            return;
        }
        int value_from_stack = stack_pop(stack);
        if (value_from_stack == -1 && stack->top < 0)
        { // Confirma que o -1 é de pilha vazia
            printf("Erro: Pilha vazia, nao ha nada para 'pop'.\n");
        }
        else
        {
            set_variable(l, arg, value_from_stack);
        }
    }

    else if (strcmp(op, "div") == 0)
    {
        numero1 = stack_pop(stack);
        numero2 = stack_pop(stack);

        if (numero1 == -1 || numero2 == -1)
        {
            printf("Erro: pilha com menos de 2 elementos.\n");

            return;
        }
        int resultado = (numero2 / numero1);
        stack_push(stack, resultado);
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
