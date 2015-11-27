CC=gcc
FLAG=
SRC = (wildcard *.c) include/Grille.c
OBJ =
INCLUDE=include/

exec: jouer.o  $(INCLUDE)Outil.o TorpilleurDeplacer.o
	$(CC) -o $@ $^ $(FLAG)

TorpilleurDeplacer.o: TorpilleurDeplacer.c TorpilleurDeplacer.h $(INCLUDE)Struct.h $(INCLUDE)Grille.h 
	$(CC) -c $< $(FLAG)

Outil.o: $(INCLUDE)Outil.c $(INCLUDE)Outil.h $(INCLUDE)Struct.h $(INCLUDE)Grille.h 
	$(CC) -c $< $(FLAG)

jouer.o: jouer.c TorpilleurDeplacer.c $(INCLUDE)Grille.c $(INCLUDE)Outil.c $(INCLUDE)Grille.h $(INCLUDE)Struct.h
	$(CC) -c $< $(FLAG)

clean:
	rm -rf *.o
