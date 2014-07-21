#include<iostream>
#include"symbol_table.h"
#include<fstream>
#include<sstream>
int main(){
	string s;
	string jos;
	ifstream dat("auti.txt");
	auti a;
	string line;
	symbol_table l;
	while (getline(dat, line)) {
		stringstream s_line(line);
		s_line >> a.naziv;
		s_line.ignore();
		getline(s_line, s);
		a.KS = atoi(s.c_str());
		l.put(a.naziv,a);
	}
	do
	{
	cout <<"Unesite ime auta kojeg zelite naci: ";
	cin >> s;
	auti *b = l.get(s);
	if (b!= nullptr)
	{
		cout <<b->naziv << " " << b->KS << endl;
	}
	else
	{
		cout <<"Nema trazenog auta. ";
	}
	cout <<"Zelite jos Da/Ne ";
	cin >> jos;
	} while (jos == "DA" || jos == "Da");

	dat.close();
	cout << endl;
	system("pause");
	return 0;
}