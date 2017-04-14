#include "stdafx.h"
#include "Affichage.h"
#include "LigueSoccer.h"
#include "Calendrier.h"

#include <iostream>
#include <exception>

using namespace std;

//GOLFIER Maxime GOLM16039801
int main()
{
	try {
		LigueSoccer *lg = new LigueSoccer();
		Calendrier *cal = new Calendrier();
		Affichage::choixPrincipal(lg, cal);
		delete cal;
		delete lg;
	} catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}
	return 0;
}

