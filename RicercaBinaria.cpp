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

int n;

int bin_ricors (int vett[], int elem, int p, int u);

void main ()
{
int vector[50];
int x, first, last;

	cout<<"Quanti elementi vuoi inserire nel tuo vettore?"<<endl;
	cin>>n;

	cout<<"Inserisci gli elementi del tuo vettore: "<<endl;
	for (int i=0; i<n; i++)
		cin>>vector[i];

	cout<<"Quale numero vuoi cercare all'interno del vettore?"<<endl;
		cin>>x;

		if ( bin_ricors (vector[], x, first, last) == -1 )
			cout <<"Non è stata trovata alcuna corrispondenza."<<endl;
		else
			cout <<"E' stata trovata una corrispondenza."<<endl;

}

int bin_ricors (int vett[], int elem, int p, int u)
    {
		p = vett[0];
		u = vett[n-1];
		
        if (p >= u)
            return -1;
        
        int m = (p+u)/2;
        
        if (elem<vett[m])
            return bin_ricors(vett[], elem, p, m-1);
        if (elem>vett[m])
            return bin_ricors(vett[], elem, m+1, u);
        else
            return m;
    } 
