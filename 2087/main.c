#include <stdio.h>
#define MAXSIZE 20
int main() {
    int instance;
    char mobile[MAXSIZE], *ptr;

    scanf("%d",&instance);
    if( getchar() == '\n')
    {
        while( instance--)
        {
            scanf("%s",mobile);
            printf("6%s\n",mobile+6);
        }
    }
    return 0;
}