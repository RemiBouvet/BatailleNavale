/**
* \file Placement_bateau.c
* \brief fichier qui contient l'ensemble des fonctions pour le placement des bateaux.
* \author ZERBANE Mehdi
* \version 1.0
*/

#include "../../include/Outil.h"
#include "../../include/Grille.h"
#include "../../include/Struct.h"
#include "../../include/Placement_obstacle.h"
#include "../../include/afficher.h"

t_plateau grille;

/**
* \fn int bStringtonum(char *v,int *res)
* \brief Fonction qui convertis une chaine de caractères en int si la chaine de caractère est un int
* \param char *v Chaine de caractere a convertir, int *res pointeur sur lequel sera retourner l'entier qui est dans la chaine de caracteres
* \return 1 si on a un entier dans la chaine de caracteres, 0 dans le cas contraire
*/
int bStringtonum(char *v,int *res){ /* Fonction qui convertis une chaine de caractères en int si la chaine de caractère est un int*/
	int eNum=1;
	int i;
	*res=0;
	for(i=0;i<strlen(v);i++)
		eNum=eNum && isdigit(v[i]);
	if(eNum==1){
		*res=atoi(v); //On convertis la chaine en int
	}
	return eNum; //On retourne eNum qui sera de 1 si on a que des int dans la chaine de caractères, et de 0 si on a minimum 1 caractere
}

/**
* \fn int verif_presence(t_bateau bateau,int i,int j,int eChoix_sens,int eNum_grille)
* \brief Fonction qui regarde si là où l'on souhaite placer le bateau il y a dejà un bateau ou un obstacle
*
* \param t_bateau bateau prend la valeur du bateau rentré, int i valeur de la ligne de la matrice, int j valeur de la colonne de la matrice, int eChoix_sens 1 pour horizontal et 2 pour vertical, int eNum_grille vaut 1 pour J1 et 2 pour J2
* \return 1
*
*/
int verif_presence(t_bateau bateau,int i,int j,int eChoix_sens,int eNum_grille){ 
	int eCompteur=0, eResultat_b=0, eResultat_o=0, eResultat_t=0; /* Fonction qui regarde si là où l'on souhaite placer le bateau il y a dejà un bateau ou un obstacle*/
	if(eChoix_sens==1){
		while(eCompteur<bateau){
			Grille_lire_bateau(i,j+eCompteur,eNum_grille,&eResultat_b); //On regarde si il y a un bateau
			Grille_lire_obstacle(i,j+eCompteur,eNum_grille,&eResultat_o); //On regarde si il y a un obstacle
			Grille_lire_torpilleur(i,j+eCompteur,eNum_grille,&eResultat_t); //On regarde si il y a un torpilleur
			if(eResultat_b!=0 || eResultat_o!=0 || eResultat_t!=0)return 0; // Si il y a quelque chose on return 0
			eCompteur++;
		}
	}
    	else if(eChoix_sens==2){
		while(eCompteur<bateau){
			Grille_lire_bateau(eCompteur+i,j,eNum_grille,&eResultat_b); //On regarde si il y a un bateau
			Grille_lire_obstacle(eCompteur+i,j,eNum_grille,&eResultat_o); //On regarde si il y a un obstacle
			Grille_lire_torpilleur(eCompteur+i,j,eNum_grille,&eResultat_t); //On regarde si il y a un torpilleur
			if(eResultat_b!=0 || eResultat_o!=0 || eResultat_t!=0)return 0; // Si il y a quelque chose on return 0
	        	eCompteur++;
	   	}
   	}
	return 1; //Sinon on return 1
}

