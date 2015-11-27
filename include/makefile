FLAG= -g -Wall

main : Grille.o Outil.o
	gcc -o main Grille.o Outil.o $(FLAG)
Outil.o : Outil.c Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
Grille.o : Grille.c
	gcc -c Grille.c $(FLAG)
