FLAG= -g -Wall -lmenu -lncurses
PREFIX=.
SRCDIR=$(PREFIX)/src
INCDIR=$(PREFIX)/include
BINDIR=$(PREFIX)/bin
CC=gcc
EXEC=bataillenavale
OBJ=$(SRCDIR)/grille/Grille.o $(SRCDIR)/grille/Outil.o $(SRCDIR)/jouer/TorpilleurDeplacer.o $(SRCDIR)/jouer/TorpilleurChoisir.o $(SRCDIR)/jouer/TorpilleurAttaquer.o $(SRCDIR)/jouer/jouer.o $(SRCDIR)/Placer/Placement_bateau.o $(SRCDIR)/Placer/Placement_obstacle.o $(SRCDIR)/Affichage/afficher.o $(SRCDIR)/main.o

$(EXEC) : $(OBJ)
	$(CC) -o $(BINDIR)/$(EXEC) $^ $(FLAG)

%.o: %.c $(INCDIR)
	$(CC) -o $@ -c $< $(FLAG)

main.o : $(SRCDIR)/main.c
	$(CC) -c $^ $(FLAG) 

clean : 
	rm -r -f $(SRCDIR)/grille/*.o
	rm -r -f $(SRCDIR)/*.o
	rm -r -f $(SRCDIR)/jouer/*.o
	rm -r -f $(SRCDIR)/Placer/*.o
	rm -r -f $(SRCDIR)/Affichage/*.o
	rm -r -f $(INCDIR)/*.gch
	rm -r -f *~
