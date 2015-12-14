FLAG= -g -Wall -lncurses -ltinfo

prog : Grille.o Outil.o TorpilleurDeplacer.o TorpilleurChoisir.o TorpilleurAttaquer.o jouer.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : ../grille/Outil.c ../grille/Outil.h
	gcc -c ../grille/Outil.c ../grille/Outil.h $(FLAG)
	
Grille.o : ../grille/Grille.c 
	gcc -c ../grille/Grille.c $(FLAG)

TorpilleurDeplacer.o : TorpilleurDeplacer.c TorpilleurDeplacer.h JouerStruct.h
	gcc -c TorpilleurDeplacer.c TorpilleurDeplacer.h JouerStruct.h $(FLAG)

TorpilleurChoisir.o : TorpilleurChoisir.c TorpilleurChoisir.h JouerStruct.h
	gcc -c TorpilleurChoisir.c TorpilleurChoisir.h JouerStruct.h $(FLAG)

TorpilleurAttaquer.o : TorpilleurAttaquer.c TorpilleurAttaquer.h JouerStruct.h
	gcc -c TorpilleurAttaquer.c TorpilleurAttaquer.h JouerStruct.h $(FLAG)

jouer.o : jouer.c 
	gcc -c jouer.c $(FLAG)

clean : 
	rm -rf *o
	rm -rf *gch
	rm -rf *~
