#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MAX_SIZE 1024

typedef struct SEQQUEUE
{
    void* data[MAX_SIZE];  
    int size;
}SeqQueue;

//初始化
SeqQueue* Init_SeqQueue();
//入队
void Push_SeqQueue(SeqQueue* queue,void* data);
//返回队头元素
void* Front_SeqQueue(SeqQueue* queue);
//出队
void Pop_SeqQueue(SeqQueue* queue);
//返回队尾元素
void* Back_SeqQueue(SeqQueue* queue);
//清空
void Clear_SeqQueue(SeqQueue* queue);
//清理内存
void FreeSpace_SeqQueue(SeqQueue* queue);
//大小
int Size_SeqQueue(SeqQueue* queue);

#endif
