#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "fonctions.h"
#include <math.h>
#define CHAINEMAX 1000


char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    /* vide buffer */
    while(getchar() != '\n');

    return caractere;
}

void moteur(int* nombreDeCoups, char motMystere[], char motMystereCode[], int longueurMotMystere)
{
int i = 0;
char caractere = lireCaractere();

/* TRICHE */
// La triche fait tout buggé, a refaire apres

    if(strchr(motMystere, caractere) == NULL) //compteur
        {
            *nombreDeCoups -= 1;
        }
    /* COMPARAISON */
    for(i = 0; i < longueurMotMystere; i++)
    {
        if(caractere == motMystere[i])
        {
            motMystereCode[i] = caractere;
        }
    }
}

void intialisationMotMystereCode(char motMystereCode[], int longueurMotMystere)
{
    int i;
    for(i = 0; i < longueurMotMystere; i++)
    {
        motMystereCode[i] = '*';
    }
    /* SINON J AI N IMPORTE QUOI APRES LES ETOILES */
    motMystereCode[i] = '\0';
}

void menuDeJeu(char motMystereCode[], int nombreDeCoups)
{
    printf("\nVeuillez deveninez le mot\n");
    printf("%s\n", motMystereCode);
    printf("Nombre de coups: %d\n", nombreDeCoups);

    printf("\nDevinez une lettre: ");
}

int recommencer()
{
    int choix = 2;
    printf("\nUne autre partie? ");
    while(choix != 0 || choix != 1) // Boucle de securite
    {
    printf("1: Oui\n0: Quitter\n");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1:
            return 1;
            break;
        case 0:
            return 0;
            break;
        default:
            printf("\nJe n'ai pas compris ...");
            break;
    }
    }
}

int recupererNombreDeMots()
{
    int nombreDeMots = 0;
    FILE* dictionnaire = NULL;
    char chaine[TAILLEMAX] = "";
    dictionnaire = fopen("files/dictionnaire.txt", "r");

    if(dictionnaire != NULL)
    {

    printf("Dictionnaire ouvert\n");
    // Calcul du nombre de mots
    while(fgets(chaine, TAILLEMAX, dictionnaire) != NULL)
        {
            nombreDeMots++;
        }

    fclose(dictionnaire);
    }

    // fail
    else
    {
        printf("\ndictionnaire non ouvert ...");
    }


    return nombreDeMots;
}

void choixMotMystere(int nombreDeMots, char* motMystere[])
{

    char buffer[CHAINEMAX] = "";

    FILE* dictionnaire = NULL;
    dictionnaire = fopen("files/dictionnaire.txt", "r");

    /* RANDOM */
    int numeroRandom = random(nombreDeMots);
    int i = 0;

    if(dictionnaire != NULL)
        {
            printf("\nInitialisation du motMystere\n");
            rewind(dictionnaire);
            printf("Numero de seed: %d\n", numeroRandom);
            // BOUCLE DE SES MORTS
            for(i = 0; i != numeroRandom; i++)
            {
                fgets(buffer, CHAINEMAX, dictionnaire);
            }

            /* PATCH POUR PAS AVOIR UN CARACTERE ENTER EN PLUS */
            int vidange = strlen(buffer) - 1;

            buffer[vidange] = '\0'; // Sinon on a un enter en plus dans la chaine

            strcpy(motMystere, buffer); // COPIE DANS LA CHAINE PRINCIPALE


            fclose(dictionnaire);
        }
    else
    {
        printf("Dictionnaire non ouvert");
    }

}

int random(int nombreDeMots)
{
    int min = 0;
    int max = nombreDeMots;
    int numeroRandom = 0;

    numeroRandom = (rand() % (max - min + 1)) + min;
    return numeroRandom;
}