/**
* \fn int Assez_de_place(t_bateau bateau, int i,int j,int eChoix_sens,int eNum_grille)
* \brief Fonction qui regarde si il y a assez de place pour placer un bateau
*
* \param t_bateau bateau prend la valeur du bateau rentré
* \return 1 si on a de la place, 0 dans le cas contraire
*
*/
int Assez_de_place(t_bateau bateau, int i,int j,int eChoix_sens,int eNum_grille){ /*Fonction qui regarde si il y a assez de place pour placer un bateau*/
	if(eChoix_sens==1){
		return (j+bateau-1<N); //On regarde verticalement si notre position + la taille du bateau est inférieur à N
	}
	else if(eChoix_sens==2){
		return (i+bateau-1<M); // idem mais horizontalement
	}
	return 0;//On retourne 0 dans le cas ou on ne connait pas le sens 
}

/**
* \fn void Placer_grillebateau(t_bateau bateau, int i,int j,int eNum_grille,int eChoix_sens)
* \brief On place sur la grille le bateau
*
* \param t_bateau bateau prend la valeur du bateau rentré, int i valeur de la ligne de la matrice, int j valeur de la colonne de la matrice, int eChoix_sens 1 pour horizontal et 2 pour vertical, int eNum_grille vaut 1 pour J1 et 2 pour J2
* \return void
*
*/
void Placer_grillebateau(t_bateau bateau, int i,int j,int eNum_grille,int eChoix_sens){ 
	int eCompteur=0;
	if(eChoix_sens==1){
		while(eCompteur<bateau){ //Tant qu'on à pas la taille du bateau on continue de l'inscrire dans la grille
			Grille_ecrire_bateau(i,j+eCompteur,eNum_grille,bateau);
			eCompteur++;
		}
	}else if(eChoix_sens==2){
		while(eCompteur<bateau){
			Grille_ecrire_bateau(i+eCompteur,j,eNum_grille,bateau);
			eCompteur++;
		}
	}
}

/**
* \fn void Enlever_grillebateau(t_bateau bateau, int i,int j,int eNum_grille,int eChoix_sens)
* \brief Fonction qui supprime un bateau d'une grille
*
* \param t_bateau bateau prend la valeur du bateau rentré, int i valeur de la ligne de la matrice, int j valeur de la colonne de la matrice, int eChoix_sens 1 pour horizontal et 2 pour vertical, int eNum_grille vaut 1 pour J1 et 2 pour J2
* \return void
*
*/
void Enlever_grillebateau(t_bateau bateau, int i, int j, int eNum_grille, int eChoix_sens){ 
	int eCompteur=0,eBateau=0,eObstacle=0;
	if(eChoix_sens == 1){
		while(eCompteur < bateau){
			Grille_lire_bateau(i, j+eCompteur, eNum_grille, &eBateau); // On regarde si il y a un bateau
 			Grille_lire_obstacle(i, j+eCompteur, eNum_grille, &eObstacle); //On regarde si il y a un bateau
			if(eBateau == bateau && eObstacle == 0)Grille_ecrire_bateau(i, j+eCompteur, eNum_grille, Aucun_b); //On supprime le bateau
			eCompteur++;
		}
	}else if(eChoix_sens == 2){
		while(eCompteur < bateau){
			Grille_lire_bateau(i+eCompteur, j, eNum_grille, &eBateau);
 			Grille_lire_obstacle(i+eCompteur, j, eNum_grille, &eObstacle);
			if(eBateau == bateau && eObstacle == 0)Grille_ecrire_bateau(i+eCompteur, j, eNum_grille, Aucun_b);
			eCompteur++;
		}
	}
}

