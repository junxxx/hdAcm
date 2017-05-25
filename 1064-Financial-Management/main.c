#include <stdio.h>
#define Month 12

int main() {
    float balance[Month], sum = 0;
    int i;

    for(i = 0; i < Month; i++)
    {
        scanf("%f",&balance[i]);
        sum += balance[i];
    }
    printf("$%.2f\n",sum/Month);
    return 0;
}