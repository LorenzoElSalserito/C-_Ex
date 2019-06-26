
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

void ScegliProdotto();
void GeneraHappyMeal();
void StampaRiepilogo();

char scelta='s';
int ContatoreBambini=0;
int ContatoreAdulti=0;
int ContatoreGiochino=0;
int sceltagiochino=0;
	string gioco1="Batman";
	string gioco2="Superman";
	string gioco3="WonderWoman";
	string gioco4="Aquaman";
int batman=0;
int superman=0;
int wonderwoman=0;
int aquaman=0;
char *sceltapersona=&scelta;

int main (){

ScegliProdotto();
StampaRiepilogo();

return 0;
}

void ScegliProdotto(){
		cout<<"Pasto per bambini o pasto per adulti?"<<endl;
		cout<<"A=adulti, B=bambini, Z per uscire"<<endl;
		cin>>scelta;
		if (scelta=='b'||scelta=='B'){
			ContatoreBambini=ContatoreBambini+1;
			GeneraHappyMeal();cout<<"vuole altro?"<<endl;
			cin>>scelta;
			if(scelta=='s'||scelta=='S'){
				ScegliProdotto();
				}
			}
		if(scelta=='a'||scelta=='A'){
			ContatoreAdulti=ContatoreAdulti+1;
			cout<<"vuole altro?"<<endl;
			cin>>scelta;
			if(scelta=='s'||scelta=='S'){
				ScegliProdotto();
				}
			}
		if(scelta=='z'||scelta=='Z'){
			cout<<"Arrivederci"<<endl;
			}
		else{
			cout<<"Arrivederci"<<endl;
			}
	}

void GeneraHappyMeal(){
	cout<<"Vuoi un giochino?"<<endl;
	cin>>scelta;
		if(scelta=='s'||scelta=='S'){
			ContatoreGiochino=ContatoreGiochino+1;
			srand(time(0));
			sceltagiochino=rand()%4+1;
		    if (sceltagiochino==1){
				batman=batman+1;
				}
		    if (sceltagiochino==2){
				superman=superman+1;
				}
		    if (sceltagiochino==3){
				wonderwoman=wonderwoman+1;
				}
		    if (sceltagiochino==4){
				aquaman=aquaman+1;
				}
			}
		if(scelta=='n'||scelta=='N'){
			cout<<"Perfetto, si goda il suo pasto!"<<endl;
			}
		else{
			cout<<"Si goda il suo pasto!"<<endl;
			}
	}

void StampaRiepilogo(){
	cout<<"Ecco il riepilogo di quello che ha ordinato:"<<endl;
	cout<<"Ha preso "<<ContatoreAdulti<<" pasti per adulti;"<<endl;
	cout<<"Ha preso "<<ContatoreBambini<<" pasti per bambini;"<<endl;
	cout<<"Ti ho dato "<<batman<<" giochi di batman"<<endl;
	cout<<"Ti ho dato "<<superman<<" giochi di superman"<<endl;
	cout<<"Ti ho dato "<<wonderwoman<<" giochi di wonderwoman"<<endl;
	cout<<"Ti ho dato "<<aquaman<<" giochi di aquaman"<<endl;
	}
