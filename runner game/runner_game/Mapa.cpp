#include "Mapa.h"

Mapa::Mapa()
{
	Vec3 pos = Vec3(0,0,0);
	Vec3 przesuniecie = Vec3(0,0,10.0f);
	// tworzy int iloscPolStartowych pol na przod oraz wypelnia je losowo 
	for(int i = 0; i < iloscPolStartowych; i++)
	{
		ObiektFizyczny* pole = new ObiektFizyczny(pos,TypyObiektow::typPole);
		pos += przesuniecie;
		wektorPol.push_back(pole);
	}
	// w powyzszej petli powineinem jeszcze dodawac inne obiekty do moich pol
}
void Mapa::rysuj()
{
	vector<ObiektFizyczny*>::iterator it;
	for(it = wektorPol.begin(); it != wektorPol.end(); it++)
	{
		(*it)->rysuj();
	}
}
void Mapa::debugRysuj()
{
	vector<ObiektFizyczny*>::iterator it;
	for(it = wektorPol.begin(); it != wektorPol.end(); it++)
	{
		(*it)->debugRysuj();
	}
}
void Mapa::generujPola(int ilePol)
{
	// metoda kasuje pola za graczem oraz dodaje pola przed graczem w ilosci - int ilePol 
}
void Mapa::generujPola(int ileWygenerowac, int ileUsunac)
{
	// metoda kasuje pola za graczem oraz dodaje pola przed graczem w ilosci - int ilePol 
}