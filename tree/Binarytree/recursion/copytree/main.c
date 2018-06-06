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

//遍历二叉树
void Recursion(BinaryNode* root)
{
    if(root == NULL)
        return;

    //根
    printf("%c",root->c);
    //左孩子
    Recursion(root->lchild);
    //右孩子
    Recursion(root->rchild);
}

//拷贝二叉树
BinaryNode* CopyTree(BinaryNode* root)
{
    if(root == NULL)
        return NULL;

    //拷贝左子树
    BinaryNode* lchild = CopyTree(root->lchild);
    //拷贝右子树
    BinaryNode* rchild = CopyTree(root->rchild);

    //创建结点
    BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
    newnode->c = root->c;
    newnode->lchild = lchild;
    newnode->rchild = rchild;

    return newnode;

}

void FreeSpace_Tree(BinaryNode* root)
{
    if(root == NULL)
        return;

    FreeSpace_Tree(root->lchild);
    FreeSpace_Tree(root->rchild);
    free(root);
}
//构造二叉树并遍历
void Create_BinaryTree()
{
    //创建结点
    BinaryNode node1 = {'A',NULL,NULL};
    BinaryNode node2 = {'B',NULL,NULL};
    BinaryNode node3 = {'C',NULL,NULL};
    BinaryNode node4 = {'D',NULL,NULL};
    BinaryNode node5 = {'E',NULL,NULL};
    BinaryNode node6 = {'F',NULL,NULL};
    BinaryNode node7 = {'G',NULL,NULL};
    BinaryNode node8 = {'H',NULL,NULL};
    BinaryNode node9 = {'I',NULL,NULL};

    //建立结点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;
    node7.rchild = &node9;

    BinaryNode* node = CopyTree(&node1);
    Recursion(&node1);
    printf("\n");
    Recursion(node);
    printf("\n");

    FreeSpace_Tree(node);
}


int main()
{
    Create_BinaryTree();
    return 0;
}