/**
* \fn void Enlever_grilletousbateau(int eNum_grille)
* \brief Fonction qui supprime tous les bateaux d'une grille
*
* \param int eNum_grille Prend la valeur 1 pour J1 et 2 pour J2
* \return void
*
*/
void Enlever_grilletousbateau(int eNum_grille){ /*Fonction qui supprime tous les bateaux d'une grille*/
	int i=0, j=0, eObstacle=0;
	if(eNum_grille == 2){
		for(i=0;i < N;i++){
			for(j=0;j < M;j++){
				Grille_lire_obstacle(i, j, eNum_grille, &eObstacle);
				if((grille.grille2[i][j].bateau == Sous_Marin || grille.grille2[i][j].bateau == Destroyer || grille.grille2[i][j].bateau == Porte_Avion || grille.grille2[i][j].torpilleur == Present) && !eObstacle){
			 		grille.grille2[i][j].bateau=Aucun_b; //On met toutes les cases avec aucun_b
					grille.grille2[i][j].torpilleur=0; //On met toutes les cases à 0
				}

			}
		}
	}else if(eNum_grille==1){
		for(i=0;i < N;i++){
			for(j=0;j < M;j++){
				Grille_lire_obstacle(i, j, eNum_grille, &eObstacle);
				if((grille.grille1[i][j].bateau == Sous_Marin || grille.grille1[i][j].bateau == Destroyer || grille.grille1[i][j].bateau == Porte_Avion || grille.grille1[i][j].torpilleur == Present) && !eObstacle){
			 		grille.grille1[i][j].bateau=Aucun_b; 
					grille.grille1[i][j].torpilleur=0;
				}

			}
		}
	}
	
}

/**
* \fn void Placer_bateau_auto(int eNum_grille,int eNb_torpilleur,int eNb_sous_m,int eNb_Port_A,int eNb_Dest)
* \brief Fonction qui place aléatoirement des bateaux
*
* \param int eNum_grille prend 1 pour J1 et 2 pour J2, int eNb_torpilleur Nombre de torpilleurs, int eNb_sous_m Nombre de sous_marins, int eNb_Port_A Nombre de porte-avion, int eNb_Dest Nombre de destroyer
* \return void
*
*/
void Placer_bateau_auto(int eNum_grille, int eNb_torpilleur, int eNb_sous_m, int eNb_Port_A, int eNb_Dest){ 
	int eCompteur=0,eChoix_sens,i=0,j=0,eOk=0,eNb=0,eValide=0,eChoix=0;
	char sC[20];
	clear();
	srand(time(NULL));
	do{
		eCompteur=0;
		//On place le sous-marin
		do{
			while(eCompteur!=eNb_sous_m){
                		eOk=0;
				i=uHasard(N); //On prend un nombre au hasard avec comme max N
				j=uHasard(M); //On prend un nombre au hasard avec comme max M
				if(bCroit(0,i,N-1) && bCroit(0,j,M-1)){
					eChoix_sens=uHasard(2); // On prend un nombre au hasard avec comme max 2
					if(verif_presence(Sous_Marin,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Sous_Marin,i,j,eChoix_sens,eNum_grille)){
						Placer_grillebateau(Sous_Marin, i,j,eNum_grille,eChoix_sens);
						eOk=1;
						eCompteur++;
					}
				}
			}
		}while(!eOk);
	 	eOk=0;
		eCompteur=0;
		//Destroyer
		do{
			while(eCompteur!=eNb_Dest){
				eOk=0;
				i=uHasard(N);
				j=uHasard(M);
			    	if(bCroit(0,i,N-1) && bCroit(0,j,M-1)){
					eChoix_sens=uHasard(2);
					if(verif_presence(Destroyer,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Destroyer,i,j,eChoix_sens,eNum_grille)){
						Placer_grillebateau(Destroyer, i,j,eNum_grille,eChoix_sens);
						eOk=1;
						eCompteur++;
					}
				}
			}
		}while(!eOk);
		eOk=0;
		eCompteur=0;
		//Porte_Avion
		do{
			while(eCompteur!=eNb_Port_A){
				eOk=0;
				i=uHasard(N);
				j=uHasard(M);
				if(bCroit(0,i,N-1) && bCroit(0,j,M-1)){
					eChoix_sens=uHasard(2);
					if(verif_presence(Porte_Avion,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Porte_Avion,i,j,eChoix_sens,eNum_grille)){
						Placer_grillebateau(Porte_Avion, i,j,eNum_grille,eChoix_sens);
						eOk=1;
						eCompteur++;
					}                    
				}
			}
		}while(!eOk);
		eOk=0;
		eNb=0;
		//Torpilleur(s)
		while(eNb!=eNb_torpilleur){
			eOk=0;
			do{
				i=uHasard(N);
				j=uHasard(M);
				if(bCroit(0,i,N-1) && bCroit(0,j,M-1)){		          
					eChoix_sens=uHasard(2);
					if(verif_presence(Present,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Present,i,j,eChoix_sens,eNum_grille)){
						Grille_ecrire_torpilleur(i,j,eNum_grille,Present);
						eOk=1;
						eNb++;	
					}		            
				}
			}while(!eOk);

		}
		Grille_perso_afficher(eNum_grille); //On affiche la grille du joueur
		do{
			printw("Vous êtes satisfait de vos bateaux ?? (Oui:1) : ");
			refresh();
			echo();
			scanw("%s",sC);
			noecho();
		}while(!bStringtonum(sC,&eChoix));
		if(bStringtonum(sC,&eChoix)){
			if(eChoix==1)eValide=1;
			else{
				eValide=0;
				Enlever_grilletousbateau(eNum_grille); //Si l'utilisateur n'est pas satisfait on supprime tous les bateaux de la grille
				clear();
			}
		}else  Enlever_grilletousbateau(eNum_grille); //Si on a pas d'entiers on supprime tous les bateaux de la grille
	}while(!eValide);
}

