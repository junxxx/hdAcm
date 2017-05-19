#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10000

int digitalRoot( int poly, int base, int power );
int digital( int num);

int main() {

    int test, poly, base, power;

    while( scanf("%d",&test) != EOF )
    {
        if( test == 0)
            break;
        poly = digital(test);
        base = poly;
        power = test;
        printf("%d\n",digitalRoot( poly, base, power-1 ) );
    }

    return 0;
}

int digital( int num )
{
    int digit;
    if( num < 10 )
        digit = num;
    else
    {
        digit = 0;
        while( num >= 10 )
        {
            digit += num % 10;
            num = num / 10;
        }
        digit += num;
    }

    if( digit >= 10 )
        return digital( digit );
    else
        return digit;
}
int digitalRoot( int poly, int base, int power )
{

    while( power > 0 )
    {
        if( poly < 10 )
        {
            poly = poly * base;
            power--;
        }
        else
        {
            poly = digital( poly );
        }
        if( base >= 10 )
        {
            base = digital( base );
        }

        digitalRoot( poly, base, power );
    }
    poly = digital( poly );
    return poly;
}
