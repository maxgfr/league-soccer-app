#ifndef SPORTIF_H
#define SPORTIF_H

#include <iostream>

using namespace std;

class Sportif
{

protected:
	string nom;
	string prenom;

public:

#pragma region Constructeur
	Sportif();
	Sportif(string,string);
	~Sportif();
#pragma region Constructeur

#pragma region Getter
	string getNom();
	string getPrenom();
#pragma endregion Getter

#pragma region Setter
	void setNom(string);
	void setPrenom(string);
#pragma endregion Setter


};

#endif