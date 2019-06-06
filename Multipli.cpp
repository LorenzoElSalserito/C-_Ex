
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

//questo programma prende in input dei numeri, e determinato un range, ne stampa i multipli;

int main (){
int range;
int numeri;
int multipli;

cout<<"Ciao! Dammi i numeri di cui vuoi i multipli"<<endl;
cin>>numeri;
cout<<"Dammi ora il range per la quale devo fare i multipli"<<endl;
cin>>range;
cout<<"i multipli saranno: "<<endl;
for(int i=1; i<=range;i++){
	for(int j=1;j<=numeri;j++){
    multipli=i*j;
    cout<<multipli<<endl;
	}
}

 return 0;
}
