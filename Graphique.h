#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

    #include <MLV/MLV_all.h>
    #include "Moteur.h"
    #include "Plateau.h"

    /*Fonction d'affichage de la matrice représentée pa le type PLateau. Dessine le plateau de taille 'x_window' x 'y_window' et avec
    en fond l'image 'image' donné sous la forme des pièces du 'plateau' avec son 'curseur'*/
    void AfficheMatrice(int x_window, int y_window, MLV_Image * image, Plateau plateau, Carre curseur);

    /*Attend et gère un évènement produit pas l'utilisateur, permet de récupèrer les touches directionnelles permettant de faire bouger
    le 'curseur' et modifiant ainsi l'arrangement du 'plateau' de taille 'x_window' x 'y_window'*/
    void Evenement(int x_window, int y_window, Carre * curseur, Plateau * plateau);

    /*Affiche graphiquement le message de victoire sur l'image 'image'*/
    void AnnounceWin(MLV_Image * image);

    /*Libère la mémoire liée à l' 'image' et ferme la fenêtre graphique*/
    void CloseWindow(MLV_Image * image);

#endif