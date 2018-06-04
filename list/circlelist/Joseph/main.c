/*约瑟夫问题（丢手绢）
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "circlelinklist.h"

#define M 8
#define N 3

typedef struct MYNUM
{
      CircleLinkNode node;
      int val;
}MyNum;

void MyPrint(CircleLinkNode* data)
{
      MyNum* num = (MyNum*)data;
      printf("%d ",num->val);
}

int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2)
{
      MyNum* num1 = (MyNum*)data1;
      MyNum* num2 = (MyNum*)data2;

      if(num1->val == num2->val)
          return CIRCLELINKLIST_TRUE;
     
      return CIRCLELINKLIST_FALSE;
}

int main()
{
    int i;
    //创建循环链表
    CircleLinkList* list = Init_CircleLinkList();

    //链表插入数据
    MyNum num[M];
    for(i=0 ; i<8; i++)
    {
          num[i].val = i+1;
          Insert_CircleLinkList(list,i,(CircleLinkNode*)&num[i]);
    }

    //打印
    Print_CircleLinkList(list,MyPrint);
   printf("\n");

    int index = 1;
    //辅助指针
    CircleLinkNode* pCurrent = list->head.next;
    while(Size_CircleLinkList(list)>1)
    {
        if(index == N)
        {
            MyNum* mynum = (MyNum*)pCurrent;
            printf("%d ",mynum->val);

            //缓存带删除结点的下一个结点

            CircleLinkNode* pNext = pCurrent->next;
            //根据值删除
            RemoveByValue_CircleLinkList(list,pCurrent,MyCompare);
            pCurrent = pNext;
            if(pCurrent == &(list->head))
                pCurrent = pCurrent->next;
            
            index = 1;
         }
         pCurrent = pCurrent->next;
         if(pCurrent == &(list->head))
                pCurrent = pCurrent->next;
         
         index ++;
          
     }


    if(Size_CircleLinkList(list) == 1)
    {
          MyNum* tnum = (MyNum*)Front_CircleLinkList(list);
          printf("%d ",tnum->val);
    }
    else
    {
          printf("wrong\n");
    }
    printf("\n");
    //释放内存
    FreeSpace_CircleLinkList(list);
    return 0;
}
