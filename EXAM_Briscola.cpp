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

struct carte //questa va messa prima di tutte le funzioni così è visibile globalmente!
{char seme; //s, b, o, c
int valore;
int punteggio;
} mazzo[50];


carte briscola;
carte mani[2][3]; //primo indice righe, secondo colonne. La riga 0 sono le carte dell'uomo. La riga 1 sono le carte del PC.
carte tavolo[2]; //array a due celle che contiene le carte buttate in ogni turno
carte cimitero[40]; //array che conserva tutte le carte uscite

void generazione_carte ();
void punti_carte ();
void mischia_mazzo ();
void prima_mano ();
void stampa_mano_giocatore ();
void stampa_mano_computer ();
void tira_carta ();
void tira_carta_computer ();
void i_a ();
void i_a_attacco ();
void i_a_difesa ();
void presa ();
void prima_pescata ();
void generazione_cimitero (); //funzione che da ad ogni cella del vettore cimitero il valore 0, così da renderla riconoscibile nel momento in cui ci sia da aggiungere una nuova carta giocata
void stampa_cimitero ();
void conta_briscola ();
void conta_carico ();
void conta_briscole_cimitero ();
void conta_carte_vincitrici (); //conta quante carte abbiamo NOI COMPUTER in mano che possono vincere quella dell'avversario sullo stesso palo lol
void i_a_attacco_final ();

bool c_1_b = (mani[1][0].seme == briscola.seme), c_2_b = (mani[1][1].seme == briscola.seme), c_3_b = (mani[1][2].seme == briscola.seme);
bool c_1_c = (mani[1][0].punteggio >= 10), c_2_c = (mani[1][1].punteggio >= 10), c_3_c = (mani[1][2].punteggio >= 10);//condizioni affinchè le carte siano carichi, ovvero abbiano un punteggio compreso maggiore o uguale a 10
bool c_1_l = (mani[1][0].punteggio == 0), c_2_l = (mani[1][1].punteggio == 0), c_3_l = (mani[1][2].punteggio == 0); //condizioni singolari per la liscezza di una carta in mano di NOI COMPUTER
bool c_1_p = !(c_1_l || c_1_c), c_2_p = !(c_2_l || c_2_c), c_3_p = !(c_3_l || c_3_c); //condizione per pesezza della carta
bool c_1_ppc = ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) ), c_2_ppc = ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) ), c_3_ppc = ( (mani[1][2].punteggio <= mani[1][1].punteggio) && (mani[1][2].punteggio <= mani[1][0].punteggio) ); //condizione per le carte più piccole
bool c_t_c = (tavolo[1].punteggio >= 10), c_t_b = (tavolo[1].seme == briscola.seme), c_t_l = (tavolo[1].punteggio == 0), c_t_p = ((tavolo[1].punteggio > 0) && (tavolo[1].punteggio < 10));// consideriamo se la carta sul tavolo è .carico, .liscio, .briscola (1 in questo caso perchè consideriamo l'umano) 
bool c_s_p1 = (tavolo[1].seme == mani[1][0].seme), c_s_p2 = (tavolo[1].seme == mani[1][1].seme), c_s_p3 = (tavolo[1].seme == mani[1][2].seme); //condizione che almeno una delle carte che abbiamo NOI COMPUTER in mano sia dello stesso palo di quella tirata dal giocatore
bool c_m_p1 = (tavolo[1].punteggio < mani[1][0].punteggio), c_m_p2 = (tavolo[1].punteggio < mani[1][1].punteggio), c_m_p3 = (tavolo[1].punteggio < mani[1][2].punteggio); //condizione che almeno una delle carte che NOI COMPUTER abbiamo in mano sia di punteggio maggiore di quella tirata dal giocatore.
bool c_l_b = (c_t_l && c_t_b), c_p_b = (c_t_p && c_t_b), c_c_b = (c_t_c && c_t_b); //combinazioni delle booleane di cui sopra sulle caratteristiche della carta tirata nel caso di briscola
bool c_1_null = (mani[1][0].seme == mazzo[45].seme), c_2_null = (mani[1][1].seme == mazzo[45].seme), c_3_null = (mani[1][2].seme == mazzo[45].seme);

