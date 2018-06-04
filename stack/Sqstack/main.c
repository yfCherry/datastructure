#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"sqstack.h"

typedef struct PERSON
{
      char name[64];
      int age;
}Person;

int main()
{
      SeqStack* stack = Init_SeqStack();

      //创建数据
      Person p1 = {"a",1};
      Person p2 = {"b",2};
      Person p3 = {"d",3};
      Person p4 = {"c",4};
      Person p5 = {"e",5};

      //插入数据
      Push_SeqStack(stack,&p1);
      Push_SeqStack(stack,&p2);
      Push_SeqStack(stack,&p3);
      Push_SeqStack(stack,&p4);
      Push_SeqStack(stack,&p5);

      //输出数据
      while(Size_SeqStack(stack)>0)
      {
            //访问栈顶元素
            Person* p = (Person*)Top_SeqStack(stack);
            printf("name:%s age:%d\n",p->name,p->age);
            //弹出栈顶元素
            Pop_SeqStack(stack);
      }

        FreeSpace_SeqStack(stack);
}
