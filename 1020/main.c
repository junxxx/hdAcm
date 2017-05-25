#include <stdio.h>
#define MAXSIZE 10001

int main() {
    int instance, count ;
    char string[MAXSIZE],  *cell;

    scanf("%d",&instance);
    if( getchar() == '\n')
    {
        while( instance-- ){
            gets(string);
            count = 1;
            cell = string;
            while( *cell != '\0')
            {
                if(*cell == *(cell+1))
                    count++;
                else
                {
                    if( count > 1)
                        printf("%d",count);
                    printf("%c",*cell);
                    count = 1;
                }
                cell++;
            }
            printf("\n");
        }
    }
    return 0;
}