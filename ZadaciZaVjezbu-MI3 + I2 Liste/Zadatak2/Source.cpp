#include<iostream>
#include"Osoba.h"
#include <vector>
int pronadji_binarno(vector<Osoba>brojevi,string what) {

	int broj_pretrazivanja = 0;
	int low = 0;
	int high = brojevi.size() - 1;

	while (low <= high) {
		
		broj_pretrazivanja++;

		int mid = (low + high) / 2;

		if (brojevi[mid].OIB == what) { // Naðen je.
			cout << "Posao obavljen u " << broj_pretrazivanja << " pretrazivanja" << endl;
			return mid;
		} 
		else if (brojevi[mid].OIB > what) { // U lijevoj je polovici.
			high = mid - 1;
		}
		else { // U desnoj je polovici.
			low = mid + 1;
		}
	}

	return -1;
}

int main(){
	Osoba student;
	string jos;
	string trazeno;
	vector<Osoba> k;
	
	do
	{
		cout << "Unesite ime studenta: ";
		getline(cin,student.Ime);
		cout <<"Unesite prezime studenta: ";
		getline(cin,student.Prezime);
		cout <<"Unesite OIB studenta: ";
		getline(cin,student.OIB);
		cout <<"Unseite godinu rodjenja studenta: ";
		cin >> student.GodinaRodjenja;
		k.push_back(student);
		cout <<"Zelite jos? Da/Ne ";
		cin >> jos;
		cin.ignore();
	} while (jos == "Da" || jos == "DA");
	
	cout <<"Koji OIB zelite pronaci ? ";
	cin >> trazeno;


	if (pronadji_binarno(k,trazeno) == -1)
	{
		cout <<"OIB ne postoji u zadanom polju." << endl;
	}


	
	system("pause");
return 0;
}