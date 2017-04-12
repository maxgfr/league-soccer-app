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

class Chargement : public Singleton<Chargement>
{

	friend class Singleton<Chargement>;

private:
	Chargement() {}

public:

	vector<Joueur*> ChargerJoueur(string);

	vector<Parcours*> ChargerParcours(string);

	vector<Personne*> ChargerPersonne(string);

	vector<Palmares*> ChargerPalmares(string);

	vector<Contrat*> ChargerContrat(string);

	vector<Rupture*> ChargerRupture(string);

	vector<Club*> ChargerClub(void);

};

