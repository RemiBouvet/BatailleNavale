#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"
#include "Placer/client.h"
#include "Placer/serveur.h"
#include "grille/Socket.h"
#include "grille/Outil.h"
#define WIDTH 30
#define HEIGHT 10

int eClient=0,eServeur=0;

extern SOCKET sock;
int main(void){
	char Buffer[1024];
      	strcpy(Buffer,"Coucou");
	int cb;

	WINDOW *win;
	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	refresh();
	printw("*************************************************************************************************************\n");
	printw("******************************* Bienvenue sur le jeu de la Bataille Navale ++********************************\n");
	printw("*************************************************************************************************************\n");
	int taille=init_grille();
	clear();
	
	if(eServeur == 0 && eClient == 0){
		// en local ...			
	}
	//si je suis serveur
	else if(eServeur == 1){

		serveur();

		 // si je suis client
		 cb=send(sock,Buffer, strlen(Buffer),0);
		 if (cb==SOCKET_ERROR){
      			printw("\nDesole, je n'ai pas envoyer les donnees du a l'erreur :");
		}else{
     			 printw("\nsend        : OK\n");
		}
		clear();	
		
	}
	else if(eClient == 1){
						clear();
		client();
		clear();
		printw("\nDesole, je n'ai pas recu de donnee"); 
		refresh();
		cb=recv(sock,Buffer,sizeof(Buffer),0);
		if (cb==SOCKET_ERROR){printw("\nDesole, je n'ai pas recu de donnee"); refresh();}
		else
    		 {
    		 	clear();
		      Buffer[cb]=0; // Permet de fermer le tableau après le contenu des data, car la fonction recv ne le fait pas
		      printw("\nVoici les donnees : %s",Buffer);
		      refresh();
     		 }
     		 refresh();
     		 
	}
	
	//Jouer_Partie(taille, win);
	endwin();
	return 1;
}
