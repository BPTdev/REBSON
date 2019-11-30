# REBSON

## Description
Le projet REBSON est un jeu en mode console de la bataille navale qui se joue cependant de 3 à 10 joueurs. Le jeu traditionnel se jouant à deux, de nombreuses règles ont été modifiées. La documentation les explique en détail.

## Génération
Vous aurez besoin de:

- Clion
- un compilateur C
- Un Ordinateur avec Windows
- L'Invite de commandes

Pour générer l'exécutable (sans cloner ou télécharger le repository entier), vous devez:
1. Aller sur le Repository REBSON sur Github [ici](https://github.com/cpnvbenoit/REBSON)
1. Dans le dossier `\code\RESBON-total\` du Repos: prenez le `CMakeLists.txt` et le `main.c`, et le dossier `data` dans `\code\RESBON-total\cmake-build-debug\`.
1. Placez-les dans un dossier en local `rebson_test` (ou autre dossier nommé sans accent ni espace). Ouvrez le `CMakeLists.txt` avec CLion puis ouvrez le main.c avec CLion.
1. Builder le projet dans CLion. Placer le dossier data dans le même dossier que l'éxecutable.

## Exécution
Pour exécuter le programme sans le générer, vous devez:

1. Télécharger en local le fichier `RESBON-total.exe` dans `code\global\cmake-build-debug\` et le dossier `data` qu'il faut placer dans le même dossier que l'éxecutable.
1. Executez le fichier avec l'Invite de commandes.