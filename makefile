FLAG= -g -Wall -lmenu -lncurses
PREFIX=.
SRCDIR=$(PREFIX)/src
INCDIR=$(PREFIX)/include
CC=gcc

prog : Grille.o Outil.o TorpilleurDeplacer.o TorpilleurChoisir.o TorpilleurAttaquer.o jouer.o Placement_bateau.o Placement_obstacle.o afficher.o main.o
	$(CC) -o prog $^ $(FLAG)
	
Outil.o : $(SRCDIR)/grille/Outil.c $(INCDIR)/Outil.h
	$(CC) -c $^ $(FLAG)
	
Grille.o : $(SRCDIR)/grille/Grille.c 
	$(CC) -c $^ $(FLAG)

TorpilleurDeplacer.o : $(SRCDIR)/jouer/TorpilleurDeplacer.c $(INCDIR)/TorpilleurDeplacer.h $(INCDIR)/JouerStruct.h
	$(CC) -c $^ $(FLAG)

TorpilleurChoisir.o : $(SRCDIR)/jouer/TorpilleurChoisir.c $(INCDIR)/TorpilleurChoisir.h $(INCDIR)/JouerStruct.h
	$(CC) -c $^ $(FLAG)

TorpilleurAttaquer.o : $(SRCDIR)/jouer/TorpilleurAttaquer.c $(INCDIR)/TorpilleurAttaquer.h $(INCDIR)/JouerStruct.h
	$(CC) -c $^ $(FLAG)

jouer.o : $(SRCDIR)/jouer/jouer.c $(INCDIR)/JouerStruct.h
	$(CC) -c $^ $(FLAG)

Placement_bateau.o: $(SRCDIR)/Placer/Placement_bateau.c $(INCDIR)/Struct.h $(INCDIR)/Outil.h $(INCDIR)/Placement_bateau.h
	$(CC) -c $^ $(FLAG)

Placement_obstacle.o: $(SRCDIR)/Placer/Placement_obstacle.c $(INCDIR)/Struct.h $(INCDIR)/Placement_obstacle.h $(INCDIR)/Outil.h
	$(CC) -c $^ $(FLAG)

afficher.o : $(SRCDIR)/Affichage/afficher.c $(INCDIR)/afficher.h 
	$(CC) -c $^ $(FLAG)

main.o : $(SRCDIR)/main.c
	$(CC) -c $^ $(FLAG) 

clean : 
	rm -r -f *o
	rm -r -f *gch
	rm -r -f *~
