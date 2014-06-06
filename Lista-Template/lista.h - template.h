#ifndef _LISTA_H_
#define _LISTA_H_
#include<iostream>
using namespace std;
template <class T>
struct cvor {
	cvor<T>* next;
	T element;
};

template <class T> class lista {
private:
	cvor<T>* _head; // "Prvi ispred" poèetka liste.
	cvor<T>* _tail; // "Prvi iza" kraja liste.

public:
	lista<T>();
	cvor<T>* end();
	cvor<T>* first();
	bool insert(T element, cvor<T>* pos);
	bool read(cvor<T>* pos, T& element);
	bool remove(cvor<T>* pos);
	cvor<T>* find(T element);
	cvor<T>* empty();
	cvor<T>* next(cvor<T>* pos);
	cvor<T>* prev(cvor<T>* pos);
};

template<class T>
lista<T>::lista() {
	_tail = new cvor<T>;
	//_tail->element = "TAIL"; // Dodano samo za potrebe debuggiranja, treba ga baciti van.
	_tail->next = nullptr;
	
	_head = new cvor<T>;
	//_head->element = "HEAD"; // Dodano samo za potrebe debuggiranja, treba ga baciti van.
	_head->next = _tail;
}

template <class T>
cvor<T>* lista<T>::end() {
	return _tail;
}

template <class T>
cvor<T>* lista<T>::first() {
	return _head->next;
}

template <class T>
bool lista<T>::insert(T element, cvor<T>* pos) {
	cvor<T>* novi = new cvor<T>;
	novi->element = element;

	cvor<T>* previous = prev(pos);
	previous->next = novi;
	novi->next = pos;
	return true;
}

template <class T>
bool lista<T>::read(cvor<T>* pos, T& element) {
	element = pos->element;
	return true;
}

template <class T>
bool lista<T>::remove(cvor<T>* pos) {
	cvor<T>* previous = prev(pos);
	previous->next = pos->next;
	delete pos;
	
	return true;
}

template <class T>
cvor<T>* lista<T>::find(T element) {
	cvor<T>* temp = _head;
	while (temp != end()) {
		if (temp->element == element) {
			return temp;
		}
		temp = temp->next;
	}
	return end();
}

template <class T>
cvor<T>* lista<T>::empty() {
	cvor<T>* temp = _head->next;
	while (temp != end()) {
		cvor<T>* dalje = temp->next;
		delete temp;
		temp = dalje;
	}
	_head->next = _tail;
	return end();
}

template <class T>
cvor<T>* lista<T>::next(cvor<T>* pos) {
	return pos->next;
}

template <class T>
cvor<T>* lista<T>::prev(cvor<T>* pos) {
	cvor<T>* temp = _head;
	while (temp->next != end() && temp->next != pos) {
		temp = temp->next;
	}
	return temp;
}
template<class T>
void ispisi_listu(lista<T>& l) {
	T element;
	cout << "ISPIS LISTE: " << endl;
	for (cvor<T>* pos = l.first(); pos != l.end(); pos = l.next(pos)) {
		l.read(pos, element);
		cout << element << endl;
	}
	cout << endl;
}
#endif