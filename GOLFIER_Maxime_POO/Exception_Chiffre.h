#ifndef EXCEPTION_CHIFFRE_H
#define EXCEPTION_CHIFFRE_H

#include <iostream>
#include <exception>

using namespace std;


class Exception_Chiffre : public exception {
private:
	char * ad_texte;
public:
	Exception_Chiffre(char * texte) { ad_texte = texte; }
	const char * what() const { return ad_texte; }

};
#endif