#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int len);

int main()
{
    int instance, i, size;
    int number[1001];

    while( scanf("%d", &instance) != EOF )
    {
        while( instance-- )
        {
            scanf("%d", &size );
            for( i = 0; i < size; i++)
                scanf("%d",&number[i]);
            InsertionSort(number, size);
            for( i = 0; i < size; i++)
            {
                if( i == size -1)
                    printf("%d\n",number[i]);
                else
                    printf("%d ",number[i]);
            }
        }
    }
    return 0;
}

void InsertionSort(int arr[],  int len)
{
    int j, p, tmp;
    for( p = 1; p < len; p++ ) {
        tmp = arr[p];
        j = p - 1;
        for(; j >= 0 && tmp < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}