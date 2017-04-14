#include "stdafx.h"
#include "Autonome.h"
#include "Rupture.h"

#pragma region Constructeur
Autonome::Autonome()
{
}

Autonome::Autonome(string a, string b, float c, float d, string e, vector<Parcours*> f, Rupture *g, Contrat *h) : Joueur(a, b, c, d, e, f), JoueurContract(h,a,b)
{
	setRupture(g);
}


Autonome::~Autonome()
{
	delete rupture;
}
#pragma endregion Constructeur

#pragma region Getter
Rupture * Autonome::getRupture()
{
	return rupture;
}
#pragma endregion Getter

#pragma region Setter
void Autonome::setRupture(Rupture *r)
{
	rupture = r;
}
#pragma endregion Setter

void Autonome::indiquerSonEtat()
{
	cout << "Je suis un joueur autonome ;) \n";
}