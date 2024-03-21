# include <stdio.h>
# include <stdlib.h>

int main(int narg, char *argv[]){

    FILE *pF = fopen("teste.txt", "r");

    char buffer[50];

    if (pF == NULL){
        printf("O arquivo nao foi encontrado!");
        return EXIT_FAILURE;
    }

    else{
        fgets(buffer, 50, pF);

        printf("%s", buffer);

        fclose(pF);

        return EXIT_SUCCESS;
}

}