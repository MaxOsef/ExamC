// Librairies
#include <stdio.h>
#include <stdlib.h>

// Prototypes de fonctions / procédures
void saisieValeur(int tab[4][4]); 
void affichageMatrice(int tab[4][4]); 
int calculDiag(int tab[4][4]); 
int valPaire(int tab[4][4]);
int valImpaire(int tab[4][4]); 

// Programme principal
int main() {
    // Informations sur le concepteur
    printf("----------------------------------------\n");
    printf("Programme realiser par: Maximilien LEBER\n");
    printf("Section:    IRT1\tGroupe:\tG1\n");
    printf("Date version:   12/01/2019\n");
    printf("----------------------------------------\n");
    
    // Déclaration de variables
    int tab_val[4][4] = {0}, produit_diag = 0, val_paire = 0, val_impaire = 0;

    // Exécution du programme
    saisieValeur(tab_val);

    affichageMatrice(tab_val);

    produit_diag = calculDiag(tab_val);
    printf("Produit diagonales : %d", produit_diag);

    val_paire = valPaire(tab_val);
    printf("Quantité : %d", val_paire);

    val_impaire = valImpaire(tab_val);
    printf("Quantité : %d", val_impaire);

    return 0;
}

// Fonctions / Procédures

// Saisie des valeurs et remplissage du tableau
void saisieValeur(int tab[4][4]) {
    int i=0, j=0, val=0;

    printf("\n############################################\n");
    printf("\nRemplissage de la matrice\n");
    printf("\n--------------------------------------------\n");

    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            do {
                printf("Entrez la valeur de la ligne %d, colonne %d : ", i+1, j+1);
                scanf("%d", &val);

                if(val>=0 && val<=10) {
                    tab[i][j] = val;
                } else {
                    printf("\nValeur invalide.\nVeuillez introduire une valeur comprise entre 0 et 10.\n\n");
                }
                
                getc(stdin);
            } while (val<0 || val>10);
        }
    }

    printf("\n--------------------------------------------\n");
}

// Affichage des valeurs du tableau en matrice
void affichageMatrice(int tab[4][4]) {
    int i=0, j=0;

    printf("\n############################################\n");
    printf("\nAffichage de la matrice\n");
    printf("\n--------------------------------------------\n\n");

    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if(i==j || i+j==3) {
                printf("\033[1;31m");
                printf("%d\t", tab[i][j]);
                printf("\033[0m");
            } else {
                printf("%d\t", tab[i][j]); 
            }
        }
        printf("\n\n");
    }

    printf("--------------------------------------------\n");
}

// Calcul du produit des diagonales de la matrice
int calculDiag(int tab[4][4]) {
    int i=0, j=0, total=1;

    printf("\n############################################\n");
    printf("\nCalcul du produit des deux diagonales\n");
    
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if(i==j || i+j == 3) {
                total = total * tab[i][j];
            }
        }
    }

    return total;
}

// Calcul du nombre de valeurs paires
int valPaire(int tab[4][4]) {
    int i=0, j=0, cpt=0;
    printf("\n--------------------------------------------\n");
    printf("\nQuantité de valeurs paires\n");
    
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if(tab[i][j]%2 == 0) {
                cpt++;
            }
        }
    }

    return cpt;
}

// Calcul du nombre de valeurs impaires
int valImpaire(int tab[4][4]) {
    int i=0, j=0, cpt=0;
    printf("\n--------------------------------------------\n");
    printf("\nQuantité de valeurs impaires\n");
    
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            if(tab[i][j]%2 != 0) {
                cpt++;
            }
        }
    }

    return cpt;
}
