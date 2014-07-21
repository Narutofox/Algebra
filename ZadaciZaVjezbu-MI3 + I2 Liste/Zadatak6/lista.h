#ifndef _LISTA_H_
#define _LISTA_H_


#include "auti.h"

typedef auti ELTYPE; // Lista èuva studente.

struct cvor;

typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION previous;
	POSITION next;
};

class lista {
private:
	POSITION _head; // "Prvi ispred" poèetka liste.
	POSITION _tail; // "Prvi iza" kraja liste.

public:
	lista();
	POSITION end();
	POSITION first();
	bool insert(ELTYPE element, POSITION pos);
	bool read(POSITION pos, ELTYPE& element);
	bool remove(POSITION pos);
	POSITION empty();
	POSITION next(POSITION pos);
	POSITION prev(POSITION pos);
};

#endif