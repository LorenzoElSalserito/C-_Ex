
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

//Letti 10 numeri da input, determinare il submassimo.

int main (){
int index=10;
int sequenza[index];
int numero;
int massimo=0;
int submassimo=0;

for (int i=0;i<index;i++) {
cout<<"Dammi il numero della sequenza"<<endl;
cin>>numero;
sequenza[i]=numero;
if(sequenza[i]>massimo){
		submassimo=massimo;
		massimo=sequenza[i];
		}
}

cout<<"Il submassimo è: "<<submassimo/*<<" il massimo è "<<massimo*/<<endl;
return 0;
}
