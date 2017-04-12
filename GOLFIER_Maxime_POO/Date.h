#ifndef DATE_H
#define DATE_H


#include <iostream>
using namespace std;

class Date
{
private:
	int jour;
	int mois;
	int annee;

public:

#pragma region Constructeur
	Date();
	Date(int, int, int);
	~Date();
#pragma endregion Constructeur

#pragma region Getter
	int getJour();
	int getMois();
	int getAnnee();
#pragma endregion Getter

#pragma region Setter
	void setJour(int);
	void setMois(int);
	void setAnnee(int);
#pragma endregion Setter

	int JourParMois();
	bool AnneeBiss();
	void AddJour(int num);

	friend ostream& operator<<(ostream& os, const Date& dt);
	bool operator>(const Date &) const;
	bool operator==(const Date &) const;
	
};

#endif 

