    
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

//programma che effettua la sommatoria

int main(){

int numero=0;
int range=0;
int somma=0;

cout<<"Dimmi quante volte devo effettuare la somma: "<<endl;
cin>>range;
cout<<"Procediamo alla sommatoria! Dammi i numeri: "<<endl;

for(int i=0; i<range; i++){
	cin>>numero;
	somma = somma+numero;
	}
	
cout<<somma;

return 0;
}