int chi_ha_vinto = 1; //variabile che assume valore 0 se prende il pc, 1 se prende il giocatore
int punteggio_giocatore = 0; //variabile autoaggiornante che conserva il punteggio del giocatore
int punteggio_computer = 0; //variabile autoaggiornante che conserva il punteggio del computer
int scorri_mazzo = 0; //variabile che segna l'avanzare del mazzo nelle pescate
int z=0;
int conta_mani;
int conta_briscole; //briscole in mano
int conta_carichi; //carichi in mano
int conta_briscole_uscite; //briscole cimiterate
int conta_vincenti; //contatore associato a void conta carte vincitrici

void main ()
{
	generazione_cimitero ();
	generazione_carte ();
	punti_carte ();
	mischia_mazzo ();
	prima_mano ();
	

	for (int i = 0; i<50; i++)
		cout<<mazzo[i].valore<<mazzo[i].seme<<" "<<mazzo[i].punteggio<<endl; //per stampare il mazzo

	cout<<"Ciao! Questo programma ti permette di giocare a briscola contro il computer."<<endl<<endl<<endl<<endl;
	cout<<"Il computer mischia il mazzo..."<<endl;
	cout<<"Il computer da le carte..."<<endl<<endl;
	cout<<"La briscola e': "<<briscola.valore<<briscola.seme<<endl<<endl;

	for (conta_mani=0; conta_mani<=19 ; conta_mani++)
	{

	switch (chi_ha_vinto)
	{
		case 1:
		{
			cout <<"E' il tuo turno!"<<endl;
	cout<<"Queste sono le tue carte:  "<<endl;

	stampa_mano_giocatore ();

	cout<<"Scrivi quale carta vuoi tirare"<<endl;

	tira_carta ();

	tira_carta_computer ();
		};break;

		case 0:
		{
    cout <<"E' il turno del computer!"<<endl;
	tira_carta_computer ();

	cout<<"Queste sono le tue carte:  "<<endl;

	stampa_mano_giocatore ();

	cout<<"Scrivi quale carta vuoi tirare"<<endl;

	tira_carta ();
		};break;
	}

	presa ();

	scorri_mazzo = scorri_mazzo+2;

	prima_pescata ();

	cout<<"Le Carte uscite sono:"<<endl;
	stampa_cimitero ();
	conta_briscole_cimitero ();
	cout<<"ci sono "<<conta_briscole_uscite<<" briscole nel cimitero"<<endl;
	cout<<endl;

	}

	cout<<"La partita e' finita!"<<endl;

	if (punteggio_giocatore > punteggio_computer)
	{
		cout<<"Hai vinto! "<<punteggio_giocatore<<" a "<<punteggio_computer<<endl;
	}
	if (punteggio_computer > punteggio_giocatore)
	{
		cout<<"Ha vinto il computer!"<<punteggio_computer<<" a "<<punteggio_giocatore<<endl;
	}
	if (punteggio_computer == punteggio_giocatore)
	{
		cout<<"Patta!"<<endl;
	}

	system ("pause");
}

void generazione_carte () //questa funzione assegna ad ogni cella dell'array mazzo il valore ed il seme della rispettiva carta. Per farlo lo dividiamo in quattro gruppi di 10 ed utilizziamo un semplice ciclo di for per farlo scorrere.
{
for (int i=0; i<10; i++)
	{
		mazzo[i].seme = 's';
		mazzo[i].valore = i+1;
	}

for (int i=10; i<20; i++)
	{
		mazzo[i].seme = 'b';
		mazzo[i].valore = i-9;
	}

for (int i=20; i<30; i++)
	{
		mazzo[i].seme = 'o';
		mazzo[i].valore = i-19;
	}

for (int i=30; i<40; i++)
	{
		mazzo[i].seme = 'c';
		mazzo[i].valore = i-29;
	}

for (int i=40; i<50; i++) //carte nulle per le ultime tre mani
	{
		mazzo[i].seme = 'N';
		mazzo[i].valore = 0;
		mazzo[i].punteggio = 0;
	}
}

void punti_carte ()
{
	for (int i=0; i<40; i++)
	{
		if (mazzo[i].valore == 1)
			mazzo[i].punteggio = 11;
		if (mazzo[i].valore == 3)
			mazzo[i].punteggio = 10;
		if (mazzo[i].valore == 10)
			mazzo[i].punteggio = 4;
		if (mazzo[i].valore == 9)
			mazzo[i].punteggio = 3;
		if (mazzo[i].valore == 8)
			mazzo[i].punteggio = 2;
		if (mazzo[i].valore != 1 && mazzo[i].valore != 3 && mazzo[i].valore != 10 && mazzo[i].valore != 9 && mazzo[i].valore != 8)
			mazzo[i].punteggio = 0;
	}
}

