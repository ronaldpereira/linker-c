CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: linker.exe librarie

linker.exe:
	$(CC) $(CFLAGS) linker.c -o linker.exe
	@echo  "\n***IMPORTANT***\nBe sure to include the output, main input and auxiliar inputs file path in the argument of the Linker program\nExample: ./linker.exe ../tst/output.mif ../tst/main.a ../tst/librarie1.a ../tst/librarie2.a [...]\n"

clean:
	rm linker.exe && cd ../assembler && make clean
	@echo "\nThe linker executable has been sucessfully removed\n"

librarie:
	cd ../assembler && make all