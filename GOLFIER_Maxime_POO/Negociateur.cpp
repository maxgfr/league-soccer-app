#include "stdafx.h"
#include "Negociateur.h"

#pragma region Constructeur
Negociateur::Negociateur()
{
}

Negociateur::Negociateur(float mD, float mM, int d, Club *c, Mutex m, Negociation *sauv)
{
	setMontantDesire(mD);
	setMontantMax(mM);
	setDureeNegoc(d);
	setClubRepresentant(c);
	setEtat(false);
	setMutex(m);
	setSauv(sauv);
}


Negociateur::~Negociateur()
{
	delete representantClub;
}
#pragma endregion Constructeur

#pragma region Getter
float Negociateur::getMontantDesire()
{
	return montantDesire;
}

float Negociateur::getMontantBloquant()
{
	return montantBloquant;
}

int Negociateur::getDureeNegoc()
{
	return dureeNegoc;
}

Club * Negociateur::getClubRepresentant()
{
	return representantClub;
}

bool Negociateur::getEtat()
{
	return etat;
}

Mutex Negociateur::getMutex()
{
	return unMutex;
}
Negociation * Negociateur::getSauv()
{
	return sauv;
}

#pragma endregion Getter

#pragma region Setter
void Negociateur::setMontantDesire(float m)
{
	montantDesire = m;
}

void Negociateur::setMontantMax(float m)
{
	montantBloquant = m;
}

void Negociateur::setDureeNegoc(int d)
{
	dureeNegoc = d;
}

void Negociateur::setClubRepresentant(Club *c)
{
	representantClub = c;
}

void Negociateur::setEtat(bool e)
{
	etat = e;
}

void Negociateur::setMutex(Mutex m)
{
	unMutex = m;
}

void Negociateur::setSauv(Negociation *s)
{
	sauv = s;
}
#pragma endregion Setter

