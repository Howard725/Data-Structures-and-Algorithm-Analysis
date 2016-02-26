//
// Created by Administrator on 2016/2/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"

int IsEmpty_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return 1;
    }

    return S->TopOfStack == EmptyTOS;
}

int IsFull_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return 1;
    }

    return S->TopOfStack == S->Capacity-1;
}

Stack_Array CreateStack_Array( int Capacity )
{
    Stack_Array S = NULL;

    if ( Capacity <= MinStackSize )
    {
        printf("Capacity is illegal.");
        return NULL;
    }

    S = malloc(sizeof(struct StackRecord));
    if ( S == NULL )
    {
        printf("cannot create Stack.");
        return NULL;
    }
    S->Array = malloc( Capacity * sizeof(int) );
    if ( S == NULL )
    {
        printf("cannot create Stack Array.");
        return NULL;
    }

    S->Capacity = Capacity;
    MakeEmpty_Array(S);

    return S;
}

void DisposeStack_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }

    free(S->Array);
    free(S);
}

void MakeEmpty_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }

    S->TopOfStack = EmptyTOS;
}

void Push_Array( int X, Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }
    if ( IsFull_Array(S) )
    {
        printf("Stack full.");
        return;
    }
    S->Array[++(S->TopOfStack)] = X;
}

int Top_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return 0;
    }
    if ( IsEmpty_Array(S) )
    {
        printf("Stack is empty.");
        return 0;
    }

    return S->Array[S->TopOfStack];
}

void Pop_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return;
    }

    if ( IsEmpty_Array(S) )
    {
        printf("Stack is empty.");
        return;
    }

    --(S->TopOfStack);
}

int TopAndPop_Array( Stack_Array S )
{
    if ( S == NULL )
    {
        printf("Stack doesn't exist.");
        return 0;
    }
    if ( IsEmpty_Array(S) )
    {
        printf("Stack is empty.");
        return 0;
    }

    return S->Array[(S->TopOfStack)--];
}




























