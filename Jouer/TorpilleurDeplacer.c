#include "include/Struct.h"
#include "include/Grille.h"
#include <stdio.h>
#include <stdlib.h>

t_plateau plateau;

void init_temporaire(){
	int eJoueur = 1;
	Grille_init();
	Grille_ecrire_bateau(5,3, eJoueur, Torpilleur);
	Grille_lire_matrice(eJoueur,plateau.grille1);
}

void Trouver_Torpilleur(int eJoueur){
	int i, j;
	for(i=0; i < N; i++){
		for(j=0; j < M; j++){
			if(plateau.grille1[i][j].bateau == Torpilleur){
				printf("%i %i", i, j);
			}
		}
	}
}