#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"sqqueue.h"

typedef struct PERSON
{
    char name[64];  
    int age;
}Person;
int main()
{
    SeqQueue* queue = Init_SeqQueue();
      //创建数据
      Person p1 = {"a",1};
      Person p2 = {"b",2};
      Person p3 = {"d",3};
      Person p4 = {"c",4};
      Person p5 = {"e",5};

      //插入数据
      Push_SeqQueue(queue,&p1);
      Push_SeqQueue(queue,&p2);
      Push_SeqQueue(queue,&p3);
      Push_SeqQueue(queue,&p4);
      Push_SeqQueue(queue,&p5);

      //输出队尾
      Person* pb = (Person*)Back_SeqQueue(queue);
      printf("name:%s age:%d\n",pb->name,pb->age);

      while(Size_SeqQueue(queue)>0)
      {
            //取出队头元素
           Person* p =(Person*)Front_SeqQueue(queue);
           printf("name:%s age:%d\n",p->name,p->age);
           //从队头弹出
           Pop_SeqQueue(queue);

      }

      FreeSpace_SeqQueue(queue);
      return 0 ;
}
