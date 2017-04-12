#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <iostream>

using namespace std;

class Reglement
{

private :
	float seuilVigueur;
	string descriptionDroit;
	float montantTransfert;
	float montantEncaisse;
	float montantRestant;

public:

#pragma region Constructeur
	Reglement();
	Reglement(float, string, float, float, float);
	~Reglement();
#pragma endregion Constructeur

#pragma region Getter
	float getSeuilVigueur();
	string getDescriptionDroit();
	float getMontantTransfert();
	float getMontantEncaisse();
	float getMontantRestant();
#pragma endregion Getter

#pragma region Setter
	void setSeuilVigueur(float);
	void setDescriptionDroit(string);
	void setMontantTransfert(float);
	void setMontantEncaisse(float);
	void setMontantRestant(float);
#pragma endregion Setter
};

#endif

