FLAG= -g -Wall

prog : Fonction_groupe.o afficher.o Outil.o main.o
	gcc -o prog $^ $(FLAG)
	
Outil.o : Outil.c Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
	
Fonction_groupe.o : Fonction_groupe.c 
	gcc -c Fonction_groupe.c $(FLAG)
	
afficher.o : afficher.c afficher.h 
	gcc -c afficher.c $(FLAG)
	
main.o : main.c 
	gcc -c main.c $(FLAG)
