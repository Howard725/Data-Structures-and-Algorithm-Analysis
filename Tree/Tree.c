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
        if ( X < T->Element )
            T->Left = Insert( X, T->Left );
        else if ( X > T->Element )
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

SearchTree Delete( ElementType X, SearchTree T )
{
    SearchTree temp;
    ElementType RightMin;
    //检查参数有效性
    if ( T == NULL )
        return NULL;
    //较小，从左子树中删除
    if ( X < T->Element )
        T->Left = Delete( X, T->Left );
    else if ( X > T->Element ) //较大，从右子树中删除
        T->Right = Delete( X, T->Right );
    else
    {
        if ( T->Right == NULL || T->Left == NULL )
        {
            temp = T;
            if ( T->Right == NULL )
                T = T->Left;
            else if ( T->Left == NULL )
                T = T->Right;
            else
                T = NULL;

            free(temp);
        }
/*        //相等，则判断是否只有一个儿子
        if ( T->Right == NULL && T->Left == NULL )
        {
            free(T);
            return NULL;
        }
        else if ( T->Right == NULL && T->Left != NULL )
        {
            temp = T->Left;
            free(T);
            return temp;
        }
        else if ( T->Right != NULL && T->Left == NULL )
        {
            temp = T->Right;
            free(T);
            return temp;
        }//如果只有一个儿子，则释放自己返回儿子*/
        else
        {
            temp = FindMin(T->Right);
            RightMin = temp->Element;
            T->Element = RightMin;
            T->Right = Delete(RightMin, T->Right);
        }//如果有两个儿子，赋值为右子树的最小值并递归删除右子树的最小值，返回自身
    }
    return T;
}

ElementType Retrieve( Position P )
{
    //检查参数有效性

    return P->Element;
}





















