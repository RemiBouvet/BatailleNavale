#include "../grille/Grille.h"
#include "TorpilleurDeplacer.h"
#include "TorpilleurChoisir.h"
#include "TorpilleurAttaquer.h"
#include "../Affichage/include/afficher.h"
#include <stdio.h>
#include <stdlib.h>

void Jouer_init_temporaire(){
	int eJoueur = 1;
	Grille_init();
	Grille_ecrire_torpilleur(0,0, eJoueur, Present);
	Grille_ecrire_torpilleur(7,7, eJoueur, Present);
	Grille_ecrire_bateau(0,0, 2, 3);
	Grille_ecrire_obstacle(7,6, eJoueur, Oui);
	Grille_ecrire_obstacle(5,5, 2, Oui);
}

void Jouer_Changer_Joueur(int *eJoueur){
	//Fonction qui permet de changer de joueur
	if(*eJoueur == 1){
		*eJoueur = 2;
	}
	else {
		*eJoueur = 1;
	}
}

void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur){
	//Fonction qui gère le fait de trouver et de choisir le torpilleur a jouer
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur, N_Torpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur, N_Torpilleur);
	Jouer_Selectionner_Torpilleur(peNumero_Torpilleur, N_Torpilleur);
	Jouer_Afficher_Torpilleur_Selectionne(*peNumero_Torpilleur);
}

void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur){
	//Fonction qui permet de gérer le deplacement du torpilleur
	t_direction dDirection;
	int bValide = 0;
	while(!bValide){
		Jouer_Choisir_Direction(&dDirection);
		bValide = Jouer_Deplacement_Valide(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
		if(!bValide){
			printw("\nDirection invalide (Presence d'un torpilleur ou d'un obstacle ou hors carte)");
			refresh();
		}
	}
	Jouer_Deplacer_Torpilleur(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur, N_Torpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur, N_Torpilleur);
}

void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur){
	//Fonction qui permet de gérer l'attaque du torpilleur
	t_portee gPortee[N][M];
	t_coordonnee cCurseur;
	int bAttaque_Possible;
	int eJoueurAdverse = eJoueur;
	Jouer_Changer_Joueur(&eJoueurAdverse);
	
	Jouer_Calculer_Portee(eJoueur, pcTorpilleur, *peNumero_Torpilleur, gPortee, N_Torpilleur); 
	Jouer_Afficher_Portee(gPortee);
	bAttaque_Possible = Jouer_Attaque_Possible(gPortee);
	if(bAttaque_Possible){
		Jouer_Choisir_Attaque(gPortee, &cCurseur, N_Torpilleur);
		Grille_ecrire_toucher(cCurseur.x,cCurseur.y, eJoueurAdverse, Oui);
		
	}
	else{
		printw("\nAttaque impossible HAHAHAHAHAH");
		refresh();
	}
}

int Jouer_Gagnant(int eJoueur){
	//Fonction qui permet de déterminer si le joueur adverse a perdu à la fin du tour
	Jouer_Changer_Joueur(&eJoueur);
	int eBateau, eToucher;
	int bGagnant = 1;
	int i, j;
	for(i=0; i < N; i++){
		for(j=0; j < M; j++){
			Grille_lire_bateau(i,j, eJoueur,&eBateau);
			Grille_lire_toucher(i,j, eJoueur,&eToucher);
			if(eBateau != Aucun_b && eToucher == Non){
				bGagnant = 0;
			}
		}
	}
	return bGagnant;
}


void Jouer_Partie(int N_Torpilleur){
	//Fonction qui définie la routine de la Partie
	int eJoueur = 0;

	t_coordonnee* cTorpilleur = malloc(N_Torpilleur * sizeof(t_coordonnee)); // tableau de n entiers
	int eNumero_Torpilleur;
	int bGagnant = 0;
	
	while(!bGagnant){
		Grille_masque_afficher(eJoueur);
		Jouer_Changer_Joueur(&eJoueur);
		Grille_perso_afficher(eJoueur);
		Jouer_Choisir(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur);
		Jouer_Deplacer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur);
		Jouer_Attaquer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur);
		bGagnant = Jouer_Gagnant(eJoueur);
	}
	printw("\nLe joueur %i a gagne !", eJoueur);
	refresh();
}

/*int main(){
	Jouer_init_temporaire(); //Temporaire

	Jouer_Partie();
	printw("\n");
	
	return 1;
}*/
