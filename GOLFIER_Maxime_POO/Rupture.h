#ifndef RUPTURE_H
#define RUPTURE_H

#include <string>

class Joueur;
class Club;

class Rupture
{
private:
	Joueur *joueur;
	std::string raisonDep;
	Club *nouvClub;
	float penalite;

public:

#pragma region Constructeur
	Rupture();
	Rupture(Joueur*, std::string, Club*, float);
	~Rupture();
#pragma endregion Constructeur

#pragma region Getter
	Joueur* getJoueur();
	std::string getRaisonDep();
	Club* getNouvClub();
	float getPenalite();
#pragma endregion Getter

#pragma region Setter
	void setJoueur(Joueur*);
	void setRaisonDep(std::string);
	void setNouvClub(Club*);
	void setPenalite(float);
#pragma endregion Setter
};

#endif