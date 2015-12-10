#include "../grille/Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"
#include "../Placer/Placement_bateau.h"
#include "../Placer/Placement_obstacle.h"



int main(){
	Grille_init();
	//Placement_obstacle(1);
	//Placement_bateau(1,1);
	//Grille_masque_afficher(1);
	Grille_perso_afficher(1);
	return 0;
}