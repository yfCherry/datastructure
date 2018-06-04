#include "sqqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//初始化
SeqQueue* Init_SeqQueue()
{
    int i;
    SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue)) ;
    for(i=0;i<MAX_SIZE;i++)
        queue->data[i] = NULL;
    queue->size = 0;
   
    return queue;
}
//入队
void Push_SeqQueue(SeqQueue* queue,void* data)
{
    //数组左边当作队头
    if(queue == NULL)
        return;
    if(data == NULL)
        return;
    if(queue->size == MAX_SIZE)
        return;

    queue->data[queue->size] = data;
    queue->size ++;
}
//返回队头元素
void* Front_SeqQueue(SeqQueue* queue)
{
    if(queue == NULL)
        return NULL;
    if(queue->size == 0)
        return NULL;
      
    return queue->data[0];
}
//出队
void Pop_SeqQueue(SeqQueue* queue)
{
    int i;
    //需要移动元素
    if(queue == NULL)
        return;
    if(queue->size == 0)
        return;

    for(i=0;i<queue->size-1;i++)
    {
          queue->data[i] = queue->data[i+1];
    }

    queue->size--;
}
//返回队尾元素
void* Back_SeqQueue(SeqQueue* queue)
{
      if(queue == NULL)
          return NULL;
      if(queue->size == 0)
          return NULL;

      return queue->data[queue->size-1];
}
//清空
void Clear_SeqQueue(SeqQueue* queue)
{
      if(queue == NULL)
          return;

      queue->size = 0;
}
//清理内存
void FreeSpace_SeqQueue(SeqQueue* queue)
{
      if(queue == NULL)
          return;

      free(queue);
}
//大小
int Size_SeqQueue(SeqQueue* queue)
{
      if(queue == NULL)
          return -1;

      return queue->size;
}


