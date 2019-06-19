  
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



int main(){

int numero;
int index=10;
int lista[index];
int input;
int tappo;
int NumeroCercato;

cout<<"Ciao, per semplicità ho creato un array di 10 elementi, se vuoi cambiarlo premi 1, altrimenti premi 2"<<endl;
cin>>input;
switch(input){
	case 1:
	cin>>index;
	break;
	case 2:
	break;
	}
cout<<"Perfetto, possiamo proseguire"<<endl;
cout<<"Adesso riempiamo l'array, scegli un numero per chiudere la sequenza"<<endl;
cin>>tappo;
cout<<"Riempiamo l'array!"<<endl;

while(numero!=tappo){
for(int k=0; k<index; k++){
    cout<<"Dammi un numero: ";
	cin>>numero;
	lista[k]=numero;
	}
}

cout<<"Dimmi ora il numero che vuoi cercare:"<<endl;
cin>>NumeroCercato;

for(int i=0; i<index; i++){
	if(lista[i]==NumeroCercato){
		cout<<"Il numero "<<NumeroCercato<<" ed è stato inserito la "<<lista[i]<<" volta "<<endl;
		break;
		}
	}
for(int i=0; i<index; i++){
	if(lista[i]!=NumeroCercato){
		cout<<"Il numero "<<NumeroCercato<<" non è nella lista"<<endl;
		break;
		}
	}
return 0;
}
