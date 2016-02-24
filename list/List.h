//
// Created by Administrator on 2016/2/23.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

/* operations */
/* Basic Operations: PrintList, MakeEmpty, Find, FindKth, Insert, Delete */
/* ElementType = int */
void PrintList( List L );
List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( int X, List L );
void Delete( int X, List L );
Position FindPrevious( int X, List L );
void Insert( int X, List L, Position P);
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
int Retrieve( Position P );

#endif //LIST_LIST_H
