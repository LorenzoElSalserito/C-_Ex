  
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

//dato un array, controllare se n è presente tra i suoi elementi;

int main (){
int index=10;
int array[index];
int n, x;
int aus=10000;


cout<<"Dammi il numero da cercare"<<endl;
cin>>n;
cout<<"Quanti numeri vuoi inserire?"<<endl;
cin>>index;

for (int i=0;i<index;i++){
cout<<"Ok, ora dammi i numeri della matrice"<<endl;
cin>>x;
if(x==n){
	aus=x;
	}
array[i]=x;
}

if (aus==n){
	cout<<"il numero è dentro l'array"<<endl;
	}
else{
	cout<<"Il numero non è dentro l'array"<<endl;
	}

return 0;
}
