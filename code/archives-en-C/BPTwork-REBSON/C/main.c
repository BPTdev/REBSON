#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define casebatoparpers 10// defini le nombre de cases bateaux par personnes
#define rappcaseplayandtot  5//defini le rapport entre les nombre de case des joueurs et le total des case

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
    printf(" il faut une grille de %d cases de cote\n",res);
    system("pause");
}
void shipfich() {
    int nombrealeatoire; //nombre aléatoire
    char c;
    /*
     * indexof =  strchr (variable avec le text (string),'caractere chercher' )
     *structure = !id;pseudo/
     * en faisant la differance entre les valeur des "strchr ()" = nombre de caractere a prendre pour l'id ou le pseudo
     * Dans id.txt !01;Tapix72/
     * */
    FILE *fichier = NULL;
    fichier = fopen("id.txt", "r");
    // pour eviter que le retour a ligne ou tout autre caractere non souhaiter soit pris avec
    for (int i = 0; i < cote; ++i) {
        for (int j = 0; j < cote; ++j) {
            do {
                c = fgetc(fichier);//prend le premiere caractere la fois suvante prend le suivant

            } while (c <= 32);
        }
    }
    fclose(fichier);
}
int stringcontainchar(char string[50], char chartest) { //est-ce qu'un caractère est dans un chaine
    printf("longueur chaine = %d", strlen(string));
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == chartest) {
            return 1;    //le caractère existe dans la chaine
        }
    }
    return 0;   //le caractère n'existe PAS dans la chaine
}
int main() {
    larg_grille(10);// le 10 correspond au nombre de joueur
}