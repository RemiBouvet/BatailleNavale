#include "include/Grille.h"
#include "TorpilleurDeplacer.h"
#include "TorpilleurChoisir.h"
#include <stdio.h>
#include <stdlib.h>


void Jouer_init_temporaire(int *eJoueur){
	*eJoueur = 1;
	Grille_init();
	Grille_ecrire_bateau(5,5, *eJoueur, Torpilleur);
	Grille_ecrire_bateau(7,7, *eJoueur, Torpilleur);
	Grille_ecrire_obstacle(7,6, *eJoueur, Oui);
}

void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur){
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur);
	Jouer_Selectionner_Torpilleur(peNumero_Torpilleur);
	Jouer_Afficher_Torpilleur_Selectionne(*peNumero_Torpilleur);
}

void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur ){
	t_direction dDirection;
	int bValide = 0;
	while(!bValide){
		Jouer_Choisir_Direction(&dDirection);
		bValide = Jouer_Deplacement_Valide(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur);
		//printf("\n Valide =%i", bValide);
		if(!bValide){
			printf("\nDirection invalide (Presence d'un bateau ou d'un obstacle)");
		}
	}
	Jouer_Deplacer_Torpilleur(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur);
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur);
}

int main(){
	int eJoueur;	//Temporaire
	Jouer_init_temporaire(&eJoueur);

	t_coordonnee cTorpilleur[N_Torpilleur];
	int eNumero_Torpilleur;


	Jouer_Choisir(eJoueur, cTorpilleur, &eNumero_Torpilleur);
	Jouer_Deplacer(eJoueur, cTorpilleur, &eNumero_Torpilleur);
	
	return 1;
}