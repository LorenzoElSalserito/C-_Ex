
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

//Letta una sequenza che termina con -1, restituire, massimo, minimo e media;

int main (){
int index=0;
int sequenza[index];
int numero;
int ausiliario;
int massimo=0;
int minimo=0;
int media=0;
int somma=0;

while (numero!=-1) {
cout<<"Dammi il numero della sequenza"<<endl;
cin>>numero;
sequenza[index]=numero;
if(numero>massimo){
		massimo=numero;
		}
if(numero<ausiliario){
	minimo=numero;
    }
if(numero<massimo){
	ausiliario=numero;
	}
index++;
}

for(int i=0;i<index;i++){
	somma=sequenza[i]+somma;
	media=somma/index;
}

cout<<"I valori di massimo, minimo e media sono: "<<massimo<<" "<<minimo<<" "<<media<<" "<<endl;
return 0;
}
