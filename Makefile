CC=gcc
CFLAGS= -ggdb -Wall -Werror -I./

CLP_SRCS = test.c avl.c

test: test.c avl.c
	$(CC) $(CFLAGS) $(CLP_SRCS) -o ./test

clean:
	rm -fr *.o ./test

.PHONY: clean
