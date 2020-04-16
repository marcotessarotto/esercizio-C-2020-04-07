#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define NUM_CHARS 30



char ** random_char_array(char ** char_array,int length){

	int array[length];

	//creo un array di int contenente numeri distinti casuali
	//da 0 a length-1 che utilizzerò per creare il mio char_array_random

	for(int i=0;i<length;++i){

		int x=rand() % length;
		array[i]=x;

		for(int j=0;j<i;++j)

			if(array[j]==x){
				i--;
				break;
			}
	}

	char ** char_array_random=(char **)malloc(length * sizeof (char *));

	for(int i=0;i<length;++i)
		char_array_random[i]=char_array[array[i]];


	return char_array_random;
}


int main(int argc, char **argv) {

	char str[] = "hello world mi chiamo pino sono date delle stringhe";
	char s[]=" ";
	printf("%s\n\n",str);

	char **tokens=(char **)malloc(NUM_CHARS*sizeof(char *));
	int n_tkns=0;

	char * tkn=strtok(str,s);

	while(tkn!=NULL && NUM_CHARS){
		tokens[n_tkns]=tkn;
		n_tkns++;

		// ho definito una dimensione massima NUM_CHARS anzichè usare
		// la system call realloc (che ho lasciato commentatata qui sotto)
		//perchè dopo la 4a iterazione mi dava l'errore
		//realloc(): invalid next size

		//tokens=(char **)realloc(tokens,n_tkns*sizeof(char *));

		tkn=strtok(NULL,s);
	}

	tokens=random_char_array(tokens,n_tkns);

	for(int i=0; i<n_tkns;++i)
		printf("%s ",tokens[i]);

	return 0;
}
