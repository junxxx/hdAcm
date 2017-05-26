#include <stdio.h>
int main()
{
    int instance, step;
    while( scanf("%d",&instance) != EOF)
    {
        if( instance == 0 )
            break;
        step = 0;
        while( instance > 1 )
        {
            if( instance % 2 == 0 ) 
                instance /= 2;
            else
                instance = (3*instance +1)/2;
            step++;
        }
        printf("%d\n",step);
    }

    return 0;
}
