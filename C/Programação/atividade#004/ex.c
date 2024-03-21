# include <stdio.h>
# include <stdlib.h>

void nome_extenso(char numero[4]);

#include <stdio.h>
#include <stdlib.h>

void nome_extenso(char numero[4]);

int main(int narg, char *argv[]) {
    // sem arquivo
    if (narg == 1) {
        char buffer[4];
        printf("Informe um número que esteja no intervalo de 1 a 999 (1 <= N <= 999): ");
        scanf("%s", buffer);

        nome_extenso(buffer);
    }
    // com arquivo
    else if (narg == 2) {
        FILE *pF = fopen(argv[1], "r");

        if (pF == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return EXIT_FAILURE;
        }

        char buffer[4];
        while (fscanf(pF, "%s", buffer) == 1) {
            nome_extenso(buffer);
        }

        fclose(pF);

        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}




void nome_extenso(char numero[4]){

    // Se o numero é menor que 10
    if (numero[1] == '\0'){
        char unidade;
        unidade = numero[0];
        
        if (unidade == '1'){
            printf("um");
        }
        else if (unidade == '2'){
            printf("dois");
        }
        else if (unidade == '3'){
            printf("três");
        }
        else if (unidade == '4'){
            printf("quatro");
        }
        else if (unidade == '5'){
            printf("cinco");
        }
        else if (unidade == '6'){
            printf(" e seis");
        }
        else if (unidade == '7'){
            printf("sete");
        }
        else if (unidade == '8'){
            printf("oito");
        }
        else if (unidade == '9'){
            printf("nove");
        }
    
    }
    
    // Para o numero maior que 10 e menor que 100
    else if (numero[2] == '\0'){
        char dezena = numero[0];
        
        if (dezena == '1'){
            if (numero[1] == '0'){
                printf("dez");
            }
            else if (numero[1] == '1'){
                printf("onze");
            }
            else if (numero[1] == '2'){
                printf("doze");
            }
            else if (numero[1] == '3'){
                printf("treze");
            }
            else if (numero[1] == '4'){
                printf("catorze");
            }
            else if (numero[1] == '5'){
                printf("quinze");
            }
            else if (numero[1] == '6'){
                printf("dezesseis");
            }
            else if (numero[1] == '7'){
                printf("dezessete");
            }
            else if (numero[1] == '8'){
                printf("dezoito");
            }
            else if (numero[1] == '9'){
                printf("dezenove");
            }
            numero[1] = '0';
        }
        
        else if (dezena == '2'){
            printf("vinte");
        }
        else if (dezena == '3'){
            printf("trinta");
        }
        else if (dezena == '4'){
            printf("quarenta");
        }
        else if (dezena == '5'){
            printf("cinquenta");
        }
        else if (dezena == '6'){
            printf("sessenta");
        }
        else if (dezena == '7'){
            printf("setenta");
        }
        else if (dezena == '8'){
            printf("oitenta e ");
        }
        else if (dezena == '9'){
            printf("noventa");
        }
    
        char unidade;
        unidade = numero[1];
        
        if (unidade == '1'){
            printf(" e um");
        }
        else if (unidade == '2'){
            printf(" e dois");
        }
        else if (unidade == '3'){
            printf(" e três");
        }
        else if (unidade == '4'){
            printf(" e quatro");
        }
        else if (unidade == '5'){
            printf(" e cinco");
        }
        else if (unidade == '6'){
            printf(" e seis");
        }
        else if (unidade == '7'){
            printf(" e sete");
        }
        else if (unidade == '8'){
            printf(" e oito");
        }
        else if (unidade == '9'){
            printf(" e nove");
        }
    
    }
    
    // Se o numero for maior que 100
    else{
         char centena = numero[0];
         
        if (centena == '1'){
            printf("cento e ");
        }
        else if (centena == '2'){
            printf("duzentos e ");
        }
        else if (centena == '3'){
            printf("trezentos e ");
        }
        else if (centena == '4'){
            printf("quatrocentos e ");
        }
        else if (centena == '5'){
            printf("quinhetos e ");
        }
        else if (centena == '6'){
            printf("seiscentos e ");
        }
        else if (centena == '7'){
            printf("setecentos e ");
        }
        else if (centena == '8'){
            printf("oitocentos e ");
        }
        else if (centena == '9'){
            printf("novecentos e ");
        }

    char dezena;
    dezena = numero[1];
        
    if (dezena == '1'){
            if (numero[2] == '0'){
                printf("dez");
            }
            else if (numero[2] == '1'){
                printf("onze");
            }
            else if (numero[2] == '2'){
                printf("doze");
            }
            else if (numero[2] == '3'){
                printf("treze");
            }
            else if (numero[2] == '4'){
                printf("catorze");
            }
            else if (numero[2] == '5'){
                printf("quinze");
            }
            else if (numero[2] == '6'){
                printf("dezesseis");
            }
            else if (numero[2] == '7'){
                printf("dezessete");
            }
            else if (numero[2] == '8'){
                printf("dezoito");
            }
            else if (numero[2] == '9'){
                printf("dezenove");
            }
            numero[2] = '0';
    }
    else if (dezena == '2'){
        printf("vinte");
    }
    else if (dezena == '3'){
        printf("trinta");
    }
    else if (dezena == '4'){
        printf("quarenta");
    }
    else if (dezena == '5'){
        printf("cinquenta");
    }
    else if (dezena == '6'){
        printf("sessenta");
    }
    else if (dezena == '7'){
        printf("setenta");
    }
    else if (dezena == '8'){
        printf("oitenta");
    }
    else if (dezena == '9'){
        printf("noventa");
    }
    
    char unidade;
    unidade = numero[2];
        
    if (unidade == '1'){
        printf(" e um");
    }
    else if (unidade == '2'){
        printf(" e dois");
    }
    else if (unidade == '3'){
        printf(" e três");
    }
    else if (unidade == '4'){
        printf(" e quatro");
    }
    else if (unidade == '5'){
        printf(" e cinco");
    }
    else if (unidade == '6'){
        printf(" e seis");
    }
    else if (unidade == '7'){
        printf(" e sete");
    }
    else if (unidade == '8'){
        printf(" e oito");
    }
    else if (unidade == '9'){
        printf(" e nove");
    }
    }
}