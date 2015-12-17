#ifndef TORPILLEUR_ATTAQUER
#define TORPILLEUR_ATTAQUER

#include "JouerStruct.h"

void Jouer_Calculer_Portee(int eJoueurAdverse, t_coordonnee cTorpilleur[], int eNumero_Torpilleur,t_portee gPortee[N][M], int N_Torpilleur, int Taille_Portee);
void Jouer_Afficher_Portee(t_portee gPortee[N][M]);
int Jouer_Attaque_Possible(t_portee gPortee[N][M]);
void Jouer_Init_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur);
void Jouer_Deplacer_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur);
void Jouer_Choisir_Attaque(int eJoueur, int eNumero_Torpilleur, t_portee gPortee[N][M], t_coordonnee *cCurseur,int N_Torpilleur);

#endif
