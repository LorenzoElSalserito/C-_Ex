
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
    
    int indice=10;
    int inquinamento [10];
    int valore=19; //max valore=100; min valore=0;
    int giorni;

void TassoInquinamento ();
void PiccoInquinamento ();
void StampaInquinamento ();

int main (){
TassoInquinamento();
StampaInquinamento();

return 0;
}

void TassoInquinamento(){
	cout<<"Dammi la sequenza di numeri per i tassi di inquinamento"<<endl;
    cout<<"Termina la sequenza con un numero negativo"<<endl;
    cout<<"Ricorda che si termina anche con valori maggiori o diversi da 100"<<endl;
    indice=0;
    while (valore>0 && valore<=100){
		indice = indice+1;
		cin>>valore;
		inquinamento [indice] = valore;
		}	
	cout<<"Perfetto, hai terminato la sequenza!"<<endl;
	}

void PiccoInquinamento(){
	for (int i=1; i<indice; i++){
		if (inquinamento[i]>inquinamento[i+1] && inquinamento[i]>inquinamento[i-1]){
			cout<<"Picco nel giorno "<<i<<" con valore "<<inquinamento[i]<<endl;
			}
		}
			cout<<"Non è stato rilevato alcun picco"<<endl;
	}

void StampaInquinamento(){
	for(int i=0; i<indice; i++){
		cout<<inquinamento[i]<<" "<<endl;
		}
	PiccoInquinamento();
	}
