#ifndef _B_TREE_LINK_H
#define _B_TREE_LINK_H

#include "binaryTreeNode.hpp"
#include "..\chapter6\chain.h"
#include "..\chapter8\arrayStack.h"
#include "..\chapter9\arrayQueue.h"
#include "..\exception\myExceptions.h"


template <typename T>
void visit(binaryTreeNode<T> *t)
{
    std::cout << t->element << " ";
}


template <typename T>
void preOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr){
        visit(t);
        preOrder(t->leftchild);
        preOrder(t->rightchild);
    }
}


template <typename T>
void preOrderRe(binaryTreeNode<T> *t)
{
    preOrder(t);
    std::cout << std::endl;
}


template <typename T>
void preOrderIter(binaryTreeNode<T> *t)
{
    if (t == nullptr){return;}
    arrayStack< binaryTreeNode<T>* > st;
    st.push(t);
    while (!st.empty()){
        t = st.top();
        visit(t);
        st.pop();
        if (t->rightchild){
            st.push(t->rightchild);}
        if (t->leftchild){
            st.push(t->leftchild);}
    }
   
    /* 
    arrayStack< binaryTreeNode<T>* > s;
    binaryTreeNode<T>* root = t;
    while (true){
        visit(t);
        if (t->leftchild){
            s.push(t);
            t = t->leftchild;
            continue;
        }
        else if(t->rightchild){
            t = t->rightchild;
            continue;
        }
        else{
            if (s.empty()) {return;}
            t = s.top(); s.pop();
            if (t->rightchild){
                t = t->rightchild;
                continue;
            }
            else{
                return;
            }
        }
    }
    */
}


template <typename T>
void infix(binaryTreeNode<T> *t)
/* 
 * inOrder traversal and add '(' and ')'
 */
{
    if (t != nullptr){
        std::cout << "(";
        infix(t->leftchild);
        visit(t);
        infix(t->rightchild);
        std::cout << ")";
    }
}


template <typename T>
void inOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr){
        inOrder(t->leftchild);
        visit(t);
        inOrder(t->rightchild);
    }
    return;
}


template <typename T>
void inOrderRe(binaryTreeNode<T> *t)
{
    inOrder(t);
    std::cout << std::endl;
}


template <typename T>
void inOrderIter(binaryTreeNode<T> *t)
{
    if (t == nullptr){return;}
    arrayStack< binaryTreeNode<T>* > st;

    while (!st.empty() or t != nullptr){
        while (t != nullptr){
            st.push(t);
            t = t->leftchild;
        }
        t = st.top(); visit(t); st.pop();
        t = t->rightchild;
    }
    /*
    while (true)
    {
        if (t->leftchild != nullptr){
            st.push(t);
            t = t->leftchild;
            continue;
        }
        else if (t->rightchild != nullptr) {
            visit(t);
            t = t->rightchild;
            continue;
        }else{
            visit(t);
            if (st.empty() == true){
                return;
            }
            t = st.top();
            st.pop();
            visit(t);
            if (t->rightchild != nullptr){
                t = t->rightchild;
            }
        }
    }
    return; */
}


template <typename T>
void inOrderAddress(binaryTreeNode<T> *t)
{
    if (t != nullptr){
        inOrderAddress(t->leftchild);
        std::cout << t << " ";
        inOrderAddress(t->rightchild);
    }
    return;
}


template <typename T>
void postOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr) {
        postOrder(t->leftchild);
        postOrder(t->rightchild);
        visit(t);
    }
    return;
}


template <typename T>
void postOrderRe(binaryTreeNode<T> *t)
{
    postOrder(t);
    std::cout << std::endl;
}


template <typename T>
void postOrderIter(binaryTreeNode<T> *t)
{
    if (t == nullptr) {return;}
    binaryTreeNode<T>* root = t;
    arrayStack< binaryTreeNode<T>* > st;

    while (!st.empty() or t == root){
        while (t != nullptr){
            if (t->rightchild) {st.push(t->rightchild);}
            st.push(t);
            t = t->leftchild;
        }
        t = st.top(); st.pop();
        if (t->rightchild != nullptr
            and !st.empty()
            and t->rightchild == st.top())
        {
            st.pop();  // delete right node from stack
            st.push(t);  // push back the middle node
            t = t->rightchild;
        }
        else{
            visit(t);
            t = nullptr;
        }
    }
}


template <typename T>
void levelOrder(binaryTreeNode<T> *t)
{
    arrayQueue< binaryTreeNode<T>* > q;
    while(t != nullptr){
        visit(t);
        if (t->leftchild != nullptr){
            q.push(t->leftchild);
        }
        if (t->rightchild != nullptr){
            q.push(t->rightchild);
        }

        try{
            t = q.front();
        }
        catch(queueEmpty) {
            return;
        }
        q.pop();
    }
}


template <typename T>
binaryTreeNode<T>* copy_node(binaryTreeNode<T>* t)
{
    binaryTreeNode<T> *new_root =
        new binaryTreeNode<T>(t->element, t->leftchild, t->rightchild);
    return new_root;
}


