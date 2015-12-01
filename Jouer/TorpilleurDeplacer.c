#include "include/Struct.h"
#include "include/Grille.h"
#include "TorpilleurDeplacer.h"
#include <stdio.h>
#include <stdlib.h>



void Jouer_init_temporaire(){
	int eJoueur = 1;
	Grille_init();
	Grille_ecrire_bateau(5,3, eJoueur, Torpilleur);
	Grille_ecrire_bateau(7,7, eJoueur, Torpilleur);
}

void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[N_Torpilleur]){
	int i, j;
	int n = 0;
	int eResultat;
	for(i=0; i < N; i++){
		for(j=0; j < M; j++){
			Grille_lire_bateau(i,j, eJoueur,&eResultat);
			if(eResultat == Torpilleur){
				cBateau[n].x = i;
				cBateau[n].y = j;
				n++;
			}
		}
	}
}

void Jouer_Afficher_Torpilleur(t_coordonnee cTorpilleur[N_Torpilleur]){
	int i;
	for(i=0; i < N_Torpilleur; i++){
		printf("\nTorpilleur %i : x = %i y = %i", i+1, cTorpilleur[i].x, cTorpilleur[i].y);
	}
}

void Jouer_Selectionner_Torpilleur(int *peNumero_Torpilleur){
	int eSaisie;
	printf("\nVeuillez selectionner votre torpilleur :");
	scanf("%i", &eSaisie);
	while(eSaisie < 1 || eSaisie > N_Torpilleur){
		printf("\nNumero de torpilleur incorrect, veuiller entrez un numero a nouveau :");
		scanf("%i", &eSaisie);
	}
	*peNumero_Torpilleur = eSaisie - 1;
}

void Jouer_Afficher_Torpilleur_Selectionne(int eNumero_Torpilleur){
	printf("\nLe Torpilleur selectionne est le numero %i", eNumero_Torpilleur + 1);
}

void Jouer_Deplacer_Torpilleur(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[N_Torpilleur]){
	int x = 0, y = 0;
	if(direction == Haut){
		y = -1;
	}
	if(direction == Bas){
		y = +1;
	}
	if(direction == Droite){
		x = +1;
	}
	if(direction == Gauche){
		x = -1;
	}
	Grille_ecrire_bateau(cTorpilleur[eNumero_Torpilleur].x,cTorpilleur[eNumero_Torpilleur].y, eJoueur, Aucun_b);
	Grille_ecrire_bateau(cTorpilleur[eNumero_Torpilleur].x + x,cTorpilleur[eNumero_Torpilleur].y + y, eJoueur, Torpilleur);
}