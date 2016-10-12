#ifndef LISTA
#define LISTA
#include <stdbool.h>

typedef struct Address
{
	char Label[20]; // Nome do label
	int Pc; // Valor do Pc do label
} registro_t;

typedef struct celula_t* apontador_t;

typedef struct celula_t
{
	registro_t registro;
	apontador_t frente;
} celula_t;

typedef struct lista_t
{
	apontador_t cabeca;
	apontador_t ultima;
} lista_t;

void aloca_lista(lista_t *list);
void adiciona_elemento(lista_t *list, apontador_t pointer);
void grava_elemento(apontador_t pointer, char *text, int value);
int procura_elemento(apontador_t pointer, char* text);
void imprime_lista(apontador_t pointer);

#endif
