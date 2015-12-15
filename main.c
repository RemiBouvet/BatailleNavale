#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"
#include <curses.h>
#include <menu.h>
#define WIDTH 50
#define HEIGHT 200
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


int main(void){
	WINDOW *win;
	initscr();
	clear();
	noecho();
	cbreak();	//Line buffering disabled. pass on everything 
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	
	refresh();
	printw("*************************************************************************************************************\n");
	printw("******************************** Bienvenue sur le jeu de la Bataille Navale *********************************\n");
	printw("*************************************************************************************************************\n");
	int nb_torpilleur=Commencer_jeu_placement_bateau();
	Jouer_Partie(nb_torpilleur, win);
	endwin();
	return 1;
}

