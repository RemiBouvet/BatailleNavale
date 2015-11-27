FLAG= -g -Wall

main : Fonction_groupe.o Outil.o
	gcc -o main Fonction_groupe.o Outil.o $(FLAG)
Outil.o : Outil.c Outil.h
	gcc -c Outil.c Outil.h $(FLAG)
Fonction_groupe.o : Fonction_groupe.c 
	gcc -c Fonction_groupe.c $(FLAG)
