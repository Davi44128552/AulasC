// Faça um programa em linguagem C que receba um valor inteiro positivo N 
// e mostre todos os números da sequência Fibonacci que sejam menores do que N.

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

	// Numero digitado pelo usuario
	int num;
	printf("Digite um numero inteiro e positivo: ");
	scanf("%d", &num);

	// Primeiros dois termos
	int n0 = 0;
	int n1 = 1;
	int x;

	// loop
	while (n1 < num) {
		x = n1;
		printf("%d \n", n1);
		n1 = n1 + n0;
		n0 = x;
	}
	

	return EXIT_SUCCESS;
}