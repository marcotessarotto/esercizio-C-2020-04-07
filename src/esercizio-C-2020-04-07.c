/*
 * esercizio-C-2020-04-07.c
 *
 *  Created on: Apr 2, 2020
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SEPARETOR " "
int *randomNumber;

int main(int argc, char **argv) {

	char str[] = "hello world mi chiamo pino sono date delle stringhe";
	generateRandomString(str);
	return 0;
}

void generateRandomString(char *inputString) {
	int stringLength = wordCounter(inputString);
	char *outputString;
	randomNumber = calloc(stringLength, sizeof(int));

}

void randomNumberSequence(int upperLimit) {
	unsigned random = 0;
	randomNumber = calloc(upperLimit,sizeof(int));

	for (int i = 0; i < upperLimit; i++) {

		if(i==0)
			randomNumber[i]= rand() % upperLimit;
		else{
			 while(isValid ==0){

			}

		}
		random = rand() % upperLimit;

	}

	return;
}

int wordCounter(char *inputString) {
	int count = 0;

	char *token;
	token = strtok(inputString, SEPARETOR);
	while (token != NULL) {
		token = strtok(NULL, SEPARETOR);
		count++;
	}
	return count;
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
