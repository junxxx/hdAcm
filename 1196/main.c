#include <stdio.h>
#include <math.h>
#define MAXSIZE 10001
int main() {
    int i, number, index, tmp, step;
    int binary[MAXSIZE];

    while( scanf("%d",&number) != EOF )
    {
        if( number == 0 )
            break;
        index = 0;
        while( number )
        {
            tmp = number%2;
            binary[index] = tmp;
            index++;
            number = number/2;
        }

        for( i = 0; i < index; i++)
        {
            if( binary[i] )
            {
                step = i;
                break;
            }
        }
        printf("%d\n",(int)pow(2,step));
    }
    return 0;
}