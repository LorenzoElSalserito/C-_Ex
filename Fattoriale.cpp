
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

//semplice programma che calcola il fattoriale

int main (){
int numero;
int contatore;
int fattoriale;


cout<<"Dammi il numero del quale vuoi che calcoli il fattoriale"<<endl;
cin>>numero;
if(numero==0 || numero==1){
	fattoriale=1;
	}
else{
contatore=numero;
while (contatore!=0){
	fattoriale=numero*(numero-1);
	contatore--;
	}
}
cout<<"Il fattoriale di "<<numero<<" è "<<fattoriale<<endl;
return 0;
}
