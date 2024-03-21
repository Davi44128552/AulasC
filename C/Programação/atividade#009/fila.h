#ifndef FILA_H
#define FILA_H

// Criação do nó (com as informações do cliente)
typedef struct No{
    char nome[250];
    int conta;
    float valor;
    struct No* proximo;

} No;

// Criação da estrutura fila
typedef struct Fila{
    No* inicio;
    No* fim;
    
} Fila;

Fila* criar_fila();
int enfileirar(Fila **f, char nome[250], int conta, float valor);
int fila_vazia(Fila *f);
float consulta_valor_proximo(Fila *f);
int consulta_conta_proximo(Fila *f);
char *desenfileirar(Fila **f);

#endif