FLAG= -g -Wall

placer: Grille.o Outil.o Placement_bateau.o
	gcc -o placer Grille.o Outil.o Placement_bateau.o $(FLAG)
Outil.o: Outil.c Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
Grille.o: Grille.c Grille.h
	gcc -c Grille.c $(FLAG)
Placement_bateau.o: Placement_bateau.c Struct.h
	gcc -c Placement_bateau.c $(FLAG)