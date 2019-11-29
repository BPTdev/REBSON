/*
 * Benoit Pierrehumbert
 * Bataille Navale
 * 05.04.2019
 * En cours: affichage donnée grille
 */


#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#pragma execution_character_set("utf-8")
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center


#define cote 10

int datagrille[10][10];///bato 1= 1 / compteurbato1   bato2= 2 / compteurbato2   bato3= 3 / compteurbato3

void shipfich() {
    int nombrealeatoire; //nombre aléatoire
    char c;

    srand((unsigned) time(NULL));
    nombrealeatoire = 1 + rand() % 4; //Choisit un nombre aléatoire entre 1 et 4
    FILE *fichier = NULL;
    switch (nombrealeatoire) {
        //Choix d'une des 4 grille
        case 1:
            fichier = fopen("grille/Grille1.txt", "r");
            break;
        case 2:
            fichier = fopen("grille/Grille2.txt", "r");
            break;
        case 3:
            fichier = fopen("grille/Grille3.txt", "r");
            break;
        case 4:
            fichier = fopen("grille/Grille4.txt", "r");
            break;
    }

    // pour eviter que le retour a ligne ou tout autre caractere non souhaiter soit pris avec
    for (int i = 0; i < cote; ++i) {
        for (int j = 0; j < cote; ++j) {
            do {
                c = fgetc(fichier);
                datagrille[i][j] = c - 48;
            } while (c <= 32);
        }
    }
    fclose(fichier);
}

int menu() {
    int resmenu = 0;
    printf("1. Aide\n"
           "2. Jouer\n"
           "3.Quitter\n");
    do {
        resmenu = _getch();
    } while (resmenu != 49 && resmenu != 50 && resmenu != 51);
    return resmenu;
}

int affgrille(int hauteur, int largeur) {
    switch (datagrille[hauteur - 1][largeur - 1]) {
        case 0:
            printf(" "); //cas standard
            break;
        case 1: // si il y a un bato
            printf(" ");
            break;
        case 2: // si il y a un bato
            printf(" ");
            break;
        case 3: // si il y a un bato
            printf(" ");
            break;
        case 10://A lo
            printf("O");
            break;
        case 11://touché
            printf("X");
            break;
        case 12://touché
            printf("X");
            break;
        case 13://touché
            printf("X");
            break;
        case 21://coulé
            printf("%c", 219);
            break;
        case 22://coulé
            printf("%c", 219);
            break;
        case 23://coulé
            printf("%c", 219);
            break;
    }
}

void top(int cotes) {
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("\n");
    printf("   %c", STLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, STRC);
}                          // ┌───┬───┐

int mid(int cotes, int i, int ligne) {
    int a = 1;
    if (i <= 9) {
        printf("\n %d %c", i - 1, SVSB);
    } else if (i == 10) {
        printf("\n %d %c", i - 1, SVSB);
    }
    for (int i = -1; i <= cotes - 3; i++) {
        printf(" ");
        affgrille(ligne, a);
        printf(" %c", SVSB);
        a++;
    }
    printf(" ");
    affgrille(ligne, a);
    printf(" %c", SVSB);

}         // │   │   │

void midmid(int cotes) {
    printf("\n   %c", SVLB);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SVRB);
}                       // ├───┼───┤

void bootom(int cotes) {
    printf("\n   %c", SBLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);
}                       // └───┴───┘

void grille(int Cotes) {
    printf("     A   B   C   D   E   F   G   H   I   J");
    top(Cotes);///OK
    int j;
    int k = 0;
    for (j = 1; j < Cotes; j++) {
        mid(Cotes, j, j);    ///OK
        midmid(Cotes); ///OK
        k = j;
    }

    mid(Cotes, j, k + 1);///OK
    bootom(Cotes); ///OK
    printf("\n");
}

