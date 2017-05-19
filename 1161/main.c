#include <stdio.h>
#define MAXSIZE 1001
#define false 0
#define true 1
char lower( char X);
int isUpperCase( char X);
int main() {
    char string[MAXSIZE], *ptrToChar;
    while( gets(string) )
    {
        ptrToChar = string;
        while( *ptrToChar != '\0')
        {
            *ptrToChar = lower( *ptrToChar );
            printf("%c",*ptrToChar);
            ptrToChar++;
        }
        putchar('\n');
    }
    return 0;
}

char lower( char X )
{
    if( isUpperCase( X ) )
        X += 32;
    return X;
}

int isUpperCase( char X )
{
    if( X >= 'A' && X <= 'Z')
        return true;
    return false;
}