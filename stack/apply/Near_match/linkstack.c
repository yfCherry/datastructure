#include "linkstack.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//初始化
LinkStack* Init_LinkStack()
{
      LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
      stack->head.next = NULL;
      stack->size = 0;

      return stack;
}
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data)
{
      if(data == NULL)
          return;
      if(stack == NULL)
          return;

      data->next = stack->head.next;
      stack->head.next = data;

      stack->size++;
}
//出栈
void Pop_LinkStack(LinkStack* stack)
{
      if(stack == NULL)
          return;
      if(stack->size == 0)
          return;

      //第一个有效结点
      LinkNode* pNext = stack->head.next;
      stack->head.next = pNext->next;

      stack->size--;
}
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack)
{
    if(stack == NULL)
        return NULL;
    if(stack->size == 0)
        return NULL;
     return stack->head.next;
}
//元素个数
int Size_LinkStack(LinkStack* stack)
{
    if(stack == NULL)
        return -1;
      return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
      if(stack == NULL)
          return;

      stack->head.next = NULL;
      stack->size = 0;
}
//销毁
void FreeSpace_LinkStack(LinkStack* stack)
{
      if(stack == NULL)
          return;

      free(stack);
}


