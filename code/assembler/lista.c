#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"
#include "binary_converter.h"
#include "function_assembler.h"

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

	for(i = 0; text[i] != '\0'; i++)
		pointer->registro.Label[i] = text[i];
	pointer->registro.Label[i] = '\0';

	pointer->registro.Pc = value;
	pointer->registro.File = file;
}

int procura_elemento(apontador_t pointer, char* text, int file)
{
	while(!(strcmp(text, pointer->registro.Label) == 0 && pointer->registro.File == file))
		pointer = pointer->frente;

	return pointer->registro.Pc;
}

int procura_extern(apontador_t pointer, char* text)
{
	while(strcmp(text, pointer->registro.Label) != 0)
		pointer = pointer->frente;

	return pointer->registro.Pc;
}

void atribui_pc(apontador_t pointer, int pc)
{
	while(pointer != NULL)
	{
		pointer->registro.Pc = pc;
		pointer = pointer->frente;
		pc += 2;
	}
}
