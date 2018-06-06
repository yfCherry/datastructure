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

//求二叉树的高度
int CalculateTreeDepth(BinaryNode* root)
{
    if(root == NULL)
        return 0;

    int depth = 0;
    //求左子树的高度
    int lDepth = CalculateTreeDepth(root->lchild);
    //求右子树的高度
    int rDepth = CalculateTreeDepth(root->rchild);
    //比较左右高度 保存较大者
    depth = lDepth>=rDepth ? lDepth+1 :rDepth+1;

    return depth;
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
    
    int depth = CalculateTreeDepth(&node1);
    printf("depth:%d\n",depth);


}
int main()
{
    Create_BinaryTree();
    return 0;
}
