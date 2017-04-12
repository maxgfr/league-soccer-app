#include "stdafx.h"
#include "LigueSoccer.h"

#pragma region constructeur
LigueSoccer::LigueSoccer()
{
}
LigueSoccer::LigueSoccer(vector<Club*> v, vector <Entraineur*> ve)
{
	setListeClub(v);
	setListeEntraineur(ve);
}

LigueSoccer::~LigueSoccer()
{
	for_each(listClub.begin(), listClub.end(), default_delete<Club>());
	for_each(listEntraineur.begin(), listEntraineur.end(), default_delete<Entraineur>());
}
#pragma endregion constructeur

#pragma region getter
vector<Club*> LigueSoccer::getListeClub()
{
	return listClub;
}
vector<Entraineur*> LigueSoccer::getListeEntraineur()
{
	return listEntraineur;
}
#pragma endregion getter

#pragma region setter
void LigueSoccer::setListeClub(vector<Club*> li )
{
	listClub = li;
}
void LigueSoccer::setListeEntraineur(vector<Entraineur*> e)
{
	listEntraineur = e;
}
#pragma endregion setter

#pragma region vector
void LigueSoccer::AjoutClub(Club *c)
{
	listClub.push_back(c);
}

void LigueSoccer::AjoutEntraineur(Entraineur *e)
{
	listEntraineur.push_back(e);
}

void LigueSoccer::SupprimerClub(Club *p)
{
	string nom = p->getNom();
	int size=0;
	size = listClub.size();
	for (int i = 0; i < size; i++) {
		if (listClub.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			listClub.erase(listClub.begin() + i);
		}
	}
}

void LigueSoccer::SupprimerEntraineur(Entraineur *p)
{
	string nom = p->getNom();
	int size = 0;
	size = listEntraineur.size();
	for (int i = 0; i < size; i++) {
		if (listEntraineur.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve et supprime dans mon vecteur: \n";
			listEntraineur.erase(listEntraineur.begin() + i);
		}
	}
}

int LigueSoccer::RechClub(string nom)
{
	int size =0;
	size = listClub.size();
	for (int i = 0; i < size; i++) {
		if (listClub.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int LigueSoccer::RechEntraineur(string nom)
{
	int size = 0;
	size = listEntraineur.size();
	for (int i = 0; i < size; i++) {
		if (listEntraineur.at(i)->getNom().compare(nom) == 0) {
			cout << "Element trouve dans mon vecteur: \n";
			return i;
		}
	}
	cout << "L'element n'a pas ete trouve dans le vecteur\n";
	return -1;
}

int LigueSoccer::RechClubPlusTitre()
{
	if (listClub.empty())
	{
		cout << "La liste des club est vide !!!\n";
		return -1;
	}
	int pos = 0, size = 0, num =0, record = 0;
	size = listClub.size();
	for (int i = 0; i < size; i++) {
		num = listClub.at(i)->getPalmares().size();
		if (num > record)
		{
			record  = num;
			pos = i;
		}
	}
	return pos;
}

int LigueSoccer::RechEntraineurPlusTitre()
{	
	if (listEntraineur.empty())
	{
		cout << "La liste d'entraineur est vide !!!\n";
		return -1;
	}
	int pos = 0, size = 0, num = 0, record = 0;
	for (int i = 0; i != listEntraineur.size(); i++)
	{
		for (int j = 0; j != listEntraineur.at(i)->getListeTitre().size(); j++)
		{
			num += listEntraineur.at(i)->getListeTitre()[j]->getEnsPalm().size();
		}
		if (num > record)
		{
			record = num;
			pos = i;
		}
	}
	return pos;
}

#pragma endregion vector

#pragma region Contrat et Rupture
void LigueSoccer::MajTransac(Contrat *contrat)
{
	Joueur *joueur = contrat->getJoueurContractant();

	if (listClub.empty()) {
		cout << "La liste de club est vide, impossible de mettre à jour la transaction !!!\n";
		return;
	}

	//parcours de la lise de club
	for (int i = 0; i != listClub.size(); i++) {

		//on gère la suppression de contrat pour l'ancien club en supprimant le joueur	
		if (listClub[i] == contrat->getClubLibere()) {
			//on verifie si le joueur n'est pas hétéronome, car il y a des contraintes dans ce cas là...
			for (int j = 0; j != listClub[i]->getEffectif().size(); j++) {
				if (joueur == listClub[i]->getEffectif()[j]) {
					listClub[i]->SupprimerJoueur(contrat->getJoueurContractant());
				}
			}
		}

		//on gère l'ajout de contrat pour le nouveau club
		if (listClub[i] == contrat->getClubContractant()) {
			// le joueur n'existe pas dans le club alors on l'ajoute direct à l'effectif
			listClub[i]->AjoutJoueur(contrat->getJoueurContractant());
			//puis on ajoute son contrat au club
			listClub[i]->AjoutContrat(contrat);
		}

		
	}
	delete joueur;
}

void LigueSoccer::MajRupture(Rupture *rup, Club *ancien)
{
	if (listClub.empty())
	{
		cout << "La liste de rupture est vide, impossible de faire la mise a jour de rupture de contrat!!!\n";
		return;
	}

	//parcours de la liste club
	for (int i = 0; i != listClub.size(); i++) {
		//on gère l'ajout d'une rupture pour le joueur
		if (listClub[i] == rup->getNouvClub()) {
			//on transforme le joeur en joueur autonome pour qu'il puisse avoir sa rupture repertoriée
			Autonome *joue = (Autonome*)rup->getJoueur();
			joue->setRupture(rup);
			listClub[i]->AjoutJoueur(joue);
		}
		//on gere pour supprimer le joueur de son ancien cub
		if (listClub[i] == ancien) {
			//on verifie si le joueur n'est pas hétéronome, car il y a des contraintes dans ce cas là...
			for (int j = 0; j != listClub[i]->getEffectif().size(); j++) {
				if (rup->getJoueur() == listClub[i]->getEffectif()[j]) {
					listClub[i]->AjoutRupture(rup);
					//on supprime le joeur de l'ancien club
					listClub[i]->SupprimerJoueur(rup->getJoueur());
					break;
				}
			}
		}
	}
}
#pragma endregion Contrat et Rupture
