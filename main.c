#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"


int main(void){
	int taille=init_grille();
	Jouer_Partie(taille);
	return 1;
}
