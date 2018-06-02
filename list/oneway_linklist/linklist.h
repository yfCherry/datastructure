#ifndef LINKLIST_H
#define LINKLIST_H

//链表结点
typedef struct LINKNODE
{
      void* data;//指向任何类型的数据
      struct LINKNODE* next;
}LinkNode;

//链表结构体
typedef struct LINKLIST
{
      LinkNode* head;
      int size;
}LinkList;

//打印函数指针
typedef void(*PRINTLINKNODE)(void*);
 
//初始化链表
LinkList* Init_LinkList();
//插入
void Insert_LinkList(LinkList* list,int pos,void* data);
//删除一个结点
void RemoveByPos_LinkList(LinkList* list,int pos);
//链表大小
int Size_LinkList(LinkList* list);
//查找
int Find_LinkList(LinkList* list,void* data);
//打印
void Print_LinkList(LinkList* list,PRINTLINKNODE print);
//返回第一个结点
void* Front_LinkList(LinkList* list);
//释放空间
void FreeSpace_LinkList(LinkList* list);

#endif
