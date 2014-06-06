#include<iostream>
#include"lista.h - template.h"
#include <string>



int main(){
	lista <std::string> prezimena;
	lista <std::string> imena;
	lista <int> godine;
	lista <double> visina;
	imena.insert("Naruto",imena.first());
	prezimena.insert("Uzumaki",prezimena.first());
	godine.insert(19,godine.first());
	visina.insert(175.25,visina.first());
	ispisi_listu(imena);
	ispisi_listu(prezimena);
	ispisi_listu(godine);
	ispisi_listu(visina);
	system("pause");
	return 0;
}