void mischia_mazzo () //questa funzione serve a mischiare le carte del mazzo, come spiegato nel prossimo commento
{
carte aus;
srand(time(0));

for (int j=0; j<100000; j++) 
for (int i=0; i<=39; i++)
{
aus = mazzo[i]; //salvo la carta della posizione, ne metto al suo posto una a caso e poi risostituisco la sua vecchia posizione con quella presa...
int indice = rand()%39;
mazzo[i]=mazzo[indice];
mazzo [indice]=aus;
}

briscola = mazzo[39]; //assegnazione della briscola
}

void prima_mano()
{

int c=0; //c è una variabile che identifica l'indice delle carte del mazzo. Inizia dalla carta di indice 0, per poi aumentare. N.B. La carta di indice 0 è la prima del mazzo.

for (int i=0; i<3; i++) //for delle COLONNE
{
	for (int j=0; j<2; j++) //for delle RIGHE
	{
		mani[j][i] = mazzo[c];
		c++; //una a noi una al pc, una a noi una al pc...
	}
}

}

void stampa_mano_giocatore ()
{
	for (int i=0; i<3; i++)
	{ 
		cout<<"Carta "<<i+1<<" "<<mani[0][i].valore<<mani[0][i].seme<<endl; //inserire i .seme e .valore
	}
}

void stampa_mano_computer () //a titolo informativo
{
	cout<<"Le carte del computer sono: "<<endl;
	for (int i=0; i<3; i++)
	{ 
		cout<<mani[1][i].valore<<mani[1][i].seme<<endl; //inserire i .seme e .valore
	}
	conta_carico ();
	conta_briscola ();
	cout<<"Il computer possiede "<<conta_carichi<<" carichi e "<<conta_briscole<<" briscole."<<endl;
}

void prima_pescata ()
{
	int i;
	int j;
   
	if (chi_ha_vinto == 1)
	{
		i=0;
		j=0;

		while (mani[0][i].valore != 0 || mani[0][i].seme == 'N')
			i++;

		mani[0][i] = mazzo[4 + scorri_mazzo];

		while (mani[1][j].valore != 0 || mani[1][j].seme == 'N')
			j++;

		mani[1][j] = mazzo[5 + scorri_mazzo];
	}
      
	if (chi_ha_vinto == 0)
	{
		i=0;
		j=0;

		while (mani[1][i].valore != 0 || mani[1][i].seme == 'N')
			i++;

		mani[1][i] = mazzo[4 + scorri_mazzo];

		while (mani[0][j].valore != 0 || mani[0][j].seme == 'N')
			j++;

		mani[0][j] = mazzo[5 + scorri_mazzo];
	}

}

void tira_carta ()
{
	int val=0;//valore 1 2 o 3 della carta, inserito dal giocatore per scegliere la carta da lanciare. Inizializzato a 0 per entrare nel ciclo.
	int z=0;
while (val<1 || val>3 || mani[0][val-1].valore == 0)
{
cout <<"Inserisci il numero della carta che vuoi tirare (1, 2, 3): "<<endl;
cin>>val;
}

cout <<"Hai scelto la "<<val<<"a carta, ovvero: "<<mani[0][val-1].valore<<mani[0][val-1].seme<<endl;

tavolo[1].valore = mani[0][val-1].valore;
tavolo[1].seme = mani[0][val-1].seme;
tavolo[1].punteggio = mani[0][val-1].punteggio;

while (cimitero[z].valore != 0 || cimitero[z].seme == 'N')
	z++;
cimitero[z] = mani[0][val-1];

mani[0][val-1].valore = 0; //inizializzata in questo modo per essere identificata e sostituita nel momento in cui, alla fine della mano, dovrò pescare dal mazzo una carta e prenderla in mano nella stessa posizione di quella appena tirata.



}

