#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

***randomizzare le parole***

è data una stringa di caratteri contenente parole separate dal carattere spazio

randomizzare le parole per produrre una nuova stringa di caratteri
vanno riutilizzate tutte le singole parole (una sola volta ciascuna)

[generatore di numeri casuali:
vedere esempio:
https://github.com/marcotessarotto/exOpSys/tree/master/006.4random-number
si può utilizzare la funzione rand()
http://man7.org/linux/man-pages/man3/rand.3.html ]

esempio:

è data la stringa di caratteri:
"hello world mi chiamo pino sono date delle stringhe"


output:
"mi stringhe chiamo pino sono date world delle hello"

 */

#define DEBUG_MSG 0

int main() {
	char str[] = "hello world mi chiamo pino sono date delle stringhe";

	// esempio 006.4
	//char str[] = "hello world mi chiamo pino sono date delle stringhe";
	//char str[] = "prima seconda   terza quarta";
	char s[] = " "; // caratteri separatori da utilizzare per la suddivisione
	char *token;

	int word_len = 1;
	int pos = 0;
	char ** words = calloc(word_len, sizeof(char *));
	if (words == NULL) {
		perror("calloc");
		exit(1);
	}

	// ottieni il primo token
	token = strtok(str, s);

	// "cammina" attraverso gli altri token
	while (token != NULL ) {
#if DEBUG_MSG
		printf( "%s\n", token );
#endif

		words[pos] = token;
		pos++;

		if (pos == word_len) {
			word_len = word_len * 2;
			words = realloc(words, word_len * sizeof(char *));

#if DEBUG_MSG
			printf("***realloc %d\n", word_len);
#endif

			if (words == NULL) {
				perror("realloc");
				exit(1);
			}
		}

		token = strtok(NULL, s); // le chiamate successive a strtok
	}

	printf("\n");

	printf("ho individuato %d parole\n", pos);

	for (int i = 0; i < pos; i++) {
		printf("%d: %s\n", i, words[i]);
	}

	printf("\n");


	srand(1245); // inizializziamo il seed del generatore di numeri pseudocasuali

	// randomizzare le parole per produrre una nuova stringa di caratteri
	// vanno riutilizzate tutte le singole parole (una sola volta ciascuna)

	// provo a fare pos permutazioni dell'array words:

	for (int i = 0; i < pos; i++) {
		int p1 = rand() % pos;
		int p2 = rand() % pos;

		char * temp;

		temp = words[p1];
		words[p1] = words[p2];
		words[p2] = temp;
	}

	printf("permutazione delle parole:\n");
	// risultato:
	for (int i = 0; i < pos; i++) {
		printf("%s ", words[i]);
	}

	printf("\n");

	return 0;
}
