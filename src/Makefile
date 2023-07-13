LIBS=-llinkedlist

.PHONY: all clean

all: myprogram

myprogram: main.o helpers.o
	$(CC) main.o helpers.o -L../lib $(LIBS) -o myprogram

main.o: main.c
	$(CC) -c -I../src -I../lib main.c -o main.o

helpers.o: helpers.c
	$(CC) -c -I../lib -I../lib helpers.c -o helpers.o
	
clean:
	$(RM) *.o myprogram
