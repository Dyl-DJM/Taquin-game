#include "Plateau.h"

/*Initialise le plateau 'P'*/
void InitialisationPlateau(Plateau * P){
    int i, j;

    for(i = 0; i < NB_LIG ;i++){
        for(j = 0; j < NB_COL;j++){
            ((P->bloc)[i][j]).lig = i;
            ((P->bloc)[i][j]).col = j;
        }
    }
}