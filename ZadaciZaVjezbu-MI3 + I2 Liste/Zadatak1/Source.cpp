#include<iostream>
using namespace std;

int pronadji_binarno(float brojevi[], int n, float what) {

	int broj_pretrazivanja = 0;
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		
		broj_pretrazivanja++;

		int mid = (low + high) / 2;

		if (brojevi[mid] == what) { // Naðen je.
			cout << "Posao obavljen u " << broj_pretrazivanja << " pretrazivanja" << endl;
			return mid;
		} 
		else if (brojevi[mid] > what) { // U lijevoj je polovici.
			high = mid - 1;
		}
		else { // U desnoj je polovici.
			low = mid + 1;
		}
	}

	return -1;
}

int main(){
	int n;
	float a;
	float trazeno;
	cout <<"Koliko brojeva zelite unjeti? ";
	cin >> n;
	float* binarno = new float [n];
	for (int i = 0; i < n; i++)
	{
		cout <<"Unesite decimalan "<< i+1 <<" broj: ";
		cin >> a;
		binarno[i] = a;
	}
	cout <<"Koji decimalni broj zelite pronaci ? ";
	cin >> trazeno;

	if (pronadji_binarno(binarno,n,trazeno) == -1)
	{
		cout <<"Broj ne postoji u zadanom polju. ";
	}


	delete[] binarno;
	system("pause");
return 0;
}