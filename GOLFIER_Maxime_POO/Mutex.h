#ifndef MUTEX_H
#define MUTEX_H

#include<windows.h>

class Mutex {

	HANDLE unMutex;
	void * unObjet;

public:
	Mutex() {
		unMutex = CreateMutex(NULL, false, NULL);
	}
	void Synchroniser() {
		WaitForSingleObject(unMutex, INFINITE);
	}

	void Liberer() {
		ReleaseMutex(unMutex);

	}

	void * getObjet() {
		return unObjet;
	}

	void setObjet(void* unObj) {
		unObjet = unObj;
	}


};
#endif