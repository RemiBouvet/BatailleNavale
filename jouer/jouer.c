/**
* \file jouer.c
* \brief fichier qui contient l'ensemble des fonctions qui rélaisent l'affichage.
* \author BOUVET Remi
* \version 1.0
*/

#include "TorpilleurDeplacer.h"
#include "TorpilleurChoisir.h"
#include "TorpilleurAttaquer.h"
#include "JouerStruct.h"

void Jouer_Init_Torpilleur(int *N_Torpilleur, int *N_Deplacement, int *Taille_Portee){
	//Fonction qui permet d'initialiser le nombre de torpilleur, le nombre de déplacement par tour, la taille de la portée du torpilleur.
	int ech;
	int bValider = 0;

	//Initialisation des valeur
	*N_Torpilleur = 2;
	*N_Deplacement = 2;
	*Taille_Portee = 3;

	//Choix du nombre de torpilleur
	printw("\nConfiguration de la partie :\n");
	printw("\nVeuillez selectionner le nombre de torpilleur par joueur à l'aide des flèches , appuyez sur entree pour valider: %i torpilleur.", *N_Torpilleur);
	refresh();
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68:
				if(*N_Torpilleur > 1)
					*N_Torpilleur -= 1;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nVeuillez selectionner le nombre de torpilleur par joueur à l'aide des flèches , appuyez sur entree pour valider: %i torpilleur.", *N_Torpilleur);
				break;
			case 67:
				if(*N_Torpilleur < 5)
					*N_Torpilleur += 1;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nVeuillez selectionner le nombre de torpilleur par joueur à l'aide des flèches , appuyez sur entree pour valider: %i torpilleur.", *N_Torpilleur);
				break;
			case 10:
				bValider = 1;
				break;
		}
	}
	clear();

	//Choix du nombre de case de déplacement
	printw("\nConfiguration de la partie :\n");
	printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
	printw("\nVeuillez selectionner le nombre de case de deplacement par torpilleur à l'aide des flèches , appuyez sur entree pour valider: %i case de deplacement.", *N_Deplacement);
	refresh();
	bValider = 0;
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68:
				if(*N_Deplacement > 1)
					*N_Deplacement -= 1;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
				printw("\nVeuillez selectionner le nombre de case de deplacement par torpilleur à l'aide des flèches , appuyez sur entree pour valider: %i case de deplacement.", *N_Deplacement);
				break;
			case 67:
				if(*N_Deplacement < 8)
					*N_Deplacement += 1;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
				printw("\nVeuillez selectionner le nombre de case de deplacement par torpilleur à l'aide des flèches , appuyez sur entree pour valider: %i case de deplacement.", *N_Deplacement);
				break;
			case 10:
				bValider = 1;
				break;
		}
	}
	clear();

	//Choix de la taille de la portee
	printw("\nConfiguration de la partie :\n");
	printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
	printw("\nNombre de case de deplacement choisi : %i.", *N_Deplacement);
	printw("\nVeuillez selectionner la taille de la portee du torpilleur, appuyez sur entree pour valider : %ix%i", *Taille_Portee, *Taille_Portee);
	refresh();
	bValider = 0;
	while(bValider == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 68:
				*Taille_Portee = 3;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
				printw("\nNombre de case de deplacement choisi : %i.", *N_Deplacement);
				printw("\nVeuillez selectionner la taille de la portee du torpilleur, appuyez sur entree pour valider : %ix%i", *Taille_Portee, *Taille_Portee);
				break;
			case 67:
				*Taille_Portee = 5;
				clear();
				printw("\nConfiguration de la partie :\n");
				printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
				printw("\nNombre de case de deplacement choisi : %i.", *N_Deplacement);
				printw("\nVeuillez selectionner la taille de la portee du torpilleur, appuyez sur entree pour valider : %ix%i", *Taille_Portee, *Taille_Portee);
				break;
			case 10:
				bValider = 1;
				break;
		}
	}
	clear();
	printw("\nConfiguration de la partie :\n");
	printw("\nNombre de torpilleur choisi : %i.", *N_Torpilleur);
	printw("\nNombre de case de deplacement choisi : %i.", *N_Deplacement);
	printw("\nTaille de la portee choisie : %ix%i", *Taille_Portee, *Taille_Portee);
	//Formatage de la valeur de la Taille_Portee
	if(*Taille_Portee == 5){
		*Taille_Portee = 1;
	}
	else{
		*Taille_Portee = 0;
	}
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
	Jouer_Selectionner_Torpilleur(eJoueur,pcTorpilleur,peNumero_Torpilleur, N_Torpilleur);
}

