#include "listaencadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Registro *inserir(Registro *lista, int matricula, const char *nome, int ddd, const char *telefone, const char *email, const char *tipo) {
    // Crie um novo registro
    Registro *novo = (Registro *)malloc(sizeof(Registro));
    if (!novo) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }

    novo->matricula = matricula;
    strncpy(novo->nome, nome, sizeof(novo->nome));
    novo->ddd = ddd;
    strncpy(novo->telefone, telefone, sizeof(novo->telefone));
    strncpy(novo->email, email, sizeof(novo->email));
    strncpy(novo->tipo, tipo, sizeof(novo->tipo));
    novo->proximo = NULL;

    if (!lista || strcmp(nome, lista->nome) < 0) {
        novo->proximo = lista;
        return novo;
    }

    Registro *atual = lista;
    while (atual->proximo && strcmp(nome, atual->proximo->nome) >= 0) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return lista;
}

void percorrer(Registro *lista) {
    Registro *atual = lista;
    while (atual) {
        printf("Matrícula: %d\nNome: %s\nDDD: %d\nTelefone: %s\nEmail: %s\nTipo: %s\n\n", atual->matricula, atual->nome, atual->ddd, atual->telefone, atual->email, atual->tipo);
        atual = atual->proximo;
    }
}

Registro *carregar(Registro *lista, const char *nomeArquivo) {
    // Implemente a leitura do arquivo e a chamada de inserir para cada registro lido
}

void salvar(Registro *lista, const char *nomeArquivo) {
    // Implemente a escrita dos dados da lista no arquivo
}
