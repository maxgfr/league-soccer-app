#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat
{

private:
	int nbTotButLocal;
	int nbTotButAdverse;

public:
	
#pragma region Constructeur
	Resultat();
	Resultat(int, int);
	~Resultat();
#pragma endregion Constructeur

#pragma region Getter
	int getNbLocal();
	int getNbAdverse();
#pragma endregion Getter

#pragma region Setter
	void setNbLocal(int);
	void setNbAdverse(int);
#pragma endregion Setter
};

#endif
