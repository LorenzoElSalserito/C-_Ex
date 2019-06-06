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

//questo programma prende in input un range numerico, una dimensione per determinare la grandezza dell'array
//e ne restituisce in output la tabella riempita con quel range

int main (){
int dimensione=0;
int range_numerico;
int tabella [dimensione][dimensione];


cout<<"Ciao! Dammi la dimensione della matrice"<<endl;
cin>>dimensione;
cout<<"Bene, la tua matrice sarà "<<dimensione<<" per "<<dimensione<<endl;
cout<<"Adesso dammi il range numerico per la quale vuoi che faccia le mie operazioni"<<endl;
cin>>range_numerico;
for(int i=1; i<dimensione; i++){
for(int j=1; j<=range_numerico; j++){
tabella [i][i]=j;
cout<<"la tabella prodotta è "<<tabella[i][i]<<endl;
 }
}
 return 0;
}
