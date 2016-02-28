//
// Created by Administrator on 2016/2/26.
//

#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

int main()
{
    int i = 0;
    SearchTree T = NULL;
    Position P = NULL;

    for ( i = 5; i < 10; ++i )
        T = Insert(i, T);

    for ( i = 0; i < 5; ++i )
        T = Insert(i, T);

    P = FindMin(T);
    if ( P == NULL )
        printf("cannot find min Element.");
    else
        printf("%d\n", P->Element );

    P = FindMax(T);
    if ( P == NULL )
        printf("cannot find max Element.");
    else
        printf("%d\n", P->Element );

    P = Find( 0, T );
    if ( P == NULL )
        printf("cannot find 0 in the tree.");
    else
        printf("%d\n", Retrieve(P) );

    for ( i = 0; i < 10; ++i )
        T = Delete(i, T);



    system("PAUSE");
    return 0;
}