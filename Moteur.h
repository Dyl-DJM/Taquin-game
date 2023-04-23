#ifndef __MOTEUR__
#define __MOTEUR__

    #include "Graphique.h"
    #include "Plateau.h"

    #define NB_COUPS 120

    #define X_WIND 512
    #define Y_WIND 512

    /*Mélange le plateau en s'assurant qu'il y ait une solution*/
    Carre PlateauAleatoire(Plateau * plateau);

    /*Renvoie 1 si le plateau est dans une disposition représentant une victoire
    (les cases de 'plateau' sont toutes au bon endroit et 'curseur' se trouve en bas à droite) et 0 sinon*/
    int PlateauVainqueur(Plateau plateau, Carre curseur);

    /*Permet d'échanger deux carré ('first' & 'second') de place dans le plateau*/
    void EchangeCarre(Carre first, Carre second, Carre *curseur, Plateau * plateau);

    /*Lance la partie de Taquin*/
    int LaunchGame(void);


#endif