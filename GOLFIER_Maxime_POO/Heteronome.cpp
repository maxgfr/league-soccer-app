#include "stdafx.h"
#include "Heteronome.h"

#pragma region Constructeur
Heteronome::Heteronome()
{
}

Heteronome::Heteronome(string a, string b, float c, float d, string e, vector<Parcours*> f, int g, Contrat *h) : Joueur(a, b, c, d, e, f), JoueurContract(h,a,b)
{
	setNbAnRest(g);
}

Heteronome::~Heteronome()
{
}
#pragma endregion Constructeur

#pragma region Getter
int Heteronome::getNbAnRest()
{
	return nbAnneeRestante;
}
#pragma endregion Getter

#pragma region Setter
void Heteronome::setNbAnRest(int n)
{
	nbAnneeRestante = n;
}
#pragma endregion Setter

void Heteronome::indiquerSonEtat()
{
	cout << "Je suis un joueur heteronome et il me reste " << getNbAnRest() << " annee restante...\n";
}