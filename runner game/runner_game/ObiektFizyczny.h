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
	Vec3 szescianAABBmin;
	Vec3 szescianAABBmax;
	void (ObiektFizyczny::*wskNaRysuj)();
	vector<ObiektFizyczny*> dzieci;
	TypyObiektow typObiektu;
	// metody
	void rysuj();
	void sprawdzKolizje(Gracz* gracz);
	Vec3 zwrocSrodek();
	// konstruktory
	ObiektFizyczny(Vec3 _pozycja, TypyObiektow _typObiektu);
	
private:
	// te funkcje nie moga byc widoczne dalej, wywolywalne tylko przez wskazniki w rysuj
	void rysujPole(); 
	Vec3 wielkoscPola;
};

#endif