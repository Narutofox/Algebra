#include "Osoba.h"
#include <iostream>
#include <fstream>

void selection_sort(Osoba *data, int length) {
	for (int i = 0; i < length; ++i) {
		int min_index = i;
		for (int j = i + 1; j < length; ++j) {
			if (data[j].Placa < data[min_index].Placa) {
				min_index = j;
			}
		}
		swap(data[min_index], data[i]);
	}
}

void insertion_sort(Osoba *data, int length) {
	for (int i = 1; i < length; i++) { 
		int temp = data[i].visina;
		for (int j = i; j >= 1 && data[j - 1].visina > temp; --j) {
			swap(data[j], data[j - 1]);
		}
	}
	
}
int prebroji(){
	string s;
	int brojac = 0;
	ifstream dat("osobe.txt");
	if (!dat)
	{
		cerr <<"Pogreska";
		return 1;
	}
	while (getline(dat,s))
	{
		brojac ++;
	}
	return brojac;
}
void unos(Osoba *polje,int broj){
	string s;
	ifstream dat("osobe.txt");
	if (!dat)
	{
		cerr <<"Pogreska";
		return;
	}
	for (int i = 0; i < broj; i++)
	{
		getline(dat,polje[i].ime,'\t');
		getline(dat,polje[i].prezime,'\t');
		getline(dat,s,'\t');
		polje[i].visina = atoi(s.c_str());
		getline(dat,s);
		polje[i].Placa = atof(s.c_str());
	}		
	for (int i = 0; i < broj; i++)
	{
		cout << polje[i].ime << " " << polje[i].prezime << " " << polje[i].visina << " " << polje[i].Placa << endl;
	}
		ofstream visina_osobe("visina_osobe.txt");
	if (!visina_osobe)
	{
		cerr<< "pogreska";
		return ;
	}
	visina_osobe<<"Insertion: " << endl;
	insertion_sort(polje,broj);
	for (int i = 0; i < broj; i++)
	{
		visina_osobe << polje[i].ime << " " << polje[i].prezime << " " << polje[i].visina << " " << polje[i].Placa << endl;
	}
	ofstream placa_osobe("placa_osobe.txt");
	if (!placa_osobe)
	{
		cerr<< "pogreska";
		return ;
	}
	placa_osobe <<"Selection: "<<endl;
	selection_sort(polje,broj);
	for (int i = 0; i < broj; i++)
	{
		placa_osobe << polje[i].ime << " " << polje[i].prezime << " " << polje[i].visina << " " << polje[i].Placa << endl;
	}
	dat.close();
	visina_osobe.close();
	placa_osobe.close();
}
int main(){
	int broj=prebroji();
	Osoba* polje = new Osoba[broj];
	unos(polje,broj);
	

	cout << endl;
	// heap h,  while(!h.is_empty){ eltype p = h.remove  cout p.naziv, p.laca itd...
	// uvjet ? napravi ako tocno : napravi ako netocno npr: brojevi1>>left ? true : false
	delete[] polje;
	
	system ("pause");
	return 0;
}