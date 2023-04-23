#include <stdlib.h>
#include <time.h>

#include "Moteur.h"
#include "Graphique.h"
#include "Plateau.h"


int main(void){

    /*Initialisation du seed (graine) dans
    l'aléatoire*/
    srand(time(NULL));

    /*On lance le moteur du taquin*/
    LaunchGame();

    return 0;
}

