#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef DEF_NOMDUFICHIER // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_NOMDUFICHIER // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */
#include "main.h"
#include "fonctions.h"
#define CHAINEMAX 1000



#endif

int main()
{
    int nombreDeMots = recupererNombreDeMots();
    srand(time(NULL));




    do { // SUPRABOUCLE DE JEU

    char motMystere[CHAINEMAX] = "";

    choixMotMystere(nombreDeMots, motMystere);
    printf("%s\n", motMystere);

    int longueurMotMystere = strlen(motMystere);

    int nombreDeCoups = 10;

    printf("Longueur du mot: %d\n", longueurMotMystere);


    char* motMystereCode = NULL; // Creation dynamique motMystereCode
    motMystereCode = malloc(longueurMotMystere * sizeof(char));

    /* INITIALISATION DU MOT CODE */
    intialisationMotMystereCode(motMystereCode, longueurMotMystere);

    // on commence le jeux


    /* LE MOTEUR DU JEU */
    do {
    menuDeJeu(motMystereCode, nombreDeCoups);

    moteur(&nombreDeCoups, motMystere, motMystereCode, longueurMotMystere);

    } while(strcmp(motMystere, motMystereCode) != 0 && nombreDeCoups >= 1);


    if(strcasecmp(motMystere, motMystereCode) == 0) // VICTOIRE
    {
        printf("\nFelicitation tu as devine le mot en %d coups !!\n", nombreDeCoups);
    }
    else
    {
        printf("\nDommage, tu as finis pendu !!\n");
    }

    free(motMystereCode);

    }while(recommencer() != 0);





    return 0;
}
