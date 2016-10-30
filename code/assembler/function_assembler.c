#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"
#include "binary_converter.h"
#include "function_assembler.h"

void detectaRegistrador(FILE *output, char *token, bool *binary, int pc)
{
	int i, dec;

	dec = (int)(token[1] - '0'); // Transformação de string para inteiro

	binaryConversion(binary, dec);
	for(i = 5; i < 8; i++)
	{
		fprintf(output, "%d", binary[i]);
	}
	fprintf(output, ";\n");

	pc++;
	binaryConversion(binary, pc);
	for(i = 0; i < 8; i++)
		fprintf(output, "%d", binary[i]);
	fprintf(output, "  :  ");
}

void detectaRegistradorSource(FILE *output, char *token, bool *binary)
{
	int i, dec;

	dec = (int)(token[1] - '0'); // Transformação de string para inteiro

	binaryConversion(binary, dec);
	for(i = 5; i < 8; i++)
	{
		fprintf(output, "%d", binary[i]);
	}
}

void detectaImediatoNegativo(FILE *output, char *token, bool *binary)
{
	int i, dec;

	for(i = 0; i < (int)(strlen(token)-1); i++)
	{
		token[i] = token[i+1]; //Shifta a string em uma posição à esquerda
	}
	token[i] = '\0';

	dec = atoi(token);

	binaryTwoComplement(binary, dec);
	for(i = 0; i < 8; i++)
		fprintf(output, "%d", binary[i]);
	fprintf(output, ";\n");
}

void detectaImediatoPositivo(FILE *output, char *token, bool *binary)
{
	int i, dec;

	dec = atoi(token); // Transformação de string para inteiro

	binaryConversion(binary, dec);
	for(i = 0; i < 8; i++)
	{
		fprintf(output, "%d", binary[i]);
	}
	fprintf(output, ";\n");
}

void detectaMarcador(FILE *output, lista_t lista, char *token, bool *binary, int file)
{
	int i, pc;

	pc = procura_elemento(lista.cabeca, token, file);

	binaryConversion(binary, pc);

	for(i = 0; i < 8; i++)
	{
		fprintf(output, "%d", binary[i]);
	}
	fprintf(output, ";\n");
}

void detectaExtern(FILE *output, lista_t lista, char *token, bool *binary)
{
	int i, pc;

	pc = procura_extern(lista.cabeca, token);

	binaryConversion(binary, pc);

	for(i = 0; i < 8; i++)
	{
		fprintf(output, "%d", binary[i]);
	}
	fprintf(output, ";\n");
}

void printaPc(FILE *output, bool *binary, int pc)
{
	int i;

	pc++;
	binaryConversion(binary, pc);
	for(i = 0; i < 8; i++)
		fprintf(output, "%d", binary[i]);
	fprintf(output, "  :  ");
}
