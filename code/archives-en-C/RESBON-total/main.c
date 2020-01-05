//Projet: REBSON, bataille navale de 4 à 10 joueurs.
//Authors: Samuel Roland (SRD) et Benoit Pierrehumbert (BPT)
//Date début: 28.11.2019
//Version: 1.1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

//Toutes les constantes:
#define timebeforehelp 5000 //temps avant d'afficher l'aide.
#define charnbmaxpseudo 20  //nombre de caractères max pour le pseudo.
#define casebatoparpers 10// defini le nombre de cases bateaux par personnes
#define rappcaseplayandtot  5//defini le rapport entre les nombre de case des joueurs et le total des case
#define systemcolor "color 09"    //color du jeu donc police et arrière plan.

//TABLEAU DOUBLE-BANDE:
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center

//Symboles sur la grille:
#define cazblanc 254    //caractère case blanche. ■

//Toutes les variables globales:
char pseudo[50];    //pseudo du joueur sur cet ordinateur
#define DIMENSIONSTABLEAU 16
int typegrille = 1; //Type de la grille. exemple aide, placement des bateaux ou jeu.

int grilleexemple[DIMENSIONSTABLEAU][DIMENSIONSTABLEAU] = {     //Grille définie slt pour l'aide. pas dans un fichier externe car 22 = deux caractères.
        22, 22, 0, 0, 0, 0, 11, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, 0, 0, 23, 0, -1, 0, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, -1, 0, 0, 0, 0, -1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 22, 2
};


int grillejeu[DIMENSIONSTABLEAU][DIMENSIONSTABLEAU] = {     //Grille définie slt pour l'aide. pas dans un fichier externe car 22 = deux caractères.
        22, 22, 0, 0, 0, 0, 11, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, 0, 0, 23, 0, -1, 0, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, -1, 0, 0, 0, 0, -1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 22, 2
};


//Toutes les fonctions (avant le main !):

void printdatajeu(int i, int l) {  //i= numero de la ligne. l= numero de la case (en partant de 1 !).
    //SLT pou la grillejeu !
    switch (grillejeu[i - 1][l - 1]) {
        case 0:
            printf(" ");
            break;
        case 1:
        case 2:
        case 3:
            printf(" ");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("O");
            break;
        case 21:
        case 22:
        case 23:
            printf("%c", cazblanc);
            break;
    }
}

//Fait simplement trois traits double horizontaux:
void traits3horiz() {
    printf("%c%c%c", DHSB, DHSB, DHSB);
}

//Lignes début et fin:
void lignesuperieurgrille(int Dimensions) {
    printf("    %c", DTLC);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DHTB);
    }
    traits3horiz();
    printf("%c\n", DTRC);
}

void ligneinferieurgrille(int Dimensions) {
    printf("    %c", DBLC);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╩
        traits3horiz();
        printf("%c", DHBB);
    }
    traits3horiz();
    printf("%c\n", DBRC);
}

void printdataex(int i, int l) {  //i= numero de la ligne. l= numero de la case (en partant de 1 !).
    //SLT pou la grilleexemple !
    switch (grilleexemple[i - 1][l - 1]) {
        case 0:
            printf(" ");
            break;
        case 1:
        case 2:
        case 3:
            printf(" ");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("O");
            break;
        case 21:
        case 22:
        case 23:
            printf("%c", cazblanc);
            break;
    }
}

//Lignes entre deux:
void lignedonneegrille(int i, int Dimensions) {
    int l = 1;    //numero de case.

    if (i < 10) {
        printf("  %d %c ", i, DVSB);    // ça fera ça ║
    } else {
        printf(" %d %c ", i, DVSB);    // ça fera ça ║
    }
    for (int b = 1; b < Dimensions; b++) {
        //Si 0 alors grille d'exemple de l'aide. Si 1 alors grille de jeu.
        if (typegrille == 0) {
            printdataex(i, l);
        } else {
            printdatajeu(i, l);
        }
        printf(" %c ", DVSB);
        l++;    //Colonne suivante.
    }
    if (typegrille == 0) {
        printdataex(i, l);
    } else {
        printdatajeu(i, l);
    }
    printf(" %c\n", DVSB);
}

