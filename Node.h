//
//  Node.h
//  BinarySearchTree
//
//  Created by M E on 10/16/21.
//

#ifndef Node_h
#define Node_h
class Node {
public:
    int data;
    Node* right;
    Node* left;
    
    Node(int value){
        data = value;
        right = NULL;
        left = NULL;
    }
};




#endif /* Node_h */
