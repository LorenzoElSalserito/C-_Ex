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

#define max 50

int n;
int array[max];

void bubble ();

void main ()
{
	cout <<"Quanti elementi vuoi riordinare?"<<endl;
	cin>>n;
	cout <<"Inserisci gli elementi uno per volta"<<endl;
	for (int i=0; i<n; i++)
		cin>> array[i];

	bubble ();

	cout<<"Ecco gli elementi riordinati: "<<endl;
	for (int i=0; i<n; i++)
		cout << array[i] <<" ";

	system ("pause");
}

void bubble ()
{
	int aus;

	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (array[j]<array[i])
			{
				aus = array[j];
				array[j] = array[i];
				array[i]= aus;
			}
		}
	}

}
