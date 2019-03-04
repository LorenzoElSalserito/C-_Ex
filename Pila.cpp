#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <sstream>

#define MAX 50

using namespace std;

void push ();
void pop ();
void stampa ();

int pila[MAX];
int top = -1;

void main ()
{
	int x = 0;

	while (x != 4)
	{
	cout<<"Digita 1 per aggiungere un elemento alla pila;"<<endl;
	cout<<"Digita 2 per eliminare un elemento della pila;"<<endl;
	cout<<"Digita 3 per stampare un la pila;"<<endl;
	cout<<"Digita 4 per terminare la pila;"<<endl;

		cin>> x;
	
	switch (x)
	{
	case 1: push();break;
	case 2: pop();break;
	case 3: stampa();break;
	case 4: {
			cout <<"La pila è terminata."<<endl;
			};break;

	}
	}
}

void push ()
{
	int elem;

	if (top == MAX-1)
		cout <<"Attenzione! Pila piena."<<endl;
	else
	{
		cout <<"Inserisci elemento della pila "<<endl;
		cin >> elem;
		
		top++;
		pila[top] = elem;

	}
}

void pop ()
{

	if (top == -1)
		cout <<"Attenzione! Pila vuota."<<endl;
	else
	{
		cout <<"Attenzione! L'elemento "<<pila[top]<<"sta per essere eliminato"<<endl;
		pila[top] = 0;
		top--;
	}
}

void stampa ()
{
	for(int i=top; i>=0; i--)
		cout<<pila[i]<<" "<<endl;
}
