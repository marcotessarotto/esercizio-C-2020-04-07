#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

typedef struct{
   char * char_array;
   int length_char_array;
}word;


int getRandomNumber(int upper_limit);
void print_word(word words);

int main ()
{

	int number_of_words = 0;
	word * words = NULL;


	char ch = getchar();
	int counts_letters_in_a_word = 1;
	int allocated_space = 2;
	//
	//words = calloc(1, sizeof(word));
	//words[number_of_words -1].char_array = calloc(allocated_space, sizeof(char));
	while(ch != EOF){

		if(counts_letters_in_a_word == 1){
			number_of_words++;
			words = realloc(words, number_of_words * sizeof(word));
			words[number_of_words -1].char_array = calloc(allocated_space, sizeof(char));
		}

		if(ch == ' '){
			counts_letters_in_a_word = 0;
		}

		if(counts_letters_in_a_word > allocated_space){
			allocated_space = allocated_space * 2;
			words[number_of_words -1].char_array = realloc(words[number_of_words -1].char_array, allocated_space * sizeof(char));
		}

		if(ch != ' '){
			words[number_of_words -1].char_array[counts_letters_in_a_word -1] = ch;
			words[number_of_words -1].length_char_array = counts_letters_in_a_word;
		}

		ch = getchar();
		counts_letters_in_a_word++;
	}


	putchar('\n');
	for(int i=0 ; i<number_of_words ; i++){
		print_word(words[i]);
	}






	return 0;
}

// return an random int [0, upper_limit-1]
int getRandomNumber(int upper_limit){
	srand ( time(NULL) );

	int random_number = rand() % upper_limit;

	return random_number;
}

void print_word(word words){
	for(int i=0 ; i< words.length_char_array ; i++){
		printf("%c", words.char_array[i]);
	}
	printf(" ");
}
