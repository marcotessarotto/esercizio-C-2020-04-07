#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** array_remove(char **arr, int len, int index)
{
	int offset = 0;
	len--;
	char **new_arr = calloc(len, sizeof(char*));
	for (int i = 0; i < len; i++) {
		if (i == index)
			offset = 1;
		new_arr[i] = arr[i + offset];
	}
	return new_arr;
}

// Words are expected to be passed as command line arguments!
int main(int argc, char *argv[])
{
	int words = argc - 1;
	time_t t = time(NULL);
	srand(t);

	char **new_arr = argv;
	while (words) {
		int rnd = rand() % words + 1;
		printf(new_arr[rnd]);
		if (words > 1)
			printf(" ");
		new_arr = array_remove(new_arr, words + 1, rnd);
		words--;
	}

	/*
	 * If no words have been passed to the program, freeing new_arr would
	 * imply freeing argv, and this yields an "invalid pointer" error.
	 */
	if (argc > 1)
		free(new_arr);

	return 0;
}
