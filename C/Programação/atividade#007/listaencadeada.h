#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

// Definição da estrutura de dados para o registro
typedef struct Registro {
    int matricula;
    char nome[100];
    int ddd;
    char telefone[20];
    char email[100];
    char tipo[20];
    struct Registro *proximo;
} Registro;

// Protótipos das funções
Registro *inserir(Registro *lista, int matricula, const char *nome, int ddd, const char *telefone, const char *email, const char *tipo);
void percorrer(Registro *lista);
Registro *carregar(Registro *lista, const char *nomeArquivo);
void salvar(Registro *lista, const char *nomeArquivo);

#endif
