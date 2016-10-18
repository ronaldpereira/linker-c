#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *output, *_main, *library[argc-2];
	int i;

	output = fopen(argv[1], "w+r"); // Abertura do arquivo de saida
	_main = fopen(argv[2], "w+r"); // Abertura do arquivo principal (main)

	for (i = 2; i < argc; i++)
		library[i-2] = fopen(argv[i], "w+r"); // Abertura por meio de uma iteração de todos os arquivos de funções externas (libraries)

	return 0;
}
