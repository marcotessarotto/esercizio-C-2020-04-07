#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Words are expected to be passed as command line arguments!
int main(int argc, char *argv[])
{
	int words = argc - 1;
	time_t t = time(NULL);
	srand(t);
	bool *used = calloc(words, sizeof(bool));
	if (used == NULL) {
		perror("calloc() failed. Quitting.");
		exit(EXIT_FAILURE);
	}

	int count = 0;
	while (count < words) {
		int rnd = rand() % words + 1;
		if (used[rnd])
			continue;
		else
			used[rnd] = 1;

		printf(argv[rnd]);
		if (count != words - 1)
			printf(" ");
		count++;
	}

	free(used);
	return 0;
}
