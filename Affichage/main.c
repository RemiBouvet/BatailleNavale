#include "Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"
#include "Placement_bateau.h"

t_case grille1[N][M];
t_case grille2[N][M];

t_plateau grille; //structure qui prend 2 grille

int main(){
	Grille_init();
	//placer_obstacle(1);
	Placer_bateau(1,1);
	//Grille_masque_afficher(1);
	Grille_perso_afficher(2);
	return 0;
}