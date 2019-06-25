
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
    
    int n1, n2, n3, n4, gioca;
    int somma1, somma2;
    int seed1=1234;
    int seed2=5678;

void TiraDado();
void TiraDadoPc();
void Vittoria();
void GiocaAncora();

int main (){

TiraDado();
TiraDadoPc();
Vittoria();
GiocaAncora();
cout<<"Ciao Topo di Fogna"<<endl;

return 0;
}

void TiraDado(){
	cout<<"Mescola i Dadi Topo di Fogna!"<<endl;
	srand(time(0));
	n1=rand()%6+1;
	n2=rand()%6+1;
	somma1=n1+n2;
	cout<<"Ti sono usciti "<<n1<<" e "<<n2<<endl;
	cout<<"Bel Tiro! Hai fatto "<<somma1<<endl;
	}
	
void TiraDadoPc(){
	cout<<"Ti faccio vedere io come si fa! Topo di Fogna!"<<endl;
	srand(time(0));
	n3=(rand()%6+1+rand()%6+1)/2;
	n4=(rand()%6+1+rand()%6+1)/2;
	somma2=n3+n4;
	cout<<"Mi sono usciti "<<n3<<" e "<<n4<<endl;
	cout<<"Non male mozzo! Ho fatto "<<somma2<<endl;
	}
	
void Vittoria(){
	if(somma1>somma2){
		cout<<"Hai vinto tu Mozzo!"<<endl;
		}
	if(somma1==somma2){
		cout<<"Parità..."<<endl;
		}
	if(somma1<somma2){
		cout<<"Fatti da parte Mozzo, e lustrami gli stivali! Hai perso!"<<endl;
		}
	}

void GiocaAncora(){
	cout<<"Vuoi fare un'altra partita Mozzo?"<<endl;
	cout<<"Se si, dammi un numero maggiore di 0"<<endl;
	cin>>gioca;
	while(gioca>0){
		TiraDado();
		TiraDadoPc();
		Vittoria();
		GiocaAncora();
		}
	}
