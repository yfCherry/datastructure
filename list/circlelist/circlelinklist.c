#include "circlelinklist.h"
#include <stdio.h>
#include <stdlib.h>

//初始化
CircleLinkList* Init_CircleLinkList()
{
     CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
     list->head.next = &(list->head);
     list->size = 0;

     return list;
}
//插入
void Insert_CircleLinkList(CircleLinkList* list,int pos,CircleLinkNode* data)
{
    int i;
      if(list == NULL)
          return;
      if(data == NULL)
          return;

      if(pos<0 || pos>=list->size)
          pos = list->size;

      //根据位置查找结点
      //辅助指针变量
      CircleLinkNode* pCurrent = &(list->head);
      for(i=0 ; i<pos ;i++)
          pCurrent = pCurrent->next;

      data->next = pCurrent->next;
      pCurrent->next = data;

      list->size++;

}
//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list){
      return list->head.next;
}
//删除（位置）
void RemoveByPos_CircleLinkList(CircleLinkList* list,int pos)
{
    int i;
      if(list == NULL)
          return;

      if(pos<0 ||pos>=list->size)
          return;

      //根据pos找结点
      //辅助指针变量
      CircleLinkNode* pCurrent = &(list->head);
      for(i=0 ; i<pos ;i++)
          pCurrent = pCurrent->next;

      //缓存当前结点的下一结点
      CircleLinkNode* pNext = pCurrent->next;
      pCurrent->next = pNext->next;

      list->size--;
}
//删除（值）
void RemoveByValue_CircleLinkList(CircleLinkList* list,CircleLinkNode* data,COMPARENODE compare)
{
    int i;
      if(list == NULL)
          return;
      if(data == NULL)
          return;

      //循环链表
      //辅助指针变量
      CircleLinkNode* pPrev = &(list->head);
       CircleLinkNode* pCurrent = list->head.next;
      for(i=0 ; i<list->size ;i++)
      {
          if(compare(pCurrent,data)== CIRCLELINKLIST_TRUE) 
          {
               pPrev->next = pCurrent->next; 
                list->size--;
                break;
          }
          pPrev = pCurrent;
          pCurrent = pCurrent->next;
          
      }

}
//大小
int Size_CircleLinkList(CircleLinkList* list)
{
      return list->size;
}
//查找
int Find_CircleLinkList(CircleLinkList* list,CircleLinkNode* data,COMPARENODE compare)
{
     int i;
      if(list == NULL)
          return -1;
      if(data == NULL)
          return -1;

      //循环链表
      //辅助指针变量
       CircleLinkNode* pCurrent = list->head.next;
      int flag = -1;
       for(i=0 ; i<list->size ;i++)
      {
          if(compare(pCurrent,data)== CIRCLELINKLIST_TRUE) 
          {
              flag = i;
                break;
          }
          pCurrent = pCurrent->next;
          
      }

  return flag;
}
//判断是否为空
int Isempty_CircleLinkList(CircleLinkList* list)
{
      if(list->size == 0)
          return CIRCLELINKLIST_TRUE;
      
      return CIRCLELINKLIST_FALSE;
}
//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* list)
{
      if(list == NULL)
          return;
      free(list);
}
//打印
void Print_CircleLinkList(CircleLinkList* list,PRINTNODE print)
{
      int i;
      if(list == NULL)
          return;

      //循环链表
      //辅助指针变量
       CircleLinkNode* pCurrent = list->head.next;
       for(i=0 ; i<list->size*2 ;i++)
      {
          if(pCurrent == &(list->head)) 
          {
               pCurrent = pCurrent->next;
               printf("-------------------------\n");
          }

          print(pCurrent);
          pCurrent = pCurrent->next;   
      }
}

