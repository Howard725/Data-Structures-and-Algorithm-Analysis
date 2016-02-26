//
// Created by Administrator on 2016/2/26.
//

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue Q = CreateQueue( 10 );
    int i = 0;
    int front = 0;

    if ( Q == NULL )
    {
        printf("create Queue failed.");
        return -1;
    }

    for ( i = 0; i <= 10; i++ )
    {
        Enqueue(i, Q);
        front = Front(Q);
        if ( front != -1 )
            printf("%d\n", front );
    }
    printf("\n");

    for ( i = 0; i<= 10; i++ )
    {
/*        front = Front(Q);
        if ( front != -1 )
            printf("%d\n", front );
        Dequeue(Q);*/
        front = FrontAndDequeue(Q);
        if ( front != -1 )
            printf("%d\n", front );
    }
    printf("\n");

    system("PAUSE");
    return 0;
}

