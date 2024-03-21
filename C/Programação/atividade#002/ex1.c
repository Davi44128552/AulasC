// Faça um programa em linguagem C que receba um valor inteiro positivo N 
// e mostre os N primeiros números primos, considerando o primeiro número primo como sendo 2.

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

	int cont = 0;
	int k = 2;
	int num, cont_x;

	printf("Digite um numero inteiro positivo: ");
	scanf("%d", &num);

	while (cont < num){
		
		cont_x = 0;

		for (int j = 1; j <= k; j++){
			if (k % j == 0){
				cont_x += 1;
			}
		}
		
		if (cont_x == 2){
			printf("%d \n", k);
			cont += 1;
		} 

		k += 1;

	}

	return EXIT_SUCCESS;
}
