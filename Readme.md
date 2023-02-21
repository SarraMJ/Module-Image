Module Image

Ce projet permet d'afficher avec SDL2 et de générer une image grâce à un tableau de pixel. 
La classe image définit les dimensions de l'image (dimx, dimy), et contient un pointeur vers un tableau de pixels qui constituent l'image.
Elle contient des accesseurs et mutateurs (GetPix et SetPix) qui permettent de récupérer et modifier les pixels du tableau qui sont données membres privées. 
Elle permet également de dessiner un rectangle sur l'image, de sauvegarder l'image sous format .ppm et d'ouvrir un fichier. 

Avec SDL2, le programme peut initialiser la fenêtre pour afficher l'image, la zoomer et dézoomer, et  détruire la fenêtre quand voulu.   



## Installation
Lien pour cloner le dépôt git: https://forge.univ-lyon1.fr/p2102583/module-image.git 

## L'organisation de l'archive: 

- 12102583_12101522/src  : contient les fichiers sources suivantes: 

                                Pixel.h définit le prototype des fonctions membres de la classe Pixel.
                                Pixel.cpp contient la définition des fonctions  membres de la classe Pixel.
                                Image.h, qui fait appel à Pixel.h, définit le prototype des fonctions membres de la classe Image.
                                Image.cpp, qui fait appel au fichier Image.h, contient la définition des fonctions membres de la classe Image.
                                mainTest.cpp, qui fait appel au fichier Image.h, contient la fonction principale main() 
                                    qui teste plusieurs fonctions membres de la classe Image et produit l'exécutable bin/test.
                                mainExemple.cpp, qui fait appel au fichier Image.h, contient la fonction principale main() 
                                    qui génère deux images et produit l'exécutable bin/exemple.
                                mainAffichage.cpp, qui fait appel à Image.h, contient la fonction principale main() 
                                    qui affiche une image avec SDL2 et produit l'exécutable bin/affichage.


- 12102583_12101522/bin   : contient les trois éxécutables suivantes: 
                                test: exécute mainTest.cpp qui effectue une série de tests vérifiant que le module 
                                    fonctionne et que les données membres de l'objet sont conformes

                                exemple: exécute mainExemple.cpp qui qui créé deux objets d'images "image1" et 
                                    "image2" et dessine des rectangles sur eux en utilisant des pixels colorés.
                                     Il sauvegarde l'image1 dans un fichier sur le disque dur.  L'image2 est 
                                     créée en ouvrant l'image1 puis elle est sauvegardée  dans un autre fichier. 

                                affichage: exécute mainAffichage.cpp qui créé une image de Yoda et l'affiche dans une
                                    fenêtre, créée avec SDL2.


- 12102583_12101522/obj         : contient les fichiers .o 

- 12102583_12101522/data        : contient les images image1.ppm et image2.ppm générées grâce à l'éxécutable exemple

- 12102583_12101522/doc         : contient la documentaton doxygen image.doxy 

- 12102583_12101522/doc/html    : contient index.html la documentation html générée par doxygen



##Compilation

Le projet peut se compiler sous Linux, Windows, en ligne de commande avec un IDE (codeblocks, visual code, QtCreator).
Pour compiler le programme, il y a certaines étapes à suivre: 

- Il faut avoir déjà installé les dépendances requises pour le programme: SDL2 (image), 
    Valgrind et debug (gdb). 
-  On utilise un makefile pour simplifier la compilation de tous les fichiers et on tape la commande ' make ' dans le 
    terminal pour compiler le programme (mais assurez-vous d'être dans le bon répertoire dans le terminal ).
- On peut vérifier les erreurs avec le debug
- Pour vérifier les fuites de mémoires et problèmes d'allocation et d'accès avec Valgrind : valgrind --tool=memcheck --leak-check=full bin/monexecutable
	
Si la compilation réussit, le binaire exécutable sera généré dans le dossier bin.

Pour télécharger SDL2 :
Sous linux : 
	sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
Sous windows et MacOS il faut suivre le guide suivant : https://wiki.libsdl.org/SDL2/Installation

Pout la documentation doxygen : 
- créez le fichier doxygen en tapant:
   doxygen -g doc/image.doxy
 -  personnalisez le fichier doxygen (au minimum INPUT et OUTPUT_DIRECTORY) en tapant :
   gedit doc/image.doxy
 - generez la documentation en tapant:
   doxygen doc/image.doxy
 - ouvrez la page principale générée avec Firefox (ou autre browser) en tapant:
   firefox doc/html/index.html
   
  Ligne de commande pour compiler : 
  	make

## Exécution

Pour exécuter le programme, on ouvre une console dans le dossier où se trouve le makefile, puis on 
exécute la commande suivante (selon le programme qu'on veut exécuter): 
- bin/test
- bin/exemple
- bin/affichage

## Auteurs

Sarra Mejri, numéro étudiant: 12101522
Maya Soufan, numéro étudiant: 12102583
