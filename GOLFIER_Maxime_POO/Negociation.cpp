#include "stdafx.h"
#include "Negociation.h"

#pragma region constructeur
Negociation::Negociation()
{
}


Negociation::~Negociation()
{
}
#pragma endregion constructeur

#pragma region getter + setter
vector<Message> Negociation::getDiscution()
{
	return discution;
}

void Negociation::setDiscution(vector<Message> d)
{
	discution = d;
}
#pragma endregion getter + setter

void Negociation::Offre(string sujet, string emetteur, string information, int temps, float prix)
{
	Message m;
	m.sujet = sujet;
	m.montantOffre = prix;
	m.temps = temps;
	m.emetteur = emetteur;
	m.information = information;
	AjoutMessage(m);
}

void Negociation::AjoutMessage(Message m)
{
	discution.push_back(m);
}

void Negociation::AfficheDiscution()
{
	int size = 0;
	size = discution.size();
	for (int i = 0; i < size; i++) {
		Message m = discution.at(i);
		cout << "==>TEMPS : " << m.temps << " | SUJET : " << m.sujet << " | EMETTEUR : " << m.emetteur << "\n";
		cout << "PRIX : " << m.montantOffre << "\n";
		cout << "INFORMATION: " << m.information << "\n\n\n";
	}
}

bool Negociation::AboutissementTransaction(Message m)
{
	if (m.sujet.compare("accepter") == 0)
	{
		cout << "- INFO : Transfert finialise avec un montant :" << m.montantOffre << " euros\n";
		return true;
	}
	else {
		cout << "- INFO : Transfert non finialise...\n";
		return false;
	}
}

void Negociation::AfficheLastMessage()
{
	int last = 0;
	last = discution.size()-1;
	Message m = discution.at(last);
	cout << "==>TEMPS : " << m.temps << " | SUJET : " << m.sujet << " | EMETTEUR : " << m.emetteur << "\n";
	cout << "PRIX : " << m.montantOffre << "\n";
	cout << "INFORMATION: " << m.information << "\n\n\n";
}

bool Negociation::isOkay()
{
	int last = 0;
	bool resultat = false;
	last = discution.size()-1;
	if (last < 0) { 
		resultat = false;
	} else {
		resultat = AboutissementTransaction(discution.at(last)); 
	}
	return resultat;
}
