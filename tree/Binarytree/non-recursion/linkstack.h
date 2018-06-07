#ifndef LINKSTACK_H
#define LINKSTACK_H

//链栈结点
typedef struct LINKNODE
{
      struct LINKNODE* next;
}LinkNode;

//链栈
typedef struct LINKSTACK
{
      LinkNode head;
      int size;
}LinkStack;

//初始化
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//元素个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁
void FreeSpace_LinkStack(LinkStack* stack);

#endif
