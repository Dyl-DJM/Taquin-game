#include "Moteur.h"


/*Mélange le plateau en s'assurant qu'il y ait une solution*/
void EchangeCarre(Carre first, Carre second, Carre *curseur, Plateau * plateau){
	
    Carre tmp;

    tmp.lig = first.lig;
    tmp.col = first.col;

    (plateau->bloc)[first.lig][first.col] = (plateau->bloc)[second.lig][second.col];
    (plateau->bloc)[second.lig][second.col] = (plateau->bloc)[tmp.lig][tmp.col];

    *curseur = second;
}

/*Renvoie 1 si le plateau est dans une disposition représentant une victoire
(les cases de 'plateau' sont toutes au bon endroit et 'curseur' se trouve en bas à droite) et 0 sinon*/
int PlateauVainqueur(Plateau plateau, Carre curseur){

    int i, j;

    if(!(curseur.lig == NB_LIG - 1 && curseur.col == NB_COL - 1))
        return 0;

    for(i = 0; i < NB_LIG - 1; i++){

        for(j = 0; j < NB_COL - 1; j++){

            if(!((plateau.bloc)[i][j].lig == i && (plateau.bloc)[i][j].col == j)){
                return 0;
            }
        }
    }

    return 1;
}

/*Permet d'échanger deux carré ('first' & 'second') de place dans le plateau*/
Carre PlateauAleatoire(Plateau * plateau){

    int hasard, valid, i;
    Carre curseur;
    Carre other_carre;

    curseur.lig = NB_LIG - 1;
    curseur.col = NB_COL - 1;

    for(i = 0; i < NB_COUPS; i++){

        valid = 0;

        while(!valid){

            hasard = (rand() % 4) + 1;
            valid = 1;

            switch(hasard){

                case 1:{

                    if(!(curseur.lig < NB_LIG - 1)){
                        valid = 0;
                    }else{
                        other_carre.lig = curseur.lig + 1;
                        other_carre.col = curseur.col;
                    }
                    break;
                }
                case 2:{

                    if(!(curseur.lig > 0)){
                        valid = 0;
                    }else{
                        other_carre.lig = curseur.lig - 1;
                        other_carre.col = curseur.col;
                    }
                    break;
                }
                case 3:{

                    if(!(curseur.col > 0)){
                        valid = 0;
                    }else{
                        other_carre.lig = curseur.lig;
                        other_carre.col = curseur.col - 1;
                    }
                    break;
                }
                case 4:{

                    if(!(curseur.col < NB_COL - 1)){
                        valid = 0;
                    }else{
                        other_carre.lig = curseur.lig;
                        other_carre.col = curseur.col + 1;
                    }
                    break;
                }
            }
        }
        EchangeCarre(curseur, other_carre, &curseur, plateau);
    }

    return curseur;

}

/*Lance la partie de Taquin*/
int LaunchGame(void){

    MLV_Image * image;
    Carre curseur;
    Plateau plateau;

    int x_window, y_window;

    InitialisationPlateau(&plateau);

    x_window = X_WIND;
    y_window = Y_WIND;

    curseur = PlateauAleatoire(&plateau);

    /* METTRE CAETTE PARTIE DANS UNE FOCNTION DANS GRAPHIQUE*/

    if(fopen("Chien.png", "r") == NULL){
        exit(0);
    }

    MLV_create_window("Taquin", "Image", x_window, y_window);

    image = MLV_load_image("Chien.png");

     /* METTRE CAETTE PARTIE DANS UNE FOCNTION DANS GRAPHIQUE*/

    AfficheMatrice(x_window, y_window, image, plateau, curseur);


    while(1){

        Evenement(x_window, y_window, &curseur, &plateau);
        AfficheMatrice(x_window, y_window, image, plateau, curseur);

        if(PlateauVainqueur(plateau, curseur)){

            AnnounceWin(image);
            CloseWindow(image);
            return 0;
        }
    }

    CloseWindow(image);
    return 0;
}