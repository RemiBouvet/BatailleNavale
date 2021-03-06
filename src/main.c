#include "../include/jouer.h"
#include "../include/Placement_bateau.h"
#include "../include/afficher.h"
#include <menu.h>
#define WIDTH 50
#define HEIGHT 200

int main(void){
	//Initialisation ncurses
	WINDOW *win;
	FILE*fic1=NULL;
	initscr();
	clear();
	noecho();
	cbreak();
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	int eJoueur = 1,bQuitter=0;
	char sChoixmenu[20];
	int eChoixmenu=0;
	int N_Deplacement, N_Torpilleur, Taille_Portee;
	refresh();
	printw("*************************************************************************************************************\n");
	printw("******************************** Bienvenue sur le jeu de la Bataille Navale *********************************\n");
	printw("*************************************************************************************************************\n");
	printw("\n\n\nMenu :\n\t1 : Nouvelle Partie\n\t2 : Charger\n\t3 : Quitter\n");
	refresh();
	while(bQuitter==0){
		do{
			printw("Choix : ");
			echo();
			scanw("%s",sChoixmenu);
			noecho();
		}while(!bStringtonum(sChoixmenu,&eChoixmenu) || eChoixmenu <1 || eChoixmenu >3); //Tant que on a pas un entier compris entre 1 et 2
		if(eChoixmenu==1){
			clear();
			Jouer_Init_Torpilleur(&N_Torpilleur,&N_Deplacement, &Taille_Portee);
			Commencer_jeu_placement_bateau(N_Torpilleur);
			Jouer_Partie(eJoueur, N_Torpilleur, N_Deplacement, Taille_Portee, fic1);
		}else if(eChoixmenu==2){
			fic1=fopen("sauvegarde","r");
			if(fic1!=NULL){
				Grille_Charger(fic1);
				fread(&eJoueur , sizeof(int) , 1 , fic1);
				fread(&N_Torpilleur , sizeof(int) , 1 , fic1);
				fread(&N_Deplacement , sizeof(int) , 1 , fic1);
				fread(&Taille_Portee , sizeof(int) , 1 , fic1);
				Jouer_Partie(eJoueur, N_Torpilleur, N_Deplacement, Taille_Portee, fic1);      
			}  
		}else if(eChoixmenu==3){
			endwin(); //Si le joueur veut quitter
			bQuitter=1;
		}
	}
	endwin();
	return 1;
}
