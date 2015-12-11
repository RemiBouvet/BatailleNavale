FLAG= -g -Wall

prog : Grille.o afficher.o Outil.o Placement_bateau.o Placement_obstacle.o main.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : ../grille/Outil.c ../grille/Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
	
Grille.o : ../grille/Grille.c 
	gcc -c Grille.c $(FLAG)
	
afficher.o : src/afficher.c include/afficher.h 
	gcc -c afficher.c $(FLAG)

Placement_bateau.o : ../Placer/Placement_bateau.c ../Placer/Placement_bateau.h
	gcc -c Placement_bateau.c $(FLAG)

Placement_obstacle.o : ../Placer/Placement_obstacle.c
	gcc -c Placement_obstacle.c $(FLAG)

main.o : src/main.c 
	gcc -c main.c $(FLAG)

clean : 
	rm -rf *o