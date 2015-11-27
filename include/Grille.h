#ifndef GRILLE
#define GRILLE
#define N 10
#define M 10
#include "Struct.h"
void Grille_lire_case(int i, int j, int num_grille,t_case ensemble[N][M]);
void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M]);
void Grille_lire_matrice(int num_grille,t_case Case[N][M]);
void Grille_ecrire_matrice(int num_grille,t_case Case[N][M]);
void Grille_lire_bateau(int i,int j, int num_grille,int resultat);
void Grille_lire_toucher(int i,int j, int num_grille,int resultat);
void Grille_lire_obstacle(int i,int j, int num_grille,int resultat);
void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix);
void Grille_ecrire_toucher(int i,int j, int num_grille,t_toucher choix);
void Grille_ecrire_obstacle(int i,int j, int num_grille,t_obstacle choix);

#endif
