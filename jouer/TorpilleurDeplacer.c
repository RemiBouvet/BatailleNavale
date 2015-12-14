#include "../grille/Struct.h"
#include "../grille/Grille.h"
#include "TorpilleurDeplacer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
	if( x < 0 || x > N || y < 0 || y > M){
		return 0;
	}
	Grille_lire_torpilleur(x, y, eJoueur, &eTorpilleur);
	Grille_lire_obstacle(x, y, eJoueur, &eObstacle);
	if(eObstacle || eTorpilleur){
		return 0;
	}
	return 1;
}

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
}


int Jouer_Deplacer_Stringtonum(char *v,int *res){
    int bNum=1;
    int i;
    *res=0;
    for(i=0;i<strlen(v);i++)
        bNum=bNum && isdigit(v[i]);
    if(bNum==1){
        *res=atoi(v);
    }
    return bNum;
}

void Jouer_Choisir_Direction(t_direction *dDirection){
	//Fonction qui permet de saisir une direction manuellement
	char sSaisie[20];
	int eSaisie;
	int bCoordonneValide = 0;
	printw("\nVeuillez selectionner la direction dans laquelle deplacer le Torpilleur (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
    refresh();
        scanw("%s",sSaisie);
	while(!bCoordonneValide){
		if(Jouer_Deplacer_Stringtonum(sSaisie,&eSaisie) != 0){
			if(eSaisie >= 0 && eSaisie <= 3){
				*dDirection = eSaisie;
				bCoordonneValide = 1;
			}
		}
		if(!bCoordonneValide){
			printw("\nNumero de direction incorrect, veuiller entrez un numero a nouveau (Haut = 0, Bas = 1, Gauche = 2, Droite = 3):");
      		refresh();
      			scanw("%s",sSaisie);
		}
	}
}
