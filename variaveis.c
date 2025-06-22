#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h" 

static Variavel* lista_de_variaveis = NULL;

void store_variavel(const char* nome, int valor) {
    Variavel* atual = lista_de_variaveis;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
    }
  
    Variavel* nova_var = (Variavel*) malloc(sizeof(Variavel));
    if (nova_var == NULL) {
        return;
    }
    strcpy(nova_var->nome, nome);
    nova_var->valor = valor;
    nova_var->proximo = lista_de_variaveis;
    lista_de_variaveis = nova_var;
}

Variavel* load_variavel(const char* nome) {
    Variavel* atual = lista_de_variaveis;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; 
        }
        atual = atual->proximo;
    }

    return NULL; 
}
