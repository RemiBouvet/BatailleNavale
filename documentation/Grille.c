/**
*\mainpage Bataille navale ++ by BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \file Grille.c
* \brief fichier qui contient l'ensemble des fonctions pour gestion grille.
* \author BOUVET Remi & PRADERE-NIQUET Alexandre & ZERBANE Mehdi
* \version 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Struct.h"
#include "Outil.h"

t_plateau grille; //structure qui prend 2 grille

/**
* \fn void Grille_Sauvegarder(FILE * fic1)
* \brief Fonction qui permet de sauvegarder
*
* \param fichier pour sauvegarder 
* \return Ne retourne rien
*
*/
void Grille_Sauvegarder(FILE * fic1){
    fwrite(&grille , sizeof(t_plateau) , 1 , fic1);
}

/**
* \fn void Grille_Charger(FILE * fic1)
* \brief Fonction qui permet de charger une partie
*
* \param fichier pour charger une partie 
* \return Ne retourne rien
*
*/
void Grille_Charger(FILE * fic1){
    fread(&grille , sizeof(t_plateau) , 1 , fic1);
}

/**
* \fn void Grille_init()
* \brief Fonction qui permet d'initialiser la grille
*
* \param aucun 
* \return Ne retourne rien
*
*/
void Grille_init(){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            Grille_ecrire_bateau(i,j, 1, Aucun_b);
            Grille_ecrire_toucher(i,j, 1,Non);
            Grille_ecrire_obstacle(i,j,1,Aucun_o);
	    Grille_ecrire_torpilleur(i,j,1,Aucun_t);
            Grille_ecrire_bateau(i,j, 2, Aucun_b);
            Grille_ecrire_toucher(i,j, 2,Non);
            Grille_ecrire_obstacle(i,j,2,Aucun_o);
	    Grille_ecrire_torpilleur(i,j,2,Aucun_t);
        }
    }
}

/**
* \fn void Grille_lire_case(int i, int j, int num_grille,t_case *pEnsemble)
* \brief Fonction qui permet de connaitre le contenu d'une case
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a dans la case
* \return Ne retourne rien
*
*/
void Grille_lire_case(int i, int j, int num_grille,t_case *pEnsemble){
    int ab=(pEnsemble)->bateau;
    int cd=(pEnsemble)->toucher;
    int bg=(pEnsemble)->obstacle;
    int ap=(pEnsemble)->torpilleur;
    Grille_lire_bateau(i,j, num_grille,&ab);
    Grille_lire_toucher(i,j, num_grille,&cd);
    Grille_lire_obstacle(i,j,num_grille,&bg);
    Grille_lire_torpilleur(i,j,num_grille,&ap);
}

/**
* \fn void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M])
* \brief Fonction qui permet d'ecrire le contenu d'une case
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a dans la case
* \return Ne retourne rien
*
*/
void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M]){
    Grille_ecrire_bateau(i,j, num_grille, ensemble[i][j].bateau);
    Grille_ecrire_toucher(i,j, num_grille,ensemble[i][j].toucher);
    Grille_ecrire_obstacle(i,j,num_grille,ensemble[i][j].obstacle);
    Grille_ecrire_torpilleur(i,j,num_grille,ensemble[i][j].torpilleur);

}

/**
* \fn void Grille_lire_bateau(int i,int j, int num_grille,int *peResultat)
* \brief Fonction qui permet de connaitre le type de bateau 
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a
* \return Ne retourne rien
*
*/
void Grille_lire_bateau(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].bateau;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].bateau;
        }

    }

}

/**
* \fn void Grille_lire_toucher(int i,int j, int num_grille,int *peResultat)
* \brief Fonction qui permet de connaitre s'il y a eu un tir ou non 
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a
* \return Ne retourne rien
*
*/
void Grille_lire_toucher(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].toucher;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].toucher;
        }

    }
}

/**
* \fn void Grille_lire_obstacle(int i,int j, int num_grille,int *peResultat)
* \brief Fonction qui permet de connaitre s'il y a un obstacle ou non 
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a
* \return Ne retourne rien
*
*/
void Grille_lire_obstacle(int i,int j, int num_grille,int *peResultat){

    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].obstacle;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].obstacle;
        }
    }
}

