#ifndef _BT_NODE_H
#define _BT_NODE_H

#include <iostream>

template <typename T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftchild,
                      *rightchild;

    binaryTreeNode() {leftchild = rightchild = nullptr;}
    binaryTreeNode(const T& theElement)
    : element(theElement)
    {
        leftchild = rightchild = nullptr;
    }
    binaryTreeNode(const T& theElement,
                   binaryTreeNode *theLeftChild,
                   binaryTreeNode *theRightChild)
    : element(theElement)
    {
        leftchild = theLeftChild;
        rightchild = theRightChild;
    }

    ~binaryTreeNode() {
        if (leftchild){
            delete leftchild;
        }
        if (rightchild){
            delete rightchild;
        }
        std::cout << "Delete: " << element << std::endl;
    }
};

#endif