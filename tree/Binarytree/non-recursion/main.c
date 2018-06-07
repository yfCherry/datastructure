/*二叉树的非递归遍历（先序）：
 * 1采用栈的数据结构，对于每一个结点附带一个标志位，起始值为0，先拿到根结点将其入栈
 * 2如果栈中有结点，弹出栈顶结点，判断标志，根据标志转3或4；如果没有结点，转5
 * 3如果标志为1则输出，再去判断下一个栈中的栈顶结点，转2
 * 4如果标志是0，将其标志为1，取树中其孩子结点，无孩子置为NULL，并按照右孩子、左孩子、双亲结点的顺序入栈，转2
 * 5直到最后结束。
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkstack.h"

#define MY_FALSE 0
#define MY_TRUE 1

//二叉树结点
typedef struct BINARYNODE
{
    char c;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//二叉树的非递归遍历
typedef struct BITREESTACKNODE
{
    LinkNode node;
    BinaryNode* root;
    int flag;
}BiTreeStackNode;

//创建栈中的结点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* root,int flag)
{
    BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode->root = root;
    newnode->flag = flag;

    return newnode;
}

void NonRecursion(BinaryNode* root)
{
    //创建栈
    LinkStack* stack = Init_LinkStack();
    //把根结点放入栈里
    Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(root,MY_FALSE));

    while(Size_LinkStack(stack)>0)
    {
        //弹出栈顶结点
        BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
        Pop_LinkStack(stack);

        //判断弹出的结点是否为空
        if(node->root == NULL)
            continue;

        if(node->flag == MY_TRUE)
            printf("%c",node->root->c);
        else
        {
            //当前结点的右结点入栈
            Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->rchild,MY_FALSE));
            //当前结点的左结点入栈
            Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->lchild,MY_FALSE));
            //当前结点入栈，修改标志位
            node->flag = MY_TRUE;
            Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root,node->flag));
        }
        
    }

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

    //非递归遍历
    NonRecursion(&node1);
    printf("\n");

}

int main()
{
     Create_BinaryTree();

    return 0;
}
