#ifndef STRUCTURE
#define STRUCTURE

#define N 10
#define M 10
typedef enum{Aucun_b=0,Sous_Marin=3,Destroyer=4,Porte_Avion=5}t_bateau;
typedef enum{Aucun_o=0,Obstacle=1}t_obstacle;
typedef enum{Non=0,Oui=1}t_toucher;
typedef enum{Aucun_t=0,Present=1}t_torpilleur;

typedef struct {t_bateau bateau;t_obstacle obstacle;t_toucher toucher;t_torpilleur torpilleur;}t_case;

typedef struct{t_case grille1[N][M];t_case grille2[N][M];}t_plateau;

#endif
