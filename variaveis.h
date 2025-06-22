#ifndef VARIAVEIS_H
#define VARIAVEIS_H

typedef struct Variavel {
    char nome[50];          
    int valor;              
    struct Variavel* proximo; 
} Variavel;

void store_variavel(const char* nome, int valor);
Variavel* load_variavel(const char* nome);

#endif
