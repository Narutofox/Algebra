#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <string>
#include "student.h"
#include "lista.h"
using namespace std;

class symbol_table {
private:
	lista _lista;

public:
	symbol_table();

	bool put(int key, ELTYPE value);
	ELTYPE* get(int key);
	bool remove(int key);
};

#endif