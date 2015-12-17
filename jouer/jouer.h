#ifndef JOUER
#define JOUER

#include "JouerStruct.h"

void Jouer_init_temporaire();
void Jouer_Changer_Joueur(int *eJoueur);
void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur);
void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, int N_Deplacement);
void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int Taille_Portee);
int Jouer_Gagnant(int eJoueur);
void Jouer_Partie(int eJoueur, int N_Torpilleur, int N_Deplacement, int Taille_Portee, FILE *fic1);
void Jouer_Init_Torpilleur(int *N_Torpilleur, int *N_Deplacement, int *Taille_Portee);
void Jouer_Quitter_Continuer(int *bQuitter, FILE *fic1, int eJoueur, int N_Torpilleur, int N_Deplacement, int Taille_Portee);

#endif
