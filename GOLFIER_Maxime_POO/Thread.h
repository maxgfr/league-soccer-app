#ifndef THREAD_H
#define THREAD_H

#include "NegoAcheteur.h"
#include "NegoVendeur.h"

class Thread
{
public:
	Thread();
	~Thread();

	void launchThread(NegoAcheteur*, NegoVendeur*);
};
#endif
