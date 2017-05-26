#include <stdio.h>
#include <math.h>
#define MAXSIZE 100

int main() {
    char number1[MAXSIZE], number2[MAXSIZE], *ptr;
    int n1, n2, bit;

    while( scanf("%s %s",number1, number2)  != EOF )
    {
        n1 = 0;
        bit = 0;
        ptr = number1;
        while( *ptr != '\0')
            ptr++;
        ptr--;
        while( ptr >= number1 )
        {
            if( *ptr == ',')
            {
                ptr--;
                continue;
            }
            if( ptr == number1 )
            {
                if( *ptr == '-')
                    n1 *= -1;
                else if( *ptr > '0' && *ptr <= '9')
                    n1 += (*ptr - '0') * pow( 10, bit);
                break;
            }
            else
            {
                if( *ptr >= '0' && *ptr <= '9')
                {
                    n1 += (*ptr - '0') * pow( 10, bit);
                    bit++;
                }
            }
            ptr--;
        }
        bit = 0;
        n2 = 0;
        ptr = number2;
        while( *ptr != '\0')
            ptr++;
        ptr--;
        while( ptr >= number2 )
        {
            if( *ptr == ',')
            {
                ptr--;
                continue;
            }
            if( ptr == number2 )
            {
                if( *ptr == '-')
                    n2 *= -1;
                else if( *ptr > '0' && *ptr <= '9')
                    n2 += (*ptr - '0') * pow( 10, bit);
                break;
            }
            else
            {
                if( *ptr >= '0' && *ptr <= '9')
                {
                    n2 += (*ptr - '0') * pow( 10, bit);
                    bit++;
                }
            }
            ptr--;
        }
        printf("%d\n",n1+n2);
    }
    return 0;
}