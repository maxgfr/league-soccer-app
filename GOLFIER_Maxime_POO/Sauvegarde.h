#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Club.h"
#include "Date.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "LigueSoccer.h"
#include "Palmares.h"
#include "Parcours.h"
#include "Stade.h"
#include "TitreGagne.h"
#include "Rencontre.h"
#include "Calendrier.h"
#include "Singleton.h"

class Sauvegarde : public Singleton<Sauvegarde>
{

	friend class Singleton<Sauvegarde>;

private:
	Sauvegarde() {}

public:
	void EnregistrerJoueur(vector<Joueur*>);

	void EnregistrerParcours(vector<Parcours*> liste);

	void EnregistrerPersonne(vector<Personne*> liste);

	void EnregistrerPalmares(vector<Palmares*>);

	void EnregistrerContrat(vector<Contrat*> liste);

	void EnregistrerRupture(vector<Rupture*>);

	void EnregistrerClub(vector<Club*> liste);

};

