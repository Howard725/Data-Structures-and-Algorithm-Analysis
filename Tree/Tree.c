//
// Created by Administrator on 2016/2/26.
//

#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

SearchTree MakeEmpty( SearchTree T )
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find( ElementType X, SearchTree T )
{
    if ( T == NULL )
        return NULL;

    if ( X < T->Element )
        return Find( X, T->Left );
    else if ( X > T->Element )
        return Find( X, T->Right );
    else
        return T;
}

Position FindMin( SearchTree T )
{
    if ( T == NULL )
        return NULL;
    if ( T->Left != NULL )
        return FindMin(T->Left);
    else
        return T;

}

Position FindMax( SearchTree T )
{
    if ( T == NULL )
        return NULL;
    while( T->Right != NULL )
    {
        T = T->Right;
    }
    return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    //入参检查
    //如果为空指针则新建树并赋值
    //如果不为空指针则对比元素分别递归
    if ( T != NULL )
    {
        if ( X < T->Left )
            T->Left = Insert( X, T->Left );
        else if ( X > T->Right )
            T->Right = Insert( X, T->Right );
    }
    else
    {
        T = malloc( sizeof( struct TreeNode ) );
        if ( T == NULL )
        {
            printf("cannot create TreeNode.");
            return NULL;
        }
        T->Element = X;
        T->Left = T->Right = NULL;
    }

    return T;
}
























