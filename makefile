# Makefile TP3

CC= gcc
CFLAGS=  -Wall -ansi -pedantic -lMLV
FICHIER_O= *.o
F1= Main
F2= Plateau
F3= Moteur
F4= Graphique

EXECUTABLES= $(F1)
CLEAN_EXEC_RULE= make clean_exec

all:
	make main


main: $(F1).o $(F2).o $(F3).o $(F4).o
		$(CC) -o $(F1) $(F1).o $(F2).o $(F3).o $(F4).o -lMLV
		$(CC) -c Main.c $(CFLAGS)
		$(CLEAN_EXEC_RULE)

plateau: Plateau.o
		$(CC) -o $(F2) -lMLV
		$(CC) -c Plateau.c $(CFLAGS)


moteur: Moteur.o
		$(CC) -o $(F3)
		$(CC) -c Plateau.c $(CFLAGS)

graphique: Graphique.o
		$(CC) -o $(F4)
		$(CC) -c Graphique.c $(CFLAGS)	



clean_exec:
	rm -f $(FICHIER_O)

clean:
	rm -f $(FICHIER_O) $(EXECUTABLES)
