/*创建树，如果孩子为NULL，用#代替
 *例如：AB#D##C##
 先序打印为：ABDC
 * */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//二叉树结点
typedef struct BINARYNODE
{
    char c;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root)
{
    if(root == NULL)
        return;
    
    printf("%c",root->c);
    Recursion(root->lchild);
    Recursion(root->rchild);
}

BinaryNode* CreateBinaryTree()
{
    fflush(stdin);
    char c;
    scanf("%c",&c);

    BinaryNode* node;
    if(c == '#')
        node = NULL;
    else
    {
        node = (BinaryNode*)malloc(sizeof(BinaryNode));
        node->c = c;
        node->lchild = CreateBinaryTree();
        node->rchild = CreateBinaryTree();
    }

    return node;
}

int main()
{
    BinaryNode* root = CreateBinaryTree();
    Recursion(root);
    printf("\n");
    return 0;
}
