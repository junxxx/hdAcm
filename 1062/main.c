#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1001

typedef char ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef struct Node
{
    ElementType Data;
    PtrToNode Next;
};

Stack CreateStack();
int IsEmpty( Stack S );
void Push(ElementType X, Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);
void DisplayStack(Stack S);

int main() {
    char string[MAXSIZE], warp;
    char *PtrToChar;
    int instance;
    Stack S;

    scanf("%d",&instance);
    warp =  getchar();
    S = CreateStack();

    if( warp == '\n')
    {
        while( instance-- ) {
            gets(string);
            PtrToChar = string;
            while( *PtrToChar != '\0' ){
                if( *PtrToChar != ' ' )
                {
                    Push( *PtrToChar,S );
                }
                else
                {
                    DisplayStack(S);
                    printf("%c",*PtrToChar);
                    MakeEmpty(S);
                }
                PtrToChar++;
            }
            if( !IsEmpty(S))
            {
                DisplayStack(S);
                MakeEmpty(S);
            }
            printf("\n");
        }
    }
    return 0;
}

Stack CreateStack( )
{
    Stack S;

    S = malloc( sizeof( struct Node) );
    if(S == NULL)
        exit(0);
    S->Next = NULL;
    return S;
}

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof( struct Node));
    if(TmpCell == NULL)
        exit(0);
    else
    {
        TmpCell->Data = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

void Pop( Stack S)
{
    PtrToNode firstCell;

    if(S == NULL)
        exit(0);
    if( S->Next == NULL)
    {
        printf("Empty Stack");
        exit(0);
    }
    else
    {
        firstCell = S->Next;
        S->Next = S->Next->Next;
        free(firstCell);
    }
}

void DisplayStack( Stack S)
{
    if( S == NULL )
        exit(0);
    else
    {
        /*栈顶指针，不含元素，要特殊处理一下*/
        S = S->Next;
        while( S != NULL){
            printf("%c",S->Data);
            S = S->Next;
        }
    }
}

void MakeEmpty( Stack S)
{
    if(S == NULL)
        exit(0);
    else
        while( !IsEmpty( S ) )
            Pop( S );
}