#include <stdio.h>
#define MAXSIZE 100
int main() {
    int i, peopleNum, AC[MAXSIZE], max;

    while( scanf("%d", &peopleNum) != EOF )
    {
        if( peopleNum == 0 )
            break;
        for( i = 0; i < peopleNum; i++ )
        {
            scanf("%d",&AC[i]);
            if( i == 0 )
                max = AC[i];
            if( AC[i] > max )
                max = AC[i];
        }
        printf("%d\n",max);
    }
    return 0;
}