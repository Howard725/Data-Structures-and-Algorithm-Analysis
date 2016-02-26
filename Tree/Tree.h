//
// Created by Administrator on 2016/2/26.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve( Position P );

struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

#endif //TREE_TREE_H
