#include "../grille/Struct.h"
#include "../grille/Grille.h"
#include "TorpilleurChoisir.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>


void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[],int N_Torpilleur){
	//Fonction qui permet de trouver tous les torpilleurs du joueur et les stockes dans le tableau de coordonne cBateau
	int i, j;
	int n = 0;
	int eResultat;
	for(i=0; i < N; i++){
		for(j=0; j < M; j++){
			Grille_lire_torpilleur(i,j, eJoueur,&eResultat);
			if(eResultat == Present){
				cBateau[n].x = i;
				cBateau[n].y = j;
				n++;
			}
		}
	}
}

void Jouer_Afficher_Torpilleur(t_coordonnee cTorpilleur[], int N_Torpilleur){
	int i;
	for(i=0; i < N_Torpilleur; i++){
		printw("\nTorpilleur %i : x = %i y = %i", i+1, cTorpilleur[i].x, cTorpilleur[i].y);
		refresh();
	}
}

int Jouer_Choisir_Stringtonum(char *v,int *res){
    int bNum=1;
    int i;
    *res=0;
    for(i=0;i<strlen(v);i++)
        bNum=bNum && isdigit(v[i]);
    if(bNum==1){
        *res=atoi(v);
    }
    return bNum;
}

/*void Jouer_Selectionner_Torpilleur(int *peNumero_Torpilleur, int N_Torpilleur){
	//Fonction qui permet de selectionner a jouer
	char sSaisie[20];
	int eSaisie;
	int bCoordonneValide = 0;
	printw("\nVeuillez selectionner votre torpilleur :");
	refresh();
        scanw("%s",sSaisie);
	while(!bCoordonneValide){
		if(Jouer_Choisir_Stringtonum(sSaisie,&eSaisie) != 0){
			if(eSaisie > 0 && eSaisie <= N_Torpilleur){
				*peNumero_Torpilleur = eSaisie - 1;
				bCoordonneValide = 1;
			}
		}
		if(!bCoordonneValide){
			printw("\nNumero de torpilleur incorrect, veuiller entrez un numero a nouveau :");
			refresh();
      			scanw("%s",sSaisie);
		}
	}
}*/

void Jouer_Afficher_Torpilleur_Selectionne(int eNumero_Torpilleur){
	printw("\nLe Torpilleur selectionne est le numero %i", eNumero_Torpilleur + 1);
	refresh();
}

void Jouer_Selectionner_Torpilleur(int *peNumero_Torpilleur, int N_Torpilleur){
	int ech;
	int eNumero_Torpilleur = 0;
	int bValider = 0;

	while(!bValider){
		ech = getch();
		switch(ech){
			case KEY_LEFT:
				if(eNumero_Torpilleur >= 1)
					eNumero_Torpilleur--;
				Jouer_Afficher_Torpilleur_Selectionne(eNumero_Torpilleur);
				break;
			case KEY_RIGHT:
				if(eNumero_Torpilleur <= N_Torpilleur - 1)
					eNumero_Torpilleur++;
				Jouer_Afficher_Torpilleur_Selectionne(eNumero_Torpilleur);
				break;
			case KEY_ENTER:
				*peNumero_Torpilleur = eNumero_Torpilleur;
				bValider = 1;
				break;
		}
	}


}