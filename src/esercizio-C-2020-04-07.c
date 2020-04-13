#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

typedef struct{
   char * char_array;
   int length_char_array;
}word;


int getRandomNumber(int upper_limit);
void print_word(word w);

int main ()
{

	int numbers_of_words = 0;
	word * words;

	char ch = getchar();
	int count_letters_in_the_word = 1;

	while(ch != EOF){

		if(count_letters_in_the_word == 1){
			numbers_of_words++;
			words = realloc(words, numbers_of_words * sizeof(word));
		}

		if(ch == ' '){
			count_letters_in_the_word = 0;
		}else{
			words->char_array = realloc(words->char_array, count_letters_in_the_word * sizeof(char));
			words->char_array[count_letters_in_the_word-1] = ch;
			words->length_char_array = count_letters_in_the_word;
		}

		ch = getchar();
		count_letters_in_the_word++;

	}

	for(int i=0 ; i<numbers_of_words ; i++){
		for(int j=0 ; j<words[i].length_char_array ; j++){
			printf("%c", words[i].char_array[j] );
		}
		putchar('\n');
	}
	printf("\n");



	return 0;
}

// return an random int [0, upper_limit-1]
int getRandomNumber(int upper_limit){
	srand ( time(NULL) );

	int random_number = rand() % upper_limit;

	return random_number;
}

void print_word(word w){
	for(int i=0 ; i<w.length_char_array ; i++){
		printf("%c", w.char_array[i]);
	}
	printf(" ");
}
