#ifndef ARVORE_H
#define ARVORE_H

// Estruturas
typedef struct No{

	int chave;
	float valor;
	struct No* esquerda;
	struct No* direita;


} No;

typedef struct ArvoreBB{

	No* raiz;

} ArvoreBB;



// Chamada das funções
void inicializar(ArvoreBB **a);

int inserir_interativo(ArvoreBB **a, int chave, float valor);

int inserir_recursivo (ArvoreBB **a, int chave, float valor);
int inserir_recursivo_raiz(No **raiz, int chave, float valor);

float buscar_interativo(ArvoreBB *a,int chave);

float buscar_recursivo (ArvoreBB *a, int chave);
float buscar_recursivo_raiz(No *raiz, int chave);

void listar_elementos (ArvoreBB *a);
void listar_elementos_raiz(No *raiz);

#endif