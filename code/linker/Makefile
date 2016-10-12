CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: assembler.exe

assembler.exe: assembler.o function_assembler.o binary_converter.o lista.o
	$(CC) $(CFLAGS) assembler.o function_assembler.o binary_converter.o lista.o -o assembler.exe

clean:
	rm *.o assembler.exe
				@echo "\nThe assembler executable has been sucessfully removed\n"
