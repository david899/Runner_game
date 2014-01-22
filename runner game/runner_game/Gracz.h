#ifndef _GRACZ_H
#define _GRACZ_H

#include "ObiektFizyczny.h"
#include "Vec3.h"
#include <GL\freeglut.h>
#include <stack>
#include "Pole.h"

using namespace std;
class ObiektFizyczny;
class Gracz 
{
public: 
	//zmienne 
	Vec3 pozycja; // pozycja gracza jest jego srodkowym punktem (srodek z x,y,z)
	Vec3 kierunek;
	float predkosc;
	Vec3 szescianAABBmin;
	Vec3 szescianAABBmax;
	float graczX, graczY, graczZ; //szerekosc, dlugosc, wysokosc
	stack<ObiektFizyczny*> stosObiektow;

	//konstruktory
	Gracz();

	///////////////////////////////////////

	//metody
	void rysuj();
	void dodajPredkosc(float _predkosc);
	void update();
};
#endif