#include <stdio.h>
#define MAXSIZE 101

int main() {
    int count;
    char str[MAXSIZE], *ptrToChar;

    while( gets(str) )
    {
        if( *str == '#')
            break;
        count = 0;
        ptrToChar = str;
        while( *ptrToChar != '\0')
        {
            if( *ptrToChar == '1')
                count++;
            ptrToChar++;
        }
        /*指针指向字符串的最后一个字符(不是'\0')*/
        ptrToChar--;
        if( count%2 == 0)
        {
            if( *ptrToChar == 'o')
                *ptrToChar = '1';
            else if(*ptrToChar == 'e')
                *ptrToChar = '0';
        }
        else
        {
            if( *ptrToChar == 'o')
                *ptrToChar = '0';
            else if(*ptrToChar == 'e')
                *ptrToChar = '1';
        }
        printf("%s\n",str);
    }
    return 0;
}