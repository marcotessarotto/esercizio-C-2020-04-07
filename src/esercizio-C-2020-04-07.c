#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

/*
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
char * get_word(char * input_str, unsigned int n);
void random_words(char * input_str);
unsigned int * generate_random_index(unsigned int n);
unsigned int is_repeated(unsigned int * random_index, unsigned int dim);
unsigned int number_of_words(char * input_str);
char * generate_random_str(char * input_str, unsigned int * rand_index, unsigned int dim);

static char SEP[] = " ";

int main(int argc, char *argv[]) {
	char * input_str = "hello world mi chiamo pino sono date delle stringhe";

	random_words(input_str);

	exit(EXIT_SUCCESS);
}

unsigned int * generate_random_index(unsigned int n) {
	unsigned int * rand_index = calloc(n, sizeof(int));

	unsigned int lower = 0;
	unsigned int upper = n - 1;

	if (rand_index == NULL) {
		printf("calloc error!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		rand_index[i] = (rand() % (upper - lower + 1)) + lower;
		if (i > 0) {
			while (is_repeated(rand_index, i) != 0) {
				rand_index[i] = (rand() % (upper - lower + 1)) + lower;
			}
		}
	}
	return rand_index;
}

char * generate_random_str(char * input_str, unsigned int * rand_index, unsigned int dim) {
	unsigned int length = 1;
	char * final_str = calloc(length, sizeof(char));
	char * temp_str;

	if (final_str == NULL) {
		printf("calloc error!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < dim; i++) {
		temp_str = get_word(input_str, rand_index[i]);

		if (i == (dim - 1)) {
			length += strlen(temp_str);

			final_str = realloc(final_str, length * sizeof(char));

			if (final_str == NULL) {
				printf("realloc error!\n");
				exit(EXIT_FAILURE);
			}

			strcat(final_str, temp_str);
		} else {
			length += strlen(temp_str) + 1;

			final_str = realloc(final_str, length * sizeof(char));

			if (final_str == NULL) {
				printf("realloc error!\n");
				exit(EXIT_FAILURE);
			}

			strcat(final_str, temp_str);
			strcat(final_str, SEP);
		}
	}

	return final_str;
}


void random_words(char * input_str) {
	unsigned int n_words = number_of_words(input_str);
	unsigned int * rand_index = generate_random_index(n_words);
	char * new_str = generate_random_str(input_str, rand_index, n_words);

	printf("Original string: \"%s\"\n", input_str);
	printf("The random string is: \"%s\"\n", new_str);
}

unsigned int is_repeated(unsigned int * random_index, unsigned int dim) {
	int check = 0;

	for (int i = dim - 1; i >= 0; i--) {
		if (random_index[dim] == random_index[i])
			check = 1;
	}

	return check;
}

unsigned int number_of_words(char * input_str) {
	unsigned int n_words = 0;
	char * str_cpy = strdup(input_str);
	char * word;

	word = strtok(str_cpy, SEP);
	n_words++;

	while(word != NULL){
		word = strtok(NULL, SEP);
		n_words++;
	}

	return n_words - 1;
}

char * get_word(char * input_str, unsigned int n) {
	char * str_cpy = strdup(input_str);
	char * word;

	word = strtok(str_cpy, SEP);

	while(n > 0){
		word = strtok(NULL, SEP);
		n--;
	}

	return word;
}


