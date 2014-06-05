#include <string>
#include <iostream>
#include "heap.h"
using namespace std;

/**************** PRIVATNO ****************************/

POSITION heap::calc_left(POSITION parent) {
	return parent * 2 + 1;
}

POSITION heap::calc_right(POSITION parent) {
	return parent * 2 + 2;
}

POSITION heap::calc_parent(POSITION child) {
	return (child - 1) / 2;
}

bool heap::is_full() {
	return _last == CAPACITY;
}

void heap::reheapify_upward() {
	// Pomi�i taj element prema vrhu hrpe.
	POSITION pos = _last;

	// Petlju vrtim sve dok ne do�em do korijena ili dok roditelj nije ve�i ili jednak od djeteta.
	while (pos != 0 && _elements[pos].Placa < _elements[calc_parent(pos)].Placa) {
		swap(_elements[pos], _elements[calc_parent(pos)]);

		pos = calc_parent(pos);
	}
}

void heap::reheapify_downward() {
	// Indeks�trenutnog��vora�roditelja,�po�injemo�s�korijenom.
	POSITION index = 0;
	
	// Radi�sve�dok�je�indeks�roditelja�na�predzadnjem�nivou.
	while (index < _last / 2) {

		// Izra�unaj�indeks�djeteta�koje�sadr�i�ve�i�element.
		POSITION left_child = calc_left(index);
		POSITION right_child = calc_right(index);

		POSITION index_with_greater_value;

		// Mogu�e su tri situacije: nema djece, postoji lijevo dijete ili postoje oba djeteta.
		if (left_child >= _last && right_child >= _last) {
			return; // Nema djece.
		}
		else if (left_child < _last && right_child >= _last) {
			index_with_greater_value = left_child; // Postoji samo lijevo.
		}
		else { // Postoje oba djeteta pa uspore�ujem koje je ve�e.
			if (_elements[left_child].Placa <= _elements[right_child].Placa) {
				index_with_greater_value = left_child;
			}
			else {
				index_with_greater_value = right_child;
			}
		}

		// Zamijeni�ako�je�u�djetetu�ve�i�element.
		if (_elements[index].Placa > _elements[index_with_greater_value].Placa) {
			swap(_elements[index], _elements[index_with_greater_value]);
		}
		else {
			// Ina�e�je�algoritam�gotov,�element�je�na�svom�mjestu.
			return;
		}

		// Nastavi�zamjene�u�toj�grani.
		index = index_with_greater_value;
	}
}

/**************** JAVNO ****************************/

heap::heap() {
	_last = 0;
}

bool heap::is_empty() {
	return _last == 0;
}

void heap::insert(const ELTYPE& element) {
	if (is_full()) {
		throw string("Hrpa je puna!");
	}

	// Spremi element na sljede�e mjesto.
	_elements[_last] = element;

	reheapify_upward();

	// Ozna�i da smo ubacili jo� jedan element.
	_last++;
}

ELTYPE heap::remove() {
	if (is_empty()) {
		throw string("Hrpa je prazna");
	}

	ELTYPE element_na_vrhu = _elements[0];

	// Ozna�i da vadimo element.
	_last--;

	// Ako�nismo�obrisali�korijen,�preslo�i�hrpu.
	if (_last != 0) {

		// Stavi�zadnji�element�na�mjesto�korijena.
		_elements[0] = _elements[_last];

		// Preslo�i hrpu.
		reheapify_downward();
	}

	return element_na_vrhu;
}

void heap::print_tree() {
	for (unsigned int i = 0; i <= _last-1; i++) {
		cout << "(" << i << ") " << _elements[i].Placa << endl;
	}
}