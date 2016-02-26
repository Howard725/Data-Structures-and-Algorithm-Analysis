//
// Created by Administrator on 2016/2/25.
//

#ifndef STACK_STACK_ARRAY_H
#define STACK_STACK_ARRAY_H

struct StackRecord;
typedef struct StackRecord *Stack_Array;

/* ElementType = int */
int IsEmpty_Array( Stack_Array S );
int IsFull_Array( Stack_Array S );
Stack_Array CreateStack_Array( int Capacity );
void DisposeStack_Array( Stack_Array S );
void MakeEmpty_Array( Stack_Array S );
void Push_Array( int X, Stack_Array S );
int Top_Array( Stack_Array S );
void Pop_Array( Stack_Array S );
int TopAndPop_Array( Stack_Array S );

#define EmptyTOS ( -1 )
#define MinStackSize ( 0 )

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int *Array;
};

#endif //STACK_STACK_ARRAY_H
