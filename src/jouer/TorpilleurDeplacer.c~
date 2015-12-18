/**
* \file TorpilleurDeplacer.c
* \brief fichier qui contient l'ensemble des fonctions pour déplacer un torpilleur.
* \author BOUVET Remi
* \version 1.0
*/

#include "TorpilleurDeplacer.h"

/**
* \fn int Jouer_Deplacement_Valide(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur)
* \brief Fonction qui permet de vérifier si le déplacement demande est valide en fonction des obstacles et des bordures de la grille
*
* \param numero joueur, direction, numero du torpilleur, coordonnes torpilleurs, nombre de torpilleurs
* \return Ne retourne rien
*
*/
int Jouer_Deplacement_Valide(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur){
	//Fonction qui permet de vérifier si le déplacement demande est valide en fonction des obstacles et des bordures de la grille
	int eTorpilleur;
	int eObstacle;
	int x = cTorpilleur[eNumero_Torpilleur].x, y = cTorpilleur[eNumero_Torpilleur].y;
	if(direction == Haut){
		x--;
	}
	if(direction == Bas){
		x++;
	}
	if(direction == Droite){
		y++;
	}
	if(direction == Gauche){
		y--;
	}
	if(direction == Aucune){
		return 1;
	}
	if( x < 0 || x >= N || y < 0 || y >= M){
		return 0;
	}
	Grille_lire_torpilleur(x, y, eJoueur, &eTorpilleur);
	Grille_lire_obstacle(x, y, eJoueur, &eObstacle);
	if(eObstacle || eTorpilleur){
		return 0;
	}
	return 1;
}

/**
* \fn void Jouer_Deplacer_Torpilleur(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur)
* \brief Fonction qui permet de mettre a jour les coordonne du torpilleur en fonction du déplacement demandé.
*
* \param numero joueur, direction , numero torpilleur, coordonnees torpilleurs, nombre de torpilleurs
* \return Ne retourne rien
*
*/
void Jouer_Deplacer_Torpilleur(int eJoueur, t_direction direction, int eNumero_Torpilleur, t_coordonnee cTorpilleur[], int N_Torpilleur){
	//Fonction qui permet de mettre a jour les coordonne du torpilleur en fonction du déplacement demandé.
	int x = 0, y = 0;
	if(direction == Haut){
		x = -1;
	}
	if(direction == Bas){
		x = +1;
	}
	if(direction == Droite){
		y = +1;
	}
	if(direction == Gauche){
		y = -1;
	}
	Grille_ecrire_torpilleur(cTorpilleur[eNumero_Torpilleur].x,cTorpilleur[eNumero_Torpilleur].y, eJoueur, Aucun_t);
	Grille_ecrire_torpilleur(cTorpilleur[eNumero_Torpilleur].x + x,cTorpilleur[eNumero_Torpilleur].y + y, eJoueur, Present);
	cTorpilleur[eNumero_Torpilleur].x = cTorpilleur[eNumero_Torpilleur].x + x;
	cTorpilleur[eNumero_Torpilleur].y = cTorpilleur[eNumero_Torpilleur].y + y;
}


/**
* \fn void Jouer_Choisir_Direction(t_direction *dDirection)
* \brief 
*
* \param pointeur sur direction choisi
* \return Ne retourne rien
*
*/
void Jouer_Choisir_Direction(t_direction *dDirection){
	int ech;
	int bValider = 0;
	printw("\nVeuillez selectionner la direction dans laquelle deplacer le Torpilleur (Haut, Bas, Gauche, Droite, Aucune = entree):");
	refresh();
	//torpilleur_selection_afficher(cTorpilleur[eNumero_Torpilleur].x, cTorpilleur[eNumero_Torpilleur].y, eJoueur);
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68: //FLECHE GAUCHE
				*dDirection = Gauche;
				bValider = 1;
				break;
			case 67: //FLECHE DROITE
				*dDirection = Droite;
				bValider = 1;
				break;
			case 65: //FLECHE HAUT
				*dDirection = Haut;
				bValider = 1;
				break;
			case 66: //FLECHE BAS
				*dDirection = Bas;
				bValider = 1;
				break;
			case 10: //TOUCHE ENTREE
				*dDirection = Aucune;
				bValider = 1;
				break;
		}
	}
}
