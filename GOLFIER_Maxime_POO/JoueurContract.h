#ifndef JOUEURCONTRACT_H
#define JOUEURCONTRACT_H

#include "Sportif.h"
#include "Contrat.h"

class JoueurContract : public virtual Sportif
{
protected:
	Contrat *contratActuel;

public:
	JoueurContract();
	JoueurContract(Contrat*, string, string);
	virtual ~JoueurContract();

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

