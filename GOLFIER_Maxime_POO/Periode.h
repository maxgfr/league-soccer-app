#ifndef PERIODE_H
#define PERIODE_H

class Periode
{
private:
	int duree;
	int butMarquesLocal;
	int butMarquesAdverse;

public:
	
#pragma region Constructeur
	Periode();
	Periode(int, int, int);
	~Periode();
#pragma endregion Constructeur

#pragma region Getter
	int getDuree();
	int getButLocal();
	int getButAdverse();
#pragma endregion Getter

#pragma region Setter
	void setDuree(int);
	void setButLocal(int);
	void setButAdverse(int);
#pragma endregion Setter
};

#endif
