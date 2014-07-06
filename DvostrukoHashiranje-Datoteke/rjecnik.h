#ifndef _RJECNIK_H_
#define _RJECNIK_H_

#include"zivotinje.h"
#include <string>
#include <iostream>
using namespace std;

typedef int KEY;
typedef Zivotinja ELTYPE;

class rjecnik {
private:
	static const int BROJ_ELEMENATA = 30;
	unsigned int h(KEY key, int i);
	unsigned int h1(KEY key);
	unsigned int h2(KEY key);
	ELTYPE* _polje[BROJ_ELEMENATA];
	bool sekvenicja(unsigned int index,int znak);
	unsigned int sekvencijsko_polje[BROJ_ELEMENATA];
public:
	rjecnik();
	~rjecnik();
	void insert(KEY key, ELTYPE* value);
	void remove(KEY key);
	void search(KEY key);
};
#endif


