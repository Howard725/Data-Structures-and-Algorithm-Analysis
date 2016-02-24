//
// Created by Administrator on 2016/2/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main() {

    int n = 10; /* number of list's elements */
    int i = 0;
    List L = malloc( sizeof(struct Node) );
    List L2 = malloc( sizeof(struct Node) );
    Position P = L;
    Position P2 = L2;

    L = MakeEmpty( L );
    L2 = MakeEmpty( L2 );

    /* test 插入1-10 十个数字 */
    for( i = 1; i <= n; ++i )
    {
        Insert(i, L, P);
        Insert(i, L2, P2);
        P = P->Next;
        P2 = P2->Next;
    }

    PrintList(L);

    /* 第一个元素插入0 */
    printf("\n第一个元素插入0:\n");
    Insert(0, L, L);
    PrintList(L);

    /* find测试 */
    printf("\nfind测试\n");
    PrintList(Find(5, L));

    /* Delete测试 */
    printf("\ndelete测试\n");
    Delete( 6, L);
    PrintList(L);

    /* Retrieve测试 */
    printf("\nRetrieve测试\n");
    printf("%d", Retrieve(L->Next));

    /* DeleteList测试 */
    printf("\nDeleteList测试\n");
    DeleteList(L);
    PrintList(L);

    /* DeleteList Recursice测试 */
    printf("\nDeleteList_Recur测试\n");
    DeleteList_Recur(L2);
    PrintList(L2);

    system("PAUSE");

    return 0;
}











