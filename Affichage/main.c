#include "Grille.h"
#include "Struct.h"
#include "Outil.h"
#include "afficher.h"

t_case grille1[N][M];
t_case grille2[N][M];

t_plateau grille; //structure qui prend 2 grille

int main(){
	Grille_init();
	t_case test[N][M];
	Grille_afficher(1,test);
	return 0;
}