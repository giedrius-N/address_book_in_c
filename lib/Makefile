.PHONY: all clean

all: liblinkedlist.so

liblinkedlist.so: linkedlist.o
	$(CC) -shared -o liblinkedlist.so linkedlist.o

linkedlist.o: linkedlist.c
	$(CC) -c -fPIC -I../lib linkedlist.c -o linkedlist.o
	
clean:
	$(RM) *.o liblinkedlist.so
