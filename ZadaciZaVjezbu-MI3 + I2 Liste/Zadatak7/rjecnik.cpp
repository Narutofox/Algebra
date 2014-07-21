#include "rjecnik.h"

void rjecnik::insert(KEY key, ELTYPE value) {
	key = key % BROJ_ELEMENATA;
	_polje[key] = value;
}

void rjecnik::remove(KEY key) {
	key = key % BROJ_ELEMENATA;
	_polje[key].Naziv = "";
	_polje[key].KS = -1;
}

ELTYPE rjecnik::search(KEY key) {
	key = key % BROJ_ELEMENATA;
	return _polje[key];
}