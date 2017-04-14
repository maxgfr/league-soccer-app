#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
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
	void EnregistrerJoueur(vector<Joueur*>,string);

	void EnregistrerParcours(vector<Parcours*>,string);

	void EnregistrerPersonne(vector<Personne*> liste, string);

	void EnregistrerPalmares(vector<Palmares*>, string);

	void EnregistrerContrat(vector<Contrat*>, string);

	void EnregistrerRupture(vector<Rupture*>, string);

	void EnregistrerClub(vector<Club*> liste);

};

