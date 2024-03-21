# include <stdio.h>
# include <string.h>

// Struct: coleção de "variáveis" que podem ter diferentes tipos
//         listados em uma memória alocada (BASICAMENTE CLASSES SEM MÉTODOS)

struct Player // Criar a estrutura
{
   char name[12];
   int score;

};


int main(){

    // Construção da struct e atribuição de valores
    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Bro"); // Já que a estrutra há string
    player1.score = 5;

    strcpy(player2.name, "Code");
    player2.score = 7;

    // Saída
    printf("%s\n", player1.name);
    printf("%d\n", player1.score);

    printf("%s\n", player2.name);
    printf("%d\n", player2.score);

    return 0;

}