template <typename T>
binaryTreeNode<T>* preOrderCopy(binaryTreeNode<T>* t)
{
    typedef binaryTreeNode<T> t_node;

    if (t != nullptr){
        t_node *new_node = new t_node(t->element);
        new_node->leftchild = preOrderCopy(t->leftchild);
        new_node->rightchild = preOrderCopy(t->rightchild);
        return new_node;
    }else{
        return nullptr;
    }
}


template <typename T>
binaryTreeNode<T>* postOrderCopy(binaryTreeNode<T>* t)
{
    typedef binaryTreeNode<T> t_node;

    // TODO
    return nullptr;
}


template <typename T>
int countLevel(binaryTreeNode<T>* t, int nowLevel = 1)
{
    if (t != nullptr){
        int num = std::max(countLevel(t->leftchild, nowLevel),
                           countLevel(t->rightchild, nowLevel));
        return nowLevel + num;
    }else{
        return 0;
    }
}


template <typename T>
int countNodes(binaryTreeNode<T>* t)
/*  
 *  Return the sum of t and it's childnodes numbers
 */
{
    if (t != nullptr){
        return 1
               + countNodes(t->leftchild)
               + countNodes(t->rightchild);
    }else{
        return 0;
    }
}


template <typename T, typename K>
void traveCount(binaryTreeNode<T>* t, Chain<K>& ch, int numLevel)
{
    if (t != nullptr){
        if (numLevel > ch.size()){
            try{
                ch.insert(ch.size(), 1);
                // ch.insert(numLevel, 1);  // ERROR
            }
            catch(int& i){
                std::cerr << i << '\n';
            }
        }else{
            try{
                ch[numLevel-1]++;
            }
            catch(int& i){
                std::cerr << i << '\n';
            }
            
        }
        traveCount(t->leftchild, ch, numLevel + 1);
        traveCount(t->rightchild, ch, numLevel + 1);
    }else{
        return;
    }
}


template <typename T>
int maxNodesLevel(binaryTreeNode<T>* t)
{
    arrayQueue< binaryTreeNode<T>* > q;
    Chain<int> ch;

    traveCount(t, ch, 1);
    std::cout << "\n" << ch << std::endl;

    // Return the level with max number of nodes
    int c_max, index_max = 0;
    if (ch.empty()){
        throw "Chain is empty";
    }
    c_max = ch[0];
    for (int i=0; i < ch.size(); i++){
        if (ch[i] > c_max){
            c_max = ch[i]; index_max = i;
        }
    }
    return index_max + 1;
}



template <typename T>
binaryTreeNode<T>* preIn2Tree(T* preOrder, T* inOrder, int num)
{
    typedef binaryTreeNode<T> bt;
    bt *root = nullptr,
       *leftRoot = nullptr,
       *rightRoot = nullptr;

    // end of recursion
    if (num == 0) {return nullptr;}
    else if (num == 1) {
        root = new bt(preOrder[0]);
        return root;
    }
    else if (num == 2){
        if (preOrder[0] == inOrder[0]){
            rightRoot = new bt(preOrder[1]);
            root = new bt(preOrder[0], nullptr, rightRoot);
        }
        else{
            leftRoot = new bt(preOrder[1]);
            root = new bt(preOrder[0], leftRoot, nullptr);
        }
        return root;
    }

    int iSplit = 0;
    while (inOrder[iSplit] != preOrder[0]){
        iSplit++;
    }
    leftRoot = preIn2Tree(preOrder + 1, inOrder, iSplit);
    rightRoot = preIn2Tree(preOrder + iSplit + 1,
                           inOrder + iSplit + 1,
                           num - iSplit - 1);
    root = new bt(preOrder[0], leftRoot, rightRoot);
    return root;
}


template <typename T>
binaryTreeNode<T>* prePost2Tree(T* preOrder, T* postOrder, int num)
{
    throw "NO WAY!";
}


template <typename T>
binaryTreeNode<T>* inPost2Tree(T* inOrder, T* postOrder, int num)
{
    typedef binaryTreeNode<T> bt;
    bt *root = nullptr,
       *leftRoot = nullptr,
       *rightRoot = nullptr;

    if (num == 0){
        return nullptr;
    }
    else if (num == 1){
        root = new bt(inOrder[0]);
        return root;
    }
    else if (num == 2){
        if (inOrder[0] == postOrder[0]){
            leftRoot = new bt(inOrder[0]);
            root = new bt(inOrder[1], leftRoot, rightRoot);
        }
        else{
            rightRoot = new bt(postOrder[0]);
            root = new bt(inOrder[0], leftRoot, rightRoot);
        }
        return root;
    }

    int iSplit = 0;
    while (inOrder[iSplit] != postOrder[num - 1]){
        iSplit++;
    }
    leftRoot = inPost2Tree(
        inOrder, postOrder, iSplit
    );
    rightRoot = inPost2Tree(
        inOrder + iSplit + 1,
        postOrder + iSplit,
        num - iSplit - 1
    );
    root = new bt(postOrder[num - 1], leftRoot, rightRoot);
    return root;
}


#endif