void jouer() {
    printf("INISTALISATION...");
    shipfich();
    system("cls");
    char tir[5];
    int num = 0;
    int lettre;
    int gagner = 0;
    int compteurbato1 = 0;
    int compteurbato2 = 0;
    int compteurbato3 = 0;
    while (gagner == 0) {

        grille(cote);
        // ajouter un syteme qui sait si on a donner la lettre en premier ou pas (A=97/Z=122)
        SetConsoleOutputCP(65001);
        printf("Où voulez-vous tirer ?\n");
        printf("La lettre en premier\n");
        do {
            tir[2] = 0;
            scanf("%s", &tir);
            if (tir[0] < 97 || tir[0] > 106 || tir[1] < 49 || tir[1] > 57 || tir[2] != 0) {
                printf("Ce n'est pas une valeur d'une case !\n");
                printf("Où voulez-vous tirer ?\n");
                printf("La lettre en premier\n");
            }
        } while (tir[0] < 97 || tir[0] > 106 || tir[1] < 48 || tir[1] > 57);
        system("cls");
        lettre = tir[0] - 97;//97 ='a'
        num = tir[1] - 48;


        //si a lo
        if (datagrille[num][lettre] == 0) {
            system("cls");
            SetConsoleOutputCP(65001);
            printf("À l'eau !\n");
            datagrille[num][lettre] = 10;
        }
        //si toucher bato1
        if (datagrille[num][lettre] == 1) {
            system("cls");
            grille(cote);
            if (compteurbato1 != 4) {
                SetConsoleOutputCP(65001);
                system("cls");
                printf("Touché \n");
                datagrille[num][lettre] = 11;
                compteurbato1 += 1;
                if (compteurbato1 == 4) {
                    printf("coulé");
                    for (int i = 0; i < cote; ++i) {
                        for (int j = 0; j < cote; ++j) {
                            if (datagrille[i][j] == 11) {
                                datagrille[i][j] = 21;
                            }
                        }

                    }
                }
                printf(" !\n");
            }
        }
        //si toucher bato2
        if (datagrille[num][lettre] == 2) {
            system("cls");
            grille(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 12;
            compteurbato2 += 1;
            if (compteurbato2 == 3) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 12) {
                            datagrille[i][j] = 22;
                        }
                    }

                }
            }
            printf(" !\n");
        }
        //si toucher bato3
        if (datagrille[num][lettre] == 3) {
            system("cls");
            grille(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 13;
            compteurbato3 += 1;
            if (compteurbato3 == 2) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 13) {
                            datagrille[i][j] = 23;
                        }
                    }

                }
            }
            printf(" !\n");
        }
        if (compteurbato1 == 4 && compteurbato2 == 3 && compteurbato3 == 2) {
            gagner += 1;
        }
    }
    printf("Vous avez gagner !");
    system("pause");
    menu();
}

int Aide() {
    SetConsoleOutputCP(65001);
    printf("Bonjour je suis l'aide de ce jeu.\n");
    printf("Vous aller jouer à la bataille navale. \n"
           "Vous avez demandé l’aide.\n"
           "Les règles sont assez simple : Pour commencer poser vos bateaux en disant au programme les case exemple pour un bateau à 2 cases.\n"
           "Il faut dire au programme A1 et appuyer sur entrer puis taper B1 et appuyer sur entrer. Si vous n’avez pas mis un nombre correct de case à votre bateau (2,3,4) vous ne pourrez pas placer le suivant.\n"
           "Pour tirer veuillez avoir posé vos 9 « bout » de bateau. Une fois ceci fait dite au programme une case tell : C5 et faite entrer.\n"
           "Une fois que vous voyez s’afficher : Touché c’est que vous avez touché un bateau, chercher alors autour pour pouvoir lui faire sa fête.\n"
           "Une fois tous les bateaux couler vous avez gagné.\n");

}

int main() {
    int omenu = 0;//option menu
    omenu = menu();
    int quitter = -1;

        switch (omenu) {
            case 49:
                system("cls");
                Aide();
                system("pause");
                system("cls");
                menu();
                break;
            case 50:
                system("cls");
                jouer();
                break;
            case 51:
                system("cls");
                printf("Voulez-vous vraimment quitter?"
                       "\n0=Oui, 1=Non");
                scanf("%d", &quitter);

                if (quitter == 0) {
                    return 0;
                } else if (quitter == 1) {
                    menu();
                }
                break;
        }



    return 0;
}

