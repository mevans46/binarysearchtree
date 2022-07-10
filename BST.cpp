//
//  BST.cpp
//  BinarySearchTree
//
//  Created by M E on 10/16/21.
//

#include <stdio.h>
#include <iostream>
#include "BST.h"


/*
 Function: findEmpty()
 Parameters: currentNode, node to insert
 Description: if the left is null and the value is less than current node, insert left. otherwise call findempty on left node.(recursion.)
 */
void BST::findEmpty(Node* currentNode, Node* nodeToInsert){
    if(currentNode->data < nodeToInsert->data){
        if(currentNode->right==NULL){
            currentNode->right = nodeToInsert;
        }
        else{
            findEmpty(currentNode->right, nodeToInsert);
        }
    }
    else{
        if(currentNode->left==NULL){
            currentNode->left = nodeToInsert;
        }
        else{
            findEmpty(currentNode->left, nodeToInsert);
        }
    }
    
}

/*
 Function: Insert()
 Parameters: Value to insert
 Description: If no head exists head becomes new node, otherwise recurse through tree to find next available pointer.
 */
void BST::Insert(int value){
    Node* newNode = new Node(value);
    if(head ==NULL){
        head = newNode;
    }
    else{
        findEmpty(head, newNode);
    }
}
/*
 Function: getHead()
 Parameters: none
 Description: returns the head
 */
Node* BST::getHead(){
    return head;
}


/*
 Function: inorder()
 Parameters: the current node
 Description: if the node is not null, go to the left most node and work way up.
 */
void BST::Inorder(Node* node){
    
    if(node!=NULL){
        Inorder(node->left);
        std::cout << node->data << " ";
        Inorder(node->right);
    }
    
}
void BST::Inorder(){
    Inorder(getHead());
}

/*
 Function: findMaximum()
 Parameters: current node
 Description: goes through the right tree until the max is found
 */
Node* BST::findMaximum(Node* node){
    if(node==NULL){
        return NULL;
    }
    if(node->right != NULL){
        return findMaximum(node->right);
    }
    return node;
}

Node* BST::findMaximum(){
    return findMaximum(getHead());
}

/*
 Function: removeNode()
 Parameters: Value to remove
 Description: deletes and or replaces the deleted node with the next highest value
 */

Node* BST::removeNode(int x){
    Node* _node = getHead();
    Node* removed = removeNode(_node,x);
    //the node was not found for removal
    if(removed==nullptr){
        std::cout << "";
        head = nullptr;
    }
    return removed;
}

Node* BST::removeNode(Node *root, int x){
    Node* temp;
    if(root == NULL){
        return NULL;
    }
    else if(x == root->data && (root->left ==NULL && root->right==NULL)){
        
        return nullptr;
    }
    else if(x <= root->data){
        root->left = removeNode(root->left, x);
    }
    else if(x > root->data){
        root->right = removeNode(root->right, x);
    }
    
    else if(root->left && root->right){
        temp = findMaximum(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, root->data);
    }
    else{
        
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        
    }
    return root;
}
