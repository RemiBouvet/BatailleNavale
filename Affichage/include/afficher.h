#ifndef AFFICHER
#define AFFICHER
#include "../../grille/Struct.h"
#define N 10
#define M 10

void Grille_perso_afficher(int num_grille);
void Grille_masque_afficher(int num_grille);
void Portee_torpilleur_afficher(t_portee gPortee[N][M],int num_grille,int x, int y);
void torpilleur_selection_afficher(int x,int y, int num_grille);

#endif