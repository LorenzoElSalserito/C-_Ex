  
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

//datoi 2 array controllare se uno è contenuto nell'altro

int main (){
int n=10, m=20, x=0;
int lista1[n];
int lista2[m];
int contatore=0;

cout<<"Ciao! Dimmi di quanto deve essere grande il primo array"<<endl;
cin>>n;
cout<<"Dimmi di quanto deve essere grande il secondo array"<<endl;
cin>>m;
while(n==m){
	cout<<"Non posso continuare se sono uguali"<<endl;
	cout<<"Dammi nuovamente il valore del primo"<<endl;
	cin>>n;
	cout<<"Dammi nuovamente il valore del secondo"<<endl;
	cin>>m;
}
cout<<"Dammi i valori del primo array"<<endl;
for(int t=0;t<n;t++){
	cin>>x;
	lista1[t]=x;
	}
cout<<"Dammi i valori del secondo array"<<endl;	
for(int w=0;w<m;w++){
	cin>>x;
	lista2[w]=x;
	}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
	    if(lista1[i]==lista2[j]){
			contatore=contatore+1;
			}
	    }
}

if(n<m){
	if(contatore==n){
		cout<<"La lista 1 è contenuta nella lista 2"<<endl;
		}
	}
if(n>m){
	if(contatore==m){
		cout<<"La lista 2 è contenuta nella lista 1"<<endl;
		}
	}

return 0;
}
