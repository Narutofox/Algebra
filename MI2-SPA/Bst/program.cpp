#include<iostream>
#include<fstream>
#include"bst.h"
#include"Osoba.h"
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


void placa(Osoba *polje, int broj){
	bst novac;
	float unos;
	std::string jos;
		std::ifstream dat("osobe.txt");
		if (!dat)
	{
		std::cerr<<"Nemogu otovriti datoteku.";
		return;
	}
 
   for (int i = 0; i < broj; i++)
	{
		
		novac.insert(polje[i]);
	}
	do
	{
	cout <<"Unesite iznos place u decimalnim brojevima " << endl <<"npr: za placu od 3000 Kn unijeti 3000.00: ";
	cin >> unos;
	
		novac.exists(unos);
	
	

	cout <<"Jos? Da/Ne : ";
	cin >> jos;
	} while (jos == "Da");

}
int main(){
	
	int broj_osoba=prebroji();
	Osoba* polje = new Osoba[broj_osoba];
	ucitaj_podatke(polje,broj_osoba);
 	placa(polje,broj_osoba);

	

	return 0;
}