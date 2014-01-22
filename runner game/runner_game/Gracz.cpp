#include "Gracz.h"

// MUSZE TUTAJ KONIECZNIE ZMIENIC ABY WSPOLZEDNE CZLOWIEKA  !!!!!!!!!
// BYLY JEGO LEWYM DOLNYM PUNKTEM JAK W RESZCIE OBIEKTOW !!!!!!!!!

Gracz::Gracz()
{ // zaczynam na poczatku
	graczX = 3.0f;
	graczY = 16.0f;
	graczZ = 3.0f;


	pozycja.x = 15.0f;
	pozycja.y = graczY / 2;
	pozycja.z = -1.0f;

	kierunek.x = 0.0f;
	kierunek.y = 0.0f;
	kierunek.z = 1.0f;

	predkosc = 0.0f;

	szescianAABBmin.x -= pozycja.x/2;
	szescianAABBmin.y -= pozycja.y/2;
	szescianAABBmin.z -= pozycja.z/2;

	szescianAABBmax.x += pozycja.x/2;
	szescianAABBmax.y += pozycja.y/2;
	szescianAABBmax.z += pozycja.z/2;
}

///////////////////////////////////////

void Gracz::rysuj()
{
	glPushMatrix();
		glTranslatef(pozycja.x, pozycja.y, pozycja.z);
		glScalef(graczX/10, graczY/10, graczZ/10);
		glColor3f(1.0f,0.0f,0.0f);
		glutSolidCube(10.0f);
	glPopMatrix();
}
void Gracz::dodajPredkosc(float _predkosc)
{
	predkosc += _predkosc;
}
void Gracz::update()
{
	pozycja += kierunek * predkosc;

szescianAABBmin.x -= pozycja.x/2;
	szescianAABBmin.y -= pozycja.y/2;
	szescianAABBmin.z -= pozycja.z/2;

	szescianAABBmax.x += pozycja.x/2;
	szescianAABBmax.y += pozycja.y/2;
	szescianAABBmax.z += pozycja.z/2;
}

