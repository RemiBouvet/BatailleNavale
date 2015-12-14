FLAG= -g -Wall

prog : Grille.o Outil.o TorpilleurDeplacer.o TorpilleurChoisir.o TorpilleurAttaquer.o jouer.o Placement_bateau.o Placement_obstacle.o afficher.o main.o
	gcc -o prog $^ $(FLAG)
	
Outil.o : grille/Outil.c grille/Outil.h
	gcc -c grille/Outil.c grille/Outil.h $(FLAG)
	
Grille.o : grille/Grille.c 
	gcc -c grille/Grille.c $(FLAG)

TorpilleurDeplacer.o : jouer/TorpilleurDeplacer.c jouer/TorpilleurDeplacer.h jouer/JouerStruct.h
	gcc -c jouer/TorpilleurDeplacer.c jouer/TorpilleurDeplacer.h jouer/JouerStruct.h $(FLAG)

TorpilleurChoisir.o : jouer/TorpilleurChoisir.c jouer/TorpilleurChoisir.h jouer/JouerStruct.h
	gcc -c jouer/TorpilleurChoisir.c jouer/TorpilleurChoisir.h jouer/JouerStruct.h $(FLAG)

TorpilleurAttaquer.o : jouer/TorpilleurAttaquer.c jouer/TorpilleurAttaquer.h jouer/JouerStruct.h
	gcc -c jouer/TorpilleurAttaquer.c jouer/TorpilleurAttaquer.h jouer/JouerStruct.h $(FLAG)

jouer.o : jouer/jouer.c 
	gcc -c jouer/jouer.c $(FLAG)

Placement_bateau.o: Placer/Placement_bateau.c grille/Struct.h grille/Outil.h Placer/Placement_bateau.h
	gcc -c Placer/Placement_bateau.c $(FLAG)

Placement_obstacle.o: Placer/Placement_obstacle.c grille/Struct.h Placer/Placement_obstacle.h grille/Outil.h
	gcc -c Placer/Placement_obstacle.c $(FLAG)

afficher.o : Affichage/src/afficher.c Affichage/include/afficher.h 
	gcc -c Affichage/src/afficher.c $(FLAG)

main.o : main.c
	gcc -c main.c $(FLAG)

clean : 
	rm -r -f *o
	rm -r -f *gch
	rm -r -f *~
