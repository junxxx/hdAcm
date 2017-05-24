#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10001

typedef char ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
struct Node
{
    ElementType Data;
    int Quantity;
    Position Next;
};

List InitList();
Position Find(ElementType X, List L);
Position Last(List L);
int IsLast(Position P);
void Append(List L,ElementType X);
void DisplayList( List L);


int main() {
    int instance;
    char string[MAXSIZE], warp, *cell;
    Position P;
    List L;

    scanf("%d",&instance);
    warp = getchar();
    if( warp == '\n')
    {
        while( instance-- ){
            L = InitList();
            gets(string);
            cell = string;
            while( *cell != '\0'){
                P = Find(*cell,L);
                /*如果List 中有，则Quantity +1,否则在链表尾插入*/
                if( P != NULL )
                {
                    P->Quantity++;
                }
                else
                {
                    Append(L,*cell);
                }
                cell++;
            }
            DisplayList( L );
            printf("\n");
        }
    }
    return 0;
}

List InitList()
{
    List L;

    L = malloc( sizeof(struct Node));
    if( L == NULL)
        exit(0);
    L->Next = NULL;

    return L;
}

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while( P != NULL && P->Data != X)
        P = P->Next;
    return P;
}

int IsLast( Position P)
{
    return P->Next == NULL;
}

Position Last( List L)
{
    Position  P;

    if( L == NULL)
        exit(0);
    else
    {
        P = L;
        while( !IsLast( P )){
            P = P->Next;
        }
    }
    return P;
}

void Append( List L, ElementType X)
{
    PtrToNode TmpCell, LastCell;

    if( L == NULL )
        exit(0);
    else{
        TmpCell = malloc( sizeof( struct Node ) );
        if( TmpCell == NULL )
            exit(0);
        else
        {
            LastCell = Last( L );
            TmpCell->Data = X;
            TmpCell->Quantity = 1;
            LastCell->Next = TmpCell;
            TmpCell->Next = NULL;
        }
    }
}

void DisplayList( List L)
{
    if( L == NULL )
        exit(0);
    else
    {
        /*头指针不含元素*/
        L = L->Next;
        while( L != NULL){
            if( L->Quantity > 1 )
                printf("%d",L->Quantity);
            printf("%c",L->Data);
            L = L->Next;
        }
    }
}

