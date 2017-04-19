/*
  Program 1062:Text Reverse
  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1001

void textrev(char *s);
int main()
{
    int i, N;                /* i  for loop;Test case N */
    char **s;            /* number N char string */
	
    scanf("%d\n",&N);
	
    s = (char **)malloc(N * sizeof(char *));        /* dynamically malloc memory for N char strings*/
    for(i = 0;i < N;i++)
        s[i] = (char *)malloc(MAXLEN * sizeof(char));
    for(i = 0;i < N;i++)
	{
		gets(s[i]);
		textrev(s[i]);
		printf("\n");
	}    
        
    return 0;
}

void textrev(char *s)
{
    char *r = strtok(s," ");
    while(r != NULL)
    {
        printf("%s ",strrev(r));
        r = strtok(NULL," ");
    }
        
}