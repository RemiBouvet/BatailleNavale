
#include "Outil.h"
#include "Grille.h"
#include "Struct.h"
#include "Placement_bateau.h"
#define nb_bateau 4

t_case grille[N][M];

int bStringtonum(char *v,int *res){
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

void Placer_bateau(int num_grille){
    int compteur=0,choix_sens,i,j,valeur=0,ok=0;
    char sI[20];
    char sJ[20];
    for(compteur=0;compteur!=1;compteur++){
        do{
            printf("Vous allez rentrer le Sous_Marin\n");
            printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
             if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
                        ok=1;
                        if(choix_sens==1){
                            valeur=0;
                            while(valeur!=Sous_Marin){
                                Grille_ecrire_bateau(i,j,num_grille,Sous_Marin);
                                valeur++;
                                Grille_ecrire_bateau(i,j+1,num_grille,Sous_Marin);
                                valeur++;
                                Grille_ecrire_bateau(i,j+2,num_grille,Sous_Marin);
                                valeur++;
                            }
                        }
                        if(choix_sens==2){
                            valeur=0;
                            while(valeur!=Sous_Marin){
                                Grille_ecrire_bateau(i,j,num_grille,Sous_Marin);
                                valeur++;
                                Grille_ecrire_bateau(i+1,j,num_grille,Sous_Marin);
                                valeur++;
                                Grille_ecrire_bateau(i+2,j,num_grille,Sous_Marin);
                                valeur++;
                                
                            }
                        }
                    }
            }
             }
        }while(!ok);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
        ok=0;
        do{
            printf("Vous allez placer le Destroyer\n");
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){

                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
                        ok=1;
                        if(choix_sens==1){
                            valeur=0;
                            while(valeur!=Destroyer){
                                Grille_ecrire_bateau(i,j,num_grille,Destroyer);
                                valeur++;
                                Grille_ecrire_bateau(i,j+1,num_grille,Destroyer);
                                valeur++;
                                Grille_ecrire_bateau(i,j+2,num_grille,Destroyer);
                                valeur++;
                                Grille_ecrire_bateau(i,j+3,num_grille,Destroyer);
                                valeur++;
                            }
                        }
                          if(choix_sens==2){
                              valeur=0;
                             while(valeur!=Destroyer){
                                  Grille_ecrire_bateau(i,j,num_grille,Destroyer);
                                  valeur++;
                                  Grille_ecrire_bateau(i+1,j,num_grille,Destroyer);
                                  valeur++;
                                  Grille_ecrire_bateau(i+2,j,num_grille,Destroyer);
                                  valeur++;
                                  Grille_ecrire_bateau(i+3,j,num_grille,Destroyer);
                                  valeur++;
                              }
                          }
                    }
                }
            }
        }while(!ok);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
        ok=0;
        do{
            printf("Vous allez placer le Porte_Avion\n");
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){

                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
                        ok=1;
                        if(choix_sens==1){
                            valeur=0;
                            while(valeur!=Porte_Avion){
                                Grille_ecrire_bateau(i,j,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i,j+1,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i,j+2,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i,j+3,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i,j+4,num_grille,Porte_Avion);
                                valeur++;
                            }
                        }
                        if(choix_sens==2){
                            valeur=0;
                            while(valeur!=Porte_Avion){
                                Grille_ecrire_bateau(i,j,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i+1,j,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i+2,j,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i+3,j,num_grille,Porte_Avion);
                                valeur++;
                                Grille_ecrire_bateau(i+4,j,num_grille,Porte_Avion);
                                valeur++;
                            }
                        }
                    }
                }
            }
        }while(!ok);

        
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i  ",grille[i][j].bateau);
        }
        printf("\n");
    }
    
}
