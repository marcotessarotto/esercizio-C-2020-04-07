#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int conta_parole(char * str){

	char s[] = " ";
	char *token;
	int counter = 0;

	char * copia = strdup(str);

	token = strtok(copia, s);

	while (token != NULL ) {
		counter++;
		token = strtok(NULL, s);
	}
	return counter;
}

void stampa_random(char * str, int n_parole){

	int random_number;
	time_t t = time(NULL);
	int * stampati;
	int rim = n_parole;
	char * token;
	int counter=0;
	char s []= " ";

	stampati = calloc(n_parole, sizeof(int));

	srand(t);

	while(rim > 0){
		char * copia = strdup(str);
		random_number = rand() % n_parole + 1;
		token = strtok(copia, s);

			while (token != NULL ) {
				counter++;
				if ((counter ==random_number) && (stampati[counter] == 0)){
					printf("%s ", token);
					stampati[counter] = 1;
					rim--;
				}
				token = strtok(NULL, s);
			}

		counter = 0;

	}


}


int main(int argc, char *argv[]) {

	char * str= calloc(1, sizeof(char));
	int parole_tot;
	char c;
	int counter = 0;

	printf("Scrivi una stringa di caratteri, separando parole diverse con lo spazio... poi dai invio\n");

	while ((c=getchar()) != '\n'){
		str[counter]=c;
		counter++;
		str=realloc(str, (counter+1) * sizeof(char));
	}

		str[counter] = '\0';

		printf("Stringa ricevuta: %s", str);
		printf("\n");

		parole_tot =conta_parole(str);
		stampa_random(str, parole_tot);
		printf("\nCiao Ciao!!");

		return 0;
		}
