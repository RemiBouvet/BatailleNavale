#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"

#define WIDTH 200
#define HEIGHT 200

int main(void){
	WINDOW *win;

	initscr();
	clear();
	echo();
	cbreak();	/* Line buffering disabled. pass on everything */
		
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	refresh();
	int taille=init_grille();
	Jouer_Partie(taille);
	endwin();
	return 1;
}