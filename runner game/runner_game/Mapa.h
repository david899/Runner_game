#ifndef _MAPA_H
#define _MAPA_H

#include "Pole.h"

class Mapa
{
	
public:
	//zmienne
	const static int xMax = 3, yMax = 4, zMax = 100;
	const static int rozmiarPola = 10;
	Pole plansza[xMax][yMax][zMax]; // tu musze wymyslic jakis sposob na doczytujace sie na biezaco pola oraz czyszczenie tych przebiegnietych
	
	//konstruktory
	Mapa();
	
	//metody
	void rysuj();
	void debugRysuj();
};
#endif