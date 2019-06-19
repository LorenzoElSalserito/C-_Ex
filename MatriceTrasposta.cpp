  
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

int numero;
//programma che calcola la matrice trasposta

void MatriceTrasposta(int **M, int **M1, int righe, int colonne){
for(int i=0; i<righe; i++)
		for(int j=i; j<colonne; j++){
			M1[i][j] = M[j][i];
			M1[j][i] = M[i][j];
		}
	}

void StampaMatrice(int **M, int righe, int colonne){
	for(int i=0; i<righe; i++)
	{	for(int j=0; j<colonne; j++){
			cout << M[i][j]<<endl;
		}
	}
}

void RiempiMatrice(int **M, int**M1, int righe, int colonne){
	for(int k=0; k<righe ; k++){
		M[k] = new int[righe];
		M1[k] = new int[colonne];
	}	
for(int i=0; i<righe; i++){
	for(int j=0; j<colonne; j++){
		cout<<"M["<<i<<"]["<<j<<"] =" << endl;
			cin>>numero;
			M[i][j]=numero;
		}
	}
}

void RipristinaMemoria(int **M, int dim){
	for(int i =0;i < dim ; i++)
		delete [] M[i];
	delete [] M;
	}

int main(){

int dim=0;

cout<<"Dammi le dimensioni della matrice: "<<endl;
cin>>dim;

int **M;
int **M1;
M = new int*[dim];
M1 = new int*[dim];

RiempiMatrice(M,M1,dim,dim);
MatriceTrasposta(M,M1,dim,dim);
StampaMatrice(M,dim,dim);
StampaMatrice(M1,dim,dim);
RipristinaMemoria(M, dim);
RipristinaMemoria(M1, dim);
return 0;
}
