CC=gcc
DEPS = stackStructure.h torusStructure.h heapStructure.h virtualMachine.h
CFLAGS=-O3 -I. -std=c99 -Wall
OBJ = main.o vm.o torus_func.o stack_func.o heap_gc_func.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) main
