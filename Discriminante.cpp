
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

//Letti da input tre numeri, che rappresentano i coefficienti di una 
//equazione di secondo grado (siano a,b,c), calcolare il discriminante 
//come d=(b*b-(4*a*c)), e verificare se è maggiore o uguale a zero oppure 
//negativo; stampare le stringhe "discriminante maggiore o uguale a zero!!"
// o "discriminante negativo...", rispettivamente.

int main (){
int discriminante;
int quadrato;
int quattroAC;
int n1, n2, n3;

cout<<"Ciao! devo calcolare il Discriminante di un'equazione di secondo grado"<<endl;
cout<<"Per iniziare dammi 3 numeri"<<endl;
cin>>n1;
cout<<"Grazie, dammene un altro"<<endl;
cin>>n2;
cout<<"Grazie, dammene un altro"<<endl;
cin>>n3;
cout<<"Perfetto! Posso procedere al calcolo"<<endl;
quadrato = n2*n2;
quattroAC = 4*n1*n3;
discriminante = quadrato - quattroAC;
if (discriminante>=0){
	cout<<"Il discriminante è maggiore o uguale a 0 - infatti vale "<<discriminante<<endl;
	}
else{
	cout<<"discriminante negativo..."<<endl;
	}
return 0;
}
