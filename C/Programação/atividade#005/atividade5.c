# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int termo();
void vetor_random(int k, unsigned int vetor[]);
double contador_tempo(void (*funcao)());
void insertion_sort(int n, unsigned int vetor[]);
void selection_sort(int n, unsigned int vetor[]);
void bubble_sort(int n, unsigned int vetor[]);
void comb_sort(int n, unsigned int vetor[]);

// Código principal
int main(int narg, char *argv[]){

	int n_termos = termo();
	unsigned int vetor[n_termos];
	unsigned int vetor1[n_termos];
	unsigned int vetor2[n_termos];
	unsigned int vetor3[n_termos];
	vetor_random(n_termos, vetor);
	vetor_random(n_termos, vetor1);
	vetor_random(n_termos, vetor2);
	vetor_random(n_termos, vetor3);

	printf("BUBBLE SORT: \n\n");
	printf("valores do vetor: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor1[j]);
	}
	

	contador_tempo(bubble_sort);
	bubble_sort(n_termos, vetor1);
	

	printf("valores do vetor classificado: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor1[j]);
	}

	printf("INSERTION SORT: \n\n");
	printf("valores do vetor: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor[j]);
	}
	

	contador_tempo(insertion_sort);
	insertion_sort(n_termos, vetor);
	

	printf("valores do vetor classificado: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor[j]);
	}
	

	printf("SELECTION SORT: \n\n");
	printf("valores do vetor: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor2[j]);
	}
	

	contador_tempo(selection_sort);
	selection_sort(n_termos, vetor2);
	

	printf("valores do vetor classificado: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor2[j]);
	}

	printf("COMB SORT: \n\n");
	printf("valores do vetor: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor3[j]);
	}
	

	contador_tempo(comb_sort);
	comb_sort(n_termos, vetor3);
	

	printf("valores do vetor classificado: \n");
	for (int j = 0; j < n_termos; j++){
		printf("%u\n", vetor3[j]);
	}


	return EXIT_SUCCESS;

}

int termo(){

	int n = (rand() % 31);
	return n;

}

// Vetor randomico
void vetor_random(int k, unsigned int vetor[]){

	for (int j = 0; j < k; j++){
		vetor[j] = (rand() % ((100 * k) + 1));
	}

}

// Contador de tempo
double contador_tempo(void (*funcao)()){
	clock_t start = clock();
	funcao();
	clock_t end = clock();

	double tempo_total = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("tempo total: %lf \n", tempo_total);
}

// Insertion Sort
void insertion_sort(int n, unsigned int vetor[]){
	for (int j = 1; j < n; j++){
		unsigned int x = vetor[j];
		int i = j - 1;
		while (i >= 0 && vetor[i] > x){
			vetor[i + 1] = vetor[i];
			i -= 1;
		}

		vetor[i + 1] = x;

	}

}


// Selection Sort
void selection_sort(int n, unsigned int vetor[]){

	for (int j = 0; j < n; j++){
		unsigned int min = vetor[j];
		unsigned int x;
		int i = j;
		while (i < n){
			if (vetor[i] < min){
				x = min;
				min = vetor[i];
				vetor[j] = min;
				vetor[i] = x;
			}
			
			i += 1;
		}
	}

}	


// Bubble Sort
void bubble_sort(int n, unsigned int vetor[]){

	for (int k = n; k >= 0; k--){
        for (int j = 1; j < k; j++){
	    	unsigned int x = vetor[j];
	    	int i = j - 1;
		    if (vetor[i] > x){
		    	vetor[i + 1] = vetor[i];
		    	vetor[i] = x;
		    }
	    }
    }


}


// Comb Sort
void comb_sort(int n, unsigned int vetor[]){

    unsigned int j, i, gap, x;
    int trocar = 1;

    gap = n;

    while (gap > 1 || trocar == 1){
        gap = gap * 10 / 13;

        if (gap == 9 || trocar == 1){
            gap == 11;
        }
        if (gap < 1){
            gap = 1;
        }

        trocar = 0;

        for (i = 0, j = gap; j < n; i++, j++){
            if (vetor[i] > vetor[j]){
                x = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = x;
                trocar = 1;
            }
        }
    }


}

