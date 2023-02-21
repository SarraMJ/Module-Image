

#ifndef _PIXEL_H
#define _PIXEL_H

/**
 * \class Pixel 
 * 
 */
class Pixel {

 private :

   unsigned char r,g,b; //entier (0..255)   les composantes du pixel, unsigned char en C++

 public :




/**
 * @brief Constructeur par défaut de la classe
 * Initialise le pixel à la couleur noire
 * 
 */
    Pixel ();

/**
 * @brief Constructeur de la classe
 * Initialise r,g,b avec les paramètres
 * 
 * @param[in] nr 
 * @param[in] ng 
 * @param[in] nb 
 */
    Pixel (unsigned char nr, unsigned char ng, unsigned char nb);

/**
 * @brief Accesseur 
 * Récupère la composante rouge du pixel
 * 
 * @return unsigned char 
 */
   unsigned char getRouge ()const;

/**
 * @brief   Accesseur 
 * Récupère la composante verte du pixel 
 * @return unsigned char 
 */
   unsigned char getVert ()const; 

/**
 * @brief  Accesseur 
 * Récupère la composante bleue du pixel
 * @return unsigned char 
 */
   unsigned char getBleu () const; 

/**
 * @brief Mutateur 
 * Modifie la composante rouge du pixel
 * @param[in] nr
 */
   void setRouge (unsigned char nr);

   
   /**
    * @brief Mutateur
    * Modifie la composante verte du pixel
    * 
    * @param[in] ng 
    */
   void setVert (unsigned char ng);

   
   /**
    * @brief Mutateur 
    * Modifie la composante bleue du pixel
    * 
    * @param[in] nb 
    */
   void setBleu (unsigned char nb);

};

#endif