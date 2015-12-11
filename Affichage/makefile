FLAG= -g -Wall

prog : Grille.o afficher.o Outil.o Placement_bateau.o Placement_obstacle.o main.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : ../grille/Outil.c ../grille/Outil.h
	gcc -c ../grille/Outil.c ../grille/Outil.h $(FLAG)
	
Grille.o : ../grille/Grille.c 
	gcc -c ../grille/Grille.c $(FLAG)
	
afficher.o : src/afficher.c include/afficher.h 
	gcc -c src/afficher.c $(FLAG)

afficher_2.o : src/afficher_2.c include/afficher.h 
	gcc -c src/afficher_2.c $(FLAG)

Placement_bateau.o : ../Placer/Placement_bateau.c ../Placer/Placement_bateau.h
	gcc -c ../Placer/Placement_bateau.c $(FLAG)

Placement_obstacle.o : ../Placer/Placement_obstacle.c
	gcc -c ../Placer/Placement_obstacle.c $(FLAG)

main.o : src/main.c 
	gcc -c src/main.c $(FLAG)

clean : 
	rm -rf *o