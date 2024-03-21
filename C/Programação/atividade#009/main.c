# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "fila.h"

int main(int narg, char *argv[]){
    Fila *fila = criar_fila();

    // Teste
    enfileirar(&fila, "Cliente1", 123, 100.0);
    enfileirar(&fila, "Cliente2", 456, 200.0);
    enfileirar(&fila, "Cliente3", 789, 50.0);

    printf("Cliente: %s\n", desenfileirar(&fila));
    printf("Valor do cliente: %.3f\n", consulta_valor_proximo(fila));
    printf("Conta do cliente: %d\n", consulta_conta_proximo(fila));

    if (fila_vazia(fila)) {
        printf("A fila esta vazia.\n");
    } else {
        printf("A fila não está vazia.\n");
    }

    enfileirar(&fila, "Cliente4", 101, 150.0);

    return EXIT_SUCCESS;
}