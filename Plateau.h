#ifndef __PLATEAU__
#define __PLATEAU__

	/*Dimensions du plateau*/
	#define NB_COL 4
	#define NB_LIG 4

    /*Représentation d'un carré du plateau*/
	typedef struct carre{
		int lig;
		int col;
	}Carre;

    /*Représentation du plateau*/
	typedef struct plateau {
		Carre bloc[NB_COL][NB_LIG];
	}Plateau;

    /*Initialise le plateau 'P'*/
	void InitialisationPlateau(Plateau * P);

#endif