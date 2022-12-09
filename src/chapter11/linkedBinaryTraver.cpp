#include "linkedBinaryTraver.hpp"

binaryTreeNode<char>* gen_tree_1()
/* 
 * generate a binaryTree,
 * return a pointer to it's root node
 *              '+'  --> root
 *             /   \
 *           '*'   '/'
 *          /  \   /  \
 *        'a' 'b' 'c' 'd'
 *        /   /
 *      '?' '`'
 */
{
    typedef binaryTreeNode<char> bt;
    bt *n0_1 = new bt('?'), *n0_2 = new bt('`'),
       *n1_1 = new bt('a', n0_1, nullptr),
       *n1_2 = new bt('b', n0_2, nullptr),
       *n1_3 = new bt('c'), *n1_4 = new bt('d'),
       *n2_1 = new bt('*', n1_1, n1_2),
       *n2_2 = new bt('/', n1_3, n1_4),
       *n3_1 = new bt('+', n2_1, n2_2);

    return n3_1;
}

binaryTreeNode<char>* gen_tree_2()
/* 
 * generate a binaryTree,
 * return a pointer to it's root node
 *              '+'  --> root
 *             /  \
 *           'c'  'a'
 *                  \
 *                  '*'
 *                    \
 *                    'b'
 */
{
    typedef binaryTreeNode<char> bt;
    bt *n1_1 = new bt('b'),
       *n2_1 = new bt('*', nullptr, n1_1),
       *n3_1 = new bt('a', nullptr, n2_1), *n3_2 = new bt('c'),
       *n4_1 = new bt('+', n3_2, n3_1);

    return n4_1;
}

void test_1()
{
    typedef binaryTreeNode<char> bt;
    bt *root = gen_tree_1();
    bt *root2 = gen_tree_2();

    std::cout << "preOrder:     ";
    preOrder(root);
    std::cout << std::endl;
    std::cout << "preOrderIter: ";
    preOrderIter(root);
    std::cout << std::endl;
    std::cout << "inOrder:      ";
    inOrder(root);
    std::cout << std::endl;
    std::cout << "inOrderIter:  ";
    inOrderIter(root);
    std::cout << std::endl;
    std::cout << "infix:        ";
    infix(root);
    std::cout << std::endl;
    std::cout << "postOrder:    ";
    postOrder(root);
    std::cout << std::endl;
    std::cout << "postOrderIter:";
    postOrderIter(root);
    std::cout << std::endl;
    std::cout << "levelOrder:   ";
    levelOrder(root);

    std::cout << "\n****************************" << std::endl;
    std::cout << "preOrder:     ";
    preOrder(root2);
    std::cout << std::endl;
    std::cout << "preOrderIter: ";
    preOrderIter(root2);
    std::cout << std::endl;
    std::cout << "inOrder:      ";
    inOrder(root2);
    std::cout << std::endl;
    std::cout << "inOrderIter:  ";
    inOrderIter(root2);
    std::cout << std::endl;
    std::cout << "infix:        ";
    infix(root2);
    std::cout << std::endl;
    std::cout << "postOrder:    ";
    postOrder(root2);
    std::cout << std::endl;
    std::cout << "postOrderIter:";
    postOrderIter(root2);
    std::cout << std::endl;
    std::cout << "levelOrder:   ";
    levelOrder(root2);
    std::cout << "\n########Test_1: Done########" << std::endl;
}

void test_2()
{
    typedef binaryTreeNode<char> bt;
    bt *root = gen_tree_1();
    bt *root_2 = preOrderCopy(root);
    inOrderAddress(root);
    // inOrder(root);
    std::cout << std::endl;
    inOrderAddress(root_2);
    // inOrder(root_2);
    std::cout << "\n########Test_2: Done########" << std::endl;
}

void test_3()
{
    typedef binaryTreeNode<char> bt;

    bt *root = gen_tree_1();
    bt *root_2 = gen_tree_2();

    std::cout << countLevel(root) << " ";
    std::cout << countLevel(root_2) << " ";
    std::cout << countNodes(root) << " ";
    std::cout << countNodes(root_2) << " ";
    std::cout << "\n########Test_3: Done########" << std::endl;
}

void test_4(){
    typedef binaryTreeNode<char> bt;

    bt *root = gen_tree_1();
    bt *root_2 = gen_tree_2();

    std::cout << maxNodesLevel(root);
    std::cout << maxNodesLevel(root_2);
    std::cout << "\n########Test_4: Done########" << std::endl;
}

void test_5(){
    char preList[] = {'+', '*', 'a', '?', 'b', '`', '/', 'c', 'd'},
         inList[] = {'?', 'a', '*', '`', 'b', '+', 'c', '/', 'd'},
         postList[] = {'?', 'a', '`', 'b', '*', 'c', 'd', '/', '+'},
         preList2[] = {'+', 'c', 'a', '*', 'b'},
         inList2[] = {'c', '+', 'a', '*', 'b'},
         postList2[] = {'c', 'b', '*', 'a', '+'};
    void (*fArray[])(binaryTreeNode<char>*)
        = {preOrderRe, inOrderRe, postOrderRe};
    binaryTreeNode<char>
        *tree_1 = gen_tree_1(),
        *tree_2 = gen_tree_2(),
        *root_1 = preIn2Tree (preList, inList,
                        sizeof(preList) / sizeof(preList[0])),
        *root_1_2 = inPost2Tree(inList, postList,
                        sizeof(inList) / sizeof(inList[0])),
        *root_2 = preIn2Tree(preList2, inList2,
                        sizeof(preList2) / sizeof(preList2[0])),
        *root_2_2 = inPost2Tree(inList2, postList2,
                        sizeof(inList2) / sizeof(inList2[0]));
    for (int i = 0; i < 3; i++){
        fArray[i](tree_1);
        fArray[i](root_1);
        fArray[i](root_1_2);
        fArray[i](tree_2);
        fArray[i](root_2);
        fArray[i](root_2_2);
    }
    delete tree_1; delete tree_2;
    delete root_1; delete root_1_2;
    delete root_2; delete root_2_2;
}


int main()
{
    // test_1();
    // test_2();
    // test_3();
    // test_4();
    test_5();
}