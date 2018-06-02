#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    //头结点 不保存数据信息
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;

    return list;
}
//插入
void Insert_LinkList(LinkList* list,int pos,void* data)
{
    int i;

      if(list == NULL)
          return;
      if(data == NULL)
          return;

      //pos越界，友好处理
      if(pos<0 ||pos>list->size)
      {
            pos = list->size;
      }
        
      //创建新结点
      LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
      newnode->data = data;
      newnode->next = NULL;

       //找结点 辅助指针变量
       LinkNode* pCurrent = list->head;
       for(i=0 ; i<pos ; i++)
           pCurrent = pCurrent->next;
        
       //插入新结点
       newnode->next = pCurrent->next;
       pCurrent->next = newnode;

       list->size++;

}
//删除一个结点
void RemoveByPos_LinkList(LinkList* list,int pos)
{
    int i;

    if(list == NULL)
        return;
    if(pos<0||pos>=list->size)
        return;

    //查找删除结点的前一个结点
    LinkNode* pCurrent = list->head;
    for(i=0; i<pos ; i++)
        pCurrent = pCurrent->next;

    //缓存删除的结点
    LinkNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;
   
    //释放删除结点的内存
    free(pDel);

    list->size--;
      
}
//链表大小
int Size_LinkList(LinkList* list)
{
      return list->size;
}
//查找
int Find_LinkList(LinkList* list,void* data)
{
    int i=0;

    if(list == NULL)
        return;
    if(data == NULL)
        return;
    
    //遍历结点
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != NULL)
    {
          if(pCurrent->data == data)
              break;

          i++;
          pCurrent = pCurrent->next;
    }
    
    return i;
}
//打印
void Print_LinkList(LinkList* list,PRINTLINKNODE print)
{
      if(list == NULL)
          return;

      //辅助指针变量
      LinkNode* pCurrent = list->head->next;
      while(pCurrent != NULL)
      {
            print(pCurrent->data);
            pCurrent = pCurrent->next;

      }
}
//返回第一个结点
void* Front_LinkList(LinkList* list)
{
      return list->head->next->data;
}
//释放空间
void FreeSpace_LinkList(LinkList* list)
{
      if(list == NULL)
          return;

      LinkNode* pCurrent = list->head;
      while(pCurrent != NULL)
      {
          //缓存下一个结点
          LinkNode* pNext = pCurrent->next;
            free(pCurrent);
            pCurrent = pNext;
      }


      //释放链表
      list->size = 0;
      free(list);
}


