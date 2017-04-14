#include "stdafx.h"
#include "JoueurContract.h"
#include "Contrat.h"

JoueurContract::JoueurContract()
{
}

JoueurContract::JoueurContract(Contrat *c, string nom, string prenom ) : Sportif(nom,prenom)
{
	setContrat(c);
}

JoueurContract::~JoueurContract()
{
	delete contratActuel;
}

Contrat * JoueurContract::getContrat()
{
	return contratActuel;
}

void JoueurContract::setContrat(Contrat *c)
{
	contratActuel = c;
}