/**
* \fn int Changement_colonne(char * v,int *pRes)
* \brief Fonction qui convertis une chaine de caracteres en int selon sa valeur dans la colonne de jeu
*
* \param char *v Chaine de caractères (colonne) ou l'on souhaite placer le bateau, int *pRes Pointeur qui prendra la valeur de la colonne ou sera place le bateau
* \return 1 si on est dans les bornes I et J, 0 dans le cas contraire
*
*/
int Changement_colonne(char * v,int *peRes){
	 if(strcmp(v,"A")==0 || strcmp(v,"a")==0){
	 	*peRes=0;
	 	return 1;
	 }
	 else if(strcmp(v,"B")==0 || strcmp(v,"b")==0){ //Si l'utilisateur rentre B qui correspond à 1 en position dans la matrice, on met *pRes=1 et on retourne 1 car il a rentrer une lettre qui est compris dans la borne A-J
		*peRes=1;
	 	return 1;	 
	 }
	 else if(strcmp(v,"C")==0 || strcmp(v,"c")==0){
	 	*peRes=2;
	 	return 1;
	 }
	 else if(strcmp(v,"D")==0 || strcmp(v,"d")==0){
	 	*peRes=3;
	 	return 1;
	 }
	 else if(strcmp(v,"E")==0 || strcmp(v,"e")==0){
	 	*peRes=4;
	 	return 1;
	 }
	 else if(strcmp(v,"F")==0 || strcmp(v,"f")==0){
	 	*peRes=5;
	 	return 1;
	 }
	 else if(strcmp(v,"G")==0 || strcmp(v,"g")==0){
	 	*peRes=6;
	 	return 1;
	 }
	 else if(strcmp(v,"H")==0 || strcmp(v,"h")==0){
	 	*peRes=7;
	 	return 1;
	 }
	 else if(strcmp(v,"I")==0 || strcmp(v,"i")==0){
	 	*peRes=8;
	 	return 1;
	 }
	 else if(strcmp(v,"J")==0 || strcmp(v,"j")==0){
	 	*peRes=9;
	 	return 1;
	 }
	 else return 0;
}

