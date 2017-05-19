#include <stdio.h>
#define false 0
#define true 1;
int isLeapYear( int year );

int main() {
    int instance, N, startYear, endYear;
    int count;
    scanf("%d",&instance);
    while( instance-- )
    {
        scanf("%d %d",&startYear,&N);
        count = 0;
        endYear = startYear;
        while( count < N )
        {
            if( isLeapYear( endYear ) )
                count++;
            endYear++;
        }
        /*最后的一个leapYear判断成功之后，count++,endYear多加了一次*/
        printf("%d\n",endYear-1);
    }
    return 0;
}

int isLeapYear( int year )
{
    if( (year % 4 == 0 && year%100 !=0) || year % 400 == 0)
        return true;
    return false;
}