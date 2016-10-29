CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: librarie linker.exe

linker.exe: linker.o assembler.o
	$(CC) $(CFLAGS) assembler.o function_assembler.o binary_converter.o lista.o linker.o -o linker.exe
	@echo  "\n***IMPORTANT***\nBe sure to include the output, main input and auxiliar inputs file path in the argument of the Linker program\nExample: ./linker.exe ../tst/output.mif ../tst/main.a ../tst/librarie1.a ../tst/librarie2.a [...]\n"

linker.o: linker.c ../assembler/assembler.h
	$(CC) $(CFLAGS) -c linker.c

librarie: assembler.o function_assembler.o binary_converter.o lista.o

assembler.o: ../assembler/assembler.c ../assembler/lista.h ../assembler/binary_converter.h ../assembler/function_assembler.h
	$(CC) $(CFLAGS) -c ../assembler/assembler.c

function_assembler.o: ../assembler/function_assembler.c ../assembler/lista.h ../assembler/binary_converter.h ../assembler/function_assembler.h
	$(CC) $(CFLAGS) -c ../assembler/function_assembler.c

binary_converter.o: ../assembler/binary_converter.c ../assembler/lista.h ../assembler/binary_converter.h ../assembler/function_assembler.h
	$(CC) $(CFLAGS) -c ../assembler/binary_converter.c

lista.o: ../assembler/lista.c ../assembler/lista.h ../assembler/binary_converter.h ../assembler/function_assembler.h
	$(CC) $(CFLAGS) -c ../assembler/lista.c

clean:
	rm *.o linker.exe
	@echo "\nThe linker executable has been sucessfully removed\n"
