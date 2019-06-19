  
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//controlliamo se la lista è palindroma

int main(){

int numero;
int index=9;
int aus=9;
int lista[index];

cout<<"Ciao, hai un array da 9 numeri, dammi i numeri così lo riempiamo"<<endl;
for(int i=0;i<index;i++){
	cin>>numero;
	lista[i]=numero;
	}
cout<<"Adesso controllo se è Palindromo"<<endl;
cout<<"Ricorda che è palindromo quando leggendolo al contrario rimane invariato"<<endl;

for(int j=0; j<9; j++){
	if(lista[j]==lista[aus-1]){
			cout<<"E' Palindromo"<<endl;
			aus=aus-1;
		}
	else{
		cout<<"Non è Palindromo"<<endl;
		}
	}

return 0;
}
