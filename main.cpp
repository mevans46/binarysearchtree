//
//  main.cpp
//  BinarySearchTree
//
//  Created by M E on 10/16/21.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Node.h"
#include "BST.h"

using namespace std;

int main(int argc, const char * argv[]) {
    srand( (unsigned)time(NULL) );
    
    
    BST* bst = new BST();
    //for(int i=0;i<100000;i++){
     //   bst->Insert(rand() % 100 + 1);
    //}
    //Test Removing a node from an empty binary search tree
    bst->removeNode(8);
    //test insert node
    bst->Insert(5);
    //Test removing the head after its created
    bst->removeNode(5);
    //test inorder
    cout << "The Inorder is: ";
    bst->Inorder();
    cout << endl;
    
    bst->Insert(3);
    //Test Removing a nonexistent node from a binary search tree
    bst->removeNode(8);
    bst->Insert(4);
    bst->Insert(8);
    //test Duplicate entry(allowed)
    bst->Insert(8);
    cout << "The Inorder is: ";
    bst->Inorder();
    cout << endl;
    bst->removeNode(8);
    bst->Insert(10);
    bst->Insert(32);
    bst->Insert(1);
    cout << "The Inorder is: ";
    bst->Inorder();
    cout << endl;
    
    //test max number
    Node* max;
    max = bst->findMaximum();
    cout << "\n";
    cout << "The max number is: " << max->data << endl;
    cout << "\n";
    return 0;
}
