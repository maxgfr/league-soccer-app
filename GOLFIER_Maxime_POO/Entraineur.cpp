#include "stdafx.h"
#include "Entraineur.h"

#pragma region constructeur
Entraineur::Entraineur() : Sportif()
{

}

Entraineur::Entraineur(string n, string p, vector<TitreGagne*> li) : Sportif (n,p)
{
	setListeTitre(li);
}


Entraineur::~Entraineur()
{
	for_each(listeTitre.begin(), listeTitre.end(), default_delete<TitreGagne>());
}
#pragma endregion constructeur

#pragma region getter
vector<TitreGagne*> Entraineur::getListeTitre()
{
	return listeTitre;
}
#pragma endregion getter

#pragma region setter
void Entraineur::setListeTitre(vector<TitreGagne*> lt)
{
	listeTitre = lt;
}
#pragma endregion setter


#pragma region vector
void Entraineur::AjoutTitre(TitreGagne *p)
{
	listeTitre.push_back(p);
}

void  Entraineur::SupprimerTitre(TitreGagne *p) {
	string nom = p->getClub()->getNom();
	int size = 0;
	size = listeTitre.size();
	for (int i = 0; i < size; i++) {
		if (listeTitre.at(i)->getClub()->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			listeTitre.erase(listeTitre.begin() + i);
		}
	}
}

int Entraineur::rechPalm(TitreGagne *p)
{
	string nom = p->getClub()->getNom();
	int size = 0;
	size = listeTitre.size();
	for (int i = 0; i < size; i++) {
		if (listeTitre.at(i)->getClub()->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}
#pragma endregion vector