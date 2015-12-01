FLAG= -g -Wall

prog : Grille.o Outil.o TorpilleurDeplacer.o TorpilleurChoisir.o jouer.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : include/Outil.c include/Outil.h
	gcc -c include/Outil.c include/Outil.h $(FLAG)
	
Grille.o : include/Grille.c 
	gcc -c include/Grille.c $(FLAG)

TorpilleurDeplacer.o : TorpilleurDeplacer.c TorpilleurDeplacer.h JouerStruct.h
	gcc -c TorpilleurDeplacer.c TorpilleurDeplacer.h JouerStruct.h $(FLAG)

TorpilleurChoisir.o : TorpilleurChoisir.c TorpilleurChoisir.h JouerStruct.h
	gcc -c TorpilleurChoisir.c TorpilleurChoisir.h JouerStruct.h $(FLAG)

jouer.o : jouer.c 
	gcc -c jouer.c $(FLAG)

clean : 
	rm -rf *o