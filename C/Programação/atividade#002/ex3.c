// Faça um programa em linguagem C que exiba os 1.000 primeiros números inteiros positivos
// que são ímpares e que não são divisíveis nem por 3 nem por 7.

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

	int cont = 0;
	int k = 0;

	while (cont < 1000){
		if ((k % 2 != 0) && (k % 3 != 0) && (k % 7 != 0)){
			printf("%d \n", k);
			cont += 1;
		}

		k += 1;
	}

	return EXIT_SUCCESS;
}
