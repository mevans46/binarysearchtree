//
//  BST.h
//  BinarySearchTree
//
//  Created by M E on 10/16/21.
//

#ifndef BST_h
#define BST_h
#include "Node.h"


class BST{
private:
    Node* head = NULL;
    void findEmpty(Node* currentNode, Node* nodeToInsert);
    Node* getHead();
public:
    BST(void) { head = NULL; }
    
    void Insert(int value);
    void Inorder(Node* root);
    void Inorder();
    Node* findMaximum(Node* root);
    Node* findMaximum();
    Node* removeNode(int x);
    Node* removeNode(Node * root, int x);
    
};





#endif /* BST_h */
