FLAG= -g -Wall

prog : Grille.o afficher.o Outil.o Placement_bateau.o Placement_obstacle.o terminal.o main.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : Outil.c Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
	
Grille.o : Grille.c 
	gcc -c Grille.c $(FLAG)
	
afficher.o : afficher.c afficher.h 
	gcc -c afficher.c $(FLAG)

Placement_bateau.o : Placement_bateau.c Placement_bateau.h
	gcc -c Placement_bateau.c $(FLAG)

Placement_obstacle.o : Placement_obstacle.c
	gcc -c Placement_obstacle.c $(FLAG)

terminal.o : terminal.c terminal.h
	gcc -c terminal.c $(FLAG)

main.o : main.c 
	gcc -c main.c $(FLAG)

clean : 
	rm -rf *o