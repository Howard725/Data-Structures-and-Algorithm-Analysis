//
// Created by Administrator on 2016/2/28.
//

#include <stdio.h>
#include "stdlib.h"
#include "AvlTree.h"

static int Height( AvlTree T )
{
    if ( T == NULL )
        return -1;
    else
        return T->Height;
}

static int Max( int arg1, int arg2 )
{
    return arg1 > arg2 ? arg1 : arg2;
}

static void UpdateHeight( Position P )
{
    P->Height = Max( Height( P->Left ), Height( P->Right ) ) + 1;
}

static Position SingleRotateWithLeft( AvlTree K2 )
{
    Position K1;

    if ( K2 == NULL )
        return NULL;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    UpdateHeight( K2 );
    UpdateHeight( K1 );

    return K1;
}

static Position SingleRotateWithRight( AvlTree K2 )
{
    Position K1;

    if ( K2 == NULL )
        return NULL;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    UpdateHeight( K2 );
    UpdateHeight( K1 );

    return K1;
}

static Position DoubleRotateWithLeft( AvlTree K3 )
{
    if ( K3 == NULL )
        return NULL;

    K3->Left = SingleRotateWithRight( K3->Left );
    return SingleRotateWithLeft( K3 );
}

static Position DoubleRotateWithRight( AvlTree K3 )
{
    if ( K3 == NULL )
        return NULL;

    K3->Right = SingleRotateWithLeft( K3->Right );
    return SingleRotateWithRight( K3 );
}

AvlTree MakeEmpty( AvlTree T )
{
    if ( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position Find( ElementType X, AvlTree T )
{
    if ( T == NULL )
        return NULL;
    else
    {
        if ( X < T->Element )
            return Find( X, T->Left );
        else if ( X > T->Element )
            return Find( X, T->Right );
        else
            return T;
    }
}

Position FindMin( AvlTree T )
{
    if ( T == NULL )
        return NULL;
    else
    {
        if ( T->Left != NULL )
            return FindMin( T );
        else
            return T;
    }
}

Position FindMax( AvlTree T )
{
    if ( T == NULL )
        return NULL;

    while( T->Right != NULL )
        T = T->Right;
    return T;
}

AvlTree Insert( ElementType X, AvlTree T )
{
    //如果T为空，则新建并返回
    if ( T == NULL )
    {
        T = malloc( sizeof(struct AvlNode) );
        if ( T == NULL )
            printf("cannot create node.");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
        return T;
    }
    else
    {
        //如果T不为空，根据大小插入对应左子树或右子树中
        if ( X < T->Element )
        {
            T->Left = Insert( X, T->Left );
            if ( Height( T->Left ) - Height( T->Right ) > 1 )
            {
                if ( T->Left->Left != NULL )
                    T = SingleRotateWithLeft( T );
                else
                    T = DoubleRotateWithLeft( T );
            }
        }
        else if ( X > T->Element )
        {
            T->Right = Insert( X, T->Right );
            if ( Height( T->Right ) - Height( T->Left ) > 1 )
            {
                if ( T->Right->Right != NULL )
                    T = SingleRotateWithRight( T );
                else
                    T = DoubleRotateWithRight( T );
            }
        }

        T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
        return T;
    }
}

AvlTree Delete( ElementType X, AvlTree T )
{
    Position P;

    if ( T == NULL )
        return NULL;
    else
    {
        if ( X < T->Element )
        {
            T->Left = Delete( X, T->Left );
            if ( Height( T->Right ) - Height( T->Left ) > 1 )
            {
                if ( T->Right->Right != NULL )
                    T = SingleRotateWithRight( T );
                else
                    T = DoubleRotateWithRight( T );
            }
        }
        else if ( X > T->Element )
        {
            T->Right = Delete( X, T->Right );
            if ( Height( T->Left ) - Height( T->Right ) > 1 )
            {
                if ( T->Left->Left != NULL )
                    T = SingleRotateWithLeft( T );
                else
                    T = DoubleRotateWithLeft( T );
            }
        }
        else {
            if (T->Left && T->Right)
            {
                P = FindMin(T->Right);
                T->Element = P->Element;
                T = Delete(P->Element, T->Right);
            }
            else
            {
                P = T;
                if ( T->Left == NULL )
                    T = T->Right;
                else
                    T = T->Left;
                free( P );
            }
        }
    }
    return T;
}

ElementType Retrieve( Position P )
{
    //检查参数有效性

    return P->Element;
}





























