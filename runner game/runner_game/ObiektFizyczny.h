#ifndef _OBIEKTFIZYCZNY_H
#define _OBIEKTFIZYCZNY_H

#include "Gracz.h"
#include "TypyRunner.h"
#include <vector>
#include <stack>
#include "Vec3.h"
#include <GL\freeglut.h>
#include <stdio.h>

class Gracz;

using namespace std;

class ObiektFizyczny
{
public:
	// zmienne
	Vec3 pozycja;
	Vec3 szescianAABB; // wielkosc szescianu 
	Vec3 szescianAABBmin;
	Vec3 szescianAABBmax;
	void (ObiektFizyczny::*wskNaRysuj)();
	vector<ObiektFizyczny*> dzieci;
	TypyObiektow typObiektu;
	Vec3 wielkoscPola;
	// metody
	void rysuj();
	void debugRysuj(); // debugRysuj - zamiast obiektow rysuje ich sfery kolizji
	void sprawdzKolizje(Gracz* gracz);
	Vec3 zwrocSrodek();
	Vec3 zwrocSrodekAABB();
	// konstruktory
	ObiektFizyczny(Vec3 _pozycja, TypyObiektow _typObiektu);
	
private:
	// te funkcje nie moga byc widoczne dalej, wywolywalne tylko przez wskazniki w rysuj
	void rysujPole(); 
	
};

#endif