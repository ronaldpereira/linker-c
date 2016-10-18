CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: assembler.exe

assembler.exe: assembler.o function_assembler.o binary_converter.o lista.o
	$(CC) $(CFLAGS) assembler.o function_assembler.o binary_converter.o lista.o -o assembler.exe

assembler.o: assembler.c lista.h binary_converter.h function_assembler.h
	$(CC) $(CFLAGS) -c assembler.c

function_assembler.o: function_assembler.c lista.h binary_converter.h function_assembler.h
	$(CC) $(CFLAGS) -c function_assembler.c

binary_converter.o: binary_converter.c lista.h binary_converter.h function_assembler.h
	$(CC) $(CFLAGS) -c binary_converter.c

lista.o: lista.c lista.h binary_converter.h function_assembler.h
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm *.o assembler.exe
	@echo "\nThe assembler executable has been sucessfully removed\n"
