/*Scrivere una funzione che visualizzi un quadrato pieno di un carattere */
/* il cui lato sia stato specificato nel parametro intero side. */

/* AGGIUNTA: Casualmente in ogni riga viene generato un carattere casuale da trovare */
/* AGGIUNTA: Griglia di posizione caselle per facilitare lettura */

/* Inclusione librerie */
#include <stdio.h>
#include <stdlib.h> /* necessario per la funzione rad */
#include <time.h> /* necessario per il seed della generazione casuale*/

/* Caratteri che formano il quadrato */
#define NORM 'l' /* carattere normale */
#define DIV '1' /* carattere diverso */

/* funzioni*/
void stampa_quadrato(int righe,     
		     int colonne,
		     int side,
		     int car_div_riga, 
		     int car_div_colonna);
int richiedi_lato(void);
int risposta(int car_div_riga,
	     int car_div_colonna);

int main(void)
{
	int side,/* input: lato del quadrato */
	    car_div_riga, /* lavoro: numero casuale riga */
	    car_div_colonna;/* lavoro: numero casuale colonna */

	side = richiedi_lato(); /* richiedi input */

	system("clear"); /* Ripulisce lo schermo */

        /* Scopo del gioco */
	printf("\nTrova l'%c !\n\n\n\n\n", 
	       DIV); 	

	/* generazione numero casuale per posizione carattere diverso*/
	srand(time(0));	
	car_div_riga = rand() % ((side-1) + 1 - 1) + 1; /* generazione riga casuale*/
	car_div_colonna = rand() % ((side-1) + 1 - 1) + 1 ; /* generazione colonna casuale*/
	

	/*printf("\n%d-%d\n",
               car_div_riga,
	       car_div_colonna);*/


	/*  Generazione quadrato */
	stampa_quadrato(side,
		        side,
		 	side,
		        car_div_riga,
			car_div_colonna);
		
	printf("\n\n\n"); /* spazia dal basso */

	risposta(car_div_riga, 
		 car_div_colonna);
	return(0);
} 

/* funzione che richiede la grandezza del quadrato*/
int richiedi_lato(void)
{
	int side, /* input: lato del quadrato*/
	    esito_lettura; /* lavoro: variabile di controllo lettura*/
	do
	{
		printf("Inserire il numero >0: ");
		esito_lettura = scanf("%d",
			      	          &side);

		if (esito_lettura != 1 || side <= 0)
			printf("Valore non accettabile\n");
		while (getchar() != '\n');
	}
	while (esito_lettura != 1 || side <= 0);
	
	return(side);
};
/* funzione che stampa il quadrato*/
void stampa_quadrato(int righe, /* lavoro: numero di righe quadrato*/
		             int colonne, /* lavoro: numero di colonne quadrato*/
	   	             int side, /* input: lato del quadrato*/
		             int car_div_riga, /* lavoro: riga carattere diverso*/
		             int car_div_colonna) /* lavoro: colonna carattere diverso*/
{
	char quadrato[righe][colonne]; /* quadrato rappresentato da array multidimensionale con righe e colonne*/
    int  num; /* lavoro: variabile per grafica numerazione tabella colonne*/

	printf("         ");
	for(num=1; num<side+1 ; num++) /* tabella numerazione colonne*/
	      printf("%2.d ",
	             num);	
	printf("\n\n\n\n");

	/* ciclo for per la formazione delle righe*/
	for (righe=0; righe<side; righe++)
	{	
			/* ciclo for per la formazione delle colonne*/
    		for(colonne=0; colonne<side; colonne++)
    		{	
			if (colonne == 0)  /* tabella numerazione righe*/
	      			printf("%d\t",
		                       righe+1);
			if (righe == (car_div_riga-1) && colonne == (car_div_colonna-1)) /* controlla se la posizione deve contere carattere diverso*/
				quadrato[righe][colonne]=DIV; /* inserisce carattere diverso */
			else
				quadrato[righe][colonne]=NORM; /* inserisce carattere normale */
         		printf("%3s", /* stampa a video */
			       quadrato[righe][colonne]);
    		}
    		printf("\n\n");
	}		
};

/* funzione che richiede la risposta e stampa l'esito*/
int risposta(int car_div_riga,
	     int car_div_colonna)
{
	int riga_risposta, /* input: riga risposta*/
	    colonna_risposta, /* input: colonna risposta*/
	    risposta, /* lavoro: conteggio risposta*/
            esito_lettura; /* lavoro: esito scanf*/
    
    /* validazione stretta input */
	do
	{
		printf("Inserire risposta in formato riga-colonna: \n");
		esito_lettura = scanf("%d-%d",
	                 	      &riga_risposta,
				      &colonna_risposta);

		if (esito_lettura != 2 || riga_risposta <= 0 || colonna_risposta <=0 )
			printf("Valore non accettabile\n");
		while (getchar() != '\n');
	}
	while (esito_lettura != 2||riga_risposta <= 0 || colonna_risposta <=0);

	/* controlla correttezza risposta*/
	if (riga_risposta != (car_div_riga) || colonna_risposta != (car_div_colonna) )
	{
		printf("Riposta errata, la risposta esatta era %d-%d\n", /* errata*/
	       	       car_div_riga,
		       car_div_colonna);
		risposta = 0;
	}
	else
	{
		printf("Risposta esatta!\n"); /* esatta*/
		risposta = 1;
	};

	return(risposta);
}


