#ifndef PLACEMENT_BATEAU
#define PLACEMENT_BATEAU

#include "../grille/Outil.h"
#include "../grille/Grille.h"
#include "../grille/Struct.h"
#include "Placement_obstacle.h"
#define nb_bateau 4
#define N_Torpilleur 2

t_case grille[N][M];

int bStringtonum(char *v,int *res);
int verif_presence(t_bateau bateau,int i,int j,int choix_sens,int num_grille);
int Assez_de_place(t_bateau bateau, int i,int j,int choix_sens,int num_grille);
void Placer_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens);
void Enlever_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens);
void Enlever_grillebateau2(int num_grille);
void Placer_bateau_auto(int num_grille,int nb_torpilleur);
void Placer_bateau_manuelle(int num_grille,int nb_torpilleur);
int init_grille();
#endif
