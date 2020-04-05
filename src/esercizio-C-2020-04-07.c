#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int *random_array(int count)
{
    int *array = calloc(count, sizeof(int));
    if(array == NULL){
        printf("\ncalloc error!\n");
        exit(1);
    }
    for (int i = 0; i < count; i++)
    {
        int random = rand() % count;
        array[i] = random;
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                i--;
                break;
            }
        }
    }

    return array;
}

int main(int argc, char *argv[])
{
    char line[] = "hello world mi chiamo pino sono date delle stringhe";
    char separatori[] = " ";
    char *token;
    char *new_line[MAX_LENGTH];
    token = strtok(line, separatori);
    new_line[0] = token;
    int count = 0;
    while (token != NULL)
    {
        token = strtok(NULL, separatori);
        count++;
        new_line[count] = token;
    }
    printf("numero di parole rilevate nella stringa: %d\n", count);
    int *random_order = random_array(count);
    for (int i = 0; i < count; i++)
    {
        int index = random_order[i];
        printf("%s ", new_line[index]);
    }

    free(random_order);
    free(new_line);
  
    return 0;
}
