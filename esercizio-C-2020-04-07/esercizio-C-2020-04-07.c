#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

char strin[] = {"hello world mi chiamo pino sono date delle stringhe"};

typedef
		struct{
				char * parola;
				int length;
		}stringhe;

stringhe * stringa;

int contaparole=0;
int contatot=0;

int contaspazi(char * str){

	int count=0;

	for(int i =0; i<strlen(str); i++)
		if(str[i] == ' ')
			count++;

	return (count+1);
}

void randomize(){

	char * frase;

	frase = malloc(strlen(strin)*sizeof(char));
	if(frase == NULL){
		perror("malloc()");
		exit(3);
	}

	int indice=0;
	int u;

	for(int i=0; i<9; i++){
		time_t t = time(NULL);

		//printf("%ld ", t);

		srand(t);

		u = rand()%9;

		memcpy(&frase[indice], stringa[u].parola, stringa[u].length);

		indice += stringa[u].length;

		if(i<8){	//mette uno spazio tra le parole
		frase[indice] = ' ';
		indice++;
		}

	}
	printf("%s", frase);
}

int main(){

	int word_len=0;
	int contatot=0;

	stringa = malloc(contaspazi(strin)*sizeof(stringhe));
	if(stringa == NULL){
		perror("malloc()");
		exit(4);
	}

	for(int i=0; i<strlen(strin); i++){

		if(strin[i] != ' '){
			word_len++;

			if(i==strlen(strin)-1){
				stringa[contaparole].length = word_len;

				stringa[contaparole].parola = malloc(word_len*sizeof(char));
				if(stringa[contaparole].parola == NULL){
					perror("malloc()");
					exit(5);
				}

				memcpy(stringa[contaparole].parola, &strin[contatot], word_len*sizeof(char));

				/*
				printf("%d", contatot);
				printf("\t%s", stringa[contaparole].parola);
				printf("\t%d\n", contaparole);
 	 	 	 	 */
				contatot += word_len;
				contaparole++;

				/*
				printf("%d", contatot);
				printf("\t%d\n", contaparole);
				*/
			}

		}else if(strin[i] == ' '){


			stringa[contaparole].length = word_len;
			stringa[contaparole].parola = malloc(word_len*sizeof(char));
			if(stringa[contaparole].parola == NULL){
				perror("malloc()");
				exit(5);
			}

			memcpy(stringa[contaparole].parola, &strin[contatot], word_len*sizeof(char));

			/*
			printf("%d", contatot);
			printf("\t%s", stringa[contaparole].parola);
			printf("\t%d\n", contaparole);
			*/

			contatot += (word_len+1);
			word_len=0;
			contaparole++;
		}

	}

	//printf("%d, contatot %d", contaparole, contatot);

	randomize();


return 0;
}
