#include <stdio.h>
#define MAXSIZE 1000001
#define Cutoff ( 3 )

void swap(int *x, int *y);
void quick_sort_recursive(int arr[], int start, int end);
void quick_sort(int arr[], int len);

void Swap( int *left, int *right );
void insertionSort( int arr[], int len );
void Quicksort( int A[], int N );
int Median3( int A[], int Left, int Right );
void Qsort( int A[], int Left, int Right );
int main()
{
    int wealth[MAXSIZE];
    int i, people, m;

    while( scanf("%d %d",&people, &m) != EOF )
    {
        if( people == 0 && m == 0 )
            break;
        for( i = 0; i < people; i++ )
            scanf("%d",&wealth[i]);
        /* sorting */
        quick_sort( wealth, people );       /* Works well*/
//        Quicksort( weah , people );　　　/*This quick sort doesn't work as expected*/
      for( i = people - 1; i >= people - m; i--)
        {
            if( i == people - m )
                printf("%d\n",wealth[i]);
            else
                printf("%d ",wealth[i]);
        }
    }

    return 0;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;//這是為了防止宣告堆疊陣列時當機
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left) {
        quick_sort_recursive(arr, start, left - 1);
    }
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

void insertionSort( int arr[], int len )
{
    int j, p, tmp;
    for( p = 1; p < len; p++)
    {
        tmp = arr[p];
        j = p - 1;
        for( ; j >= 0 && tmp > arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = tmp;
    }
}

void Swap( int *left, int *right )
{
    int tmp;

    tmp = *left;
    *left = *right;
    *right = tmp;
}

void Quicksort( int A[], int N )
{
    Qsort( A, 0, N -1 );
}

int Median3( int A[], int Left, int Right )
{
    int Center = ( Left + Right ) / 2;

    if( A[Left] > A[Center])
        Swap( &A[Left], &A[Center]);
    if( A[Left] > A[Right] )
        Swap( &A[Left], &A[Right] );
    if( A[Center] > A[Right] )
        Swap( &A[Center], &A[Right] );

    Swap( &A[Center], &A[Right -1] );
    return A[Right-1];
}

void Qsort( int A[], int Left, int Right )
{
    int i, j;
    int Pivot;

    if( Left + Cutoff <= Right )
    {
        Pivot = Median3( A, Left, Right );
        i = Left + 1; j = Right - 2;
        for( ; ; )
        {
            while( A[i] < Pivot )i++;
            while( A[j] > Pivot )j--;
            if( i < j )
                Swap( &A[i], &A[j]);
            else
                break;
        }
        Swap( &A[i], &A[Right -1]);

        Qsort( A, Left, i-1 );
        Qsort( A, i +1 ,Right );
    }
    else
        insertionSort( A + Left, Right - Left + 1 );
}
