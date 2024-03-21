#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv){

    // Representação por matrizes adjacentes
    printf("======== Matrizes ======== \n");
    int representacaoGrafos[6][6] = {{0, 1, 1, 1, 0, 0}, 
                                     {1, 0, 1, 0, 0, 0}, 
                                     {1, 1, 0, 1, 1, 0}, 
                                     {1, 0, 1, 0, 0, 1}, 
                                     {0, 0, 1, 0, 0, 1}, 
                                     {0, 0, 0, 1, 1, 0}};

    for (int i = 0; i < 6; i++){
        printf("\t");

        for (int j = 0; j < 6; j++){
            printf("%d ", representacaoGrafos[i][j]);
        }

        printf("\n");
    }

    // Representação por listas adjacentes

    return EXIT_SUCCESS;

}