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

#define MAX 50
int n;
int crivello[MAX];

void eratostene ();

void main()
{
	cout<<"Inserisci un numero tra 0 e 50 di cui vuoi conoscere i numeri primi antestanti"<<endl;

	eratostene ();

	cout<<"I numeri primi che precedono "<<n<<" sono: "<<endl;
	for (int i=0; i<n; i++)
	{
		if(crivello[i] == 0)
			cout<<i<<endl;
	}

	system ("pause");
}

void eratostene ()
{

		cin>>n;

			for (int i=0; i<n; i++)
	{
		crivello[i] = 0;
	}
			
			
			
			for (int i=2; i<n; i++)
	{       
		if (crivello[i] == 0)
		{	
			for (int j=2; j<=(n/i); j++)
				{
					crivello[i*j] = 1;
				}
		}
	}


}
