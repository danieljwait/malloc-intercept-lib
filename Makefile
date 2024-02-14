CC=gcc
CFLAGS=-Wall -g

malloc.so: malloc.c
		$(CC) $^ -o $@ -fPIC -shared $(CFLAGS)

.PHONY: clean

clean:
		rm -f malloc.so
