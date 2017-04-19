#include <stdio.h>
#include <stdlib.h>
typedef struct ElementType {
    int catFood;
    int javaBeen;
    double ratio;
} ElementType;

void print(ElementType arr[],unsigned int len);
void InsertionSort(ElementType arr[], unsigned int len);
void InsertionSortInt(int arr[], unsigned int len);

int main() {
    int i;
    ElementType *element;       /*数据元素为结构体的数组*/

    double maxObtain;
    int M,N,index;
    while(scanf("%d %d",&M,&N) != EOF){
        if( M != -1 && N != -1){
            maxObtain = 0;
            element = (ElementType *)malloc(sizeof(ElementType)*N);
            for(i = 0;i < N; i++){
                scanf("%d %d",&element[i].javaBeen,&element[i].catFood);
                if(element[i].catFood != 0){
                    element[i].ratio = 1.0*element[i].javaBeen / element[i].catFood;
                }
            }
            InsertionSort(element,N);
            for(i = 0;i < N; i++){
                if(element[i].catFood != 0){
                    if( M/element[i].catFood ){
                        maxObtain += element[i].javaBeen;
                    }else{
                        maxObtain += M * (element[i].ratio);
                    }
                    M -= element[i].catFood;
                } else {
                    maxObtain += element[i].javaBeen;
                }
            }
            printf("%.3f\n",maxObtain);
        } else{
            break;
        }
    }
}

void print(ElementType arr[], unsigned int len)
{
    unsigned p;
    for (p = 0; p < len; p++) {
        if(p != len -1){
            printf("[%d]=%d %d %.3f,",p,arr[p].javaBeen,arr[p].catFood,arr[p].ratio);
        }else {
            printf("[%d]=%d %d %.3f\n",p,arr[p].javaBeen,arr[p].catFood,arr[p].ratio);
        }
    }
}

void InsertionSort(ElementType arr[], unsigned int len)
{
    int j, p;
    ElementType tmp;
    for( p = 1; p < len; p++ ) {
        tmp.javaBeen = arr[p].javaBeen;
        tmp.catFood = arr[p].catFood;
        tmp.ratio = arr[p].ratio;
        j = p - 1;
        for(; j >= 0 && tmp.ratio > arr[j].ratio; j--){
            arr[j+1].javaBeen = arr[j].javaBeen;
            arr[j+1].catFood = arr[j].catFood;
            arr[j+1].ratio = arr[j].ratio;
        }
        arr[j+1].javaBeen = tmp.javaBeen;
        arr[j+1].catFood = tmp.catFood;
        arr[j+1].ratio = tmp.ratio;
    }
}

void InsertionSortInt(int arr[], unsigned int len)
{
    int j, p;
    int tmp;
    for( p = 1; p < len; p++ ) {
        tmp = arr[p];
        j = p - 1;
        for(; j >= 0 && tmp > arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}