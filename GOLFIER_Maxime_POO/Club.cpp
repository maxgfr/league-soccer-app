#include "stdafx.h"
#include "Club.h"

#pragma region Constructeur
Club::Club() 
{
}

Club::Club(string nm, string hg, string cc, Date *d, vector<Joueur*> e, Stade *st, string vi, string ac, vector<Personne*> s, vector<Palmares*> p)
{
	setNom(nm);
	setPalmares(p);
	setHistoire(hg);
	setCouleur(cc);
	setAnnee(d);
	setEffectif(e);
	setStadeDuClub(st);
	setVilleDuClub(vi);
	setAdresseClub(ac);
	setStaff(s);
}

Club::Club(string nm, string hg, string cc, Date *d, vector<Joueur*> e, Stade *st, string vi, string ac, vector<Personne*> s, vector<Palmares*> p, vector<Contrat*> contr, vector<Rupture*> rup)
{
	setNom(nm);
	setPalmares(p);
	setHistoire(hg);
	setCouleur(cc);
	setAnnee(d);
	setEffectif(e);
	setStadeDuClub(st);
	setVilleDuClub(vi);
	setAdresseClub(ac);
	setStaff(s);
	setContrat(contr);
	setRupture(rup);
}

Club::~Club()
{
	delete stadeDuClub;
	delete anneeCreation;
	for_each(effectif.begin(), effectif.end(), default_delete<Joueur>());
	for_each(staff.begin(), staff.end(), default_delete<Personne>());
	for_each(palmares.begin(), palmares.end(), default_delete<Palmares>());
	for_each(contrats.begin(), contrats.end(), default_delete<Contrat>());
	for_each(ruptures.begin(), ruptures.end(), default_delete<Rupture>());
}
#pragma endregion Constructeur


#pragma region Getter
string Club::getHistoire()
{
	return histoireClub;
}

vector<Palmares*> Club::getPalmares()
{
	return palmares;
}

string Club::getNom()
{
	return nom;
}

string Club::getCouleur()
{
	return couleurClub;
}

Date* Club::getAnnee()
{
	return anneeCreation;
}

vector<Joueur*> Club::getEffectif()
{
	return effectif;
}

Stade* Club::getStadeDuClub()
{
	return stadeDuClub;
}

string Club::getVilleDuClub()
{
	return villeDuClub;
}

string Club::getAdresseClub()
{
	return adresseClub;
}

vector<Personne*> Club::getStaff()
{
	return staff;
}
vector<Contrat*> Club::getContrat()
{
	return contrats;
}
vector<Rupture*> Club::getRupture()
{
	return ruptures;
}
#pragma endregion Getter

#pragma region Setter
void Club::setHistoire(string h)
{
	histoireClub = h;
}

void Club::setNom(string h)
{
	nom = h;
}

void Club::setPalmares(vector<Palmares*> p)
{
	palmares = p;
}

void Club::setCouleur(string c)
{
	couleurClub = c;
}

void Club::setAnnee(Date *d)
{
	anneeCreation = d;
}

void Club::setEffectif(vector<Joueur*> e)
{
	effectif = e;
}

void Club::setStadeDuClub(Stade* st)
{
	stadeDuClub = st;
}

void Club::setVilleDuClub(string vi)
{
	villeDuClub = vi;
}

void Club::setAdresseClub(string ac)
{
	adresseClub = ac;
}

void Club::setStaff(vector<Personne*> s)
{
	staff = s;
}
void Club::setContrat(vector<Contrat*> c)
{
	contrats = c;
}
void Club::setRupture(vector<Rupture*> r)
{
	ruptures = r;
}
#pragma endregion Setter

#pragma region vector
void Club::AjoutJoueur(Joueur *p)
{
	effectif.push_back(p);
}

void Club::AjoutStaff(Personne *p)
{
	staff.push_back(p);
}

void Club::AjoutContrat(Contrat *p)
{
	contrats.push_back(p);
}

void Club::AjoutRupture(Rupture *p)
{
	ruptures.push_back(p);
}

void Club::SupprimerJoueur(Joueur * p)
{
	string nom = p->getNom();
	int size = 0;
	size = effectif.size();
	for (int i = 0; i < size; i++) {
		if (effectif.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			effectif.erase(effectif.begin() + i);
		}
	}
}

void Club::SupprimerPersonne(Personne * p)
{
	string nom = p->getNom();
	int size = 0;
	size = staff.size();
	for (int i = 0; i < size; i++) {
		if (staff.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			staff.erase(staff.begin() + i);
		}
	}
}

void Club::SupprimerContrat(Contrat * p)
{
	string nom = p->getJoueurContractant()->getNom();
	int size = 0;
	size = contrats.size();
	for (int i = 0; i < size; i++) {
		if (contrats.at(i)->getJoueurContractant()->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			contrats.erase(contrats.begin() + i);
		}
	}
}

void Club::SupprimerRupture(Rupture * p)
{
	string nom = p->getJoueur()->getNom();
	int size = 0;
	size = ruptures.size();
	for (int i = 0; i < size; i++) {
		if (ruptures.at(i)->getJoueur()->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			ruptures.erase(ruptures.begin() + i);
		}
	}
}

int Club::RechJoueur(Joueur *p)
{
	string nom = p->getNom();
	int size = 0;
	size = effectif.size();
	for (int i = 0; i < size; i++) {
		if (effectif.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int Club::RechJoueurParNom(string nom)
{
	int size = 0;
	size = effectif.size();
	for (int i = 0; i < size; i++) {
		if (effectif.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int Club::RechPersonne(Personne * p)
{
	string nom = p->getNom();
	int size = 0;
	size = staff.size();
	for (int i = 0; i < size; i++) {
		if (staff.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int Club::RechPersonneParNom(string nom)
{
	int size = 0;
	size = staff.size();
	for (int i = 0; i < size; i++) {
		if (staff.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int Club::RechContrat(Contrat *p )
{
	string nom = p->getJoueurContractant()->getNom();
	int size = 0;
	size = contrats.size();
	for (int i = 0; i < size; i++) {
		if (contrats.at(i)->getJoueurContractant()->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int Club::RechRupture(Rupture *p)
{
	string nom = p->getJoueur()->getNom();
	int size = 0;
	size = ruptures.size();
	for (int i = 0; i < size; i++) {
		if (ruptures.at(i)->getJoueur()->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

#pragma endregion vector


bool Club::operator==(const Club &c) const
{
	if (c.nom.compare(nom) == 0) {
		return true;
	}
	else {
		return false;
	}
}
