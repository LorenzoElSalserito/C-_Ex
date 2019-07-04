
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

void GeneraMatrice(int **M, int righe, int colonne){
    for(int k=0; k<righe; k++){
		M[k] = new int[righe];
		M[k] = new int[colonne];
		}
	for (int i=0;i<righe;i++){
		for(int j=0;j<colonne;j++){
		M[i][j]=0;
		}
	  }
	}

void StampaMatrice(int **M, int righe, int colonne, char c){

    for (int i=0; i<righe*righe; i++){
	for(int j=1; j<colonne*colonne; j++){
		cout<<c<<" ";
		}
		cout<<endl;	
    }
}

int main (){
    int x=0;
	char c='r';
	int **M;
	cout<<"Dammi la dimensione della matrice"<<endl;
	cin>>x;
	M = new int*[x];
GeneraMatrice(M, x, x);
StampaMatrice(M, x, x, c);
return 0;
}

