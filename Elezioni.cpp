
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

	int cont1=0;
	int cont2=0;
	int cont3=0;
    int a=0;
    int b=0;
    int c=0;
    int voto=100;
    int x=0;
    
void Votazione();
void StampaVoti();

int main (){

Votazione(); StampaVoti();

return 0;
}

void Votazione(){
    //la votazione è valida finché inserisco numeri positivi
	cout<<"Ciao! Benvenuto in VotiSmart, la piattaforma facile per i voti elettorali"<<endl;
	cout<<"*****ATTENDERE PREGO*****"<<endl;
	cout<<"Caricamento Completato, ora puoi votare!"<<endl;
	while(voto>0){
	cout<<"Ciao, dimmi per chi vuoi votare!"<<endl;
	cout<<"1)Topolino, 2)Pippo, 3)Paperino:"<<endl;
	cout<<"Per smettere di votare, inserire un 'voto<0'"<<endl;
    cin>>x;
    if (x==1){
		cout<<"Quanti voti vuoi inserire?"<<endl;
		cin>>voto;
		cont1=cont1+voto;
		}
    if (x==2){
		cout<<"Quanti voti vuoi inserire?"<<endl;
		cin>>voto;
		cont2=cont2+voto;
	}
    if (x==3){
		cout<<"Quanti voti vuoi inserire?"<<endl;
		cin>>voto;
		cont3=cont3+voto;
	}
    if (x!=1 && x!=2 && x!=3){
		cout<<"Hai inserito un candidato non valido, riprova"<<endl;
		cin>>x;
		}
	if(x<0){
		break;
		}
    }		
}
	
	void StampaVoti(){
		cout<<"1) Topolino ha preso "<<cont1<<" voti"<<endl;
		cout<<"2) Pippo ha preso "<<cont2<<" voti"<<endl;
		cout<<"3) Paperino ha preso "<<cont3<<" voti"<<endl;
		}
