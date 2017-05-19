#include <stdio.h>

int digitalRoot( int poly, int base, int power );
int digital( int num);
int isEven( int num );

int main() {

    int instance, poly, base, power;

    while( scanf("%d",&instance) != EOF )
    {
        if( instance == 0)
            break;
        poly = 1;
        base = instance;
        power = instance;
        printf("%d\n",digitalRoot( poly, base, power ) );
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
    poly = digital( poly );
    base = digital( base );
    while( power > 0 )
    {
        if( isEven( power ))
        {
            base *= base;
            power /= 2;
        }
        else
        {
            poly *= base;
            power--;
        }
       return digitalRoot( poly, base, power );
    }
    poly = digital( poly );
    return poly;
}

int isEven( int num )
{
    return num%2 == 0;
}