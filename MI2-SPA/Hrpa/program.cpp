#include<iostream>
#include<fstream>
#include"Osoba.h"
#include"heap.h"
int prebroji(){
	std::string s;
	int brojac = 0;
	std::ifstream dat("osobe.txt");
	if (!dat)
	{
		std::cerr<<"Nemogu otovriti datoteku.";
		return 1;
	}

	while (getline(dat,s))
	{
		brojac ++;
	}
	dat.close();
	return brojac;
}
void ucitaj_podatke(Osoba *polje,int broj){
	string s;
	std::ifstream dat("osobe.txt");
		if (!dat)
	{
		std::cerr<<"Nemogu otovriti datoteku.";
		return;
	}
		for (int i = 0; i < broj; i++)
		{
			getline(dat,polje[i].Ime,' ');
			getline(dat,polje[i].Prezime,'\t');
			getline(dat,s,'\t');
			polje[i].Visina = atoi(s.c_str());
			getline(dat,s);
			polje[i].Placa = atof(s.c_str());	
		}
		dat.close();
}
void sortiraj(Osoba *data, int n) {

	bool sortirano;

	for (int i = 0; i < n - 1; i++) { // Jer zadnjeg nemam s èim usporediti.
		
		sortirano = true;

		for (int j = 0; j < n - 1 - i; j++) { // Jer je ostatak liste sortiran.
			if (data[j].Placa > data[j + 1].Placa) {
				swap(data[j].Placa, data[j + 1].Placa);
				sortirano = false;
			}
		}

		if (sortirano) {
			break;
		}
	}
}

int main(){
	heap osoba;
	int broj_osoba=prebroji();
	Osoba* polje = new Osoba[broj_osoba];
	ucitaj_podatke(polje,broj_osoba);
	sortiraj(polje, broj_osoba);
	for (int i = 0; i < broj_osoba; i++)
	{
		osoba.insert(polje[i]);
	}
	/*osoba.print_tree();*/
	cout << endl;
	while (!osoba.is_empty())
	{
		ELTYPE p = osoba.remove();
		
			cout <<p.Ime<<" "<<p.Prezime<<" "<<p.Visina<<" "<<p.Placa<< endl;
		
		
	}
	
	cout << endl;
	system("pause");
	return 0;
}