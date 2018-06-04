#include "sqstack.h"


//初始化
SeqStack* Init_SeqStack()
{
    int i;
      SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
      for(i=0 ; i<MAX_SIZE;i++)
            stack->data[i] = NULL;

      stack->size = 0;
      return stack;
}
//入栈
void Push_SeqStack(SeqStack* stack,void* data)
{
      if(data == NULL)
          return;
      if(stack == NULL)
          return;
      if(stack->size == MAX_SIZE)
          return;

      stack->data[stack->size] = data;
      stack->size++;
}
//栈顶元素
void* Top_SeqStack(SeqStack* stack)
{
      if(stack == NULL)
          return NULL;
      if(stack->size == 0)
          return NULL;

      return stack->data[stack->size-1];
}
//出栈
void Pop_SeqStack(SeqStack* stack)
{
      if(stack == NULL)
          return ;
      if(stack->size == 0)
          return ;

      stack->data[stack->size-1] = NULL;
      stack->size--;

      
}
//清空
void Clear_SeqStack(SeqStack* stack)
{
    int i ;
      if(stack == NULL)
          return;
      for(i=0 ; i<stack->size ; i++)
          stack->data[i] = NULL;
      stack->size = 0;
}
//判断是否为空
int Isempty_SeqStack(SeqStack* stack)
{
      if(stack == NULL)
          return -1;

      if(stack->size == 0)
          return SEQSTACK_TRUE;

      return SEQSTACK_FALSE;
}
//栈大小
int Size_SeqStack(SeqStack* stack)
{
      return stack->size;
}
//清理内存
void FreeSpace_SeqStack(SeqStack* stack)
{
      if(stack == NULL)
          return;
      free(stack);
}



