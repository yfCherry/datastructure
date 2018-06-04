#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

//链表小结点
typedef struct CIRCLELINKNODE
{
      struct CIRCLELINKNODE* next;
}CircleLinkNode;

//链表结构体
typedef struct CIRCLELINKLIST
{
      CircleLinkNode head;
      int size;
}CircleLinkList;

//比较回调
typedef int(*COMPARENODE)(CircleLinkNode*,CircleLinkNode*);
//打印回调
typedef void(*PRINTNODE)(CircleLinkNode*);
//编写针对链表结构操作的API函数

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//初始化
CircleLinkList* Init_CircleLinkList();
//插入
void Insert_CircleLinkList(CircleLinkList* list,int pos,CircleLinkNode* data);
//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list);
//删除（位置）
void RemoveByPos_CircleLinkList(CircleLinkList* list,int pos);
//删除（值）
void RemoveByValue_CircleLinkList(CircleLinkList* list,CircleLinkNode* data,COMPARENODE compare);
//大小
int Size_CircleLinkList(CircleLinkList* list);
//查找
int Find_CircleLinkList(CircleLinkList* list,CircleLinkNode* data,COMPARENODE compare);
//判断是否为空
int Isempty_CircleLinkList(CircleLinkList* list);
//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* list);
//打印
void Print_CircleLinkList(CircleLinkList* list,PRINTNODE print);

#endif
