
// C++ program per trovare parole separate da spazi 
// usando strtok() 
#include <stdio.h> 
#include <iostream>
#include <string.h> 
using namespace std;
  
int main() 
{ 
    char str[] = "Amici per la pelle"; 
  
    //Ritorno il primo token
    char *token = strtok(str, " "); 
  
    // continuo a stampare token fin quando
    // i delimitatori della parola è presente in str[].
    while (token != NULL) 
    { 
        cout<<token<<endl; 
        token = strtok(NULL, " "); 
    } 
  
    return 0; 
} 
