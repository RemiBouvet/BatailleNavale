#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"
#include "Placer/client.h"
#include "Placer/serveur.h"
#define WIDTH 30
#define HEIGHT 10

int main(void){
	WINDOW *win;
	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	refresh();
	printw("*************************************************************************************************************\n");
	printw("******************************** Bienvenue sur le jeu de la Bataille Navale *********************************\n");
	printw("*************************************************************************************************************\n");
	int taille=init_grille();
	serveur();
	client();
	Jouer_Partie(taille, win);
	endwin();
	return 1;
}
