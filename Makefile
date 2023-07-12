.PHONY: all clean run

all:
	make -C lib
	make -C src

clean:
	make -C lib clean
	make -C src clean
	$(RM) myprogram

run:
	export LD_LIBRARY_PATH="./lib:$$LD_LIBRARY_PATH" && ./src/myprogram
