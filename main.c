#include "jouer/jouer.h"

int main(void){
	Grille_init();
Placer_bateau_auto(1,1);
	Jouer_Partie();
	return 1;
}