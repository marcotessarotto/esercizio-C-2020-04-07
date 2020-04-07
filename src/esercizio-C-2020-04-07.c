/*
 * esercizio-C-2020-04-07.c
 *
 *  Created on: Apr 2, 2020
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SEPARETOR " "
int *randomNumber;

void generateRandomString(char *inputString);
void randomNumberSequence(int upperLimit);
int isValid(int index);
int wordCounter(char *inputString);
char* randomWord(char *inputString, int index);

int main(int argc, char **argv) {

	char *str = "hello world mi chiamo pino sono date delle stringhe";
	generateRandomString(str);
	return 0;
}

void generateRandomString(char *inputString) {
	int stringLength = wordCounter(inputString);
	int dim = 1;
	char *outputString = calloc(dim, sizeof(char));
	char *tmpString;

	randomNumber = calloc(stringLength, sizeof(int));
	randomNumberSequence(stringLength);

	for (int i = 0; i < stringLength; i++) {
		tmpString = randomWord(inputString, randomNumber[i]);
		strcat(tmpString, SEPARETOR);

		dim = dim + strlen(tmpString) + 1;

		outputString = realloc(outputString, dim * sizeof(char));
		strcat(outputString, tmpString);
	}
	printf("Original string: %s\n", inputString);
	printf("Random string: %s\n", outputString);

	return;
}

void randomNumberSequence(int upperLimit) {
	randomNumber = calloc(upperLimit, sizeof(int));

	for (int i = 0; i < upperLimit; i++) {
		randomNumber[i] = rand() % upperLimit;
		if (i > 0) {
			while (isValid(i) == 0) {
				int tmp = rand() % upperLimit;
				randomNumber[i] = tmp;
			}
		}
	}

	return;
}

int isValid(int index) {
	int bool = 1;
	for (int i = index - 1; i > 0; i--) {
		if (randomNumber[i] == randomNumber[index])
			bool=0;
	}
	return bool;
}

int wordCounter(char *inputString) {
	int count = 1;
	char *copy = strdup(inputString);
	char *token;

	token = strtok(copy, SEPARETOR);

	while (token != NULL) {
		token = strtok(NULL, SEPARETOR);
		count++;
	}
	return count - 1;
}

char* randomWord(char *inputString, int index) {
	char *copy = strdup(inputString);
	char *word;

	word = strtok(copy, SEPARETOR);

	while (index > 0) {
		word = strtok(NULL, SEPARETOR);
		index--;
	}

	return word;

}

/*
 ***randomizzare le parole*** rand() % 50

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
 * */
