#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct PERSON
{
      LinkNode node;
      char name[64];
      int age;
}Person;

int main()
{
    LinkStack* stack = Init_LinkStack(); 

    Person p1,p2,p3,p4,p5;
    strcpy(p1.name,"a");
    strcpy(p2.name,"b");
    strcpy(p3.name,"c");
    strcpy(p4.name,"d");
    strcpy(p5.name,"e");
    p1.age = 1;
    p2.age = 2;
    p3.age = 3;
    p4.age = 4;
    p5.age = 5;

    Push_LinkStack(stack,(LinkNode*)&p1);
    Push_LinkStack(stack,(LinkNode*)&p2);
    Push_LinkStack(stack,(LinkNode*)&p3);
    Push_LinkStack(stack,(LinkNode*)&p4);
    Push_LinkStack(stack,(LinkNode*)&p5);

    while(Size_LinkStack(stack)>0)
    {
          //取出栈顶指针
         Person* p = (Person*)Top_LinkStack(stack);
         printf("name:%s age:%d\n",p->name,p->age);

         Pop_LinkStack(stack);
    }

    FreeSpace_LinkStack(stack);
}
