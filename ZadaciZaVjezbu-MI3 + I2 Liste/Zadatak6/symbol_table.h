#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <string>
#include "lista.h"
using namespace std;

class symbol_table {
private:
	lista _lista;

public:
	symbol_table();

	bool put(string key, ELTYPE value);
	ELTYPE* get(string key);
	bool remove(string key);
};

#endif