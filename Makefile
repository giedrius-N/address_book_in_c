MAIN := main.c
BINS := $(MAIN:.c=)
OBJS := $(MAIN:.c=.o)

.PHONY: all clean

all: $(BINS)

$(BINS): %: %.o
	$(CC) -o $@ $^
$(OBJS): %.o: %.c
	$(CC) -c -o $@ $^

clean:
	$(RM) $(BINS) $(OBJS)
