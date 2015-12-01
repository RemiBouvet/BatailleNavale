#ifndef TORPILLEUR_DEPLACER
#define TORPILLEUR_DEPLACER

#define N_Torpilleur 2

typedef struct {int x;int y;} t_coordonnee;
typedef enum{Haut, Bas, Gauche, Droite}t_direction;

void Jouer_init_temporaire();
void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[N_Torpilleur]);
void Jouer_Afficher_Torpilleur(t_coordonnee cTorpilleur[N_Torpilleur]);
void Jouer_Selectionner_Torpilleur(int *peNumero_Torpilleur);
void Jouer_Afficher_Torpilleur_Selectionne(int eNumero_Torpilleur);
void Jouer_Deplacer_Torpilleur(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[N_Torpilleur]);

#endif