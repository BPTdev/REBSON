#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define casebatoparpers 10// defini le nombre de cases bateaux par personnes
#define rappcaseplayandtot  3
//defini le rapport entre les nombre de case des joueurs et le total des case

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

int main() {
    int t=0;
    while(1){
    printf("donner moi cb de joueur vous evz oueche");
    scanf("%d",&t);
    larg_grille(t);// le 10 correspond au nombre de joueur
    }
}