void tira_carta_computer ()
{

	cout<<"Il computer ha in mano: "<<endl;
	stampa_mano_computer ();
	cout<<"Il computer sta pensando..."<<endl;

	/*	cout<<"Il computer ha tirato la carta "<<mani[1][0].valore<<mani[1][0].seme<<endl;

tavolo[0].valore = mani[1][0].valore;
tavolo[0].seme = mani[1][0].seme;
tavolo[0].punteggio = mani[1][0].punteggio;

while (cimitero[z].valore != 0)
	z++;
cimitero[z] = mani[1][0]; //cambiare indice 0 del computer una volta inserita I.A.

mani[1][0].valore = 0; //azzera carta tirata, cioè sempre la prima i difesa
*/	
switch (chi_ha_vinto)
	{
	case 1:
		{
cout<<"Il computer ha tirato la carta "<<mani[1][0].valore<<mani[1][0].seme<<endl;

tavolo[0].valore = mani[1][0].valore;
tavolo[0].seme = mani[1][0].seme;
tavolo[0].punteggio = mani[1][0].punteggio;

while (cimitero[z].valore != 0 || cimitero[z].seme == 'N')
	z++;
cimitero[z] = mani[1][0]; //cambiare indice 0 del computer una volta inserita I.A.

mani[1][0].valore = 0; //azzera carta tirata, cioè sempre la prima i difesa 

		};break;

	case 0:
		{
			if (conta_mani <= 16)
			{
				i_a_attacco ();

		cout<<"Il computer ha tirato la carta "<<tavolo[0].valore<<tavolo[0].seme<<endl;

	for (int i=0; i<=2; i++)
		{
			if (mani[1][i].punteggio == tavolo [0].punteggio && mani[1][i].valore == tavolo [0].valore && mani[1][i].seme == tavolo [0].seme)
			{
				while (cimitero[z].valore != 0 || cimitero[z].seme == 'N')
					z++;

				cimitero[z] = mani[1][i]; //cimiteriamo la carta tirata

				mani[1][i].valore = 0; //cerca nella mano la carta tirata confrontando col tavolo, e la azzera per il pescaggio.
			}
	    }
			}

			else
			{

				i_a_attacco_final ();

		cout<<"Il computer ha tirato la carta "<<tavolo[0].valore<<tavolo[0].seme<<endl;

	for (int i=0; i<=2; i++)
		{
			if (mani[1][i].punteggio == tavolo [0].punteggio && mani[1][i].valore == tavolo [0].valore && mani[1][i].seme == tavolo [0].seme)
			{
				while (cimitero[z].valore != 0 || cimitero[z].seme == 'N')
					z++;

				cimitero[z] = mani[1][i]; //cimiteriamo la carta tirata

				mani[1][i].valore = 0; //cerca nella mano la carta tirata confrontando col tavolo, e la azzera per il pescaggio.

			}
		}
			}

		};break;
	}
	/*
	if (chi_ha_vinto == 1) //difesa
{

cout<<"Il computer ha tirato la carta "<<mani[1][0].valore<<mani[1][0].seme<<endl;

tavolo[0].valore = mani[1][0].valore;
tavolo[0].seme = mani[1][0].seme;
tavolo[0].punteggio = mani[1][0].punteggio;

while (cimitero[z].valore != 0)
	z++;
cimitero[z] = mani[1][0]; //cambiare indice 0 del computer una volta inserita I.A.

mani[1][0].valore = 0; //azzera carta tirata, cioè sempre la prima i difesa 



	i_a_difesa ();

	cout<<"Il computer ha tirato la carta "<<tavolo[0].valore<<tavolo[0].seme<<endl;

	for (int i=0; i<=2; i++)
		{
			if (mani[1][i].punteggio == tavolo [0].punteggio && mani[1][i].valore == tavolo [0].valore && mani[1][i].seme == tavolo [0].seme)
			{
				while (cimitero[z].valore != 0)
					z++;

				cimitero[z] = mani[1][i]; //cimiteriamo la carta tirata

				mani[1][i].valore = 0; //cerca nella mano la carta tirata confrontando col tavolo, e la azzera per il pescaggio.
			}
	    }
	}
	
if (chi_ha_vinto == 0 && (cimitero[2*(conta_mani+3)].seme == 'f')) //attacca
{
	    i_a_attacco ();

		cout<<"Il computer ha tirato la carta "<<tavolo[0].valore<<tavolo[0].seme<<endl;

	for (int i=0; i<=2; i++)
		{
			if (mani[1][i].punteggio == tavolo [0].punteggio && mani[1][i].valore == tavolo [0].valore && mani[1][i].seme == tavolo [0].seme)
			{
				while (cimitero[z].valore != 0)
					z++;

				cimitero[z] = mani[1][i]; //cimiteriamo la carta tirata

				mani[1][i].valore = 0; //cerca nella mano la carta tirata confrontando col tavolo, e la azzera per il pescaggio.
			}
	    }
}
*/

}

