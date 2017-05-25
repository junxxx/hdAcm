#include <stdio.h>
<<<<<<< HEAD

int main() {
    printf("Hello, World!\n");
    return 0;
=======
#include <string.h>
#define MAXSIZE 1001

int ctoD( char X );
int main() {
    int i, j, instance, longer, carry, out;
    int firstLen, secondLen;
    char num1[MAXSIZE];
    int num1rev[MAXSIZE];
    char num2[MAXSIZE];
    int num2rev[MAXSIZE];
    int num3[MAXSIZE];

    scanf("%d",&instance);
    out = 1;
    while( instance -- )
    {
        /*注意，清空变量中上一轮存储的数据*/
        memset(num1rev, 0, sizeof(num1rev));
        memset(num2rev, 0, sizeof(num2rev));
        scanf("%s %s",num1, num2);
        firstLen = 0;
        /*将字符串逆序列存在int型数组中*/
        for( i = strlen(num1)-1; i >=0; i-- )
            num1rev[firstLen++] = ctoD( num1[i] );
        secondLen = 0;
        for( i = strlen(num2)-1; i >=0; i-- )
            num2rev[secondLen++] = ctoD( num2[i] );
        longer = firstLen >= secondLen ? firstLen : secondLen;
        /*进位*/
        carry = 0;
        for(j = 0; j < longer; j++)
        {
            /*每一位的数*/
            num3[j] = ( num1rev[j] + num2rev[j] + carry ) % 10;
            /*每一位相加和的进位*/
            carry = ( num1rev[j] + num2rev[j] + carry ) / 10;
        }
        /*最高位进位*/
        if( carry == 1 )
            num3[longer++] = 1;
        printf("Case %d:\n",out++);
        printf("%s + %s = ",num1, num2);
        for( i = longer -1 ; i >= 0; i-- )
            printf("%d",num3[i]);
        if( instance > 0)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}

int ctoD( char X )
{
    if( X >= '0' && X <= '9')
        return X - 48;
>>>>>>> e9fb9f33201f955753ea3eb046af7ee4ae0aa5c9
}