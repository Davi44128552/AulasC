// Faça um algoritmo que receba do usuário um número inteiro 
// e exiba o maior número primo que seja menor do que o número digitado.

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

	int num;
	int primo;
	int cont;
    int maior;
	printf("Digite um numero inteiro positivo: ");
	scanf("%d", &num);

	if (num <= 2){
		printf("Nao ha numero primo menor que este");
	}

	else{

		for (int j = 1; j < num; j++){
			cont = 0;
			for (int i = 1; i <= j; i ++){
            	if (j % i == 0){
                	cont += 1;
            	}
        	}
        	if (cont == 2){
            	maior = j;
        	}
		}

    	printf("%d", maior);

	}

	return EXIT_SUCCESS;

}
