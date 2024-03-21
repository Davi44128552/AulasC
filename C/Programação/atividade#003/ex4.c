// Faça um programa em C que receba valores inteiros positivos maiores do que 2 para as variáveis
// x, y e z, todos menores ou iguais a 20, receba valores numéricos quaisquer para a matriz A de
// dimensão (x , y) e para matriz B de dimensão (y , z), calcule e mostre o produto dessas duas matrizes.

# include <stdlib.h>
# include <stdio.h>

int main(int narg, char *argv[]){

    // Definição das dimensões das matrizes a serem trabalhadas
    int x, y, z;
    x = 0;
    y = 0;
    z = 0;

    while (x < 2 || x > 20){
        printf("Digite um numero para x (no intervalo [2, 20]): ");
        scanf("%d", &x);

        if (x < 2 || x > 20){
            printf("ESTE NUMERO NAO ESTA NO INTERVALO !!! \n");
        }
    }

    while (y < 2 || y > 20){
        printf("Digite um numero para y (no intervalo [2, 20]): ");
        scanf("%d", &y);

        if (y < 2 || y > 20){
            printf("ESTE NUMERO NAO ESTA NO INTERVALO !!! \n");
        }
    }

    while (z < 2 || z > 20){
        printf("Digite um numero para z (no intervalo [2, 20]): ");
        scanf("%d", &z);

        if (z < 2 || z > 20){
            printf("ESTE NUMERO NAO ESTA NO INTERVALO !!! \n");
        }
    }

    // Adição dos termos às matrizes
        // Matriz A
    int matriz_a[x][y];
    for (int j = 0; j < x; j++){
        for (int i = 0; i < y; i++){
            printf("Digite o termo [%d][%d]: ", j, i);
            scanf("%d", &matriz_a[j][i]);
        }
    }

        // Matriz B
    int matriz_b[y][z];
    for (int j = 0; j < y; j++){
        for (int i = 0; i < z; i++){
            printf("Digite o termo [%d][%d]: ", j, i);
            scanf("%d", &matriz_b[j][i]);
        }
    }

    // Multiplicação das matrizes
    int matriz_resultante[x][z];
    for (int j = 0; j < x; j++){
        for (int i = 0; i < z; i++){
            matriz_resultante[j][i] = 0;
            for (int k = 0; k < y; k++){
                matriz_resultante[j][i] += (matriz_a[j][k]) * (matriz_b[k][i]);
            }
        }
    }
    
    // Saída
    for (int j = 0; j < x; j++){
        for (int i = 0; i < z; i++){
            printf("%d \n", matriz_resultante[j][i]);
        }
    }


    return EXIT_SUCCESS;

}