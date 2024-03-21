#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação da função para a criação da fila
Fila* criar_fila(){
    Fila* novafila = (Fila*)malloc(sizeof(Fila));
    novafila -> inicio = NULL;
    novafila -> fim = NULL;

    return novafila;
}

// Criação da função enfileirar
int enfileirar(Fila **f, char nome[250], int conta, float valor){
    No* novo_no = (No*)malloc(sizeof(No));

    // Analise da alocação do nó
    if (novo_no == NULL){
        printf("Falha na alocacao da memoria! \n");
        return 0;
        
    }

    strcpy(novo_no -> nome, nome);
    novo_no -> conta = conta;
    novo_no -> valor = valor;
    novo_no -> proximo = NULL;

    if ((*f) -> fim == NULL){
        (*f) -> inicio = novo_no;
        (*f) -> fim = novo_no;
    }

    else{
        (*f) -> fim -> proximo = novo_no;
        (*f) -> fim = novo_no;
    }

    return 1;
}

// Criação da função  fila vazia
int fila_vazia(Fila *f){
    if (f -> inicio == NULL){
        return 1;   
    }
    
    else{
        return 0;   
    }
    
}

// Criação da função consulta valor próximo 
float consulta_valor_proximo(Fila *f){
    // Analisando se a fila está vazia
    if (fila_vazia(f)){
        printf("ERRO! A fila esta vazia!\n");
        return -1;
    }

    No* no_primeiro = f -> inicio;
    float quantia_cliente = no_primeiro -> valor;
    return quantia_cliente;
    
}

// Criação da função consulta conta próximo
int consulta_conta_proximo(Fila *f){
    if (fila_vazia(f)){
        printf("ERRO! A fila esta vazia!\n");
        return -1;
    }
    
    No* no_primeiro = f -> inicio;
    int conta_cliente = no_primeiro -> conta;
    return conta_cliente;
}

// Criação da função desenfileirar
char *desenfileirar(Fila **f){

    // Análise da fila
    if (fila_vazia(*f)){
        printf("ERRO! A fila esta vazia!\n");
        return NULL;
    }
    
    No* no_primeiro = (*f) -> inicio;
    char* nome_cliente = strdup(no_primeiro -> nome);
    
    (*f) -> inicio = no_primeiro -> proximo;
    free(no_primeiro);
    
    return nome_cliente;
}