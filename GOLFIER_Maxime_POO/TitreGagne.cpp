#include "stdafx.h"
#include "TitreGagne.h"

#pragma region constructeur
TitreGagne::TitreGagne() //inutile
{
}

TitreGagne::TitreGagne(vector<Palmares*> s, Club *c)
{
	setEnsPalm(s);
	setClub(c);
}


TitreGagne::~TitreGagne()
{
	for_each(ensPalm.begin(), ensPalm.end(), default_delete<Palmares>());
	delete club;
}
#pragma endregion constructeur

#pragma region getter
vector<Palmares*> TitreGagne::getEnsPalm()
{
	return ensPalm;
}

Club* TitreGagne::getClub()
{
	return club;
}
#pragma endregion getter

#pragma region setter
void TitreGagne::setEnsPalm(vector<Palmares*> s)
{
	ensPalm = s;
}

void TitreGagne::setClub(Club *c)
{
	club = c;
}
#pragma endregion setter

#pragma region vector
void TitreGagne::AjoutPalm(Palmares *p)
{
	ensPalm.push_back(p);
}

void TitreGagne::SupprimerPalm(Palmares *p) {
	string nom = p->getTitre();
	int size = 0;
	size = ensPalm.size();
	for (int i = 0; i < size; i++) {
		if (ensPalm.at(i)->getTitre().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			ensPalm.erase(ensPalm.begin() + i);
		}
	}
}

int TitreGagne::rechPalm(Palmares *p)
{
	string nom = p->getTitre();
	int size = 0;
	size = ensPalm.size();
	for (int i = 0; i < size; i++) {
		if (ensPalm.at(i)->getTitre().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

#pragma endregion vector
