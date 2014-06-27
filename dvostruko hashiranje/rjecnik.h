#ifndef _RJECNIK_H_
#define _RJECNIK_H_

#include"zivotinje.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef int KEY;
typedef Zivotinja ELTYPE;

class rjecnik {
private:
	static const int BROJ_ELEMENATA = 30;
	/*Zivotinja* _polje = new Zivotinja [BROJ_ELEMENATA];*/
	unsigned int h(KEY key, int i);
	unsigned int h1(KEY key);
	unsigned int h2(KEY key);
	ELTYPE _polje[BROJ_ELEMENATA];
	bool sekvenicja(unsigned int index,int znak);
	unsigned int sekvencijsko_polje[BROJ_ELEMENATA];
public:
	rjecnik();
	~rjecnik();
	void insert(KEY key, ELTYPE value);
	void remove(KEY key);
	void search(KEY key);
};
int brojac = 0;
int a;
#endif


unsigned int rjecnik :: h1(KEY key){
	return key % BROJ_ELEMENATA;
}
unsigned int rjecnik :: h2(KEY key){
	return 2*(key%BROJ_ELEMENATA)+1;
}
unsigned int rjecnik::h(KEY key, int i ){

	return (h1(key) + i * h2(key)) % BROJ_ELEMENATA;

}
rjecnik::rjecnik(){
	for (int i = 0; i < BROJ_ELEMENATA ;i++)
	{
		_polje[i].broj = -1;
		_polje[i].naziv = "prazno";
	}

}
rjecnik::~rjecnik(){
	
}

bool rjecnik::sekvenicja(unsigned int index,int znak){
	if (znak == 1)
	{
		if (brojac == BROJ_ELEMENATA)
		{
			cout <<"Polje je puno";
			return false;
		}
		sekvencijsko_polje[brojac] = index;
		brojac ++;
		return true;
		
	}
	else if (znak == 2)
	{
	for (int i = 0; i < brojac; i++)
		{
			if (sekvencijsko_polje[i] == index)
			{
		
				i = a;
				int* temp = new int[brojac];
				for (int j = 0; j < a; j++)
				{
					temp[j] = sekvencijsko_polje[j];
				}
				for (int o = a+1; o < brojac; o++)
				{
					temp[o] = sekvencijsko_polje[o];
				}
				brojac --;
				for (int d = 0; d < brojac; d++)
				{
					sekvencijsko_polje[d] = temp[d];
				}
				delete[] temp;
				return true;
			}
			}
	return false;
	}
	else if (znak == 3)
	{
		for (int i = 0; i < brojac; i++)
		{
			if (sekvencijsko_polje[i] == index)
			{
				return true;
			}
			
	}
	return false;
}
	else
	{
		return false;
	}
}
void rjecnik::insert(KEY key, ELTYPE value){
	int insert = 1;
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);
		
		if (_polje[index].broj == -1 && _polje[index].naziv == "prazno")
		{
			_polje[index].broj = key;
			_polje[index].naziv = value.naziv;
			sekvenicja(index,insert);
			break;
		}
	}
}	
void rjecnik::remove (KEY key){
	int remove = 2;
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);
		if (sekvenicja(index,remove))
		{
			_polje[index].broj = -1;
			_polje[index].naziv = "prazno";
			break;
		}
		else 
		{
			cout <<"Podatak sa trezenim kljucem ne postoji" << endl;
			break;
		}
	}
}
void rjecnik::search(KEY key){
	int search = 3;
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);
		if (sekvenicja(index,search))
		{
			cout <<"Element na polju "<< key << " je "<< _polje[index].naziv << endl;
			break;
		}
		else 
		{
			cout << "Nema trezenog elementa" << endl;
			break;
		}
	}	
}
