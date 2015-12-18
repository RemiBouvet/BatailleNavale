/**
* \file TorpilleurAttaquer.c
* \brief fichier qui contient l'ensemble des fonctions pour attaquer avec un torpilleur.
* \author BOUVET Remi
* \version 1.0
*/

#include "TorpilleurAttaquer.h"

/**
* \fn void Jouer_Calculer_Portee(int eJoueurAdverse, t_coordonnee cTorpilleur[], int eNumero_Torpilleur,t_portee gPortee[N][M], int N_Torpilleur, int Taille_Portee)
* \brief Fonction qui permet de stocker dans la grille gPortee[N][M] les cases où le torpilleur selectionne a la possibilite d'attaquer
*
* \param 
* \return Ne retourne rien
*
*/
void Jouer_Calculer_Portee(int eJoueurAdverse, t_coordonnee cTorpilleur[], int eNumero_Torpilleur,t_portee gPortee[N][M], int N_Torpilleur, int Taille_Portee){
	//Fonction qui permet de calculer et de stocker dans la grille gPortee[N][M] les cases où le torpilleur selectionne a la possibilite d'attaquer
	int eObstacle;
	int eToucher;
	int i, j;
	int x = cTorpilleur[eNumero_Torpilleur].x;
	int y = cTorpilleur[eNumero_Torpilleur].y;

	//Initialisation de la grille gPortee
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			gPortee[i][j] = Hors_Portee;
		}
	}


	for(i = x - (1 + Taille_Portee); i < x + (2 + Taille_Portee); i++){ //On cherche autour du torpilleur selectionné
		if(i >= 0 && i < N){											//On vérifie qu'on reste dans la grille
			for(j = y - (1 + Taille_Portee); j < y + (2 + Taille_Portee); j++){
				if(j >= 0 && j < M){									//On vérifie qu'on reste dans la grille
					Grille_lire_obstacle(i, j, eJoueurAdverse, &eObstacle);
					Grille_lire_toucher(i, j, eJoueurAdverse, &eToucher);
					if(eObstacle == Aucun_o && eToucher == Non){	//Si il n'y a pas d'obstacle ou si la case n'a pas déjà été touchée alors on peut attquer
						gPortee[i][j] = Portee;
					}
				}
			}
		}
	}
}

/**
* \fn int Jouer_Attaque_Possible(t_portee gPortee[N][M])
* \brief Fonction qui permet de determiner si l'attaque est possible c'est à dire si le torpilleur a bien une case où il peut attaquer
*
* \param 
* \return 
*
*/
int Jouer_Attaque_Possible(t_portee gPortee[N][M]){
	//Fonction qui permet de determiner si l'attaque est possible c'est à dire si le torpilleur a bien une case où il peut attaquer
	int i, j;	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if(gPortee[i][j]){ //Si il y a bien une case Portee dans la grille gPortee on peut attaquer.
				return 1;
			}
		}
	}
	return 0;
}

/**
* \fn void Jouer_Init_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur)
* \brief Initialise le curseur
*
* \param 
* \return Ne retourne rien
*
*/
void Jouer_Init_Curseur(t_portee gPortee[N][M], t_coordonnee *cCurseur){
	//Initialise le curseur
	int i, j;
	int bPortee;
	if(gPortee[cCurseur->x][cCurseur->y] == Hors_Portee){ //Si le curseur est Hors_Portee alors on cherche en endroit ou il y a Portee.
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

/**
* \fn Jouer_Choisir_Attaque(int eJoueur, int eNumero_Torpilleur, t_portee gPortee[N][M], t_coordonnee *cCurseur,int N_Torpilleur)
* \brief Fonction qui permet de selectionner l'attaque du joueur
*
* \param 
* \return Ne retourne rien
*
*/
void Jouer_Choisir_Attaque(int eJoueur, int eNumero_Torpilleur, t_portee gPortee[N][M], t_coordonnee *cCurseur,int N_Torpilleur){
	//Fonction qui permet de selectionner l'attaque du joueur
	int ech;
	int bValider = 0;
	int x = cCurseur->x, y = cCurseur->y;
	printw("\nVeuillez selectionner votre torpilleur a l'aide des fleches haut, bas, gauche et droite :");
	refresh();
	clear();
	Portee_torpilleur_afficher(gPortee,eJoueur,cCurseur->x, cCurseur->y);
	refresh();
	while(bValider == 0){ //Tant qu'on ne valide pas le curseur
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68: //FLECHE GAUCHE
				y--;
				while(gPortee[x][y] == Hors_Portee && y > 0){//On va a gauche tant qu'on ne trouve pas une case valide, on s'arrête en fin de grille
					y--;
				}
				if(gPortee[x][y] == Hors_Portee){//Si la case n'est pas valide
					y = cCurseur->y - 1;		//On réinitialise à la ligne juste au-dessus de torpilleur
					x = 0;
					while(gPortee[x][y] == Hors_Portee && x <= N - 1){//On cherche une case valide sur toute la ligne
						x++;
					}
				}
				break;
			case 67: //FLECHE DROITE
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
			case 65: //FLECHE HAUT
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
			case 66: //FLECHE BAS
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
		if(gPortee[x][y] == Portee && x >= 0 && x < N && y >= 0 && y < M){ //On vérifie la validité du curseur
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




