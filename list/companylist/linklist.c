#include "linklist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));  
    list->head.next = NULL;
    list->size = 0;

    return list;
}
//插入
void Insert_LinkList(LinkList* list,int pos,LinkNode* data)
{
    int i;
      if(list == NULL)
          return;
      if(data == NULL)
          return;

      if(pos<0 || pos>list->size)
          pos = list->size;

      //查找插入位置
      LinkNode* pCurrent = &(list->head);
      for( i=0 ; i<pos ; i++)
          pCurrent = pCurrent->next;

      //插入新结点
      data->next =pCurrent->next;
      pCurrent->next = data;

      list->size++;
}
//删除一个结点
void RemoveByPos_LinkList(LinkList* list,int pos)
{
    int i;
     if(list == NULL)
         return;

     if(pos<0 ||pos>=list->size)
         return;
     //辅助指针变量
     LinkNode* pCurrent = &(list->head);
     for(i=0 ; i<pos ; i++)
         pCurrent = pCurrent->next;

     //删除结点
     pCurrent->next = pCurrent->next->next;

     list->size--;

}
//链表大小
int Size_LinkList(LinkList* list)
{
      
}
//查找

int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare)
{
      if(list == NULL)
          return;

      if(data == NULL)
          return;
    
      LinkNode* pCurrent = list->head.next;
      int pos = 0;
      while(pCurrent != NULL)
      {
            if(compare(pCurrent,data) == 0)
                break;
            pCurrent = pCurrent->next;
            pos++;
      }

      return pos;
}
//打印
void Print_LinkList(LinkList* list,PRINTLINKNODE print)
{
      if(list == NULL)
          return;

      //
      LinkNode* pCurrent = list->head.next;
      while(pCurrent != NULL)
      {
            print(pCurrent);
            pCurrent = pCurrent->next;
      }     

}
//返回第一个结点
void* Front_LinkList(LinkList* list)
{
    return list->head.next;      
}
//释放空间
void FreeSpace_LinkList(LinkList* list)
{
      if(list == NULL)
          return;

      free(list);
}

