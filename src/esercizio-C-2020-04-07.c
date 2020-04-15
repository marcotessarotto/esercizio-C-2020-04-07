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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define NUM_CHARS 30

char ** random_char_array(char ** char_array,int length){

	int array[length];

	for(int i=0; i<length; i++)
	{
		int x=rand() % length;
		array[i]=x;

		for(int j=0; j<i; j++)
		{
			if(array[j]==x){
				i--;
				break;
			}
		}
	}


	char ** char_array_ran=(char **)malloc(length * sizeof (char *));

	for(int i=0; i<length; i++)
		char_array_ran[i]=char_array[array[i]];

	return char_array_ran;

}

int main(int argc, char **argv) {

	char str[] = "hello world mi chiamo pino sono date delle stringhe";
	char s[]=" ";

	//Stampo la stringa di partenza
	printf("%s \n\n",str);

	char **tokens=(char **)malloc(sizeof(char *));
	int n=0;
	char * tkn=strtok(str,s);

	while(tkn!=NULL)
	{
		tokens[n]=tkn;
		n++;
		tokens=realloc(tokens,(n+1)*sizeof(char *));
		tkn=strtok(NULL,s);
	}

	tokens=random_char_array(tokens,n);

	//Stampo la stringa randomizzata
	for(int i=0; i<n;++i)
	{
		printf("%s ",tokens[i]);
	}

	return 0;
}


