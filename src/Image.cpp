#include <iostream>
#include <fstream>
#include "Image.h"
#include <assert.h>

using namespace std;


/** \mainpage
 * @brief  LIFAPCD
 * @author Sarra Mejri p2101522, Maya Soufan p2102583
 * 
 * \class Image
 */


Image::Image(){
   
    dimx=0; 
    dimy=0;
    tab = nullptr;
}



Image::Image (unsigned int dimensionX, unsigned int dimensionY) {

    assert(dimensionX> 0 && dimensionY> 0);
    dimx = dimensionX; 
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy]; 
    Pixel p;
    for (unsigned int i = 0; i< dimx*dimy; i++) {
        tab[i] = p;
    }
}


Image::~Image () {
    dimx = 0;
    dimy = 0;
    if (tab != nullptr) {
        delete [] tab;
        tab = nullptr;  
    }

}


Pixel & Image::getPix(unsigned int x, unsigned int y) const {
   assert(x < dimx );
   assert(x>= 0);
   assert(y>= 0);
   assert(y < dimy);
   return tab[y*dimx+x]; 
} 


void Image::setPix(unsigned int x, unsigned int y,  const Pixel & couleur) {
    assert( x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);
    assert(tab != nullptr);
    getPix(x,y)=couleur; 

}


void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax,unsigned int Ymax, const Pixel & couleur)  {
    for (unsigned int i = Xmin; i<= Xmax; i++) {
        for (unsigned int j = Ymin; j <= Ymax; j++) {
            setPix(i,j,couleur);
        }
    }
}



void Image::effacer(const Pixel & couleur) {
        dessinerRectangle(0,0,dimx-1, dimy-1, couleur);
}



void Image::testRegression() {
    
    //test constructeur par défaut 
 
    Image test_constructeur;
    assert(test_constructeur.dimx==0);
    assert(test_constructeur.dimy==0);
    assert(test_constructeur.tab==nullptr);
    
    //test constructeur par copie

    Image image_test(64,128);
    assert(image_test.dimx==64);
    assert(image_test.dimy==128);
    assert( image_test.tab!=nullptr );
    
   for(unsigned int i=0;i<image_test.dimx ; i++)
   {
    for(unsigned int j=0;j<image_test.dimy; j++)
      {
          assert(image_test.getPix(i, j).getRouge()==0 && image_test.getPix(i,j).getVert() == 0 
          && image_test.getPix(i,j).getBleu()==0);   // car une image en sortie du constructeur doit être toute noire
      } 
   }
    

  //  test GetPix
    
    //test coordonées (0,0)
    assert(image_test.getPix(0,0).getRouge() == image_test.tab[0].getRouge());
    assert(image_test.getPix(0,0).getVert() == image_test.tab[0].getVert());
    assert(image_test.getPix(0,0).getBleu() == image_test.tab[0].getBleu());
    

    //test coordonnées (dimx, dimy)
    assert(image_test.getPix(image_test.dimx-1,image_test.dimy-1).getRouge() == image_test.tab[image_test.dimx*image_test.dimy-1].getRouge());
    assert(image_test.getPix(image_test.dimx-1,image_test.dimy-1).getVert() == image_test.tab[image_test.dimx*image_test.dimy-1].getVert());
    assert(image_test.getPix(image_test.dimx-1,image_test.dimy-1).getBleu() == image_test.tab[image_test.dimx*image_test.dimy-1].getBleu());

    // test modifier la couleur avec getPix et SetPix 

    Pixel couleur1(250,240,230);

    image_test.setPix(5, 5, couleur1);
    assert(image_test.getPix(5,5).getRouge()==250 
        && image_test.getPix(5,5).getVert() == 240
        && image_test.getPix(5,5).getBleu()==230);

    // test dessinerRectangle

    Pixel c(125,167,89);
    image_test.dessinerRectangle(20,20,50,50,c);

    for (unsigned int i = 20; i <= 50; i++) 
    {
        for (unsigned int j =20; j<= 50 ; j++) 
        {
                    assert(image_test.getPix(i,j).getRouge() == 125
                    && image_test.getPix(i,j).getVert()==167
                    && image_test.getPix(i,j).getBleu()==89);

        }
    } 

    //  test effacer

    Pixel couleur2(170,200,180);
    image_test.effacer(couleur2);
     for ( unsigned int i = 0; i < image_test.dimx; i++) 
     {
        for (unsigned int j = 0; j < image_test.dimy; j++) 
        {
                    assert(image_test.getPix(i,j).getRouge() == 170
                    && image_test.getPix(i,j).getVert()==200
                    && image_test.getPix(i,j).getBleu()==180);

        }
    } 

}



void Image::sauver(const std::string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}


void Image::ouvrir(const std::string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx >= 0 && dimy >= 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}



void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}


void Image::afficherInit() {
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
        // Creation de la fenetre
    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	//Remplir l'écran de gris clair
    SDL_SetRenderDrawColor(renderer, 192,192,192,255);
    SDL_RenderClear(renderer);
}


void Image::afficherBoucle() {
    
    SDL_Event events;
	bool quit = false; 
    float zoom = 1; 

    // tant que ce n'est pas la fin ...
	while (!quit) {


		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_T:
					 {
                        zoom = zoom * 1.5;

                     }
					break;
				case SDL_SCANCODE_G:
					    {
                        zoom = zoom * 0.5; 
                       
                        }
					break;
                case SDL_SCANCODE_ESCAPE:
                    quit = true;

                    break;
				default: break;
				}
			}
		}

 
	
        float xcenter = ((200 - (dimx * zoom))/ 2); //calcule la coordonnée x du centre de l'image 
        float ycenter = ((200 - (dimy * zoom))/ 2); //calcule la coordonnée y du centre de l'image 
        for (unsigned int i = 0; i <dimx; i++) {
                            for (unsigned int j=0; j<dimy; j++) {
                                Pixel pi = getPix(i, j);
                                SDL_SetRenderDrawColor(renderer, pi.getRouge(), pi.getVert(), pi.getBleu(), 255);
                                SDL_Rect zoomy; 
                                zoomy.h = zoom;
                                zoomy.w = zoom;
                                zoomy.x = (float)(i*zoom+xcenter);
                                zoomy.y= (float)(j*zoom+ycenter);
                                SDL_RenderFillRect(renderer, &zoomy); 
                            }
                        }


		//affiche
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

	}
}

void Image::afficherDetruit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}


void Image::afficher() {
    afficherInit();
    afficherBoucle();
    afficherDetruit();

}