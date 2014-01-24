#include "Gracz.h"

// MUSZE TUTAJ KONIECZNIE ZMIENIC ABY WSPOLZEDNE CZLOWIEKA  !!!!!!!!!
// BYLY JEGO LEWYM DOLNYM PUNKTEM JAK W RESZCIE OBIEKTOW !!!!!!!!!
// teraz wspolzedna sa srodkiem 
#include <math.h>

Gracz::Gracz()
{ // zaczynam na poczatku
	graczX = 3.0f; // szereokosc, grubosc, wysokosc solidCuba ktory jest graczem
	graczY = 16.0f;
	graczZ = 3.0f;

	// pozycja srodka gracza
	pozycja.x = 15.0f;
	pozycja.y = graczY / 2;
	pozycja.z = -1.0f;

	kierunek.x = 0.0f;
	kierunek.y = 0.0f;
	kierunek.z = 1.0f;

	predkosc = 0.0f;

	szescianAABBmin = szescianAABBmax = pozycja; // od tej pozycji przesuniecia ponizsze maja sens
	szescianAABBmin.x -= abs(szescianAABBmin.x/2);
	szescianAABBmin.y -= abs(szescianAABBmin.y/2);
	szescianAABBmin.z -= abs(szescianAABBmin.z/2);

	szescianAABBmax.x += abs(szescianAABBmax.x/2);
	szescianAABBmax.y += abs(szescianAABBmax.y/2);
	szescianAABBmax.z += abs(szescianAABBmax.z/2);
	szescianAABB = Vec3(graczX,graczY,graczZ);
}

///////////////////////////////////////

void Gracz::rysuj()
{
	glPushMatrix();
		glTranslatef(pozycja.x, pozycja.y, pozycja.z);
		glScalef(graczX, graczY, graczZ);
		glColor3f(1.0f,0.0f,0.0f);
		glutSolidCube(1.0f);
	glPopMatrix();
}
void Gracz::debugRysuj()
{
	// wspolzedne srodka
	Vec3 srodek = Vec3();
	srodek = zwrocSrodekAABB();
	// rysowanie aktualnego
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(srodek.x, srodek.y, srodek.z);
		glScalef(
			szescianAABB.x,
			szescianAABB.y,
			szescianAABB.z);

		glutWireCube(1.0f);
	glPopMatrix();
}
void Gracz::dodajPredkosc(float _predkosc)
{
	predkosc += _predkosc;
}
void Gracz::update()
{
	pozycja += kierunek * predkosc;
	szescianAABBmin += kierunek * predkosc;
	szescianAABBmax += kierunek * predkosc;
}
Vec3 Gracz::zwrocSrodekAABB()
{
	Vec3 zwracany = Vec3();
	zwracany.x = szescianAABBmin.x + (szescianAABBmax.x - szescianAABBmin.x)/2;
	zwracany.y = szescianAABBmin.y + (szescianAABBmax.y - szescianAABBmin.y)/2;
	zwracany.z = szescianAABBmin.z + (szescianAABBmax.z - szescianAABBmin.z)/2;
	return zwracany;
}
//void Gracz::sprawdzKolizje()
//{
//
//}

