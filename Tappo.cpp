
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

//Dato un intero x ed una sequenza di numeri positivi terminata da un
// tappo negativo, determinare se x è presente nella sequenza (stampando
// su standard output la stringa "presente!" in caso affermativo, "non presente..." altrimenti).

int main (){
int x;
int index=10;
int sequenza[index];
int tappo_negativo;

cout<<"Dammi il numero da controllare nella sequenza: "<<endl;
cin>>x;
index=0;

while (tappo_negativo>=0){
	cout<<"Dammi un numero per la sequenza!"<<endl;
	cin>>tappo_negativo;
	sequenza[index]=tappo_negativo;
	index+=1;
	}


for(int i=0; i<index;i++){
	if(sequenza[i]==x){
		cout<<"x è nella sequenza"<<endl;
		break;
		}
	else{
		cout<<"x non è nella sequenza"<<endl;
		}
	}
return 0;
}

