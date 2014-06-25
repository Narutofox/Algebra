#include <iostream>
#include <string>
#include "symbol_table.h"
#include "osoba.h"
#include <fstream>
using namespace std;

int prebroji(){
	int brojac = 0;
	string s;
	ifstream dat2("Radnici.txt");
	if (!dat2)
	{
		cerr <<"Pogreska";
		return 1;
	}

	while (getline(dat2,s))
		{
			brojac ++;
		}
	return brojac;
}

void unos(osoba radnik){
	string jos;
	ofstream dat("Radnici.txt");
	if (!dat)
	{
		cerr <<"Pogreska";
		return ;
	}
	do
	{
		cout <<"Unesite ime radnika: "<< endl;
		cin >> radnik.Ime;
		cout <<"Unesite prezime radnika: "<<endl;
		cin >> radnik.Prezime;
		cout <<"Unesite dob radnika: " << endl;
		cin >> radnik.Dob;
		cout <<"Unesite ID radnika: " << endl;
		cin >> radnik.ID;

		dat << radnik.Ime <<"\t"<<radnik.Prezime<<"\t" << radnik.Dob <<"\t"<< radnik.ID<< endl;

		cout <<"Jos Da/Ne: ";
		cin >> jos;
	} while (jos== "Da" || jos == "DA" || jos == "da" || jos == "dA");
	dat.close();

}

void ispis(osoba* polje, int broj){
		string s;
	ifstream dat2("Radnici.txt");
	if (!dat2)
	{
		cerr <<"Pogreska";
		return;
	}
		
		
		for (int i = 0; i < broj; i++)
		{
			getline(dat2,polje[i].Ime,'\t');
			getline(dat2,polje[i].Prezime,'\t');
			getline(dat2,s,'\t');
			polje[i].Dob = atoi(s.c_str());
			getline(dat2,s);
			polje[i].ID = atoi(s.c_str());
		}


		for (int i = 0; i < broj; i++)
		{
			cout << polje[i].Ime <<" "<< polje[i].Prezime <<" "<<polje[i].Dob <<" "<< polje[i].ID<< endl;
		}
		dat2.close();
}
void ispisi(osoba* s) {
	if (s != nullptr) {
		cout << "Pronasao radnika: " << s->Ime << " " << s->Prezime << endl;
	}
	else {
		cout << "Trazeni radnik ne postoji" << endl;
	}
}
int main(){
	osoba radnik;
	int a;
	string jos;
	unos(radnik);
	int broj = prebroji();
	osoba* polje = new osoba[broj];
	ispis(polje,broj);

	symbol_table id;
	for (int i = 0; i < broj; i++)
	{
		id.put(polje[i].ID,polje[i]);
	}
	do
	{
	cout <<"Unesite ID radnika za pretrazivanje: ";
	cin >> a;
	osoba* postojeci = id.get(a);
	ispisi(postojeci);
	cout <<"Ponovo Da/Ne? ";
	cin >> jos;
	} while (jos== "Da" || jos == "DA" || jos == "da" || jos == "dA");
	

	system("pause");
	delete[] polje;
	return 0;
}