/**
* \fn void Grille_lire_obstacle(int i,int j, int num_grille,int *peResultat)
* \brief Fonction qui permet de connaitre s'il y a un torpilleur ou non 
*
* \param numero ligne, numero colonne, numero de grille, ce qu'il y a
* \return Ne retourne rien
*
*/
void Grille_lire_torpilleur(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].torpilleur;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].torpilleur;
        }

    }
}

/**
* \fn void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix)
* \brief Fonction qui permet d'ecrire le type de bateau qu'il y a dans la case
*
* \param numero ligne, numero colonne, numero de grille, le type de bateau
* \return Ne retourne rien
*
*/
void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(choix==Sous_Marin){
                if(num_grille==1)grille.grille1[i][j].bateau=Sous_Marin;
                else if(num_grille==2)grille.grille2[i][j].bateau=Sous_Marin;
            }
            if(choix==Destroyer){
                if(num_grille==1)grille.grille1[i][j].bateau=Destroyer;
                else if(num_grille==2)grille.grille2[i][j].bateau=Destroyer;
            }
            if(choix==Porte_Avion){
                if(num_grille==1)grille.grille1[i][j].bateau=Porte_Avion;
                else if(num_grille==2)grille.grille2[i][j].bateau=Porte_Avion;
            }
            else if(choix==Aucun_b){
                if(num_grille==1)grille.grille1[i][j].bateau=Aucun_b;
                else if(num_grille==2)grille.grille2[i][j].bateau=Aucun_b;
            }
        }
    }
}

/**
* \fn void Grille_ecrire_toucher(int i,int j, int num_grille,t_toucher choix)
* \brief Fonction qui permet d'ecrire s'il y a un tir effectue ou non
*
* \param numero ligne, numero colonne, numero de grille, si touche ou non
* \return Ne retourne rien
*
*/
void Grille_ecrire_toucher(int i,int j, int num_grille,t_toucher choix){
    if(i>=0 && i<N && j>=0 && j<M){
        if(bCroit(1,num_grille,2)){
            if(choix==Oui){
                if(num_grille==1)grille.grille1[i][j].toucher=Oui;
                else if(num_grille==2)grille.grille2[i][j].toucher=Oui;
            }
            else if(choix==Non){
                if(num_grille==1)grille.grille1[i][j].toucher=Non;
                else if(num_grille==2)grille.grille2[i][j].toucher=Non;
            }
        }
    }
}

/**
* \fn void Grille_ecrire_obstacle(int i,int j, int num_grille,t_obstacle choix)
* \brief Fonction qui permet d'ecrire un obstacle ou non
*
* \param numero ligne, numero colonne, numero de grille, si on place obstacle ou non
* \return Ne retourne rien
*
*/
void Grille_ecrire_obstacle(int i,int j, int num_grille,t_obstacle choix){
    //Assert1("Numero grille",num_grille==1);
    //Assert1("Numero grille",num_grille==2);
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(choix==Obstacle){
                if(num_grille==1)grille.grille1[i][j].obstacle=Obstacle;
                else if(num_grille==2)grille.grille2[i][j].obstacle=Obstacle;
            }
            else if(choix==Aucun_o){
                if(num_grille==1)grille.grille1[i][j].obstacle=Aucun_o;
                else if(num_grille==2)grille.grille2[i][j].obstacle=Aucun_o;
            }
        }
    }
}

/**
* \fn void Grille_ecrire_torpilleur(int i,int j, int num_grille,t_torpilleur choix)
* \brief Fonction qui permet d'ecrire s'il y a un torpilleur ou non
*
* \param numero ligne, numero colonne, numero de grille, s'il y a un torpilleur ou non
* \return Ne retourne rien
*
*/
void Grille_ecrire_torpilleur(int i,int j, int num_grille,t_torpilleur choix){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(choix==Aucun_t){
                if(num_grille==1)grille.grille1[i][j].torpilleur=Aucun_t;
                else if(num_grille==2)grille.grille2[i][j].torpilleur=Aucun_t;
            }
            else if(choix==Present){
                if(num_grille==1)grille.grille1[i][j].torpilleur=Present;
                else if(num_grille==2)grille.grille2[i][j].torpilleur=Present;
            }
        }
    }
}
