#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXSIZE 1000

/* hexadecimal to decimal*/
int hextodec( char X );
int main() {
    char number1[MAXSIZE], number2[MAXSIZE];
    int num1, num2;
    int i;

    while( scanf("%s %s",number1, number2) != EOF )
    {
        num1 = 0;
        num2 = 0;
        for( i = 0; i < strlen(number1); i++ )
        {
            num1 += hextodec( number1[i] ) * pow( 16, strlen(number1)-1 -i );
        }
        for( i = 0; i < strlen(number2); i++ )
        {
            num2 += hextodec( number2[i] ) * pow( 16, strlen(number2)-1 -i );
        }
        printf("%d\n",num1+num2);
    }
    return 0;
}

int hextodec( char X )
{
    if( X >= '0' && X <= '9')
        return X - '0';
    if( X == 'A' || X == 'a')
        return 10;
    if( X == 'B' || X == 'b')
        return 11;
    if( X == 'C' || X == 'c')
        return 12;
    if( X == 'D' || X == 'd')
        return 13;
    if( X == 'E' || X == 'e')
        return 14;
    if( X == 'F' || X == 'f')
        return 15;
}