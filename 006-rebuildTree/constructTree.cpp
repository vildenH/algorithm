#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    binaryTreeNode *m_pRight;
};
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
BinaryTreeNode *ConstructCore(int *startPreorder,int *endPreorder,int* startInorder,int *endInorder)
