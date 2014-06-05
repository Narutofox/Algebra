#include "bst.h"

/*************** PRIVATNE METODE ****************/

POSITION bst::create_new_node(const ELTYPE& element) {

	cvor* novi = new cvor;
	novi->element = element;
	novi->left_child = nullptr;
	novi->right_child = nullptr;

	return novi;
}

POSITION bst::insert(const ELTYPE& element, POSITION* parent) {
	if (*parent == nullptr) {
		*parent = create_new_node(element);
		return *parent;
	}

	// Pronađi čvor u koji treba staviti element.
	if (element.Placa < (*parent)->element.Placa) {
		return insert(element, &(*parent)->left_child);
	}
	else {
		return insert(element, &(*parent)->right_child);
	}
}

bool bst::exists(const float placa, POSITION parent) {
	if (parent == nullptr) {
		cout <<"Ne" << endl;
		return false;
	}

	if (placa < parent->element.Placa) {
		return exists(placa, parent->left_child);
	}
	else if (placa > parent->element.Placa) {
		return exists(placa, parent->right_child);
	}
	else {
		cout <<"Da" << endl;
		return true;
	}
}

/*************** JAVNE METODE ****************/

bst::bst() {
	_root = nullptr;
}

POSITION bst::insert(const ELTYPE& element) {
	return insert(element, &_root);
}

bool bst::exists(const float& placa) {
	return exists(placa, _root);
}