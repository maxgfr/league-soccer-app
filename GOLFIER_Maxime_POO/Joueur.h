#ifndef JOUEUR_H
#define JOUEUR_H

#include "Parcours.h"
#include "Sportif.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Joueur : public virtual Sportif
{

protected:
	float taille;
	float poids;
	string villeDeNaissance;
	vector<Parcours*> parcoursDuJoueur;

public:

#pragma region Constructeur
	Joueur();
	Joueur(string, string, float, float, string, vector<Parcours*>);
	~Joueur();
#pragma endregion Constructeur

#pragma region Getter
	float getTaille();
	float getPoids();
	string getVilleNaissance();
	vector<Parcours*> getParcoursJoueur();
#pragma endregion Getter

#pragma region Setter
	void setTaille(float);
	void setPoids(float);
	void setVilleNaissance(string);
	void setParcoursJoueur(vector<Parcours*>);
#pragma endregion Setter

	void AjoutParcours(Parcours*);
	void SupprimerParc(Parcours *);
	int RechParc(Parcours *);


	bool operator==(const Joueur &) const;

};

#endif


