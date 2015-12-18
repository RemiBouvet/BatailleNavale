# BatailleNavale ++

## Compilation

Pour compiler ce programme vous pouvez faire la commande "make" dans le terminal, cette commande compilera le programme et mettra un executable dans le dossier bin.

## Execution du programme

Pour executer le programme vous pouvez faire la commande "bin/bataillenavale"

## Séparation des tâches

Zerbane Mehdi : Placement des obstacles et des bateaux\

Bouvet Rémi : Déplacement et attaque

Pradère-Niquet Alexandre : Affichage

##Conception
  enum (Aucun, Torpilleur, Sous-Marin, Destroyer, Porte-Avion) t_bateau

  enum (Aucun, Obstacle) t_obstacle

  enum (Non, Oui) t_toucher
  
  enum(Aucun_t,Present)t_torpilleur;

  structure case{t_bateau bateau, t_obstacle obstacle, t_toucher toucher, t_torpilleur torpilleur)

  struture {case grille1,case grille2} t_plateau
  t_plateau grille

  int bQuitter


   1. Rep jusqu'à quitter(bQuitter)
   
        bQuitter = 0;
        MenuAfficher
        PartieLancer

          PartieInitialiser($$eJoueur, Grille)
              eJoueur = 1 ou 2
              GrilleGenerer(eJoueur $$ Grille)
                ObstaclePlacer($$Grille)
                GrilleAfficher(Grille)
              BateauPlacer(eJoueur$ Grille$)
                JoueurPlacer(eJoueur $ Grille$)
                GrilleAfficher(eJoueur, Grille)
                JoueurPlacer(eJoueur $ Grille $)
                GrilleAfficher(eJoueur, Grille)


          Rep jusqu'à bPartieFini(Grille, bQuitter)
              JoueurJouer(eJoueur $ Grille)
                  PlateauAfficher(eJoueur,Grille)
                    GrilleAfficher(eJoueur,Grille)
                    GrilleMasque(eJoueur, Grille)
                    HUDAfficher(eJoueur) 
                  TorpilleurDeplacer(eJoueur $Grille $)
                  PlateauAfficher(eJoueur, Grille)
                  TorpilleurAttaquer(eJoueur $ Grille)
                  PlateauAfficher(eJoueur, Grille)
              ChangerJoueur($eJoueur, bQuitter$)
          fin rep
    fin rep

