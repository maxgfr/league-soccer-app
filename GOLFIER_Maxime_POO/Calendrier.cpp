#include "stdafx.h"
#include "Calendrier.h"


#pragma region Constructeur
Calendrier::Calendrier()
{
}

Calendrier::Calendrier(vector<Rencontre*> v)
{
	setListeRencontre(v);
}

Calendrier::~Calendrier()
{
	for_each(listRencontre.begin(), listRencontre.end(), default_delete<Rencontre>());
}
#pragma endregion Constructeur

#pragma region Getter
vector<Rencontre*> Calendrier::getListeRencontre()
{
	return listRencontre;
}
#pragma endregion Getter

#pragma region Setter
void Calendrier::setListeRencontre(vector<Rencontre*> v)
{
	listRencontre = v;
}
#pragma endregion Setter

void Calendrier::AjoutRencontre(Rencontre *c)
{
	listRencontre.push_back(c);
}

void Calendrier::SupprimerRencontre(Rencontre *c)
{
	int size = listRencontre.size();
	int fait1, fait2;
	string nom1 = c->getClubAdverse()->getNom();
	string nom2 = c->getClubReceveur()->getNom();
	Date *d1 = c->getDateMatch();
	for (int i = 0; i < size; i++) {
		fait1 = listRencontre.at(i)->getClubAdverse()->getNom().compare(nom1);
		fait2 = listRencontre.at(i)->getClubReceveur()->getNom().compare(nom2);
		if (fait1 == 0 || fait2 == 0) {
			Date *d2 = listRencontre.at(i)->getDateMatch();
			if (*d2 == *d1) {
				cout << "Element trouve et supprime dans mon vecteur: \n";
				listRencontre.erase(listRencontre.begin() + i);
			}
		}
	}
}

vector<Rencontre*> Calendrier::RencontrePourUnClub(string nom)
{
	int size = listRencontre.size();
	int fait1, fait2;
	vector<Rencontre*> vec;
	for (int i = 0; i < size; i++) {
		fait1 = listRencontre.at(i)->getClubAdverse()->getNom().compare(nom);
		fait2 = listRencontre.at(i)->getClubReceveur()->getNom().compare(nom);
		if (fait1 == 0 || fait2 == 0 ) {
			vec.push_back(listRencontre.at(i));
		}
	}
	return vec;
}

Rencontre* Calendrier::RechRencontre(Date *d, string nom)
{
	int size = listRencontre.size();
	int fait1, fait2;
	for (int i = 0; i < size; i++) {
		fait1 = listRencontre.at(i)->getClubAdverse()->getNom().compare(nom);
		fait2 = listRencontre.at(i)->getClubReceveur()->getNom().compare(nom);
		if (fait1 == 0 || fait2 == 0) {
			cout << "Le nom de l equipe correspond !\n";
			Date *d1 = listRencontre.at(i)->getDateMatch();
			if (*d1 == *d) {
				cout << "Le nom de l equipe et la date correspondent!\n";
				return listRencontre.at(i);
			}
			delete d1;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return NULL;
}

int Calendrier::RechEquipe(string nom)
{
	int size = listRencontre.size();
	for (int i = 0; i < size; i++) {
		if (listRencontre.at(i)->getClubReceveur()->getNom().compare(nom) == 0) {
			cout << "L'element a ete trouve dans le vecteur\n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

