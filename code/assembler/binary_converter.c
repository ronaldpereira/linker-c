#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binary_converter.h"

bool *binaryConversion(bool *bin, int dec)
{
	int i;

	for(i = 7; i >= 0; i--)
	{
		bin[i] = dec % 2;
		dec /= 2;
	}

	return bin;
}

bool *binaryTwoComplement(bool *comp, int dec)
{
	int i, flag = 0;

	if(dec == 1) // Se dec for -1, então o algoritmo abaixo não se aplica para transformação em complemento de dois
	{
		for(i = 0; i < 8; i++)
		{
			comp[i] = 1;
		}

		return comp;
	}

	dec = dec - 1; //Complemento começa em -1

	binaryConversion(comp, dec);

	// Algoritmo de transformação em complemento de dois
	for(i = 7; i >= 0; i--)
	{
		if(comp[i] == 1 && flag == 0)
			flag = 1;

		else if(flag == 1)
		{
			if(comp[i] == 0)
				comp[i] = 1;
			else
				comp[i] = 0;
		}
	}

	return comp;
}

bool *binaryConversion16bits(bool *bin, int dec)
{
	int i;

	for(i = 15; i >= 0; i--)
	{
		bin[i] = dec % 2;
		dec /= 2;
	}

	return bin;
}

bool *binaryTwoComplement16bits(bool *comp, int dec)
{
	int i, flag = 0;

	if(dec == 1) // Se dec for -1, então o algoritmo abaixo não se aplica para transformação em complemento de dois
	{
		for(i = 0; i < 16; i++)
		{
			comp[i] = 1;
		}

		return comp;
	}

	dec = dec - 1; //Complemento começa em -1

	binaryConversion16bits(comp, dec);

	// Algoritmo de transformação em complemento de dois
	for(i = 15; i >= 0; i--)
	{
		if(comp[i] == 1 && flag == 0)
			flag = 1;

		else if(flag == 1)
		{
			if(comp[i] == 0)
				comp[i] = 1;
			else
				comp[i] = 0;
		}
	}

	return comp;
}