void i_a_attacco ()
{
	conta_briscola ();
	conta_carico ();
	conta_briscole_cimitero ();

switch (conta_briscole)
{
case 0:
	case 3:	
		{

		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
		
		};break;
	
case 1:
		{

			if (c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}
		
		}break;

case 2:
	{
		if (conta_carichi == 0)
	{
			if (c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}
	}
		if (conta_carichi == 1)
		{
			{
			if (!c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (!c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (!c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}
			}

	}
	};break;

	}

/*switch (conta_carichi)
{ 
	case 0:
		{
		if (conta_briscole == 1)
		{

			if (c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}

		}

		if(conta_briscole == 2)
		{

		if ( !(c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( !(c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( !(c_3_b) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}

		}

			if((conta_briscole == 3) || (conta_briscole == 0))
			{
		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
			}
		};break;
	
	case 1:
		{
			if (conta_briscole == 1)
			{

			if (c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}

			}

			if (conta_briscole == 2)
			{
				if (conta_briscole_uscite >= 7)
				{
		if ( !(c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( !(c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( !(c_3_b) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
				}
				else
				{
		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) && (c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) && (c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) && (c_3_b))
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
				}
			}
		};break;

	case 2:
		{

			if (conta_briscole == 0)
			{
		if ( !(c_1_c) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( !(c_2_c) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( !(c_3_c) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
			}
			
			if (conta_briscole == 1)
			{
				if (conta_briscole_uscite >= 7)
				{
		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) && !(c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) && !(c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) && !(c_3_b))
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
				}

				else
				{
		if ( (c_1_c) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (c_2_c) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (c_3_c) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
				}
			}

		};break;
	
	case 3:
	{
		if (punteggio_giocatore > punteggio_computer) //se siamo in difetto NOI COMPUTER
		{
			if  ( c_1_b || c_2_b || c_3_b ) //se abbiamo almeno una briscola
			{
		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) && (c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) && (c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) && (c_3_b))
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}

			}

			if (!c_1_b && !c_2_b && !c_3_b) //se non abbiamo nessuna briscola
			{
		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) )
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}
			}
		}

		if (punteggio_giocatore <= punteggio_computer) //Se non siamo in difetto NOI COMPUTER
		{

		if ( (mani[1][0].punteggio <= mani[1][1].punteggio) && (mani[1][0].punteggio <= mani[1][2].punteggio) && !(c_1_b) )
		{
			tavolo[0].valore = mani[1][0].valore;
			tavolo[0].seme = mani[1][0].seme;
			tavolo[0].punteggio = mani[1][0].punteggio;
		}

		if ( (mani[1][1].punteggio <= mani[1][0].punteggio) && (mani[1][1].punteggio <= mani[1][2].punteggio) && !(c_2_b) )
		{
			tavolo[0].valore = mani[1][1].valore;
			tavolo[0].seme = mani[1][1].seme;
			tavolo[0].punteggio = mani[1][1].punteggio;
		}

		if ( (mani[1][2].punteggio <= mani[1][0].punteggio) && (mani[1][2].punteggio <= mani[1][1].punteggio) && !(c_3_b))
		{
			tavolo[0].valore = mani[1][2].valore;
			tavolo[0].seme = mani[1][2].seme;
			tavolo[0].punteggio = mani[1][2].punteggio;
		}

		}
	};break;


} //chiude switch
*/
}

void i_a_attacco_final ()
{
	conta_briscola ();
	conta_carico ();
	conta_briscole_cimitero ();

	cout<<"Siamo alla terzultima mano e io sono molto intelligente anche perchè sono uscite "<<conta_briscole_uscite<< "briscole"<<endl;

switch(conta_mani)
{

case 17:
	{
switch(conta_carichi)
{

case 0:

	{
		if (c_1_ppc)
			tavolo[0] = mani [1][0];
		if (c_2_ppc)
			tavolo[0] = mani [1][1];
		if (c_3_ppc)
			tavolo[0] = mani [1][2];
	};break;

case 1:

	{
		if (conta_briscole_uscite == 10)
		{
		if (c_1_c)
			tavolo[0] = mani [1][0];
		if (c_2_c)
			tavolo[0] = mani [1][1];
		if (c_3_c)
			tavolo[0] = mani [1][2];
		}
		else
		{
		if (c_1_ppc)
			tavolo[0] = mani [1][0];
		if (c_2_ppc)
			tavolo[0] = mani [1][1];
		if (c_3_ppc)
			tavolo[0] = mani [1][2];

		if (c_1_p)
			tavolo[0] = mani [1][0];
		if (c_2_p)
			tavolo[0] = mani [1][1];
		if (c_3_p)
			tavolo[0] = mani [1][2];
		}
	};break;

case 2:

	{
			if (conta_briscole == 0 || conta_briscole == 3)
			{
		if (c_1_ppc)
			tavolo[0] = mani [1][0];
		if (c_2_ppc)
			tavolo[0] = mani [1][1];
		if (c_3_ppc)
			tavolo[0] = mani [1][2];
			}

		if (conta_briscole == 1)
		{
			if (conta_briscole_uscite == 10)
			{

				if (!c_1_c)
				{

					if (mani[1][1].punteggio >= mani[1][2].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][2];
				}

				if (!c_2_c)
				{

					if (mani[1][0].punteggio >= mani[1][2].punteggio)
						tavolo[0] = mani[1][0];
					else
						tavolo[0] = mani[1][2];
				}

				if (!c_3_c)
				{

					if (mani[1][1].punteggio >= mani[1][0].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][0];

			}
		else
		{
			if (c_1_b)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_b)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_b)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}
		}

		} //1 briscola

		if (conta_briscole == 2)
		{
			if (!c_1_b)
				tavolo[0] = mani[1][0];
			if (!c_2_b)
				tavolo[0] = mani[1][1];
			if (!c_3_b)
				tavolo[0] = mani[1][2];
		}//2 briscole

	};break;

case 3:

	{
		if (c_1_ppc)
			tavolo[0] = mani [1][0];
		if (c_2_ppc)
			tavolo[0] = mani [1][1];
		if (c_3_ppc)
			tavolo[0] = mani [1][2];

		if (c_1_b)
			tavolo[0] = mani [1][0];
		if (c_2_b)
			tavolo[0] = mani [1][1];
		if (c_3_b)
			tavolo[0] = mani [1][2];
	};break;

}
	};break;

case 18:
	{

		if (conta_briscole_uscite == 10)
		{

			if (c_1_null)
			{
				if (mani[1][1].punteggio >= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_null)
			{
				if (mani[1][0].punteggio >= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_null)
			{
				if (mani[1][0].punteggio >= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}

		}
		else
		{

			if (c_1_null)
			{
				if (mani[1][1].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][1];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_2_null)
			{
				if (mani[1][0].punteggio <= mani[1][2].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][2];
			}

			if (c_3_null)
			{
				if (mani[1][0].punteggio <= mani[1][1].punteggio)
					tavolo[0] = mani[1][0];
				else
					tavolo[0] = mani[1][1];
			}

		}

	/*switch (conta_carichi)
	{

	case 0:
		{

			if (conta_briscole == 0 || conta_briscole == 2)
			{

				if (c_1_null)
				{

					if (mani[1][1].punteggio <= mani[1][2].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_2_null)
				{

					if (mani[1][0].punteggio <= mani[1][2].punteggio)
						tavolo[0] = mani[1][0];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_3_null)
				{

					if (mani[1][1].punteggio <= mani[1][0].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][0];
				}

			}

			if (conta_briscole == 1)
			{

				if(!c_1_b && !c_1_null)
					tavolo[0] = mani[1][0];
				
				if(!c_2_b && !c_2_null)
					tavolo[0] = mani[1][1];
				
				if(!c_3_b && !c_3_null)
					tavolo[0] = mani[1][2];
			}

		};break;

	case 1:
		{

			if (conta_briscole_uscite == 10)
			{
				if(c_1_c && !c_1_null)
					tavolo[0] = mani[1][0];
				
				if(c_2_c && !c_2_null)
					tavolo[0] = mani[1][1];
				
				if(c_3_c && !c_3_null)
					tavolo[0] = mani[1][2];
			}
			else
			{
				if(!c_1_c && !c_1_null)
					tavolo[0] = mani[1][0];
				
				if(!c_2_c && !c_2_null)
					tavolo[0] = mani[1][1];
				
				if(!c_3_c && !c_3_null)
					tavolo[0] = mani[1][2];
			}

		};break;

	case 2:
		{

			if (conta_briscole_uscite == 10)
			{
				if (c_1_null)
				{

					if (mani[1][1].punteggio >= mani[1][2].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_2_null)
				{

					if (mani[1][0].punteggio >= mani[1][2].punteggio)
						tavolo[0] = mani[1][0];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_3_null)
				{

					if (mani[1][1].punteggio >= mani[1][0].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][0];
				}
			}
			else
			{
				if (c_1_null)
				{

					if (mani[1][1].punteggio <= mani[1][2].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_2_null)
				{

					if (mani[1][0].punteggio <= mani[1][2].punteggio)
						tavolo[0] = mani[1][0];
					else
						tavolo[0] = mani[1][2];
				}

				if (c_3_null)
				{

					if (mani[1][1].punteggio <= mani[1][0].punteggio)
						tavolo[0] = mani[1][1];
					else
						tavolo[0] = mani[1][0];
				}

			}

		};break;

	}*/

	};break;

case 19:
	{
		if (!c_1_null)
		{
	tavolo [0] = mani[1][0];
		}

		if (!c_2_null)
		{
	tavolo [0] = mani[1][1];
		}

		if (!c_3_null)
		{
	tavolo [0] = mani[1][2];
		}
	};break;


}

}

}

void conta_carte_vincitrici ()
{
	for (int i=0; i<=2; i++)
	{
		if (c_s_p1 && c_m_p1)
			conta_vincenti ++;

		if (c_s_p2 && c_m_p2)
			conta_vincenti ++;

		if (c_s_p3 && c_m_p3)
			conta_vincenti ++;

	}
}

void conta_briscola ()
{
	conta_briscole = 0;

	for (int i = 0; i<=2; i++)
	{
		if (mani[1][i].seme == briscola.seme)
			conta_briscole = conta_briscole +1;
	}

}

void conta_briscole_cimitero ()
{
	conta_briscole_uscite =0;

	for (int i = 0; i<=39; i++)
	{
		if (cimitero[i].seme == briscola.seme)
			conta_briscole_uscite = conta_briscole_uscite +1;
	}
}

void conta_carico ()
{
		conta_carichi = 0;

	for (int i = 0; i<=2; i++)
	{
		if (mani[1][i].punteggio >= 10)
			conta_carichi = conta_carichi +1;
	}
}

void presa ()
{
   char s1, s2, br; //dichiarazione dei semi delle carte e della briscola
   int v1, v2, p1, p2, tot;  //dichiarazione dei valori delle carte e dei punteggi

   br = briscola.seme;

   bool su, m1, b2; //dichiarazione delle var. booleane.

	s1 = tavolo[1].seme;
   s2 = tavolo[0].seme;
   p1 = tavolo[1].punteggio; //e richiamo su questi la funzione punteggio
   p2 = tavolo[0].punteggio;
   tot = p1 + p2;

   switch (chi_ha_vinto)
   {
   case 1:
	   {
   v1 = tavolo[1].valore;
   v2 = tavolo[0].valore;
   s1 = tavolo[1].seme;
   s2 = tavolo[0].seme;
   p1 = tavolo[1].punteggio; //e richiamo su questi la funzione punteggio
   p2 = tavolo[0].punteggio;
   tot = p1 + p2;

   br = briscola.seme;

   bool su, m1, b2; //dichiarazione delle var. booleane.

   su = (s1 == s2); //su è la variabile che indica che le due carte hanno lo stesso seme
   m1 = (p1 > p2 || (p1 == p2 && v1 > v2)); //m1 è la variabile che indica che la carta 1 ha valore maggiore della carta 2
   b2 = (s2 == br); //s2 è la variabile che indica che la carta 2 ha lo stesso seme della briscola

   if ((su && m1) || (!su && !b2)) // condizioni di vittoria del giocatore 
   {   cout <<tavolo[1].valore<<tavolo[1].seme<< " prende su " <<tavolo[0].valore<<tavolo[0].seme<<endl;
       cout <<"Prendi tu!"<<endl;
       cout << "Hai guadagnato "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=1;

	   punteggio_giocatore = punteggio_giocatore + tot;
   }
   else //condizioni di vittoria del computer
   {   cout <<tavolo[0].valore<<tavolo[0].seme<< " prende su " <<tavolo[1].valore<<tavolo[1].seme<<endl;
       cout <<"Prende il PC!"<<endl;
       cout << "E guadagna "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=0;

	   punteggio_computer = punteggio_computer + tot;
   }
	   };break;

   case 0:
	   {
   v1 = tavolo[0].valore;
   v2 = tavolo[1].valore;
   s1 = tavolo[0].seme;
   s2 = tavolo[1].seme;
   p1 = tavolo[0].punteggio; //e richiamo su questi la funzione punteggio
   p2 = tavolo[1].punteggio;
   tot = p1 + p2;

   br = briscola.seme;

   bool su, m1, b2; //dichiarazione delle var. booleane.

   su = (s1 == s2); //su è la variabile che indica che le due carte hanno lo stesso seme
   m1 = (p1 > p2 || (p1 == p2 && v1 > v2)); //m1 è la variabile che indica che la carta 1 ha valore maggiore della carta 2
   b2 = (s2 == br); //s2 è la variabile che indica che la carta 2 ha lo stesso seme della briscola

   if ((su && m1) || (!su && !b2)) // condizioni di vittoria del PC
   {   cout <<tavolo[0].valore<<tavolo[0].seme<< " prende su " <<tavolo[1].valore<<tavolo[1].seme<<endl;
       cout <<"Prende il PC!"<<endl;
       cout << "E guadagna "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=0;

	   punteggio_computer = punteggio_computer + tot;
   }

   else //condizioni di vittoria del giocatore
   {   cout <<tavolo[1].valore<<tavolo[1].seme<< " prende su " <<tavolo[0].valore<<tavolo[0].seme<<endl;
       cout <<"Prendi tu!"<<endl;
       cout << "Hai guadagnato "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=1;

	   punteggio_giocatore = punteggio_giocatore + tot;
   }

	   };break;
   }

   /*
   if (chi_ha_vinto == 1)
   {
   s1 = tavolo[1].seme;
   s2 = tavolo[0].seme;
   p1 = tavolo[1].punteggio; //e richiamo su questi la funzione punteggio
   p2 = tavolo[0].punteggio;
   tot = p1 + p2;

   br = briscola.seme;

   bool su, m1, b2; //dichiarazione delle var. booleane.

   su = (s1 == s2); //su è la variabile che indica che le due carte hanno lo stesso seme
   m1 = (p1 > p2); //m1 è la variabile che indica che la carta 1 ha valore maggiore della carta 2
   b2 = (s2 == br); //s2 è la variabile che indica che la carta 2 ha lo stesso seme della briscola

   if ((su && m1) || (!su && !b2)) // condizioni di vittoria del giocatore 
   {   cout <<tavolo[1].valore<<tavolo[1].seme<< " prende su " <<tavolo[0].valore<<tavolo[0].seme<<endl;
       cout <<"Prendi tu!"<<endl;
       cout << "Hai guadagnato "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=1;

	   punteggio_giocatore = punteggio_giocatore + tot;
   }
   else //condizioni di vittoria del computer
   {   cout <<tavolo[0].valore<<tavolo[0].seme<< " prende su " <<tavolo[1].valore<<tavolo[1].seme<<endl;
       cout <<"Prende il PC!"<<endl;
       cout << "E guadagna "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=0;

	   punteggio_computer = punteggio_computer + tot;
   }

   }
 if ((chi_ha_vinto == 0) && (cimitero[2*(conta_mani+1)].punteggio == 0))
   {
   
   s1 = tavolo[0].seme;
   s2 = tavolo[1].seme;
   p1 = tavolo[0].punteggio; //e richiamo su questi la funzione punteggio
   p2 = tavolo[1].punteggio;
   tot = p1 + p2;

   br = briscola.seme;

   bool su, m1, b2; //dichiarazione delle var. booleane.

   su = (s1 == s2); //su è la variabile che indica che le due carte hanno lo stesso seme
   m1 = (p1 > p2); //m1 è la variabile che indica che la carta 1 ha valore maggiore della carta 2
   b2 = (s2 == br); //s2 è la variabile che indica che la carta 2 ha lo stesso seme della briscola

   if ((su && m1) || (!su && !b2)) // condizioni di vittoria del PC
   {   cout <<tavolo[0].valore<<tavolo[0].seme<< " prende su " <<tavolo[1].valore<<tavolo[1].seme<<endl;
       cout <<"Prende il PC!"<<endl;
       cout << "E guadagna "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=0;

	   punteggio_computer = punteggio_computer + tot;
   }

   else //condizioni di vittoria del giocatore
   {   cout <<tavolo[1].valore<<tavolo[1].seme<< " prende su " <<tavolo[0].valore<<tavolo[0].seme<<endl;
       cout <<"Prendi tu!"<<endl;
       cout << "Hai guadagnato "<<tot<<" punti."<<endl;
	   
	   chi_ha_vinto=1;

	   punteggio_giocatore = punteggio_giocatore + tot;
   }

   }*/
}

void generazione_cimitero ()
{
		for (int i=0; i<40; i++)
		{
			cimitero[i].valore = 0;
			cimitero[i].punteggio = 0;
			cimitero[i].seme = 'f';
		}
}

void stampa_cimitero ()
{
	for (int i=0; i<40; i++)
		cout<<cimitero[i].valore<<cimitero[i].seme<<" ";
}
