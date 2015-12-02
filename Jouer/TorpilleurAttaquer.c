#include "include/Struct.h"
#include "include/Grille.h"
#include "TorpilleurAttaquer.h"
#include <stdio.h>
#include <stdlib.h>

void Jouer_Calculer_Portee(int eJoueurAdverse, t_coordonnee cTorpilleur[N_Torpilleur], int eNumero_Torpilleur,t_portee gPortee[N][M]){
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
		for(j = y - 1; j < y +2; j++){
			Grille_lire_obstacle(i, j, eJoueurAdverse, &eObstacle);
			Grille_lire_toucher(i, j, eJoueurAdverse, &eToucher);
			if(eObstacle == 0 && eToucher == 0){
				gPortee[i][j] = Portee;
			}
		}
	}
}

void Jouer_Afficher_Portee(t_portee gPortee[N][M]){
	printf("\n");
	int i, j;	
	for(i = 0; i < N; i++){
		printf("\n");
		for(j = 0; j < M; j++){
				printf("%i ", gPortee[i][j]);
		}
	}
	printf("\n");
}

int Jouer_Attaque_Possible(t_portee gPortee[N][M]){
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


void Jouer_Deplacer_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur){
	int eSaisie;
	t_direction dDirection;
	printf("\nVeuillez selectionner la direction dans laquelle deplacer le curseur (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
	scanf("%i", &eSaisie);
	while(eSaisie < 0 || eSaisie > 3){
		printf("\nNumero de direction incorrect, veuiller entrez un numero a nouveau (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
		scanf("%i", &eSaisie);
	}
	int x = cCurseur->x, y = cCurseur->y;
	dDirection = eSaisie;
	if(dDirection == Haut){
		x--;
		printf("%i", x);
		while(gPortee[x][y] == Hors_Portee && x > 0){
			x--;
		}
	}
	if(dDirection == Bas){
		x++;
		while(gPortee[x][y] == Hors_Portee && x < N){
			x++;
		}
	}
	if(dDirection == Droite){
		y++;
		while(gPortee[x][y] == Hors_Portee && y < M){
			y++;
		}
	}
	if(dDirection == Gauche){
		y--;
		while(gPortee[x][y] == Hors_Portee && y > 0){
			y--;
		}
	}
	if(gPortee[x][y] == Portee){
		cCurseur->x = x;
		cCurseur->y = y;
	}
}
