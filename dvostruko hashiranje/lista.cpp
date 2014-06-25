#include "lista.h"

lista::lista() {
	_head = new cvor;
	_tail = new cvor;

	_head->previous = nullptr;
	_head->next = _tail;

	_tail->previous = _head;
	_tail->next = nullptr;
}

POSITION lista::end() {
	return _tail;
}

POSITION lista::first() {
	return _head->next;
}

bool lista::insert(ELTYPE element, POSITION pos) {
	cvor* novi = new cvor;

	novi->element = element;
	novi->previous = pos->previous;
	novi->next = pos;

	pos->previous->next = novi;
	pos->previous = novi;

	return true;
}

bool lista::read(POSITION pos, ELTYPE& element) {
	element = pos->element;
	return true;
}

bool lista::remove(POSITION pos) {
	pos->previous->next = pos->next;
	pos->next->previous = pos->previous;
	
	delete pos;

	return true;
}

POSITION lista::find(int broj) {
	cvor* temp = _head;
	while (temp != end()) {
		if (temp->element.broj == broj) {
			return temp;
		}
		temp = temp->next;
	}
	return end();
}

POSITION lista::empty() {
	cvor* temp = _head->next;
	while (temp != end()) {
		cvor* dalje = temp->next;
		delete temp;
		temp = dalje;
	}

	_head->next = _tail;
	_tail->previous = _head;

	return end();
}

POSITION lista::next(POSITION pos) {
	return pos->next;
}

POSITION lista::prev(POSITION pos) {
	return pos->previous;
}