void lignemilieugrille(int Dimensions) {
    printf("    %c", DVLB);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DC);
    }
    traits3horiz();
    printf("%c\n", DVRB);
}

void Affgrille() {  //permet d'afficher toutes la grille

    if (typegrille == 1) {
        system("cls");
        SetConsoleOutputCP(65001); // For accented characters
        printf("Bataille Navale – Partie en cours\n\n");
    }
    //Ensemble des types de lignes:
    SetConsoleOutputCP(437); // For semi-graphic characters
    //Ec
    char c = 65;
    printf("      ");    //espace avant les lettres des colonnes
    for (int i = 0; i < DIMENSIONSTABLEAU; ++i) {
        printf("%c   ", c); //Lettres des colonnes
        c += 1; //Lettre suivante avec code ASCII
    }
    printf("\n");
    lignesuperieurgrille(DIMENSIONSTABLEAU);
    for (int row = 0; row < DIMENSIONSTABLEAU; row++) {
        if (row > 0) {
            lignemilieugrille(DIMENSIONSTABLEAU);
        }
        lignedonneegrille(row + 1, DIMENSIONSTABLEAU);
    }
    ligneinferieurgrille(DIMENSIONSTABLEAU);

    // légende des symboles:
    SetConsoleOutputCP(65001); // For accented characters
    printf("   Légende:\n"
           "   X = A l'eau\n"
           "   O = Touché (bateau)\n"
           "   ■ = Coulé (le bateau est touché en entier)\n");
    //A compléter...
}


int larg_grille(int nbjoueur){
    /* taille bateaux :
 * 1,
 * 2,
 * 3,
 * 4
 * total 10 case bateaux par personne
 * rapport nb case personne / case total = 20%
 * si 4 joueurs case joueurs =40 case grille =~200 case
 * 200 case = grille de 15/15
 * calcul largeur: 200^(1/2)
 * calcul case total: (nb_joueurs * 10)*5 => 4*10*5
 * calcul entier: (4*10*5)^(1/2)*/
    float largnotarr = 0;
    int res = 0;
    largnotarr = (nbjoueur*casebatoparpers*rappcaseplayandtot);
    largnotarr = sqrt(largnotarr);
    res = round(largnotarr) ;
    //printf(" il faut une grille de %d cases de cote\n",res);
    //system("pause");
    return res;
}//calcule


