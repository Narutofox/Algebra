#ifndef _RJECNIK_H_
#define _RJECNIK_H_

#include "auti.h"

typedef unsigned int KEY;
typedef auti ELTYPE;

class rjecnik {
private:
	static const int BROJ_ELEMENATA = 24; // Zašto 24?
	ELTYPE _polje[BROJ_ELEMENATA];

public:
	void insert(KEY key, ELTYPE value);
	void remove(KEY key);
	ELTYPE search(KEY key);
};

#endif