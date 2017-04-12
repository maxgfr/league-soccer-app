#include "stdafx.h"
#include "Joueur.h"

#pragma region constructeur
Joueur::Joueur() : Sportif()
{

}


Joueur::Joueur(string n, string pr, float t, float p, string v, vector<Parcours*> parc) : Sportif (n,pr)
{
	setTaille(t);
	setPoids(p);
	setVilleNaissance(v);
	setParcoursJoueur(parc);
}

Joueur::~Joueur()
{
	for_each(parcoursDuJoueur.begin(), parcoursDuJoueur.end(), default_delete<Parcours>());
}
#pragma endregion constructeur

#pragma region getter
float Joueur::getTaille()
{
	return taille;
}

float Joueur::getPoids()
{
	return poids;
}

string Joueur::getVilleNaissance()
{
	return villeDeNaissance;
}

vector<Parcours*> Joueur::getParcoursJoueur()
{
	return parcoursDuJoueur;
}
#pragma endregion getter

#pragma region setter
void Joueur::setTaille(float t)
{
	taille = t;
}

void Joueur::setPoids(float p)
{
	poids = p;
}

void Joueur::setVilleNaissance(string v)
{
	villeDeNaissance = v;
}

void Joueur::setParcoursJoueur(vector<Parcours*> p)
{
	parcoursDuJoueur = p;
}
#pragma endregion setter

void Joueur::AjoutParcours(Parcours *p)
{
	parcoursDuJoueur.push_back(p);
}

void Joueur::SupprimerParc(Parcours *p) {
	string nom = p->getNomClubActuel();
	int size = 0;
	size = parcoursDuJoueur.size();
	for (int i = 0; i < size; i++) {
		if (parcoursDuJoueur.at(i)->getNomClubActuel().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			parcoursDuJoueur.erase(parcoursDuJoueur.begin() + i);
		}
	}
}

int Joueur::RechParc(Parcours *p)
{
	string nom = p->getNomClubActuel();
	int size = 0;
	size = parcoursDuJoueur.size();
	for (int i = 0; i < size; i++) {
		if (parcoursDuJoueur.at(i)->getNomClubActuel().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

bool Joueur::operator==(const Joueur &j) const
{
	if (j.nom.compare(nom) == 0) {
		if (j.prenom.compare(prenom) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}