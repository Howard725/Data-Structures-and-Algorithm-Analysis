//
// Created by Administrator on 2016/2/25.
//

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreateStack( void ) {
    Stack S = malloc(sizeof(struct Node));
    if (S == NULL)
    {
        printf("cannot create Stack.");
        return NULL;
    }
    MakeEmpty(S);
    return S;
}

void DisposeStack( Stack S )
{
    if( S == NULL )
    {
        printf( "Stack doesn't exist. ");
        return;
    }

    while( !IsEmpty(S) )
        Pop(S);

    free(S);
}

void MakeEmpty( Stack S )
{
    if( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }

    S->Next = NULL;
}

void Push( int X, Stack S )
{
    PtrToNode temp = malloc(sizeof(struct Node));
    if( temp == NULL )
    {
        printf("cannot create Node.");
        return;
    }
    temp->Element = X;
    temp->Next = S->Next;
    S->Next = temp;
}

int Top( Stack S )
{
    if( IsEmpty(S))
    {
        printf("The Stack is empty.");
        return 0;
    }

    return S->Next->Element;
}

void Pop( Stack S )
{
    PtrToNode temp;

    if( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }

    if( IsEmpty(S) )
    {
        printf("The Stack is empty.");
        return;
    }

    temp = S->Next;
    S->Next = temp->Next;
    free(temp);

}









