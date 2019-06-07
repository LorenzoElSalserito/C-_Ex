    
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

//dato un array, controllare se gli elementi sono ordinati;

int main (){
int array[10];
int x;

cout<<"dammi 10 elementi da inserire nell'array"<<endl;

for(int i=0;i<10;i++){
	cin>>x;
	array[i]=x;
	}
	
for(int j=0;j<10;j++){
	if(array[j]<array[j+1] && array[j+1]<array[j+2]){
		cout<<"l'array è in ordine crescente"<<endl;
		break;
		}
	if(array[j]>array[j+1] && array[j+1]>array[j+2]){
		cout<<"l'array è in ordine decrescente"<<endl;
		break;
		}
	else{
		cout<<"l'array è in ordine misto"<<endl;
		break;
		}

	}
return 0;
}