/**
* \fn void Placer_bateau_manuelle(int eNum_grille,int eNb_torpilleur,int eNb_sous_m,int eNb_Port_A,int eNb_Dest)
* \brief Fonction qui place manuellement des bateaux
*
* \param int eNum_grille prend 1 pour J1 et 2 pour J2, int eNb_torpilleur Nombre de torpilleurs, int eNb_sous_m Nombre de sous_marins, int eNb_Port_A Nombre de porte-avion, int eNb_Dest Nombre de destroyer
* \return void
*
*/
void Placer_bateau_manuelle(int eNum_grille,int eNb_torpilleur,int eNb_sous_m,int eNb_Port_A,int eNb_Dest){
	int eCompteur=0,eChoix_sens=0,i=0,j=0,eOk=0,eChoix=0,eValide=0;
	char sI[20];
	char sJ[20];
	char sC[20];
	clear();
	Grille_perso_afficher(eNum_grille);
	printw("Vous allez rentrer le Sous-Marin (3 cases)\n");
	refresh();
	do{
		while(eCompteur!=eNb_sous_m){
			eOk=0; //Variable qui vérifie si le bateau a été placer
			eChoix=0;
			printw("Veuillez entrer les coordonnées i (ligne) et j (colonne) de départ pour placer le bateau n°%i: ",eCompteur+1);
			refresh();
			echo();
			scanw("%s",sI); //On entre les coordonnées en chaine de caractères
			scanw("%s",sJ);
			noecho();
			if(bStringtonum(sI,&i) && Changement_colonne(sJ,&j)){ //On transforme la chaine sI en int sur la variable i, et on entre une colonne en lettre et on la renvoi en int sur j
				if(bCroit(0,i,N)){
					printw("Dans quelle sens souhaitez vous placé le bateau ? 1 Horizontal , 2 Vertical\t : ");
					refresh();
					echo();
					scanw("%i",&eChoix_sens);
					noecho();
					if(bCroit(1,eChoix_sens,2)){
						if(verif_presence(Sous_Marin,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Sous_Marin,i,j,eChoix_sens,eNum_grille)){ //On vérifié si il y a dejà un bateau à l'endroit ou on va placer notre bateau, et on vérifie si il y a la place pour le mettre
							Placer_grillebateau(Sous_Marin, i,j,eNum_grille,eChoix_sens); //Si oui on place le bateau
							eOk=1;
						}
					}
				}
			}
			clear();
			Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
			printw("Vous êtes satisfait de votre choix ? Oui:1 \t Non:0 \n");
			refresh();
			echo();
			scanw("%s",sC);
			noecho();
			if(bStringtonum(sC,&eChoix)){ //On convertie en int sC si dans la chaine de caractères il y a que un entier
				if(eChoix==1 && eOk==1){
					eValide=1;
					eCompteur++;
				}  //Variable qui vérifie si l'utilisateur est d'accord avec sa position et si le bateau a été placé
				else{
					eValide=0;
					Enlever_grillebateau(Sous_Marin, i,j,eNum_grille,eChoix_sens); //Sinon on supprime le bateau
				}
			}else Enlever_grillebateau(Sous_Marin, i,j,eNum_grille,eChoix_sens);
		}
	}while(!eValide);
 	eOk=0;
	clear();
	eCompteur=0;
	Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
	printw("Vous allez placer le Destroyer (4 cases)\n");
	refresh();
	do{
		while(eCompteur!=eNb_Dest){
			printw("Veuillez entrer les coordonnées i (ligne) et j (colonne) pour placer le bateau n°%i: ",eCompteur+1);
			refresh();
			echo();
			scanw("%s",sI);
			scanw("%s",sJ);
			noecho();
			if(bStringtonum(sI,&i) && Changement_colonne(sJ,&j)){ //On transforme la chaine sI en int sur la variable i, et on entre une colonne en lettre et on la renvoi en int sur j
				if(bCroit(0,i,N)){
					printw("Dans quelle sens souhaitez vous placer le bateau ? 1 Horizontal , 2 Vertical\t : ");
					refresh();
					echo();
					scanw("%i",&eChoix_sens);
					noecho();
					if(bCroit(1,eChoix_sens,2)){
						refresh();
						if(verif_presence(Destroyer,i,j,eChoix_sens,eNum_grille) && Assez_de_place(Destroyer,i,j,eChoix_sens,eNum_grille)){ //On vérifié si il y a dejà un bateau à l'endroit ou on va placer notre bateau, et on vérifie si il y a la place pour le mettre
							Placer_grillebateau(Destroyer, i,j,eNum_grille,eChoix_sens); //On place le bateau sur la grille si les conditions sont validées						
							eOk=1;
						}
					}
				}
			}
			clear();
			Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
			printw("Vous êtes satisfait de votre choix ? Oui:1 \t Non:0 \n");
			refresh();
			echo();
			scanw("%s",sC);
			noecho();
			if(bStringtonum(sC,&eChoix)){
				if(eChoix==1 && eOk==1){
					eValide=1;
					eCompteur++;
				} 
				else{
					eValide=0;
					Enlever_grillebateau(Destroyer, i,j,eNum_grille,eChoix_sens); //On l'enlève sinon
				}
			}else Enlever_grillebateau(Destroyer, i,j,eNum_grille,eChoix_sens);
		}
	}while(!eValide);
	clear();
	eCompteur=0; //On remet le compteur à 0
	Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
	printw("Vous allez placer le Porte-Avion (5 cases)\n");   
	eOk=0;
	do{
		while(eCompteur!=eNb_Port_A){
			refresh();
			printw("Veuillez entrer les coordonnées i (ligne) et j (colonne) pour placer le bateau n°%i : ",eCompteur+1);
			refresh();
			echo();
			scanw("%s",sI);
			scanw("%s",sJ);
			noecho();
			if(bStringtonum(sI,&i) && Changement_colonne(sJ,&j)){
				if(bCroit(0,i,N)){
					printw("Dans quelle sens souhaitez vous placer le bateau ? 1 Horizontal , 2 Vertical\t : ");
					refresh();
					echo();
					scanw("%i",&eChoix_sens);
					noecho();
					if(bCroit(1,eChoix_sens,2)){
						if(verif_presence(Porte_Avion,i,j,eChoix_sens,eNum_grille)&& Assez_de_place(Porte_Avion,i,j,eChoix_sens,eNum_grille)){//On vérifié si il y a dejà un bateau à l'endroit ou on va placer notre bateau, et on vérifie si il y a la place pour le mettre
							Placer_grillebateau(Porte_Avion,i,j,eNum_grille,eChoix_sens); //Si les conditions sont validées on place le bateau
							eOk=1;
						}
					}
				}
			}
			clear();
			Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
			printw("Vous êtes satisfait de votre choix ? Oui:1 \t Non:0 \n");
			refresh();
			echo();
			scanw("%s",sC);
			noecho();
			if(bStringtonum(sC,&eChoix)){
				if(eChoix==1 && eOk==1){
					eValide=1;
					eCompteur++;
				}
				else{
					eValide=0;
					Enlever_grillebateau(Porte_Avion,i,j,eNum_grille,eChoix_sens);
				}
			}else Enlever_grillebateau(Porte_Avion,i,j,eNum_grille,eChoix_sens);
		}
	}while(!eValide);
	Grille_perso_afficher(eNum_grille);
	eOk=0;
	eCompteur=0;
	clear();
	Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
	refresh();
	while(eCompteur!=eNb_torpilleur){ //Tant qu'on a pas le nombre de torpilleur souhaiter
		do{
			eOk=0;
			printw("Vous allez rentrer le torpilleur (1 case) n°%i \n",eCompteur+1);
			printw("Veuillez entrer les coordonnées i (ligne) et j (colonne) de depart pour placer le bateau : ");
			refresh();
			echo();
		   	scanw("%s",sI);
			scanw("%s",sJ);
			noecho();
			if(bStringtonum(sI,&i) && Changement_colonne(sJ,&j)){
			    if(bCroit(0,i,N)){
					if(verif_presence(Present,i,j,eChoix_sens,eNum_grille)){
						Grille_ecrire_torpilleur(i,j,eNum_grille,Present);
						eOk=1;
					}
			    }
			}
			clear();
			Grille_perso_afficher(eNum_grille); //On affiche la grille pour visualiser notre bateau
			printw("Vous êtes satisfait de votre choix ? Oui:1 \t Non:0 \n");
			refresh();
			echo();
			scanw("%s",sC);
			noecho();
			if(bStringtonum(sC,&eChoix)){
				if(eChoix==1 && eOk==1)eValide=1;
				else{
					eValide=0;
					Enlever_grillebateau(Present,i,j,eNum_grille,eChoix_sens);
				}
			}else  Enlever_grillebateau(Present,i,j,eNum_grille,eChoix_sens);
	        }while(!eValide);
		eCompteur++;	
	}	
	clear();
	Grille_perso_afficher(eNum_grille);
}

