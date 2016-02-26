//
// Created by Administrator on 2016/2/25.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

/* ElementType = int */
int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( int X, Stack S );
int Top( Stack S );
void Pop( Stack S );

/* 为了在其他源文件中可用 */
struct Node{
    int Element;
    PtrToNode Next;
};

#endif //STACK_STACK_H
