#include "stdafx.h"
#include "Contrat.h"

#pragma region Constructeur
Contrat::Contrat()
{
}

Contrat::Contrat(Joueur *a, Club *b, Club *c, int d, Date *e, Reglement *f, Date *g)
{
	setJoueurContractant(a);
	setClubContractant(b);
	setClubLibere(c);
	setDureeContrat(d);
	setDateEntree(e);
	setReglement(f);
	setDateContrat(g);
}


Contrat::~Contrat()
{
	delete clubContractant;
	delete clubLibere;
	delete joueurContractant;
	delete dateEntree;
	delete reglement;
	delete dateContrat;
}
#pragma endregion Constructeur

#pragma region Getter
Joueur * Contrat::getJoueurContractant()
{
	return joueurContractant;
}

Club * Contrat::getClubContractant()
{
	return clubContractant;
}

Club * Contrat::getClubLibere()
{
	return clubLibere;
}

int Contrat::getDureeContrat()
{
	return dureeContrat;
}

Date * Contrat::getDateEntree()
{
	return dateEntree;
}

Reglement * Contrat::getReglement()
{
	return reglement;
}

Date * Contrat::getDateContrat()
{
	return dateContrat;
}
#pragma endregion Getter

#pragma region Setter
void Contrat::setJoueurContractant(Joueur *j)
{
	joueurContractant = j;
}

void Contrat::setClubContractant(Club *c)
{
	clubContractant = c;
}

void Contrat::setClubLibere(Club *c)
{
	clubLibere = c;
}

void Contrat::setDureeContrat(int d)
{
	dureeContrat = d;
}

void Contrat::setDateEntree(Date *d)
{
	dateEntree = d;
}

void Contrat::setReglement(Reglement *d)
{
	reglement = d;
}

void Contrat::setDateContrat(Date *dc)
{
	dateContrat = dc;
}
#pragma endregion Setter