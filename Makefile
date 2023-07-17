.PHONY: clean all src lib

all: lib src

lib:
	make -C lib

src:
	make -C src

clean:
	make -C lib clean
	make -C src clean
