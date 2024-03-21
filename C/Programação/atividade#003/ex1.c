// Faça um programa em C que receba N (6 ≤ N ≤ 15) números de uma cartela da Mega Sena
// jogada por um usuário. Em seguida, leia os seis números sorteados na Mega Sena. O algoritmo
// deverá mostrar a quantidade de acertos do apostador com sua cartela, os números que ele
// acertou e se ele fez a Mega-Sena (6 acertos), a Quina (5 acertos) ou a Quadra (4 acertos).

# include <stdlib.h>
# include <stdio.h>

int main(int narg, char *argv[]){

    

    // Quantidade de termos que o usuário deseja adicionar
    int n = 0;
    while (n < 6 || n > 15){
        printf("Digite quantos termos voce deseja marcar na cartela da mega-sena (escolha no intervalo [6, 15]): ");
        scanf("%d", &n);

        if (n < 6 || n > 15){
            printf("ESTE NUMERO NAO ESTA NO INTERVALO CITADO! \n");
        }
    }

    // Adição dos termos
    int n_escolhidos[n];
    for (int j = 0; j < n; j++){
        printf("Digite o termo %d da sua cartela: ", (j + 1));
        scanf("%d", &n_escolhidos[j]);
    }

    // Sorteio
    int n_sorteado[6];
    for (int j = 0; j < 6; j++){
        printf("Digite o numero %d sorteado: ", (j + 1));
        scanf("%d", &n_sorteado[j]);
    }

    // Análise dos números sorteados
    int acertos = 0;
    int i;
    for (int j = 0; j < n; j++){
        i = 0;
        while (i < 6 && n_sorteado[j] != n_escolhidos[i]){
            i += 1;
        }

        if (i < 6){
            acertos += 1;
        }
    }

    // Resultado
    if (acertos == 6){
        printf("Voce fez a MEGA-SENA!!!");
    }

    else if (acertos == 5){
        printf("Voce fez a QUINA!!!");
    }

    else if (acertos == 4){
        printf("Voce fez a QUADRA!!!");
    }

    else{
        printf("Que pena... Voce nao ganhou NADA");
    }

    return EXIT_SUCCESS;

}
