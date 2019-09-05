all: main

run: main
	./main


OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

main: $(OBJS)
	gcc -o main $(OBJS)

.c.o:
	gcc -c $< -o $@