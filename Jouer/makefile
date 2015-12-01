FLAG= -g -Wall

prog : Grille.o Outil.o TorpilleurDeplacer.o jouer.o 
	gcc -o prog $^ $(FLAG)
	
Outil.o : include/Outil.c include/Outil.h
	gcc -c include/Outil.c include/Outil.h $(FLAG)
	
Grille.o : include/Grille.c 
	gcc -c include/Grille.c $(FLAG)

TorpilleurDeplacer.o : TorpilleurDeplacer.c TorpilleurDeplacer.h
	gcc -c TorpilleurDeplacer.c $(FLAG)

jouer.o : jouer.c 
	gcc -c jouer.c $(FLAG)

clean : 
	rm -rf *o