#include "symbol_table.h"

symbol_table::symbol_table() {
}

bool symbol_table::put(int key, ELTYPE value) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.ID == key) {
			return false; // Kljuè veæ postoji.
		}
	}

	_lista.insert(value, _lista.end());
	return true;
}

ELTYPE* symbol_table::get(int key) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.ID == key) {
			return &node->element; // Vrati adresu pronaðenog elementa.
		}
	}
	return nullptr; // neme elementa s traženim kljuèem.
}

bool symbol_table::remove(int key) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.ID == key) {
			_lista.remove(node); // Ukloni.
			return true;
		}
	}
	return false; // Kljuè ne postoji.
}
