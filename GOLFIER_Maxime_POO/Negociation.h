#ifndef NEGOCIATION_H
#define NEGOCIATION_H

#include <iostream>
#include <vector>
#include "Message.h"

using namespace std;

class Negociation
{
private:
	vector<Message> discution;

public:
	Negociation();

	~Negociation();

	vector<Message> getDiscution();

	void setDiscution(vector<Message>);

	void Offre(string sujet, string emetteur, string information, int temps, float prix);

	void AjoutMessage(Message m);

	void AfficheDiscution();

	bool AboutissementTransaction(Message m);

	void AfficheLastMessage();

	bool isOkay();

	bool isDeception();

	float GetLastMontant();

};

#endif