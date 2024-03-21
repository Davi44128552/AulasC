// Faça um programa em linguagem C que permita ao usuário entrar números inteiros até que sejam
// entrados 10 números divisíveis por 3. O programa deverá, então, mostrar a média aritmética
// dos números divisíveis por 3 e a média aritmética dos demais números entrados.

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

    // Declaração de variáveis
    int cont_3 = 0;
    float soma_3 = 0;

    int cont_r = 0; 
    float soma_r = 0;

    int num;

    // Loop e análise de números divisíveis por 3
    while (cont_3 < 10){
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        if (num % 3 == 0){
            cont_3 += 1;
            soma_3 += num;
        }

        else{
            cont_r += 1;
            soma_r += num;
        }

    }

    // Cálculo da média aritmética
        // Múltiplos de 3
    float media_3 = soma_3 / cont_3;
    printf("A media dos numeros divisiveis por 3 e %.2f \n", media_3);

        // Restante
    float media_r = soma_r / cont_r;
    printf("A media dos numeros restantes e %.2f \n", media_r);

    return EXIT_SUCCESS;

}