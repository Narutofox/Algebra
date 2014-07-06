#include"rjecnik.h"
#include<fstream>
#include<sstream>

int main(){
ifstream dat("zivotinje.txt");
if (!dat)
{
	cerr <<"Pogreska";
}
string l;

rjecnik f;
while (getline(dat,l,'\t'))
{
	stringstream s_l(l);
	Zivotinja* r = new Zivotinja;
	s_l >> r->broj;
	s_l.ignore();
	getline(dat,r->naziv);
	f.insert(r->broj,r);
}

f.search(5);
f.remove(5);
f.search(5);

dat.close();
system("pause");
cout << endl;
return 0;
}