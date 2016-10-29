#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../assembler/assembler.h"

int main(int argc, char* argv[])
{
	FILE *output, *_main, *library[argc-2];
	int i;

	output = fopen(argv[1], "w+r"); // Abertura do arquivo de saida
	_main = fopen(argv[2], "r"); // Abertura do arquivo principal (main)

	for (i = 3; i < argc; i++)
		library[i-3] = fopen(argv[i], "r"); // Abertura por meio de uma iteração de todos os arquivos de funções externas (libraries)

	assembler(output, _main, library, (argc-3));

	for (i = 3; i < argc; i++)
		fclose(library[i-3]);
	fclose(_main);
	fclose(output);

	return 0;
}
