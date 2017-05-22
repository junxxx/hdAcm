#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct data
{
    char first[4];
    char second[4];
}data;
char atoDigit( char[] );
int ctoD( char X);
int strtoNum( char[] );

int main() {
    char str[1001];
    int number;

    while( gets(str) )
    {
        number = strtoNum( str );
        if( number == 0 )
            break;
        printf("%d\n",number);
    }

    return 0;
}

char atoDigit( char *str)
{
    char digital;

    if( strcmp( str, "zero") == 0 )
        digital = '0';
    if( strcmp( str, "one") == 0 )
        digital = '1';
    if( strcmp( str, "two") == 0 )
        digital = '2';
    if( strcmp( str, "three") == 0 )
        digital = '3';
    if( strcmp( str, "four") == 0 )
        digital = '4';
    if( strcmp( str, "five") == 0 )
        digital = '5';
    if( strcmp( str, "six") == 0 )
        digital = '6';
    if( strcmp( str, "seven") == 0 )
        digital = '7';
    if( strcmp( str, "eight") == 0 )
        digital = '8';
    if( strcmp( str, "nine") == 0 )
        digital = '9';

    return digital;
}

int strtoNum( char *str )
{
    data ret;
    int i, firstNum, secondNum;
    char tmpStr[6], *ptrToDigita;

    i = 0;
    ptrToDigita = ret.first;

    while( *str != '\0')
    {
        if( *str == '+' )
        {
            memset( tmpStr,0,sizeof(tmpStr) );
            i = 0;
            *ptrToDigita = '\0';
            ptrToDigita = ret.second;
            str += 2;
        }
        if( *str == '=')
        {
            *ptrToDigita = '\0';
            break;
        }
        if( *str != ' ')
        {
            tmpStr[i] = *str;
            i++;
        }
        else
        {
            if( strlen( tmpStr  ) > 0 )
            {
                tmpStr[i] = '\0';
                *ptrToDigita = atoDigit( tmpStr );
                ptrToDigita++;
                memset( tmpStr,0,sizeof(tmpStr) );
                i = 0;
            }
        }
        str++;
    }

    firstNum = secondNum = 0;
    for(i = 0; i < strlen(ret.first); i++)
    {
        firstNum += ctoD(ret.first[i]) * pow(10,strlen(ret.first)-1-i);
    }

    for(i = 0; i < strlen(ret.second); i++)
    {
        secondNum += ctoD(ret.second[i]) * pow(10,strlen(ret.second)-1-i);
    }

    return firstNum + secondNum;
}

int ctoD( char X )
{
    if( X >= '0' && X <= '9')
        return X - 48;
}