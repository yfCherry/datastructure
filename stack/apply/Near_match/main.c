/*就近匹配i:所有括号是否匹配
 * 从头开始寻找左括号，找到第一个放入栈中，继续寻找，如果有右括号，则把栈中的左括号弹出，匹配成功
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct MYSTR
{
      LinkNode node;
      char* pAddr;
      int index;
}MyStr;

int IsLeft(char c)
{
      return c=='(';
}
int IsRight(char c)
{
      return c==')';
}

MyStr* CreateMyStr(char* p,int index)
{
      MyStr* str = (MyStr*)malloc(sizeof(MyStr));
      str->pAddr = p;
      str->index = index;
      
      return str;
}
//表示没有匹配的位置，用A来表示箭头指向
void showERROR(char* str,int pos)
{
    int i;
    printf("%s\n",str);
    for(i=0;i<pos;i++)
        printf(" ");
    printf("A\n");
}
int main()
{
    //创建栈容器
    LinkStack* stack = Init_LinkStack(); 
    char* str = "1+2*(3+4)((()";
    char* p = str;
    int index = 0;

    while(*p != '\0')
    {
        //如果左括号 直接进栈
        if(IsLeft(*p))
        {
              Push_LinkStack(stack,(LinkNode*)CreateMyStr(p,index));
        }

        //如果右括号 从栈顶弹出元素 判断是不是左括号
        if(IsRight(*p))
        {
            if(Size_LinkStack(stack)>0)
            {
               MyStr* mystr = (MyStr*)Top_LinkStack(stack);
               if(IsLeft(*(mystr->pAddr)))
               {
                    Pop_LinkStack(stack);
                    free(mystr);
               }
     
            }
            else
            {
                printf("右括号没有匹配的左括号！\n");
                showERROR(str,index);
                break;
            }
         }
     
        p++;
       index++;
    }

    while(Size_LinkStack(stack)>0)
    {
        MyStr* mystr = (MyStr*)Top_LinkStack(stack);
        printf("左括号没有匹配的右括号:\n");
        showERROR(str,mystr->index);
        Pop_LinkStack(stack);
        free(mystr);
    }
    FreeSpace_LinkStack(stack);
}
