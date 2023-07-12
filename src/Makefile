LDFLAGS=-L../lib -Wl,-rpath,'$$ORIGIN/../lib'
LIBS=-llinkedlist -lhelpers

.PHONY: all clean run

all: myprogram

myprogram: main.o helpers.o
	$(CC) main.o helpers.o $(LDFLAGS) $(LIBS) -o myprogram

main.o: main.c
	$(CC) -c -I../src -I../lib main.c -o main.o

helpers.o: helpers.c
	$(CC) -c -I../src -I../lib helpers.c -o helpers.o
	
clean:
	$(RM) *.o myprogram

run:
	export LD_LIBRARY_PATH="../lib:$$LD_LIBRARY_PATH" && ./myprogram

