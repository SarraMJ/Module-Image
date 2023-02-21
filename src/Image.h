#include "Pixel.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef _IMAGE_H
#define _IMAGE_H

class Image {

 private :

   Pixel * tab; //: tableau de Pixel     // le tableau 1D de pixel
   unsigned int dimx, dimy; //: entier        // les dimensions de l'image
  SDL_Window * window;
  SDL_Renderer * renderer;

   
   /**
    * @brief Initialise et création de la fenêtre SDL2
    * 
    */
   void afficherInit();

/**
 * @brief Affiche la fenêtre et permet le zoomage avec T, dézoomage avec G ou quitter la fenêtre avec esc (ou la croix) 
 * 
 */
   void afficherBoucle();

/**
 * @brief Détruit la fenêtre générée par SDL2
 * 
 */
   void afficherDetruit();

 public :

  
   /**
 * @brief Constructeur par défaut de la classe
 * Initialise dimx et dimy à 0
 * 
 */
    Image ();

/**
 * 
 * @brief Constructeur de la classe
 * Initialise dimx et dimy (après vérification) puis alloue le tableau de pixel dans le tas (image noire)  puis alloue le tableau de pixel dans le tas (image noire)
 * @param dimensionX 
 * @param dimensionY 
 */
    Image (unsigned int dimensionX, unsigned int dimensionY);

  
   /**
 * @brief  Destructeur de la classe
 * Déallocation de la mémoire du tableau de pixels et mise à jour des champs dimx et dimy à 0
 * 
 */
    ~Image ();

 
   /**
 * @brief Accesseur 
 * Récupère le pixel original de coordonnées (x,y) en vérifiant leur validité 
 * 
 * @param[in] x 
 * @param[in] y 
 * @return Pixel&
 */
   Pixel & getPix ( unsigned int x,  unsigned int y) const; // -> 'Pixel' (l'original, pas une copie)


/**
 *  @brief  Mutateur : modifie le pixel de coordonnées (x,y)
 * 
 * @param[in] x 
 * @param[in] y 
 * @param[in] couleur 
 */
   void setPix ( unsigned int x,  unsigned int y,const Pixel & couleur);


 /**
  * @brief Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris) 

  * 
  * @param[in] Xmin 
  * @param[in] Ymin 
  * @param[in] Xmax 
  * @param[in] Ymax 
  * @param[in] couleur 
  */
   void dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel & couleur) ;


   /**
 * @brief Efface l'image en la remplissant de la couleur en paramètre (en appelant dessinerRectangle avec le bon rectangle)
 * 
 * @param[in] couleur 
 */
   void effacer (const Pixel & couleur);


   /**
 * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
 * 
 */
   void testRegression ();

/**
 * @brief Sauvegarde une image stockée dans un tableau de pixels de la classe Image dans un fichier au format PPM
 * 
 * @param[in] filename 
 */
  void sauver(const std::string & filename) const;

/**
 * @brief Charge une image à partir d'un fichier et stocke ses pixels dans un tableau de pixels de la classe Image.
 * 
 * @param[in] filename 
 */
  void ouvrir(const std::string & filename);

/**
 * @brief  Affiche le contenu de l'image à la console
 * 
 */
  void afficherConsole();

  
  /**
   * @brief Initialise la fenêtre, affiche l'image dans une fenêtre SDL2, et la détruit. 
   * 
   */
 void afficher ();
  
};

#endif