void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, int N_Deplacement){
	//Fonction qui permet de gérer le deplacement du torpilleur
	t_direction dDirection;
	dDirection = Droite;
	int bValide = 0;
	int i = 0;
	while(i < N_Deplacement && dDirection != Aucune){ //Tant qu'il reste des points de déplacement et qu'il n'a pas décider de s'arrêter
		while(bValide == 0){
			clear();
			torpilleur_selection_afficher(pcTorpilleur[*peNumero_Torpilleur].x, pcTorpilleur[*peNumero_Torpilleur].y, eJoueur);
			Jouer_Choisir_Direction(&dDirection);
			bValide = Jouer_Deplacement_Valide(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
		}
		bValide = 0;
		Jouer_Deplacer_Torpilleur(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur, N_Torpilleur);
		i++;
	}
}

void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur, int N_Torpilleur, int Taille_Portee){
	//Fonction qui permet de gérer l'attaque du torpilleur
	t_portee gPortee[N][M];
	t_coordonnee cCurseur;
	cCurseur.x = pcTorpilleur[*peNumero_Torpilleur].x;
	cCurseur.y = pcTorpilleur[*peNumero_Torpilleur].y;

	int bAttaque_Possible;
	int eJoueurAdverse = eJoueur;
	Jouer_Changer_Joueur(&eJoueurAdverse);
	
	Jouer_Calculer_Portee(eJoueurAdverse, pcTorpilleur, *peNumero_Torpilleur, gPortee, N_Torpilleur, Taille_Portee);
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
	for(i=0; i < N; i++){//On parcour l'integralite de la grille
		for(j=0; j < M; j++){
			Grille_lire_bateau(i,j, eJoueur,&eBateau);
			Grille_lire_toucher(i,j, eJoueur,&eToucher);
			if(eBateau != Aucun_b && eToucher == Non){//On test si il y a une case bateau non touchée
				bGagnant = 0;
			}
		}
	}
	return bGagnant;
}


void Jouer_Quitter_Continuer(int *bQuitter, FILE *fic1, int eJoueur, int N_Torpilleur, int N_Deplacement, int Taille_Portee){
	//Fonction qui permet à l'utilisateur de choisir de continuer ou de quitter la partie.
	int ech;
	int bContinuer = 0;
	int bSauvegarder = 0;
	while(*bQuitter == 0 && bContinuer == 0){
		timeout(-1);
		ech = getch();
		switch(ech){
			case 32: //TOUCHE espace
				bContinuer = 1;
				break;
			case 113: //TOUCHE q
				*bQuitter = 1;
				break;
			case 115: //TOUCHE s
				if(bSauvegarder == 0){
					printw("\n\nLa partie a bien été sauvegardée !");
					fic1 = fopen("sauvegarde" , "wb");
					Grille_Sauvegarder(fic1);
					fwrite(&eJoueur , sizeof(int) , 1 , fic1);
					fwrite(&N_Torpilleur , sizeof(int) , 1 , fic1);
					fwrite(&N_Deplacement , sizeof(int) , 1 , fic1);
					fwrite(&Taille_Portee , sizeof(int) , 1 , fic1);
					bSauvegarder = 1;
				}
				break;
		}
	}
}

void Jouer_Partie(int eJoueur, int N_Torpilleur, int N_Deplacement, int Taille_Portee, FILE *fic1){
	//Fonction qui définie la routine de la Partie

	t_coordonnee* cTorpilleur = malloc(N_Torpilleur * sizeof(t_coordonnee)); // tableau de n entiers
	int eNumero_Torpilleur;
	int bGagnant = 0;
	int bQuitter = 0;

	while(bGagnant == 0 && bQuitter == 0){//On joue tant qu'il n'y a pas de gagnant ou tant que l'utilisateur n'a pas décidé de quitter la partie
		clear();
		Jouer_Choisir(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur);
		Jouer_Deplacer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur, N_Deplacement);
		Jouer_Attaquer(eJoueur, cTorpilleur, &eNumero_Torpilleur, N_Torpilleur, Taille_Portee);
		bGagnant = Jouer_Gagnant(eJoueur);
		clear();
		Jouer_Changer_Joueur(&eJoueur);
		printw("\nJoueur %i a vous de jouer !\nAppuyez sur espace pour continuer, q pour quitter la partie, s pour sauvegarder :", eJoueur);
		Jouer_Quitter_Continuer(&bQuitter, fic1, eJoueur, N_Torpilleur, N_Deplacement, Taille_Portee);
	}
	if(bGagnant){
		printw("\nLe joueur %i a gagne !\n Appuyez sur une touche pour continuer !", eJoueur);
		refresh();
		getch();
	}
}