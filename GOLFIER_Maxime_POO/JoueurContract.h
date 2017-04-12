#ifndef JOUEURCONTRACT_H
#define JOUEURCONTRACT_H

#include "Contrat.h"
#include "Sportif.h"
class Contrat;

class JoueurContract : public virtual Sportif
{
protected:
	Contrat *contratActuel;

public:
	JoueurContract();
	JoueurContract(Contrat*, string, string);
	~JoueurContract();

#pragma region Getter
	Contrat* getContrat();
#pragma endregion Getter

#pragma region Setter
	void setContrat(Contrat*);
#pragma endregion Setter

#pragma region fonction virtuelle
	virtual void indiquerSonEtat() = 0;
#pragma endregion fonction virtuelle
};
#endif

