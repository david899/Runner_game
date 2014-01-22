#include "ObiektFizyczny.h"


ObiektFizyczny::ObiektFizyczny(Vec3 _pozycja, TypyObiektow _typObiektu)
{ // po czesci spelnia funkcje fabryki, wypelnia tak obiekt aby byl roznego typu od stringu _typObiektu
	
	// deklaracja gówna
	wielkoscPola = Vec3(30.0f, 40.0f, 10.0f);
	// koniec deklaracji szamba
	
	pozycja = _pozycja;
	typObiektu = _typObiektu;
	switch(typObiektu)
	{
		case typPole:
			szescianAABBmin = _pozycja;
			szescianAABBmax = szescianAABBmin + wielkoscPola;
			szescianAABB = wielkoscPola;
			wskNaRysuj = &ObiektFizyczny::rysujPole;
			break;
	}
}
void ObiektFizyczny::rysuj()
{
	(this->*wskNaRysuj)(); // rysuje aktualny obiekt
	if(dzieci.empty() == false)
	{
		vector<ObiektFizyczny*>::iterator it;
		for(it = dzieci.begin(); it != dzieci.end(); ++it);
		{
			(*it)->rysuj();
		}
	}
}
void ObiektFizyczny::debugRysuj()
{
	// wspolzedne srodka
	Vec3 srodek = Vec3();
	srodek.x = pozycja.x + (szescianAABBmax.x - szescianAABBmin.x)/2;
	srodek.y = pozycja.y + (szescianAABBmax.y - szescianAABBmin.y)/2;
	srodek.z = pozycja.z + (szescianAABBmax.z - szescianAABBmin.z)/2;
	// rysowanie aktualnego
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(srodek.x, srodek.y, srodek.z);
		glScalef
			(szescianAABBmax.x - szescianAABBmin.x,
			szescianAABBmax.y - szescianAABBmin.y,
			szescianAABBmax.z - szescianAABBmin.z);
		glutWireCube(1.0f);
	glPopMatrix();
	// innych rysuje
	if(dzieci.empty() == false)
	{
		vector<ObiektFizyczny*>::iterator it;
		for(it = dzieci.begin(); it != dzieci.end(); ++it);
		{
			(*it)->debugRysuj();
		}
	}
}
void ObiektFizyczny::sprawdzKolizje(Gracz* gracz)
{
	if(	szescianAABBmax.x > gracz->szescianAABBmin.x 
		&&
		szescianAABBmin.x < gracz->szescianAABBmax.x 
		&&
		szescianAABBmax.y > gracz->szescianAABBmin.y
		&&
		szescianAABBmin.y < gracz->szescianAABBmax.y
		&&
		szescianAABBmax.z > gracz->szescianAABBmin.z 
		&&
		szescianAABBmin.z < gracz->szescianAABBmax.z)
	{
		// kolizja wystapila

		if(dzieci.empty())
		{
			// wykonuje swoja kolizje
			gracz->stosObiektow.push(this);
		}
		else
		{
			//jezeli sa to wykonuje kolizje dzieci
			vector<ObiektFizyczny*>::iterator it;
			for(it = dzieci.begin(); it != dzieci.end(); ++it)
			{
				(*it)->sprawdzKolizje(gracz);
			}
			
		}
	}
	// nie ma kolizji
	// nie robie nie, przechodzi mi do kolejnego obiektu
}
Vec3 ObiektFizyczny::zwrocSrodek()
{
	switch(typObiektu)
	{
		case typPole:
			return Vec3(pozycja.x + wielkoscPola.x/2, pozycja.y + wielkoscPola.y/2, pozycja.z + wielkoscPola.z/2);
			break;

		default: 
			return Vec3(0,0,0);
			printf("Uwaga! Sprobowalem dostac srodek od obiektu ktorego nie ma w switchu, wynik - srodek = 0,0,0");
			break;
	}
	
}
void ObiektFizyczny::rysujPole()
{
	glPushMatrix();
		Vec3 pozycjaSrodka = zwrocSrodek();
		glColor3f(1.0f,1.0f,1.0f);
		glTranslatef(pozycjaSrodka.x, pozycjaSrodka.y, pozycjaSrodka.z);
		glScalef(wielkoscPola.x, wielkoscPola.y, wielkoscPola.z);
		glutWireCube(1.0f);
	glPopMatrix();
}
Vec3 ObiektFizyczny::zwrocSrodekAABB()
{
	Vec3 zwracany = Vec3();
	zwracany.x = szescianAABBmin.x + (szescianAABBmax.x - szescianAABBmin.x)/2;
	zwracany.y = szescianAABBmin.y + (szescianAABBmax.y - szescianAABBmin.y)/2;
	zwracany.z = szescianAABBmin.z + (szescianAABBmax.z - szescianAABBmin.z)/2;
	return zwracany;
}