
// C++ come funziona strtok_r() 
// eliminandone solo lo spazio
#include <stdio.h> 
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
  
int main() 
{ 
    char frase[] = "Geeks for Geeks"; //frase da usare
    char *token; //creo il token
    char *punt = frase; //puntatore alla frase
  
    while ((token = strtok_r(punt, " ", &punt))) //quando token==punt e &punt
        cout<<"/n"<<token; //stampa token
  
    return(0); 
}
