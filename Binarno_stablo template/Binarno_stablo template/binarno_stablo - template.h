#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_
#include <iostream>
#include <string>
using namespace std;

template <class T> struct cvor;


template <class T>
struct cvor {
	T element;
	cvor<T>* left_child;
	cvor<T>* right_child;
};

template <class T> class binarno_stablo {
private:
	cvor<T>* root_node;
	cvor<T>* create_new_node(const T& element);

public:
	void create(const T& element);
	bool insert_left(const cvor<T>* parent, const T& element);
	bool insert_right(const cvor<T>* parent, const T& element);
	cvor<T>* root();
	cvor<T>* get_left_child(const cvor<T>* parent);
	cvor<T>* get_right_child(const cvor<T>* parent);
	bool get_node(const cvor<T>* pos, T& element);

	void inorder(const cvor<T>* node);
	void preorder(const cvor<T>* node);
	void postorder(const cvor<T>* node);
};

/*************** PRIVATNE METODE ****************/
template <class T>
cvor<T>* binarno_stablo<T>::create_new_node(const T& element) {
	cvor* novi = new cvor;
	novi->element = element;
	novi->left_child = nullptr;
	novi->right_child = nullptr;
	
	return novi;
}

/*************** JAVNE METODE ****************/
template <class T>
void binarno_stablo<T>::create(const T& element) {
	root_node = create_new_node(element);
}
template <class T>
bool binarno_stablo<T>::insert_left(const cvor<T>* parent, const T& element) {
	if (parent->left_child != nullptr) {
		return false;
	}

	parent->left_child = create_new_node(element);
	return true;
}
template <class T>
bool binarno_stablo<T>::insert_right(const cvor<T>* parent, const T& element) {
	if (parent->right_child != nullptr) {
		return false;
	}

	parent->right_child = create_new_node(element);
	return true;
}
template <class T>
cvor<T>* binarno_stablo<T>::root() {
	return root_node;
}
template <class T>
cvor<T>* binarno_stablo<T>::get_left_child(const cvor<T>* parent) {
	return parent->left_child;
}
template <class T>
cvor<T>* binarno_stablo<T>::get_right_child(const cvor<T>* parent) {
	return parent->right_child;
}
template <class T>
bool binarno_stablo<T>::get_node(const cvor<T>* pos, T& element) {
	element = pos->element;
	return true;
}
template <class T>
void binarno_stablo<T>::inorder(const cvor<T>* node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi lijevo dijete.
	inorder(node->left_child);

	// Obradi ovaj èvor (roditelja).
	T element;
	if (get_node(node, element) && element != "")
	{
		cout << element << ", ";
	}

	// Obradi desno dijete.
	inorder(node->right_child);
}
template <class T>
void binarno_stablo<T>::preorder(const cvor<T>* node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi ovaj èvor (roditelja).
	T element;
	if (get_node(node, element) && element != "")
	{
		cout << element << ", ";
	}

	// Obradi lijevo dijete.
	preorder(node->left_child);

	// Obradi desno dijete.
	preorder(node->right_child);
}
template <class T>
void binarno_stablo<T>::postorder(const cvor<T>* node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi lijevo dijete.
	postorder(node->left_child);

	// Obradi desno dijete.
	postorder(node->right_child);

	// Obradi ovaj èvor (roditelja).
	T element;
	if (get_node(node, element) && element != "")
	{
		cout << element << ", ";
	}
}

#endif