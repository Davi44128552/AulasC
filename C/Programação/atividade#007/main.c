#include "listaencadeada.h"
# include <stdlib.h>
# include <stdio.h>

int main() {
    Registro *lista = NULL;
    // Aqui você pode chamar as funções inserir, carregar, salvar e percorrer conforme necessário
    // Exemplo:
    lista = carregar(lista, "dados.txt");
    lista = inserir(lista, 123, "Exemplo", 123, "555-5555", "exemplo@example.com", "Tipo");
    salvar(lista, "dados.txt");
    percorrer(lista);

    return 0;
}
