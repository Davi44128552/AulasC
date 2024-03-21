# include <stdio.h>
# include <stdlib.h>
# include "arvore.h"

int main(int narg, char *argv[]){

    ArvoreBB *minhaArvore = NULL;
    inicializar(&minhaArvore);

    inserir_interativo(&minhaArvore, 10, 3.14);
    inserir_interativo(&minhaArvore, 5, 2.71);
    inserir_interativo(&minhaArvore, 15, 1.618);

    // Testando busca interativa
    int chaveBusca = 5;
    float resultadoBusca = buscar_interativo(minhaArvore, chaveBusca);

    if (resultadoBusca != -99999.99) {
        printf("Valor encontrado para chave %d: %.2f\n", chaveBusca, resultadoBusca);
    } else {
        printf("Chave %d nao encontrada.\n", chaveBusca);
    }

    // Testando inserção recursiva
    inserir_recursivo(&minhaArvore, 25, 6.66);

    // Testando busca recursiva
    chaveBusca = 20;
    resultadoBusca = buscar_recursivo(minhaArvore, chaveBusca);

    if (resultadoBusca != -99999.99) {
        printf("Valor encontrado para chave %d: %.2f\n", chaveBusca, resultadoBusca);
    } else {
        printf("Chave %d nao encontrada.\n", chaveBusca);
    }

    // Listando elementos em ordem crescente de chave
    listar_elementos(minhaArvore);

    int skip;
    scanf("%d", &skip);

    return EXIT_SUCCESS;
}
