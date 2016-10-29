#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"
#include "binary_converter.h"

void aloca_lista(lista_t *lista)
{
	lista->cabeca = (celula_t*) calloc(1, sizeof(celula_t));
	lista->cabeca->frente = NULL;
	lista->ultima = lista->cabeca;
}

void adiciona_elemento(lista_t *lista, apontador_t pointer)
{
	apontador_t novo;

	novo = (celula_t*) calloc(1, sizeof(celula_t));
	novo->frente = pointer->frente;
	pointer->frente = novo; //Altera ponteiro pra ultima
	lista->ultima = novo; //Deixando sempre a ultima apontada para NULL
}

void grava_elemento(apontador_t pointer, char *text, int value, int file)
{
	int i;
	printf("%s %d %d\n", text, value, file);

	for(i = 0; text[i] != '\0'; i++)
		pointer->registro.Label[i] = text[i];
	pointer->registro.Label[i] = '\0';

	pointer->registro.Pc = value;
	pointer->registro.File = file;
}

int procura_elemento(apontador_t pointer, char* text)
{
	while(strcmp(text, pointer->registro.Label) != 0)
		pointer = pointer->frente;

	return pointer->registro.Pc;
}

void imprime_lista(apontador_t pointer)
{
	while(pointer != NULL)
	{
		printf("Label:%s/Pc:%d/File:%d-->", pointer->registro.Label, pointer->registro.Pc, pointer->registro.File);
		pointer = pointer->frente;
	}
	printf("\n\n");
}
