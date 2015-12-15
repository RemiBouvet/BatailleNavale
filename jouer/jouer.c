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

void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, WINDOW *win){
	//Fonction qui gère le fait de trouver et de choisir le torpilleur a jouer
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur, N_Torpilleur);
	Jouer_Selectionner_Torpilleur(eJoueur,pcTorpilleur,peNumero_Torpilleur, N_Torpilleur);
}

void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, WINDOW *win){
	//Fonction qui permet de gérer le deplacement du torpilleur
	t_direction dDirection;
	int bValide = 0;
	while(bValide == 0){
		clear();
		torpilleur_selection_afficher(pcTorpilleur[*peNumero_Torpilleur].x, pcTorpilleur[*peNumero_Torpilleur].y, eJoueur);
		Jouer_Choisir_Direction(&dDirection);
		bValide = Jouer_Deplacement_Valide(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
		if(!bValide){
			printw("\nDirection invalide (Presence d'un torpilleur ou d'un obstacle ou hors carte)");
			refresh();
		}
	}
	Jouer_Deplacer_Torpilleur(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur, N_Torpilleur);
}

void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, WINDOW *win){
	//Fonction qui permet de gérer l'attaque du torpilleur
	t_portee gPortee[N][M];
	t_coordonnee cCurseur;
	cCurseur.x = pcTorpilleur[*peNumero_Torpilleur].x;
	cCurseur.y = pcTorpilleur[*peNumero_Torpilleur].y;

	int bAttaque_Possible;
	int eJoueurAdverse = eJoueur;
	Jouer_Changer_Joueur(&eJoueurAdverse);
	
	Jouer_Calculer_Portee(eJoueurAdverse, pcTorpilleur, *peNumero_Torpilleur, gPortee, N_Torpilleur);
	Jouer_Init_Curseur(gPortee,&cCurseur);
	bAttaque_Possible = Jouer_Attaque_Possible(gPortee);
	if(bAttaque_Possible){
		clear();
		Portee_torpilleur_afficher(gPortee, eJoueur, cCurseur.x, cCurseur.y);
		Jouer_Choisir_Attaque(eJoueur, *peNumero_Torpilleur, gPortee, &cCurseur, N_Torpilleur);
		Grille_ecrire_toucher(cCurseur.x,cCurseur.y, eJoueurAdverse, Oui);
		
	}
	else{
		printw("\nDesole aucune attaque n'est possible, appuyez sur une touche pour continuer.");
		refresh();
		getch();
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


void Jouer_Quitter_Continuer(int *bQuitter){
	int ech;
	int bContinuer = 0;
	while(*bQuitter == 0 && bContinuer == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 32:
				bContinuer = 1;
				break;
			case 27:
				printw("\nEchap");
				refresh();
				*bQuitter = 1;
				break;
		}
	}
}

void Jouer_Partie(int N_Torpilleur, WINDOW *win){
	//Fonction qui définie la routine de la Partie
	int eJoueur = 1;

	t_coordonnee* cTorpilleur = malloc(N_Torpilleur * sizeof(t_coordonnee)); // tableau de n entiers
	int eNumero_Torpilleur;
	int bGagnant = 0;
	int bQuitter = 0;

	while(bGagnant == 0 && bQuitter == 0){
		clear();
		Jouer_Choisir(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur, win);
		Jouer_Deplacer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur, win);
		Jouer_Attaquer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur, win);
		bGagnant = Jouer_Gagnant(eJoueur);
		clear();
		Jouer_Changer_Joueur(&eJoueur);
		printw("\nJoueur %i a vous de jouer !\nAppuyez sur espace pour continuer ou echap pour quitter la partie", eJoueur);
		Jouer_Quitter_Continuer(&bQuitter);
	}
	if(bGagnant){
		printw("\nLe joueur %i a gagne !\n Appuyez sur une touche pour continuer !", eJoueur);
		refresh();
		echo();
	}
}