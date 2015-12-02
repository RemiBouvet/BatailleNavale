#ifndef PLACER
#define PLACER
#include "Struct.h"
#define N 10
#define M 10

int bStringtonum(char *v,int *res);
void Placer_bateau(int num_grille,int nb_torpilleur);
int verif_presence(t_bateau bateau,int i,int j,int choix_sens,int num_grille);
int Assez_de_place(t_bateau bateau, int i,int j,int choix_sens,int num_grille);
void Placer_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens);

#endif