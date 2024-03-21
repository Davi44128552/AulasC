// Faça um programa em C que receba um determinado valor N e, em seguida, receba N valores
// inteiros do usuário. O algoritmo deverá determinar se estes números, na ordem em que foram
// entrados, são ou não uma progressão geométrica. Se sim, mostrar a razão desta progressão
// geométrica. Considere N no intervalo [0;1000].

# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *arg[]){

	// Declaração e atribuição de valor para n
	int n;
	printf("Digite um numero inteiro qualquer que esteja no intervalo [0;1000]: ");
	scanf("%d", &n);

	// Criação do vetor
	int termo;
	int vetor[n];
	for (int j = 0; j < n; j++){
		printf("Digite um numero qualquer para o %dº termo do vetor:", (j + 1));
		scanf("%d", &termo);
		vetor[j] = termo;	
	}

	// Análise do vetor
	if (n <= 1){
		printf("O seguinte vetor nao e uma progressao geometrica (motivo: numero insuficiente de termos) \n");
	}
	
	else{
		float razao, x;
		razao = vetor[1] / vetor[0];
		x = vetor[1] / vetor[0];
		int i = 1;
		
		while (i < n && razao == x){
			razao = vetor[i + 1] / vetor[i];
			i += 1;
		}

		if (i == n){
			printf("A sequencia e uma progressao geometrica \n");
		}

		else{
			printf("A sequencia nao e uma progressao geometrica \n");
		}
	}


	return EXIT_SUCCESS;
}