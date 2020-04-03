/** ex 2020-04-07 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 10

char * randomize(char * str) {

	// Build token array
	int size = 0;
	int len = 0;
	char **toks = NULL;

	char *tok = strtok(str, " ");
	while(tok != NULL) {
		// Expand if required
		if (len + 1 > size) {
			if (toks == NULL) {
				toks = malloc(sizeof(char *) * BLOCK_SIZE);
			} else {
				toks = realloc(toks, sizeof(char *) * (size + BLOCK_SIZE));
			}
			if (toks == NULL) {
				printf("Failed at malloc/realloc\n");
				exit(-1);
			}
			size += BLOCK_SIZE;
		}

		// Add string
		toks[len] = strdup(tok);
		len ++;
		tok = strtok(NULL, " ");
	}


	// Shuffle array
	int rem = len;
	char **shuf = malloc(sizeof(char *) * len);
	if (shuf == NULL) {
		printf("Failed at malloc\n");
		exit(-1);
	}

	for (int i = 0; i < len; i++) {
		// Get random number
		int r_af = rand() % rem;
		int r_at = 0;
		while(toks[r_at] == NULL || r_af > 0) {
			if (toks[r_at] != NULL) r_af --;
			r_at ++;
		}
		rem --;
		shuf[i] = toks[r_at];
		toks[r_at] = NULL;
	}

	// Output string
	char *out = NULL;
	for (int i = 0; i < len; i++) {
		if (out == NULL) {
			out = strdup(shuf[i]);
		} else {
			out = realloc(out, sizeof(char) * (strlen(out) + strlen(shuf[i]) + 2));
			strcat(out, " ");
			strcat(out, shuf[i]);
		}
	}

	// Free
	for (int i = 0; i < len; i++) {
		if (toks[i] != NULL) {
			free(toks[i]);	// clear duplicated strings
		}
	}
	free(toks); // free array 1
	free(shuf); // free array 2

	return out;
}

int main(int argc, char **argv) {
	// We seed the random() to prevent the strings from repeating at each run
	srand(time(NULL));

	char * str = strdup("hello world mi chiamo pino sono date delle stringhe");
	printf(randomize(str));
	printf("\n");
}

