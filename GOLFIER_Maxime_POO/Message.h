#ifndef MESSAGE_H
#define MESSAGE_H

class Negociateur;

#include <string>

using namespace std;

struct Message {

	string sujet;
	string emetteur;
	string information;
	float montantOffre;
	int temps;
};

#endif
