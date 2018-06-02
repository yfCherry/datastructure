#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

typedef struct PERSON
{
      char name[64];
      int age;
      int score;
}Person;

//打印函数
void MyPrint(void* data)
{
      Person* p = (Person*)data;
      printf("Name:%s,age:%d,score:%d\n",p->name,p->age,p->score);
}

int main()
{
      LinkList* list = Init_LinkList();

      Person p1 = {"a",18,99};
      Person p2 = {"b",19,93};
      Person p3 = {"c",12,92};
      Person p4 = {"d",13,91};
      Person p5 = {"e",14,91};
  
      //数据插入链表
      Insert_LinkList(list,0,&p1);
      Insert_LinkList(list,0,&p2);
      Insert_LinkList(list,0,&p3);
      Insert_LinkList(list,0,&p4);
      Insert_LinkList(list,0,&p5);

      //打印
      Print_LinkList(list,MyPrint);

      //删除3位置
      RemoveByPos_LinkList(list,3);
      //打印
      Print_LinkList(list,MyPrint);

      //返回第一个结点
      Person* r = (Person*)Front_LinkList(list);
      //打印
      printf("Name:%s,age:%d,score:%d\n",r->name,r->age,r->score);


      //销毁链表
      FreeSpace_LinkList(list);

      return 0;
}
