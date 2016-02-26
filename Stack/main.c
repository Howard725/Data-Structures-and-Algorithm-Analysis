//
// Created by Administrator on 2016/2/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Stack_Array.h"

void Stack_test(){

    Stack S = CreateStack();
    int i = 0;
    int top_ele = 0;

    for ( i = 1; i <= 10; ++i )
    {
        Push(i, S);
        top_ele = Top(S);
        printf("%d\n", top_ele);
    }

    for ( i = 1; i <= 11; ++i )
    {
        top_ele = Top(S);
        printf("%d\n", top_ele);
        Pop(S);
    }

    DisposeStack(S);

}

void Stack_Array_test(){

    Stack_Array S = CreateStack_Array( 100 );
    int i = 0;
    int top_ele = 0;

    for ( i = 1; i <= 10; ++i )
    {
        Push_Array(i, S);
        top_ele = Top_Array(S);
        printf("%d\n", top_ele);
    }

    for ( i = 1; i <= 11; ++i )
    {
        top_ele = TopAndPop_Array(S);
        printf("%d\n", top_ele);
    }

    DisposeStack_Array(S);

}

int main(){

    printf("Stack_test()\n");
    Stack_test();

    printf("\nStack_Array_test()\n");
    Stack_Array_test();

    system("PAUSE");
    return 0;
}