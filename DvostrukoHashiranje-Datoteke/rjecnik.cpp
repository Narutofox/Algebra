#include"rjecnik.h"

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
	for (KEY i = 0; i < BROJ_ELEMENATA ;i++)
	{
		_polje[i] = nullptr;
		
	}
	
}
rjecnik::~rjecnik(){
	
	for (KEY i = 0; i < BROJ_ELEMENATA; i++)
	{
		delete _polje[i];
	}
}

void rjecnik::insert(KEY key, ELTYPE* value){
	
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);
		
		if (_polje[index] == nullptr)
		{
			_polje[index] = value;
			break;
		}
	}
}	
void rjecnik::remove (KEY key){
	
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);
		if (_polje[index]!= nullptr)
		{
			_polje[index]= nullptr;
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

	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++)
	{
		unsigned int index = h(key,i);

		if (_polje[index] == nullptr)
		{
			cout << "Nema trezenog elementa" << endl;
			break;
		}
		
		else if (_polje[index]->broj == key)
		{
			cout <<"Element sa kljucem "<< key << " je "<< _polje[index]->naziv << endl;
			break;
		}
	}
			
}	
