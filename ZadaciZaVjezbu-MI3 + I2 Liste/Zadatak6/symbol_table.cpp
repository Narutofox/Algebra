#include "symbol_table.h"

symbol_table::symbol_table() {
}

bool symbol_table::put(string key, ELTYPE value) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.naziv == key) {
			return false; // Klju� ve� postoji.
		}
	}

	_lista.insert(value, _lista.end());
	return true;
}

ELTYPE* symbol_table::get(string key) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.naziv == key) {
			return &node->element; // Vrati adresu prona�enog elementa.
		}
	}
	return nullptr; // neme elementa s tra�enim klju�em.
}

bool symbol_table::remove(string key) {
	for (POSITION node = _lista.first(); node != _lista.end(); node = node->next) {
		if (node->element.naziv == key) {
			_lista.remove(node); // Ukloni.
			return true;
		}
	}
	return false; // Klju� ne postoji.
}
