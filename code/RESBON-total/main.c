//Projet: REBSON, bataille navale de 4 à 10 joueurs.
//Authors: Samuel Roland (SRD) et Benoit Pierrehumbert (BPT)
//Date début: 28.11.2019
//Version: 1.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Toutes les constantes:
#define timebeforehelp 5000 //temps avant d'afficher l'aide.
#define charnbmaxpseudo 20  //nombre de caractères max pour le pseudo.

//Toutes les variables globales:
char pseudo[50];    //pseudo du joueur sur cet ordinateur


//Toutes les fonctions (avant le main !):




int main() {
    //INTRODUCTION ET CONNEXION

    //Variables de la section:
    char wanthelp[50];  //contient 0 ou 1 -> savoir si veut afficher l'aide ou pas ?

    //TODO: Introduction au jeu = Titre + description + ASCII ART

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