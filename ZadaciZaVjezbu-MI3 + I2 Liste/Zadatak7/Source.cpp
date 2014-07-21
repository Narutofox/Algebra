#include <iostream>
#include"rjecnik.h"
#include <sstream>
#include <fstream>
#include <cmath>
int Kernighan_Ritchie(string n){
	unsigned int broj = 0;
	for (unsigned int i = n.size(); i > 0; i--)
	{
		char trenutno = n[i] ;
	broj +=	trenutno * pow(31,i);
	}
	cout << broj << endl;
	/*cout << 'K' * pow(31,2) + 'I' * pow(31,1) + 'A' << endl;*/
	return broj;
}

int main(){
	auti model;
	string s;
	rjecnik m;
	ifstream dat("auti.txt");
	if (!dat)
	{
		cerr <<"Pogreska.";
	}
	string l;
	while (getline(dat,l))
	{
	stringstream s_line(l);
	s_line >> model.Naziv;
	s_line.ignore();
	getline(s_line,s);
	model.KS = atoi(s.c_str());
	unsigned int key = Kernighan_Ritchie(model.Naziv);
	m.insert(key,model);
	}
	

	


	system("pause");
	return 0;
}

