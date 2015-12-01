#include "include/Grille.h"
#include "TorpilleurDeplacer.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	t_coordonnee cTorpilleur[N_Torpilleur];
	int eJoueur = 1;
	int eNumero_Torpilleur;
	Jouer_init_temporaire();
	Jouer_Trouver_Torpilleur(eJoueur, cTorpilleur);
	Jouer_Afficher_Torpilleur(cTorpilleur);
	Jouer_Selectionner_Torpilleur(&eNumero_Torpilleur);
	Jouer_Afficher_Torpilleur_Selectionne(eNumero_Torpilleur);
	t_direction direction;
	direction = Haut;
	Jouer_Deplacer_Torpilleur(eJoueur,direction,eNumero_Torpilleur, cTorpilleur);
	Jouer_Trouver_Torpilleur(eJoueur, cTorpilleur);
	Jouer_Afficher_Torpilleur(cTorpilleur);
	return 1;
}