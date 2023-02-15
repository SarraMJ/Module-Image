#include "Image.h"
#include <iostream>
using namespace std;

int main() {
 
    Pixel rouge (120, 15, 10);
    Pixel vert (20, 202, 15);
    Pixel bleu (4, 58, 218);
 
    Image image1 (64,48);
    image1.effacer(bleu);
    image1.dessinerRectangle(5, 20, 30, 40, rouge);
    image1.setPix(51,4,vert);
    image1.setPix(20,30,vert);
    image1.sauver("try.txt");
 
    Image image2;
    image2.ouvrir("try.txt");
    image2.dessinerRectangle(29, 10, 48, 15, rouge);
    image2.dessinerRectangle(25, 24, 40, 45, vert);
    image2.sauver("try.txt");
 
    return 0;
}