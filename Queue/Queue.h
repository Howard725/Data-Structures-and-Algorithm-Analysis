//
// Created by Administrator on 2016/2/26.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );

#define MinQueueSize ( 0 )

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

#endif //QUEUE_QUEUE_H
