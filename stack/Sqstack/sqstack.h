#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//数组模拟栈的顺序存储
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

typedef struct SEQSTACK
{
      void* data[MAX_SIZE];
      int size;
}SeqStack;

//初始化
SeqStack* Init_SeqStack();
//入栈
void Push_SeqStack(SeqStack* stack,void* data);
//栈顶元素
void* Top_SeqStack(SeqStack* stack);
//出栈
void Pop_SeqStack(SeqStack* stack);
//清空
void Clear_SeqStack(SeqStack* stack);
//判断是否为空
int Isempty_SeqStack(SeqStack* stack);
//栈大小
int Size_SeqStack(SeqStack* stack);
//清理内存
void FreeSpace_SeqStack(SeqStack* stack);


#endif
