# include <stdio.h>
# include <stdlib.h>

int main(){

    int idade = 24;

    // & necessário para o ponteiro armazenar o valor
    int *anos = NULL;
    anos = &idade;

    // Onde está a idade
    printf("Endereço: %p", anos);

    // Aqui estou pegando o valor que está armazenado pelo ponteiro
    printf("Você tem %d anos", *anos);

    return 0;

}