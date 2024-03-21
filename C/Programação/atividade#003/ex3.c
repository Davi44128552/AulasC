// Faça um programa em C que receba até 100.000 valores não negativos e exiba-os em ordem
// crescente. Termine as entradas com um valor negativo.

#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]){

    int lista[100000];
    int num = 0;
    int termo;

    // Leitura dos números
    while (num < 100000 && termo >= 0){

        printf("Digite um numero: ");
        scanf("%d", &termo);
        lista[num] = termo;

        num += 1;
    }

    // Organização
    int x, i;
    for (int j = 0; j < num; j++){
        x = lista[j];
        i = j - 1;

        while (i >= 0 && x < lista[i]){
            lista[i + 1] = lista[i];
            i -= 1;
        }
        lista[i + 1] = x;

    }

    // Saída
    for (int j = 0; j < num; j++){
        printf("%d \n", lista[j]);
    }

    return EXIT_SUCCESS;

}