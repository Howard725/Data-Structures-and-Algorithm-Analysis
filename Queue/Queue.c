//
// Created by Administrator on 2016/2/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int IsEmpty( Queue Q )
{
    //需要增加对入参（指针）的检查

    return Q->Size == 0;
}

int IsFull( Queue Q )
{
    //需要增加对入参（指针）的检查

    return Q->Size == Q->Capacity;
}

Queue CreateQueue( int MaxElements )
{
    Queue Q = NULL;

    if( MaxElements < MinQueueSize )
    {
        printf("MaxElements is illegal.");
        return NULL;
    }

    Q = malloc(sizeof( struct QueueRecord ));
    if ( Q == NULL )
    {
        printf("cannot create Queue.");
        return NULL;
    }
    Q->Array = malloc( MaxElements * sizeof(ElementType));
    if ( Q->Array == NULL )
    {
        printf("cannot create Queue Array.");
        return NULL;
    }

    Q->Capacity = MaxElements;
    MakeEmpty(Q);

}

void DisposeQueue( Queue Q )
{
    //需要增加对入参（指针）的检查

    free(Q->Array);
    free(Q);
}

void MakeEmpty( Queue Q )
{
    Q->Front = 1;
    Q->Rear = 0;
    Q->Size = 0;
}

int Succ( int val, Queue Q )
{
    if ( ++val == Q->Capacity )
        return 0;
    return val;
}

void Enqueue( ElementType X, Queue Q )
{
    //检查参数有效性

    //检查队列是否满
    if ( IsFull( Q ) )
    {
        printf("Queue is Full.");
        return;
    }

    //循环移动Rear
//    Q->Rear = ( Q->Rear + 1 ) % Q->Capacity;
    Q->Rear = Succ( Q->Rear, Q );
    //将X放入
    Q->Array[Q->Rear] = X;
    Q->Size ++;
}

ElementType Front( Queue Q )
{
    //检查参数有效性
    //检查是否为空
    if ( IsEmpty(Q) )
    {
        printf("Queue is empty.");
        return -1;
    }
    return Q->Array[Q->Front];
}

void Dequeue( Queue Q )
{
    //检查参数有效性

    //检查是否为空
    if( IsEmpty(Q) )
    {
        printf("Queue is empty.");
        return;
    }
    //移动Front，更新size
    Q->Front = Succ( Q->Front, Q );
    Q->Size --;
}

ElementType FrontAndDequeue( Queue Q )
{
    int temp = 0;
    //检查参数有效性

    //检查是否为空
    if( IsEmpty(Q) )
    {
        printf("Queue is empty.");
        return -1;
    }
    temp = Q->Array[Q->Front];

    //移动Front，更新size
    Q->Front = Succ( Q->Front, Q );
    Q->Size --;

    return temp;
}













