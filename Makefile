all: main

run: main
	./main


OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

main: $(OBJS)
	@gcc -o main $(OBJS) && echo "Compilação efetuada com sucesso!"

.c.o:
	@gcc -c $< -o $@

clean:
	@rm *.o main 2>/dev/null && echo "Arquivos removidos com sucesso!" || echo "A pasta já está limpa!"