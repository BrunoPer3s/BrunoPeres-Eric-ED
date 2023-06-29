all: compila executa
compila: main.o filme.o listaCDescritor.o listaDupEncadeada.o arquivo.o
	gcc main.o filme.o listaCDescritor.o listaDupEncadeada.o arquivo.o -o prog
main.o: main.c
	gcc -c main.c
filme.o: filme.c
	gcc -c filme.c
listaCDescritor.o: listaCDescritor.c
	gcc -c listaCDescritor.c
listaDupEncadeada.o: listaDupEncadeada.c
	gcc -c listaDupEncadeada.c
arquivo.o: arquivo.c
	gcc -c arquivo.c
executa:
	./prog
clean:
	rm main.o filme.o listaCDescritor.o listaDupEncadeada.o arquivo.o prog