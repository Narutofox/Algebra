//#include <iostream>
//#include <string>
//#include "symbol_table.h"
//using namespace std;
//
//void ispisi(student* s) {
//	if (s != nullptr) {
//		cout << "Pronasao studenta: " << s->ime << " " << s->prezime << endl;
//	}
//	else {
//		cout << "Trazeni student ne postoji" << endl;
//	}
//}
//
//int main() {
//
//	// Kreiramo tablicu simbola.
//	student s1;
//	s1.ime = "Miro";
//	s1.prezime = "Miric";
//	s1.broj_indeksa = "9584515151";
//	s1.jmbag = "1111111111";
//
//	student s2;
//	s2.ime = "Ana";
//	s2.prezime = "Anic";
//	s2.broj_indeksa = "8511815415";
//	s2.jmbag = "2222222222";
//
//	student s3;
//	s3.ime = "Iva";
//	s3.prezime = "Ivic";
//	s3.broj_indeksa = "9876422818";
//	s3.jmbag = "3333333333";
//
//	symbol_table st;
//	st.put(s1.jmbag, s1);
//	st.put(s2.jmbag, s2);
//	st.put(s3.jmbag, s3);
//
//	// Trazimo postojecu osobu.
//	student* postojeci = st.get("2222222222");
//	ispisi(postojeci);
//
//	// Trazimo nepostojecu osobu.
//	postojeci = st.get("5555555555");
//	ispisi(postojeci);
//
//	// Uklanjamo osobu
//	st.remove("2222222222");
//
//	// Trazimo osobu koja vise ne postoji.
//	postojeci = st.get("2222222222");
//	ispisi(postojeci);
//
//	return 0;
//}