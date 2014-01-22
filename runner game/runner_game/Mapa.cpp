#include "Mapa.h"

Mapa::Mapa()
{
	for (int x = 0; x < xMax; x++)
	{
		for(int y = 0; y < yMax; y++)
		{
			for (int z = 0; z < zMax; z++)
				plansza[x][y][z] = Pole(x * rozmiarPola, y * rozmiarPola, z * rozmiarPola);
		}
	}
}

void Mapa::rysuj()
{

}

void Mapa::debugRysuj()
{
	for (int x = 0; x < xMax; x++)
	{
		for(int y = 0; y < yMax; y++)
		{
			for (int z = 0; z < zMax; z++)
				plansza[x][y][z].debugRysuj();
		}
	}
}


