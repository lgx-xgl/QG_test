#pragma once
#pragma once
//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define Status int
#define SUCCESS 1
#define FAILED 0

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>


using namespace std;

typedef int ElemType;

typedef struct Node {
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
    NodePtr root;
    int count;
} BinarySortTree, * BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);                         //��������

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr, ElemType);                      //����һ����

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr, ElemType);                   //ɾ��һ����

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_Search(BinarySortTreePtr, ElemType);                      //����һ����
NodePtr BST_search(BinarySortTreePtr, ElemType, int*);                      //����һ����������������λ��

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));    //ǰ������ĵݹ�д��
void BST_preorderI_pro(NodePtr p_now, void (*visit)(NodePtr));
/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr));   //ǰ�������ջд��

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));         //��������ĵݹ�
void BST_inorderI_pro(NodePtr p_now, void (*visit)(NodePtr));
/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr));         //���������ջ

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));       //��������ĵݹ�
void BST_postorderI_pro(NodePtr p_now, void (*visit)(NodePtr));
/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr));       //���������ջ

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));       //�������

int CIN();
void COUT(NodePtr o);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H