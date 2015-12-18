/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \file TorpilleurChoisir.c
* \brief fichier qui contient l'ensemble des fonctions pour choisir son torpilleur.
* \author BOUVET Remi
* \version 1.0
*/

#include "TorpilleurChoisir.h"


/**
* \fn void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[],int N_Torpilleur)
* \brief Fonction qui permet de trouver tous les torpilleurs du joueur et les stockes dans le tableau de coordonne cBateau
*
* \param le numero de joueur, coordonnees des bateaux, nombre de torpilleurs
* \return Ne retourne rien
*
*/
void Jouer_Trouver_Torpilleur(int eJoueur, t_coordonnee cBateau[],int N_Torpilleur){
	//Fonction qui permet de trouver tous les torpilleurs du joueur et les stockes dans le tableau de coordonne cBateau
	int i, j;
	int n = 0;
	int eResultat;
	for(i=0; i < N; i++){
		for(j=0; j < M; j++){
			Grille_lire_torpilleur(i,j, eJoueur,&eResultat);
			if(eResultat == Present){
				cBateau[n].x = i;
				cBateau[n].y = j;
				n++;
			}
		}
	}
}

/**
* \fn void Jouer_Selectionner_Torpilleur(int eJoueur, t_coordonnee cTorpilleur[], int *peNumero_Torpilleur, int N_Torpilleur)
* \brief Fonction qui permet de selectionner un torpilleur
*
* \param numero du joueur, les coordonnees des torpilleurs, pointeur numero torpilleur, le nombre de torpilleur
* \return Ne retourne rien
*
*/
void Jouer_Selectionner_Torpilleur(int eJoueur, t_coordonnee cTorpilleur[], int *peNumero_Torpilleur, int N_Torpilleur){
	//Fonction qui permet de selectionner un torpilleur
	int ech;
	int eNumero_Torpilleur = 0; //Initialisation de la selection
	int bValider = 0;
	printw("\nVeuillez selectionner votre torpilleur a l'aide des fleches gauche et droite :");
	refresh();
	clear();
	torpilleur_selection_afficher(cTorpilleur[eNumero_Torpilleur].x, cTorpilleur[eNumero_Torpilleur].y, eJoueur);
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68: //Décrementer la selection
				if(eNumero_Torpilleur >= 1)
					eNumero_Torpilleur--;
				clear();
				torpilleur_selection_afficher(cTorpilleur[eNumero_Torpilleur].x, cTorpilleur[eNumero_Torpilleur].y, eJoueur);
				break;
			case 67: //Incrémenter la selection
				if(eNumero_Torpilleur < N_Torpilleur - 1)
					eNumero_Torpilleur++;
				clear();
				torpilleur_selection_afficher(cTorpilleur[eNumero_Torpilleur].x, cTorpilleur[eNumero_Torpilleur].y, eJoueur);
				break;
			case 10:
				*peNumero_Torpilleur = eNumero_Torpilleur;
				bValider = 1;
				break;
		}
	}
}