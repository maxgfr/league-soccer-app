#include "stdafx.h"
#include "Date.h"

#pragma region constructeur
Date::Date() //inutile
{
}

Date::Date(int j, int m, int a)
{
	if ((m < 1 || m > 12) || (j < 1 || j > 31) || (a < 1900 || a > 2100)) {
		cout << "La date est invalide" << endl;

	}
	else {
		setJour(j);
		setMois(m);
		setAnnee(a);
	}
}
Date::~Date()
{
}
#pragma endregion constructeur

#pragma region getter
int Date::getJour()
{
	return jour;
}

int Date::getMois()
{
	return mois;
}


int Date::getAnnee()
{
	return annee;
}

#pragma endregion getter

#pragma region setter
void Date::setJour(int jo)
{
	jour = jo;
}

void Date::setMois(int mo)
{
	mois = mo;
}


void Date::setAnnee(int an)
{
	annee = an;
}
#pragma endregion setter

#pragma region fct
int Date::JourParMois()
{
	int res;
	switch (mois)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		res = 31;
	}
	switch (mois)
	{
	case 2:
		if (Date::AnneeBiss())
		{
			res = 29;
		}
		else
		{
			res = 28;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		res = 30;
		break;
	}
	return res;
}

bool Date::AnneeBiss()
{
	if (annee % 4 == 0)
		return true;
	else
		return false;
}

void Date::AddJour(int num)
{

	while ((num + jour) > Date::JourParMois())
	{
		num -= Date::JourParMois();
		if (mois == 12)
		{
			mois = 0;
			annee++;
		}
		mois++;
	}
}
#pragma endregion fct

#pragma region operator
ostream& operator<<(ostream& os, const Date& dt)
{
	os << dt.jour << '/' << dt.mois << '/' << dt.annee;
	return os;
}

bool Date::operator>(const Date & d1) const
{
	if (d1.annee > annee) {
		return true;
	}
	else {
		if (d1.mois > mois) {
			return true;
		}
		else {
			if (d1.jour > jour) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator==(const Date & d1) const
{
	if (d1.annee == annee) {
		if (d1.mois == mois) {
			if (d1.jour == jour) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
#pragma endregion operator