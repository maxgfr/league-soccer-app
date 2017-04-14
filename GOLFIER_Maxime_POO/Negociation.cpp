#include "stdafx.h"
#include "Negociation.h"

#pragma region constructeur
Negociation::Negociation()
{
}


Negociation::~Negociation()
{
	discution.pop_back();
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
	AfficheLastMessage();
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
		cout << "====== FINAL : Transfert finialise avec un montant :" << m.montantOffre << " euros ====== \n\n\n";
		return true;
	}
	else {
		cout << "====== FINAL : Le transfert fut un echec... ====== \n\n\n";
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
	last = discution.size() - 1;
	if (last < 0) {
		resultat = false;
	}
	else {
		resultat = AboutissementTransaction(discution.at(last));
	}
	return resultat;
}

bool Negociation::isDeception()
{
	int last = 0;
	bool resultat = false;
	last = discution.size() - 1;
	if (last < 0) {
		resultat = false;
	}
	else {
		Message m = discution.at(last);
		if (m.sujet.compare("refuser") == 0)
		{
			resultat = true;
		}
		else {
			resultat = false;
		}

	}
	return resultat;
}

float Negociation::GetLastMontant()
{
	int last = 0;
	last = discution.size() - 1;
	if (last < 0) {
		return NULL;
	}
	Message m = discution.at(last);
	return m.montantOffre;
}