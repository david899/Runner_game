#ifndef _MAPA_H
#define _MAPA_H

#include<vector>
#include"ObiektFizyczny.h"
using namespace std;
class ObiektFizyczny;

class Mapa
{
public:
	//zmienne
	vector<ObiektFizyczny*> wektorPol;
	
	//konstruktory
	Mapa();
	
	//metody
	void rysuj();
	void debugRysuj();
	void generujPola(int ilePol);
	void generujPola(int ileWygenerowac, int ileUsunac);
private:
	static const int iloscPolStartowych = 30;
};
#endif