  
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

//dati 2 array, si stampi un terzo array uguale alla somma dei primi 2

int main (){
int array1[5];
int array2[5];
int array3[5];
int n;

cout<<"Dammi i numeri del primo array"<<endl;
for(int i=0;i<5;i++){
cin>>n;
array1[i]=n;
}
cout<<"Dammi i numeri del secondo array"<<endl;
for(int k=0;k<5;k++){
cin>>n;
array2[k]=n;
}
cout<<"Perfetto, sto elaborando il terzo array..."<<endl;

for(int j=0;j<5;j++){
	array3[j] = array1[j]+array2[j];
	}
cout<<"il terzo array ha valori: "<<endl;
for(int t=0;t<5;t++){
cout<<array3[t]<<endl;
}
return 0;
}
