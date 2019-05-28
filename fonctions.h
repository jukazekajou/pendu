#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_NOMDUFICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

#define TAILLEMAX 1000
/* Contenu de votre fichier .h (autres include, prototypes, define...) */
#include "fonctions.h"
#include "main.h"

char lireCaractere();
void moteur(int* nombreDeCoups, char motMystere[], char motMystereCode[], int longueurMotMystere);
void intialisationMotMystereCode(char motMystereCode[], int longueurMotMystere);
void menuDeJeu(char motMystereCode[], int nombreDeCoups);
int recommencer();

// fichiers
int recupererNombreDeMots();
void choixMotMystere(int nombreDeMots, char* motMystere[]);
int random(int nombreDeMots);

#endif



