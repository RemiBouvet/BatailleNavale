#include "include/Struct.h"
#include "include/Grille.h"
#include "TorpilleurDeplacer.h"
#include <stdio.h>
#include <stdlib.h>



int Jouer_Deplacement_Valide(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[N_Torpilleur]){
	int eBateau;
	int eObstacle;
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
	Grille_lire_bateau(cTorpilleur[eNumero_Torpilleur].x + x,cTorpilleur[eNumero_Torpilleur].y + y, eJoueur, &eBateau);
	Grille_lire_obstacle(cTorpilleur[eNumero_Torpilleur].x + x,cTorpilleur[eNumero_Torpilleur].y + y, eJoueur, &eObstacle);
	if(eBateau || eObstacle){
		return 0;
	}
	return 1;
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

void Jouer_Choisir_Direction(t_direction *dDirection){
	int eSaisie;
	printf("\nVeuillez selectionner la direction dans laquelle deplacer le Torpilleur (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
	scanf("%i", &eSaisie);
	while(eSaisie < 0 || eSaisie > 3){
		printf("\nNumero de direction incorrect, veuiller entrez un numero a nouveau (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
		scanf("%i", &eSaisie);
	}
	*dDirection = eSaisie;
}