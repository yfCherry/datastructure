#include <stdio.h>
#include<stdlib.h>
#include "linklist.h"

typedef struct PERSON
{
      LinkNode node;
      char name[64];
      int age;
      int score;
}Person;

void MyPrint(LinkNode* data)
{
      Person* p = (Person*)data;
      printf("name:%s,age:%d,score:%d\n",p->name,p->age,p->score);
}

int MyCompare(LinkNode* node1,LinkNode* node2)
{
      Person* p1 = (Person*)node1;
      Person* p2 = (Person*)node2;

      if(strcmp(p1->name,p2->name) == 0 && p1->age == p2->age &&p1->score==p2->score)
            return 0;
      return -1;
            
        
}
int main()
{
      LinkList* list = Init_LinkList();

      Person p1,p2,p3,p4,p5;
      strcpy(p1.name,"e");
      strcpy(p2.name,"d");
      strcpy(p3.name,"c");
      strcpy(p4.name,"a");
      strcpy(p5.name,"b");
      p1.age = 1;
      p2.age = 2;
      p3.age = 3;
      p4.age = 4;
      p5.age = 5;
      p1.score = 1;
      p2.score = 2;
      p3.score = 3;
      p4.score = 4;
      p5.score = 5;
  
      //数据插入链表
      Insert_LinkList(list,0,(LinkNode*)&p1);
      Insert_LinkList(list,0,(LinkNode*)&p2);
      Insert_LinkList(list,0,(LinkNode*)&p3);
      Insert_LinkList(list,0,(LinkNode*)&p4);
      Insert_LinkList(list,0,(LinkNode*)&p5);

      //打印
      Print_LinkList(list,MyPrint);

      //删除3位置
      RemoveByPos_LinkList(list,3);
      //打印
      Print_LinkList(list,MyPrint);

      //查找age = 4
      Person findp;
      strcpy(findp.name,"a");
      findp.age = 4;
      findp.score = 4;
      int pos = Find_LinkList(list,(LinkNode*)&findp,MyCompare);
      printf("位置：%d\n",pos);

      //返回第一个结点
      Person* r = (Person*)Front_LinkList(list);
      //打印
      printf("Name:%s,age:%d,score:%d\n",r->name,r->age,r->score);


      //销毁链表
      FreeSpace_LinkList(list);

      return 0;


}
