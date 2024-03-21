# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Criando a estrutura de nós para a lista duplamente encadeada
struct No{

    char nome[100];
    int matricula;   
    int ddd;     
    unsigned int telefone;
    char tipo;

    struct No* proximo;
    struct No* anterior;

};

// Criação da função de inserir
void agd_inserir_inicio(struct No** cabeca, const char* nome, int matricula, int ddd, unsigned int telefone, char tipo){
    struct No* NovoNo = (struct No*)malloc(sizeof(struct No));

    // Análise da alocação de memória
    if (NovoNo == NULL){
        printf("Erro ao alocar memória \n");
        return EXIT_FAILURE;
    }

    // Adição das chaves
    strcpy(NovoNo -> nome, nome);
    NovoNo -> matricula = matricula;
    NovoNo -> ddd = ddd;
    NovoNo -> telefone = telefone;
    NovoNo -> tipo = tipo;

    // Anterior e próximo
    NovoNo -> anterior = NULL;
    NovoNo -> proximo = *cabeca;

    if (*cabeca != NULL){
        *cabeca -> anterior = NovoNo;
    }

    *cabeca = NovoNo;

}

// Criação da função de remover
void agd_remover(struct No** cabeca, const char* nome) {
    struct No* atual = *cabeca;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (atual->anterior == NULL) {
                *cabeca = atual->proximo;
                if (atual->proximo != NULL) {
                    atual->proximo->anterior = NULL;
                }
            } else {
                if (atual->proximo != NULL) {
                    atual->anterior->proximo = atual->proximo;
                    atual->proximo->anterior = atual->anterior;
                } else {
                    atual->anterior->proximo = NULL;
                }
            }
            free(atual);
        }

        atual = atual->proximo;
    }
}

// Criação da função de ordenação
void agd_ordenar(struct No** cabeca){
    struct No *atual, *x, *anterior;
    if (cabeca == NULL){
        printf("A lista se encontra vazia \n");
        return 0;
    }

    for (atual = (*cabeca); atual != NULL, atual = atual -> proximo){
        x = atual;
        anterior = atual -> anterior;

        while (anterior != NULL && strcamp(atual -> nome, x -> nome) > 0){
            x -> anterior = anterior -> anterior;
            x -> proximo = anterior;

            if (anterior -> anterior != NULL){
                anterior -> anterior -> proximo = x;
            }

            else{
                *cabeca = x;
            }

            anterior -> anterior = x;
            anterior -> proximo = x -> proximo;

            if (x -> proximo != NULL){
                x -> proximo -> anterior = anterior;
            }

            anterior = x -> anterior;
        }
    }
}


