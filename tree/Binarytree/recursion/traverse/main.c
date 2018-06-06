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

void Recursion1(BinaryNode* root);
void Recursion2(BinaryNode* root);
void Recursion3(BinaryNode* root);

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

    //递归遍历
    printf("先序：");
    Recursion1(&node1);
    printf("\n中序：");
    Recursion2(&node1);
    printf("\n后序：");
    Recursion3(&node1);
    printf("\n");

}
//先序
void Recursion1(BinaryNode* root)
{
    if(root == NULL)
        return;

    //先访问根
    printf("%c",root->c);

    //再遍历左子树
    Recursion1(root->lchild);
    //再遍历右子树
    Recursion1(root->rchild);
}
//中序
void Recursion2(BinaryNode* root)
{
    if(root == NULL)
        return;

    //遍历左子树
    Recursion2(root->lchild);
    //访问根
    printf("%c",root->c);
    //再遍历右子树
    Recursion2(root->rchild);
}
//后序
void Recursion3(BinaryNode* root)
{
    if(root == NULL)
        return;

    //遍历左子树
    Recursion3(root->lchild);
    //再遍历右子树
    Recursion3(root->rchild);
    //访问根
    printf("%c",root->c);
}

int main()
{
    Create_BinaryTree();
    return 0;
}
