#include "rjecnik.h"
int main(){
Zivotinja k;
k.broj = 25;
k.naziv = "Maca";
rjecnik st;
st.insert(k.broj,k);
st.search(k.broj);
st.remove(k.broj);
st.search(k.broj);
system("pause");
cout << endl;
return 0;
}