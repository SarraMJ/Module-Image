OBJ = obj/Image.o obj/Pixel.o 

COMPILER = g++

CFLAGS = -g -Wall

LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL

all: folders bin/test bin/exemple bin/affichage docs

folders:
	mkdir -p obj bin data

bin/test: $(OBJ) obj/mainTest.o
	$(COMPILER) $(OBJ) obj/mainTest.o -o bin/test $(LIBS_SDL) 

bin/exemple: $(OBJ) obj/mainExemple.o
	$(COMPILER) $(OBJ) obj/mainExemple.o -o bin/exemple $(LIBS_SDL) 

bin/affichage: $(OBJ) obj/mainAffichage.o
	$(COMPILER) $(OBJ) obj/mainAffichage.o -o bin/affichage $(LIBS_SDL)

obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h 
	$(COMPILER) $(CFLAGS) -c src/mainAffichage.cpp  -o obj/mainAffichage.o
	
obj/mainExemple.o: src/mainExemple.cpp src/Image.h src/Pixel.h
	$(COMPILER) $(CFLAGS) -c src/mainExemple.cpp -o obj/mainExemple.o

obj/mainTest.o: src/mainTest.cpp src/Image.h src/Pixel.h
	$(COMPILER) $(CFLAGS) -c src/mainTest.cpp -o obj/mainTest.o

obj/Image.o: src/Image.cpp src/Image.h src/Pixel.h
	$(COMPILER) $(CFLAGS) -c src/Image.cpp -o obj/Image.o

obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(COMPILER) $(CFLAGS) -c src/Pixel.cpp -o obj/Pixel.o

docs: doc/image.doxy
	doxygen doc/image.doxy

clean:
	rm -rf obj/* bin/* doc/html callgrind.out.*