/**
* \fn void Commencer_jeu_placement_bateau(int eNb_torpilleurs)
* \brief Fonction qui initialise completement la grille et qui demande à l'utilisateur de placé les bateaux
*
* \param int eNb_torpilleurs Nombre de torpilleurs
* \return void
*
*/
void Commencer_jeu_placement_bateau(int eNb_torpilleurs){
	char sChoix[20];
	char sNb_sous_m[20];
	char sNb_Dest[20];
	char sConfig[20];
	char sNb_Port_A[20];
	int eChoix=0,eValide=1,eNumJ=0,eNb_sous_m=1,eNb_Dest=1,eNb_Port_A=1,eConfig=0;
	Grille_init(); //On initialise la grille avec tout à 0
	placer_obstacle(); //On place les obstacles sur les grilles
	do{
		printw("\n\nChoix des bateaux : \n\t1 : Un seul bateau de même type\t2 : Choisir son nombre de bateaux\nChoix :  ");
		refresh();
		echo();
		scanw("%s",sConfig);
		noecho();
	}while(!bStringtonum(sConfig,&eConfig) || eConfig<1 || eConfig>2);
	if(eConfig==1){
		eNb_sous_m=1;
		eNb_Dest=1;
		eNb_Port_A=1;
	}else if(eConfig==2){
		clear();
		printw("Choix en configuration : \n");
		do{
			printw("Combien de Sous-Marin souhaitez vous (4 maximum) ? ");
			refresh();
			echo();
			scanw("%s",sNb_sous_m);
			noecho();
		}while(!bStringtonum(sNb_sous_m,&eNb_sous_m)||eNb_sous_m<1 || eNb_sous_m>4);
		do{
			printw("Combien de Destroyer souhaitez vous (4 maximum) ? ");
			refresh();
			echo();
			scanw("%s",sNb_Dest);
			noecho();
		}while(!bStringtonum(sNb_Dest,&eNb_Dest)||eNb_Dest<1 || eNb_Dest>4);
		do{
			printw("Combien de Porte-Avion souhaitez vous (4 maximum) ? ");
			refresh();
			echo();
			scanw("%s",sNb_Port_A);
			noecho();
		}while(!bStringtonum(sNb_Port_A,&eNb_Port_A)||eNb_Port_A<1 || eNb_Port_A>4);
	}
	clear();
	while(!eValide || eNumJ!=2){
		eChoix=0;
		do{
			clear();
			printw("\n\nPlacé automatique (J%i) : 1 \n\nPlacé manuelle (J%i): 2\n\n",eNumJ+1,eNumJ+1);
			printw("Choix : ");
			refresh();
			echo();
			scanw("%s",sChoix);
			noecho();
		}while(!bStringtonum(sChoix,&eChoix) || eChoix<1 || eChoix>2);
		if(eChoix==1){
			Placer_bateau_auto(eNumJ+1,eNb_torpilleurs,eNb_sous_m,eNb_Port_A,eNb_Dest); //On place automatique les bateaux sur les grilles des joueurs
			clear();
			eValide=1;
			eNumJ++;
		}
		else if(eChoix==2){
			Placer_bateau_manuelle(eNumJ+1,eNb_torpilleurs,eNb_sous_m,eNb_Port_A,eNb_Dest);
			clear();
			eValide=1;
			eNumJ++;
		}						
	}
}
