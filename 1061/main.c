#include <stdio.h>
#include <math.h>

int rDigit( unsigned int number );

int main() {
    int instance;
    unsigned int N;

    scanf("%d",&instance);
    while( instance-- )
    {
        scanf("%d",&N);
        printf("%d\n", rDigit(N));
    }
    return 0;
}

int rDigit( unsigned int number )
{
    int A = 1;
    unsigned int base, power;

    base = number;
    power = number;

    while( power  )
    {
        if( power%2 == 0)
        {
            power /= 2;
        }
        else
        {
            A = A * (base % 10) % 10;
            power = (power -1)/2;
        }
        base = (int)pow( base%10, 2) % 10;
    }
    return A;
}