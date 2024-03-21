// Faça um programa em linguagem C que receba do usuário um valor inteiro de até 10 dígitos 
// e mostre o número inteiro invertido. A inversão deve ser feita através de cálculos, apenas

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

// Receber o número pelo usuário
    int num;
    printf("Digite um numero inteiro de ate 10 digitos: ");
    scanf("%d", &num);

// Invertendo
    int num_inv = 0;
    while (num > 0) {
        int digito = num % 10; 
        num_inv = num_inv * 10 + digito;  
        num = num / 10; 
    }

    printf("%d", num_inv);

    return EXIT_SUCCESS;

}