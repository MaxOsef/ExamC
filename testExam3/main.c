// Librairies
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Prototypes de fonctions / procédures
int menu(); 
void reglesJeu(); 
void nouvellePartie(); 
void arret(); 

// Programme principal
int main() {
    // Informations sur le concepteur
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");
    printf("\n\nAppyer sur \"Entrer\" pour continuer...");
    getc(stdin);
    
    // Déclaration de variables
    int choix = 0, continuer=1;
    
    // Exécution du programme
    do {
        choix = menu();

        switch(choix) {
            case 1:
                //nouvellePartie();
                continuer = 1;
                break;
            case 2:
                reglesJeu();
                continuer = 1;
                
                break;
            case 3:
                arret();
                return 0;
            default:
                printf("Entree invalide. Recommencez.");
                continuer = 1;
                break;
        }
    } while (continuer == 1);

    return 0;
}

// Fonctions / Procédures

// Affichage du menu
int menu() {
    int choix;
    char c;

    do {
        system("clear");
        printf("\n\n########################################\n");
        printf("------------- Jeu du pendu -------------\n");
        printf("\n1:\tNouvelle partie\n2:\tRegles du jeu\n3:\tQuitter");
        printf("\n\n\tFaites votre choix: ");
        c = getchar();
        choix = c - '0';
        while(c = getchar() != '\n' && c != EOF);

        if ( isalpha(choix) ||  (choix<1 || choix>3) ) {
            printf("Selection invalide. Recommencez !");
            choix = 0;
        } else {
            return choix;
        }
    } while (choix<1 || choix>3);
}

// Affichage des règles du jeu
void reglesJeu() {
    system("clear");
    printf("########################################\n");
    printf("------------ Regles du jeu -------------\n");
    printf("\nVICTOIRE:\n\nLe joueur gagne s'il decouvre toutes les\nlettres du mot recherche avant que le\npersonnage ne soit pendu.");
    printf("\n\nDEFAITE:\n\nLe joueur perd s'il commet sept erreurs.");
    printf("\n\nAppyer sur \"Entrer\" pour continuer...");
    getc(stdin);
}

// Arret du programme
void arret() {
    system("clear");
    printf("\n\tArret du programme...\n\nAppyer sur \"Entrer\" pour continuer...");
    getc(stdin);
}

// Nouvelle partie
void nouvellePartie() {
    system("clear");
    printf("/!\\Debut de la partie /!\\\n");
    
    printf("\n\nAppyer sur \"Entrer\" pour continuer...");
    getc(stdin);
}
