
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

//Prova passaggio per riferimento;

int moltiplica(int &x, int &y);

int main()
{
  int a = 5;
  int b = 6;
  int risultato;
  risultato = moltiplica(a, b);
  cout << Il risultato della moltiplicazione è: << risultato <<endl;
  return (0);
}
// Dichiarazione della funzione
int moltiplica(int &x, int &y)
{
  int ris;
  // moltiplica ciò che trova presso gli indirizzi di memoria di x e y
  // ma non c'è bisogno di esplicitarlo
  ris = x * y;
  // Valore restituito dalla funzione
  return ris;
}
