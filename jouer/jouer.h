#ifndef JOUER
#define JOUER

#include "JouerStruct.h"

void Jouer_init_temporaire();
void Jouer_Changer_Joueur(int *eJoueur);
void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur);
void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur);
void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur);
int Jouer_Gagnant(int eJoueur);
void Jouer_Partie(int N_Torpilleur, WINDOW *win);

#endif
