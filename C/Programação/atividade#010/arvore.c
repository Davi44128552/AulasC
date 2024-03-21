# include <stdio.h>
# include <stdlib.h>
# include "arvore.h"

// Criação da função de inicializar
void inicializar(ArvoreBB **a){
    // Alocando espaço na memória
    *a = (ArvoreBB*)malloc(sizeof(ArvoreBB));

    // Análise da alocação

    // Atribuição de valor à raíz
    (*a) -> raiz = NULL;
}

// Criação da função inserir interativo
int inserir_interativo(ArvoreBB **a, int chave, float valor){
    // Criação do nó e atribuição de valores
    No* novoNo = (No*)malloc(sizeof(No));

    // Análise
    if (novoNo == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA!\n");
        return EXIT_FAILURE;
    }

    novoNo -> chave = chave;
    novoNo -> valor = valor;
    novoNo -> esquerda = NULL;
    novoNo -> direita = NULL;

    // Se a raíz for vazia
    if ((*a) -> raiz == NULL){
        (*a) -> raiz = novoNo;
        return 1;
    }

    // Se a raíz não for vazia
    No* atual = (*a) -> raiz;
    No* anterior = NULL;

    while (atual != NULL){
        anterior = atual;

        // Analisando se a chave já existe na árvore
        if (novoNo -> chave == atual -> chave){
            printf("ERRO! CHAVE JA EXISTENTE NA ARVORE!\n");
            free(novoNo);
            return 0;
        }

        else if (novoNo -> chave < atual -> chave){
            atual = atual -> esquerda;
        }

        else{
            atual = atual -> direita;
        }
    }

    // Adição do nó
    if (novoNo -> chave < anterior -> chave){
        anterior -> esquerda = novoNo;
    }

    else{
        anterior -> direita = novoNo;
    }

    return 1;


}

// Criação da função inserir recursivo 
int inserir_recursivo(ArvoreBB **a, int chave, float valor) {
    return inserir_recursivo_raiz(&((*a)->raiz), chave, valor);
}

int inserir_recursivo_raiz(No **raiz, int chave, float valor) {
    if (*raiz == NULL) {
        // Árvore está vazia ou chegou a uma folha
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("ERRO NA ALOCACAO DE MEMORIA!\n");
            return EXIT_FAILURE;
        }
        novoNo -> chave = chave;
        novoNo -> valor = valor;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
        *raiz = novoNo;
        return 1;
    }

    if (chave == (*raiz)->chave) {
        // Chave duplicada, não é permitido
        printf("ERRO! CHAVE JA EXISTENTE NA ARVORE!\n");
        return 0;
    } else if (chave < (*raiz)->chave) {
        return inserir_recursivo_raiz(&((*raiz)->esquerda), chave, valor);
    } else {
        return inserir_recursivo_raiz(&((*raiz)->direita), chave, valor);
    }
}

// Criação da função buscar interativo
float buscar_interativo(ArvoreBB *a,int chave){
    No* atual = (a) -> raiz;

    while (atual != NULL){
        // Caso a chave seja encontrada
        if (chave == atual -> chave){
            return atual -> valor;
        }

        // Caso a chave ainda não tenha sido encontrada
        else if (chave < atual -> chave){
            atual = atual -> esquerda;
        }

        else{
            atual = atual -> direita;
        }
    }

    // Caso a chave não tenha sido encontrada na ÁRVORE
    printf("ERRO! A chave nao foi encontrada na arvore! \n");
    return -99999.99;
}

// Criando a função busca recursivo
float buscar_recursivo_raiz(No *raiz, int chave) {
    if (raiz == NULL) {
        printf("ERRO! A chave nao foi encontrada na arvore! \n");
        return -99999.99;
    }

    if (chave == raiz -> chave) {
        return raiz -> valor;
    } else if (chave < raiz -> chave) {
        return buscar_recursivo_raiz(raiz -> esquerda, chave);
    } else {
        return buscar_recursivo_raiz(raiz -> direita, chave);
    }
}

float buscar_recursivo(ArvoreBB *a, int chave) {
    return buscar_recursivo_raiz(a -> raiz, chave);
}

// Criando a função listar elementos
void listar_elementos_raiz(No *raiz) {
    if (raiz != NULL) {
        listar_elementos_raiz(raiz->esquerda);
        printf("Chave: %d, Valor: %.2f\n", raiz->chave, raiz->valor);
        listar_elementos_raiz(raiz->direita);
    }
}

void listar_elementos(ArvoreBB *a) {
    printf("Elementos na arvore (em ordem crescente de chave):\n");
    listar_elementos_raiz(a->raiz);
}