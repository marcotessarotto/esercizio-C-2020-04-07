/*
 * esercizio-C-2020-04-07.c
 *
 *  Created on: Apr 2, 2020
 *      Author: marco
 */

/************TESTO ESERCIZIO***************
***randomizzare le parole***

è data una stringa di caratteri contenente parole separate dal carattere spazio

randomizzare le parole per produrre una nuova stringa di caratteri
vanno riutilizzate tutte le singole parole (una sola volta ciascuna)

[generatore di numeri casuali:
aggiungerò a breve un esempio in exOpSys che utilizza la funzione rand()
http://man7.org/linux/man-pages/man3/rand.3.html ]

esempio:

è data la stringa di caratteri:
"hello world mi chiamo pino sono date delle stringhe"


output:
"mi stringhe chiamo pino sono date world delle hello"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randomNumber(int lower, int upper);	//funzione per la generazione casuale di un intero in [lower, upper]
int get_n_token(char * c);	//funzione che restituisce il numero di token nella stringa "c"
char * get_token(char * c, int n);	//funzione che restituisce l'n-esimo token nella string "c"

int main(int argc, char *argv[]) {
	char str[] = "hello world mi chiamo pino sono date delle stringhe";
	char *res = malloc(sizeof(str));
	if(res == NULL){
		printf("malloc ha fallito!\n");
		exit(1);
	}
	res[0] = '\0';	//inizializzo la stringa a vuota
	int n_token;

	/* "visited" : array con dimensione "n_token", il cui valore i-esimo
	 * dice se l'i-esimo token è stato aggiunto (visited[i] == 1)
	 * oppure no (visited[i] == 0) alla stringa risultato "res"
	 */
	int * visited;
	n_token = get_n_token(str);	//ottengo il numero totale di token nella stringa "str"
	visited = calloc(n_token, sizeof(int));
	if(visited == NULL){
		printf("calloc ha fallito!\n");
		exit(1);
	}

	int n_token_added = 0;	//contatore dei token aggiunti correntemente

	srand (time(0));
	while(n_token_added < n_token){
		int n = randomNumber(1, n_token);	//genero un numero di token casuale

		if(visited[n] == 0){	//controllo se il token non è ancora stato aggiunto
			strcat(res, get_token(str,n));	//concateno il token alla stringa risultato
			visited[n] = 1;	//"l'i-esimo token è stato aggiunto"
			n_token_added++;

			if(n_token_added != n_token)	//controllo se il token aggiunto non è l'ultimo
				strcat(res, " ");	//aggiungo in coda a "res" anche uno spazio
		}
	}

	printf("\n%s", res);

	free(visited);
	free(res);

	return 0;
}

int randomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

int get_n_token(char * c){
	int n_token = 0;
	char * temp = strdup(c);
	char s[] = " "; // caratteri separatori da utilizzare per la suddivisione
	char *token;


	// ottieni il primo token
	token = strtok(temp, s);

	// "cammina" attraverso gli altri token
	while( token != NULL ) {
		n_token++;
		token = strtok(NULL, s); // le chiamate successive a strtok
	}

	free(temp);

	return n_token;
}

char * get_token(char * c, int n){
	char s[] = " "; // caratteri separatori da utilizzare per la suddivisione
	char *token;
	char *temp;
	temp = strdup(c);	//duplico il vettore "c" così da non intaccarlo con la tokenizzazione

	token = strtok(temp, s);	//ottengo il prino token
	n--;

	//scorro fino al token n-esimo
	while(n > 0){
		token = strtok(NULL, s);
		n--;
	}

	return token;
}