int main() {
    //INTRODUCTION ET CONNEXION

    //Variables de la section:
    char wanthelp[50];  //contient 0 ou 1 -> savoir si veut afficher l'aide ou pas ?

    //TODO: Introduction au jeu = Titre + description + ASCII ART
    //Application de la couleur:
    system(systemcolor);

    //ASCII ART du jeu:
    printf("                                                                                                                            \n"
           "                                                                                                                            \n"
           "RRRRRRRRRRRRRRRRR     EEEEEEEEEEEEEEEEEEEEEE  BBBBBBBBBBBBBBBBB        SSSSSSSSSSSSSSS        OOOOOOOOO       NNNNNNNN        NNNNNNNN\n"
           "R::::::::::::::::R    E::::::::::::::::::::E  B::::::::::::::::B     SS:::::::::::::::S     OO:::::::::OO     N:::::::N       N::::::N\n"
           "R::::::RRRRRR:::::R   E::::::::::::::::::::E  B::::::BBBBBB:::::B   S:::::SSSSSS::::::S   OO:::::::::::::OO   N::::::::N      N::::::N\n"
           "RR:::::R     R:::::R  EE::::::EEEEEEEEE::::E  BB:::::B     B:::::B  S:::::S     SSSSSSS  O:::::::OOO:::::::O  N:::::::::N     N::::::N\n"
           "  R::::R     R:::::R    E:::::E       EEEEEE    B::::B     B:::::B  S:::::S              O::::::O   O::::::O  N::::::::::N    N::::::N\n"
           "  R::::R     R:::::R    E:::::E                 B::::B     B:::::B  S:::::S              O:::::O     O:::::O  N:::::::::::N   N::::::N\n"
           "  R::::RRRRRR:::::R     E::::::EEEEEEEEEE       B::::BBBBBB:::::B    S::::SSSS           O:::::O     O:::::O  N:::::::N::::N  N::::::N\n"
           "  R:::::::::::::RR      E:::::::::::::::E       B:::::::::::::BB      SS::::::SSSSS      O:::::O     O:::::O  N::::::N N::::N N::::::N\n"
           "  R::::RRRRRR:::::R     E:::::::::::::::E       B::::BBBBBB:::::B       SSS::::::::SS    O:::::O     O:::::O  N::::::N  N::::N:::::::N\n"
           "  R::::R     R:::::R    E::::::EEEEEEEEEE       B::::B     B:::::B         SSSSSS::::S   O:::::O     O:::::O  N::::::N   N:::::::::::N\n"
           "  R::::R     R:::::R    E:::::E                 B::::B     B:::::B              S:::::S  O:::::O     O:::::O  N::::::N    N::::::::::N\n"
           "  R::::R     R:::::R    E:::::E       EEEEEE    B::::B     B:::::B              S:::::S  O::::::O   O::::::O  N::::::N     N:::::::::N\n"
           "RR:::::R     R:::::R  EE::::::EEEEEEEE:::::E  BB:::::BBBBBB::::::B  SSSSSSS     S:::::S  O:::::::OOO:::::::O  N::::::N      N::::::::N\n"
           "R::::::R     R:::::R  E::::::::::::::::::::E  B:::::::::::::::::B   S::::::SSSSSS:::::S   OO:::::::::::::OO   N::::::N       N:::::::N\n"
           "R::::::R     R:::::R  E::::::::::::::::::::E  B::::::::::::::::B    S:::::::::::::::SS      OO:::::::::OO     N::::::N        N::::::N\n"
           "RRRRRRRR     RRRRRRR  EEEEEEEEEEEEEEEEEEEEEE  BBBBBBBBBBBBBBBBB      SSSSSSSSSSSSSSS          OOOOOOOOO       NNNNNNNN         NNNNNNN\n"
           "                                                                                                                                      \n\n");

    //Message d'introduction:
    printf("Bienvenue sur REBSON, la bataille navale de 4 à 10 joueurs ! \n"
           "Comme dans le jeu traditionnel, vous êtes en pleine mer et d'autres bateaux ennemis ne sont pas loin. La mer ne fait pas 8x8 cases mais varie selon le nombres de joueurs. Vous êtes le capitaine de 4 bateaux plus ou moins grand et vous devez les maintenir le plus longtemps en vie. \n"
           "A chaque tour, tous les joueurs tireront dans la mer pour essayer de vous toucher. Mais attention puisque il y a beaucoup de camps ennemis, si vous faites attaquer, d'autres ennemis seront attirés ! Votre bateau ne survivra pas longtemps... \n"
           "\n"
           "Bonne chance à vous...\n\n\n");

    //TODO: Demander si veut lire l'aide après timebeforehelp millisecondes
    printf("Voulez-vous lire l'aide du jeu ?");
    do {
        scanf("%s", &wanthelp);
    } while (wanthelp[0] != '0' && wanthelp[0] != '1');

    //TODO: Afficher l'aide si demandé


    //TODO: Message si pas d'aide


    //TODO: Demander et prendre un pseudo au joueur + vérifier qu'il n'est pas déjà pris
    printf("Votre pseudo pour cette partie: ");
    //Prendre le pseudo:
    int isinstring;
    do {
        scanf("%s", &pseudo);
        if (strlen(pseudo) > charnbmaxpseudo) { //vérifie que inférieur au max
            printf("Nom trop long recommencez svp ! ");
        } else {
            printf("Bienvenue %s ...", pseudo);
        }
    } while (strlen(pseudo) > 20);

    //TODO: Se connecter à une partie

    //TODO: Permettre de placer ses 4 bateaux

    //TODO: Montrer les joueurs en ligne et faire attendre avant de commencer la partie

    //Calculer et appliquer la largeur de la grille en fonction des joueurs.


    //TODO: compteur avant lancement de la partie

    //PARTIE ENTIERE





    //AFFICHAGE DES SCORES
    //TODO: Afficher les personnes avec leur points et dans l'ordre decroissant


    //Pour les tests
    printf("\n\n\n\n");
    system("pause");
    return 0;
}
//Pas de fonction APRèS LE MAIN !!
//--FIN du CODE