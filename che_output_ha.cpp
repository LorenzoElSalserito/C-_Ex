#include <iostream>

using namespace std;

int main()
{   int*a;
	int*b;
	int*c;
	int d = 3;
	int e = 4;
	a = &d;
	b = a;
	c = b;
	(*c)++;
	c = &e;e+=10;
	cout << *a <<" "<< *b <<" "<< *c << endl;
	return 0;
	}


//l'output sarà 4 4 14
/* perché a=3, b=3, c=3, *c aumenta di 1, quindi a=4, b=4, c=4,
 * poi c=e=4, ad e si somma 10 per cui avremo output 4 4 14
 * */
