# include <stdio.h>
# include <stdlib.h>

// VETOR
// CRIAR_VETOR
void *criar_vetor(int tamanho){

    // Alocando a memória para o vetor
    void *vetor = NULL;
    vetor = malloc(tamanho *sizeof(int));

    // Verificando se a alocação foi bem sucedida
    if (vetor == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA!\n");
        return NULL;
    }

    // Retornando o endereço
    return vetor;

}

// OBTER_VETOR
double obter_vetor(void *mem, int x){

    // Convertendo o void para poder obter o valor
    double *vetor = (double *)mem;

    // Retornando o valor da posição
    return vetor[x];
    
}

// ATRIBUIR_VETOR
int atribuir_vetor(void *mem, int x, double valor){

    // Convertendo o void para poder atribuir o valor
    double *vetor = (double *)mem;

    vetor[x] = valor;
}

// LIBERAR_VETOR
void liberar_vetor(void *mem){
    free(mem);
}

// MATRIZ
// CRIAR_MATRIZ
void **criar_matriz(int tamanho_x, int tamanho_y) {
    // Alocação da memória
    void **matriz = (void **)malloc(tamanho_x * sizeof(void *));
    
    if (matriz == NULL) {
        printf("ERRO NA ALOCACAO DE MEMORIA!\n");
        return NULL;
    }

    // Alocar memória para cada linha (array unidimensional)
    for (int i = 0; i < tamanho_x; i++) {
        matriz[i] = malloc(tamanho_y * sizeof(double));
        
        if (matriz[i] == NULL) {
            printf("ERRO NA ALOCACAO DE MEMORIA!\n", i);
            return NULL;
        }
    }

    return matriz;
}

// OBTER_MATRIZ
double obter_matriz(void *mem, int x, int y){

    // Conversão da matriz
    double **matriz = (double **)mem;

    // Retorno
    return matriz[x][y];

}

// ATRIBUIR_MATRIZ
int atribuir_matriz(void *mem, int x, int y, double valor){

    // Conversão
    double **matriz = (double **)mem;

    // Atribuição de valor
    matriz[x][y] = valor;

}

// LIBERAR_MATRIZ
void liberar_matriz(void *mem){
    free(mem);
}