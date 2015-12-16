#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"
#include <curses.h>
#include <menu.h>
#define WIDTH 50
#define HEIGHT 200

int main(void){
	WINDOW *win;
	char sChoixmenu[20];
	int nb_torpilleur=0,eChoixmenu=0;
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
	printw("\n\n\nMenu :\n\t1 : Jouer\n\t2: Quitter\n\n");
	refresh();
	do{
		printw("Choix : ");
		echo();
		scanw("%s",sChoixmenu);
		noecho();
	}while(!bStringtonum(sChoixmenu,&eChoixmenu) || eChoixmenu <1 || eChoixmenu >2); //Tant que on a pas un entier compris entre 1 et 2
	if(eChoixmenu==1){
		clear();
		nb_torpilleur=Commencer_jeu_placement_bateau();
		Jouer_Partie(nb_torpilleur, win);
	}else if(eChoixmenu==2)endwin(); //Si le joueur veut quitter
	endwin();
	return 1;
}

