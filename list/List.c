//
// Created by Administrator on 2016/2/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

/*struct Node
{
    *//* ElementType = int *//*
    int Element;
    Position Next;
};*/

void PrintList( List L ){
    if( IsEmpty( L ) )
    {
        printf("The list is empty.\n");
        return;
    }

    Position P = L->Next;
    do{
        printf( "%d ", P->Element );
    }while( ( P = P->Next ) && printf("-> ") );

/*    P = L->Next;
    while(1)
    {
        printf("%d ", P->Element );
        P = P->Next;
        if( P != NULL )
            printf("-> ");
        else
            break;
    }*/
}

List MakeEmpty( List L ){
    L->Next = NULL;
    return L;
}

int IsEmpty( List L )
{
    return L->Next == NULL;
}

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

Position Find( int X, List L )
{
    Position P = L->Next;
    while ( P != NULL && P->Element != X )
        P = P->Next;

    return P;
}

void Delete( int X, List L )
{
    Position P = FindPrevious( X, L );
    Position temp = P->Next;

    if( !IsLast( P, L ) )
    {
        //删除
        P->Next = temp->Next;
        free(temp);
    }
}

Position FindPrevious( int X, List L )
{
    Position P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
}

void Insert( int X, List L, Position P )
{
    Position temp = malloc(sizeof(struct Node));
    if( temp == NULL ) /* 内存分配不成功 */
        return;

    temp->Element = X;
    temp->Next = P->Next;
    P->Next = temp;
}

void DeleteList( List L )
{
    Position temp, P;
    P = L->Next;
    L->Next = NULL;

    while( P != NULL )
    {
        temp = P;
        P = P->Next;
        free(temp);
    }
}

/* DeleteList递归写法 */
void Delete_Recur( Position P)
{
    if(P->Next != NULL )
        Delete_Recur( P->Next );

    free(P);
}

void DeleteList_Recur( List L )
{
    Delete_Recur( L->Next );

    L->Next = NULL;
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

int Retrieve( Position P )
{
    return P->Element;
}
















