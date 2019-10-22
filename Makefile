all: exo

exo: main.c arbre.o
	gcc main.c arbre.o -o exo

arbre.o: arbre.c
	gcc -c arbre.c