#include "../grille/Struct.h"
#include "../grille/Grille.h"
#include "TorpilleurAttaquer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Jouer_Calculer_Portee(int eJoueurAdverse, t_coordonnee cTorpilleur[], int eNumero_Torpilleur,t_portee gPortee[N][M], int N_Torpilleur){
	//Fonction qui permet de stocker dans la grille gPortee[N][M] les cases où le torpilleur selectionne a la possibilite d'attaquer
	int eObstacle;
	int eToucher;
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			gPortee[i][j] = Hors_Portee;
		}
	}
	int x = cTorpilleur[eNumero_Torpilleur].x;
	int y = cTorpilleur[eNumero_Torpilleur].y;
	for(i = x - 1; i < x +2; i++){
		if(i >= 0 && i < N){
			for(j = y - 1; j < y +2; j++){
				if(j >= 0 && j < M){
					Grille_lire_obstacle(i, j, eJoueurAdverse, &eObstacle);
					Grille_lire_toucher(i, j, eJoueurAdverse, &eToucher);
					if(eObstacle == Aucun_o && eToucher == Non){
						gPortee[i][j] = Portee;
					}
				}
			}
		}
	}
}

void Jouer_Afficher_Portee(t_portee gPortee[N][M]){
	printw("\n");
	int i, j;	
	for(i = 0; i < N; i++){
		printw("\n");
		for(j = 0; j < M; j++){
				printw("%i ", gPortee[i][j]);
		}
	}
	printw("\n");
	refresh();
}

int Jouer_Attaque_Possible(t_portee gPortee[N][M]){
	//Fonction qui permmet de determiner si l'attaque est possible c'est à dire si le torpilleur a bien une case où il peut attaquer
	int i, j;	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if(gPortee[i][j]){
				return 1;
			}
		}
	}
	return 0;
}

void Jouer_Init_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur){
	int i, j;
	int bPortee;
	if(gPortee[cCurseur->x][cCurseur->y] == Hors_Portee){
		for(i = 0; i < N ; i++){
			for(j = 0; j < M; j++){
				bPortee = gPortee[i][j];
				if(bPortee){
					cCurseur->x = i;
					cCurseur->y = j;
				}
			}
		}
	}
}

void Jouer_Choisir_Attaque(int eJoueur, int eNumero_Torpilleur, t_portee gPortee[N][M], t_coordonnee *cCurseur,int N_Torpilleur){
	int ech;
	int bValider = 0;
	int x = cCurseur->x, y = cCurseur->y;
	printw("\nVeuillez selectionner votre torpilleur a l'aide des fleches haut, bas, gauche et droite :");
	refresh();
	clear();
	Portee_torpilleur_afficher(gPortee,eJoueur,cCurseur->x, cCurseur->y);
	refresh();
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68:
				y--;
				while(gPortee[x][y] == Hors_Portee && y > 0){
					y--;
				}
				if(gPortee[x][y] == Hors_Portee){
					y = cCurseur->y - 1;
					x = 0;
					while(gPortee[x][y] == Hors_Portee && x <= N - 1){
						x++;
					}
				}
				break;
			case 67:
				y++;
				while(gPortee[x][y] == Hors_Portee && y < M - 1){
					y++;
				}
				if(gPortee[x][y] == Hors_Portee){
					y = cCurseur->y + 1;
					x = 0;
					while(gPortee[x][y] == Hors_Portee && x <= N - 1){
						x++;
					}
				}
				break;
			case 65:
				x--;
				while(gPortee[x][y] == Hors_Portee && x > 0){
					x--;
				}
				if(gPortee[x][y] == Hors_Portee){
					x = cCurseur->x - 1;
					y = 0;
					while(gPortee[x][y] == Hors_Portee && y <= M - 1){
						y++;
					}
				}
				break;
			case 66:
				x++;
				while(gPortee[x][y] == Hors_Portee && x < N - 1){
					x++;
				}
				if(gPortee[x][y] == Hors_Portee){
					x = cCurseur->x + 1;
					y = 0;
					while(gPortee[x][y] == Hors_Portee && x <= M - 1){
						y++;
					}
				}
				break;
			case 10:
				bValider = 1;
				break;
		}
		if(gPortee[x][y] == Portee){
			cCurseur->x = x;
			cCurseur->y = y;
		}
		else{
			x = cCurseur->x;
			y = cCurseur->y;
		}
		clear();
		Portee_torpilleur_afficher(gPortee,eJoueur,cCurseur->x, cCurseur->y);
	}
}




