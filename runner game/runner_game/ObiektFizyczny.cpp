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
		// kolizja
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