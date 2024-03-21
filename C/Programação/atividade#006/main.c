# include <stdio.h>
# include <stdlib.h>
# include "biblioteca.h"

int main(int narg, char *argv[]){

    // Vetor
    void *vetor = NULL;

    vetor = criar_vetor(16);

    atribuir_vetor(vetor, 8, 456.0);

    printf("A pos. 8 do vetor contem %f \n", obter_vetor(vetor, 8));
    liberar_vetor(vetor);

    // Matriz
    void **matriz = NULL;

    matriz = criar_matriz(10, 10);

    atribuir_matriz(matriz, 5, 4, 12.0);

    printf("A pos. (5,4) da matriz = %f \n", obter_matriz(matriz, 5, 4));
    liberar_matriz(matriz);

    return EXIT_SUCCESS;

}