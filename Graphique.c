
#include "Graphique.h"




void AfficheMatrice(int x_window, int y_window, MLV_Image * image, Plateau plateau, Carre curseur){
	int i, j, i_image, j_image;

	j = 0;

	MLV_clear_window(MLV_COLOR_BLACK);

	for(i=0 ; i < NB_LIG ;i++){

		for(j=0 ; j < NB_COL ;j++){

			i_image = ((plateau.bloc)[i][j]).lig * (y_window/NB_LIG);
			j_image = ((plateau.bloc)[i][j]).col * (x_window/NB_COL);

			if(!(i == curseur.lig && j == curseur.col)){
				MLV_draw_partial_image(image, j_image, i_image, x_window/NB_COL - 2, y_window/NB_COL - 2,  j * (x_window/NB_COL) - 2, i * (y_window/NB_LIG) - 2);
			}
		}
	}
	MLV_actualise_window();
}


void Evenement(int x_window, int y_window, Carre * curseur, Plateau * plateau){

	MLV_Keyboard_button touche;
	Carre other_carre;



	MLV_wait_keyboard(&touche, NULL, NULL);

	
	if(touche == MLV_KEYBOARD_DOWN && curseur->lig < NB_LIG - 1){
		other_carre.lig = curseur->lig + 1;
		other_carre.col = curseur->col;

		EchangeCarre(*curseur, other_carre , curseur, plateau);
	}

	if(touche == MLV_KEYBOARD_UP && curseur->lig > 0){

		other_carre.lig = curseur->lig - 1;
		other_carre.col = curseur->col;

		EchangeCarre(*curseur, other_carre , curseur, plateau);
	}

	if(touche == MLV_KEYBOARD_LEFT && curseur->col > 0){
		other_carre.lig = curseur->lig;
		other_carre.col = curseur->col - 1;

		EchangeCarre(*curseur, other_carre , curseur, plateau);
	}

	if(touche == MLV_KEYBOARD_RIGHT && curseur->col < NB_COL - 1){

		other_carre.lig = curseur->lig;
		other_carre.col = curseur->col + 1;

		EchangeCarre(*curseur, other_carre , curseur, plateau);
	}

	fprintf(stderr, "CURSEUR (%d - %d)\n", curseur->lig, curseur->col);


	MLV_actualise_window();
}




void AnnounceWin(MLV_Image * image){
	MLV_draw_text(12,12, "YOU WIN !!!", MLV_COLOR_BLACK, image);
	MLV_actualise_window();
}

void CloseWindow(MLV_Image * image){

	MLV_wait_seconds(5);
	MLV_free_image(image);
	MLV_free_window();
}