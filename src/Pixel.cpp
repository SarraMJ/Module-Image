#include <iostream>
#include "Pixel.h"

using namespace std;

/**
 * \class Pixel 
 * 
 */


/**
 * @brief Construct a new Pixel:: Pixel object
 * 
 */
Pixel::Pixel () {
    r = 0;
    g = 0;
    b = 0;
}
/**
 * @brief Construct a new Pixel:: Pixel object
 * 
 * @param nr 
 * @param ng 
 * @param nb 
 */
Pixel::Pixel (unsigned char nr, unsigned char ng, unsigned char nb) {
    r = nr;
    g = ng;
    b = nb;
}
/**
 * @brief 
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getRouge() const {
    return r;
}
/**
 * @brief 
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getVert() const {
    return g;
}
/**
 * @brief 
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getBleu() const {
    return b;
}
/**
 * @brief 
 * 
 * @param nr 
 */
void Pixel::setRouge(unsigned char nr) {
    r = nr;
}
/**
 * @brief 
 * 
 * @param ng 
 */
void Pixel::setVert(unsigned char ng) {
    g = ng;
}

/**
 * @brief 
 * 
 * @param nb 
 */
void Pixel::setBleu(unsigned char nb) {
    b = nb;
}





