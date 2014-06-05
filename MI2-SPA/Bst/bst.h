#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include "Osoba.h"
using namespace std;

typedef Osoba ELTYPE; 

struct cvor;

typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION left_child;
	POSITION right_child;
};

class bst {
private:
	POSITION _root;
	POSITION create_new_node(const ELTYPE& element);
	POSITION insert(const ELTYPE& element, POSITION* parent);
	bool exists(const float element, POSITION parent);

public:
	bst();
	POSITION insert(const ELTYPE& element);
	bool exists(const float& element);
};

#endif
