/*01-中缀表达式转后缀表达式：
 * 遇到数字输出，符号进栈，当遇到左括号时，压栈，遇到右括号时，将最近的左括号之上所有的符号弹出，顺延到数字后，如果栈顶符号为运算符，在遇到运算符时，比较二者优先级，后来的优先级高则压栈，否则将栈内运算符弹出再压栈。最后直到表达式结束，将栈中符号依次弹出。
 * 02-根据后缀表达式求解：
 * 遇到数字入栈，遇到运算符，弹出栈顶两个元素，先弹出的元素作为右操作数，后弹出的元素作为左操作数，将两个操作数和运算符计算后得到的数字入栈，反复执行操作，直到表达式结束，得出最终结果。
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
//01
typedef struct MYSTR
{
      LinkNode node;
      char* pAddr;
}MyStr;
//02  只向栈中存放数字
typedef struct MYSTR1
{
      LinkNode node;
      int val;
}MyStr1;
//0102
int IsNumber(char c)
{
    return c>='0' && c<='9';
}
//01
int IsLeft(char c)
{
      return c=='(';
}
//01
int IsRight(char c)
{
      return c==')';
}
//0102
int IsOperator(char c)
{
    return c=='+'||c=='-'||c=='*'||c=='/';
}
//01
MyStr* CreateMyStr(char* p)
{
      MyStr* str = (MyStr*)malloc(sizeof(MyStr));
      str->pAddr = p;
      
      return str;
}
//02
MyStr1* CreateMyStr1(char* p)
{
      MyStr1* str = (MyStr1*)malloc(sizeof(MyStr1));
      str->val = *p - '0';
      
      return str;
}

//01
int GetPriority(char c)
{
    if(c=='*'||c=='/')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    return 0;
}
//01输出
void NumberOperate(char* p)
{
    printf("%c",*p);
}
//01
void OperatorOperate(LinkStack* stack,char* p)
{
    //先取出栈顶符号
    MyStr* mystr = (MyStr*)Top_LinkStack(stack);
    if(mystr == NULL)
    {
        Push_LinkStack(stack,(LinkNode*)CreateMyStr(p));
        return;
    
    }
    if(GetPriority(*(mystr->pAddr)) < GetPriority(*p))
    {
        Push_LinkStack(stack,(LinkNode*)CreateMyStr(p));
        return;
    }
    else
    {
        while(Size_LinkStack(stack)>0)
        {
            MyStr* mystr2 = (MyStr*)Top_LinkStack(stack);
            //如果栈中优先级高，当前符号进栈
            if(GetPriority(*(mystr2->pAddr)) < GetPriority(*p))
            {   
                Push_LinkStack(stack,(LinkNode*)CreateMyStr(p));
                break;
            }
            //输出
            NumberOperate(mystr2->pAddr);
            //弹出
            Pop_LinkStack(stack);
            //释放
            free(mystr2);
        }
    }
}

//02
int Calculate(int left,int right,char c)
{
    int ret = 0;
    switch(c)
    {
        case '+':
            ret = left + right;
            break;
        case '-':
            ret = left - right;
            break;
        case '*':
            ret = left * right;
            break;
        case '/':
            ret = left / right;
            break;
        default:
            break;
    }

    return ret;
}

int main01()
{
    //创建栈容器
    LinkStack* stack = Init_LinkStack(); 
    char* str = "8+(3-1)*5";
    char* p = str;

    while(*p != '\0')
    {
        //数字
        if(IsNumber(*p))
            NumberOperate(p);
        //如果左括号 直接进栈
        if(IsLeft(*p))
        {
              Push_LinkStack(stack,(LinkNode*)CreateMyStr(p));
        }

        //如果右括号 从栈顶弹出元素 判断是不是左括号
        if(IsRight(*p))
        {
            
            while(Size_LinkStack(stack)>0)
            {
               MyStr* mystr = (MyStr*)Top_LinkStack(stack);
                   //匹配到左括号
               if(IsLeft(*(mystr->pAddr)))
               {
                    Pop_LinkStack(stack);
                    break;
               }
               NumberOperate(mystr->pAddr);
               Pop_LinkStack(stack);
               free(mystr);
     
            }
         }

        if(IsOperator(*p))
        {
            OperatorOperate(stack,p);
        }

        p++;
     
    }

    while(Size_LinkStack(stack)>0)
    {
        MyStr* mystr1 = (MyStr*)Top_LinkStack(stack);
        NumberOperate(mystr1->pAddr);
        Pop_LinkStack(stack);
        free(mystr1);
    }
    printf("\n");
    FreeSpace_LinkStack(stack);
}
//02
int main()
{
    //创建栈容器
    LinkStack* stack = Init_LinkStack(); 
    char* str = "831-5*+";
    char* p = str;

    while((*p) != '\0')
    {
        
        //数字
        if(IsNumber(*p))
        {
              Push_LinkStack(stack,(LinkNode*)CreateMyStr1(p));
            
        }
        else
        {
            MyStr1* rN = (MyStr1*)Top_LinkStack(stack);
             //先从栈中弹出右操作数
            Pop_LinkStack(stack);
             //再从栈中弹出左操作数
            MyStr1* lN = (MyStr1*)Top_LinkStack(stack);
            Pop_LinkStack(stack);

            char ret = '0';
            MyStr1* Ret = CreateMyStr1(&ret);
            Ret->val = Calculate(lN->val,rN->val,*p);
            Push_LinkStack(stack,(LinkNode*)Ret);
            
            free(rN);
            free(lN);
        }
    
        p++;
    }
    if(Size_LinkStack(stack) == 1)
    {
        MyStr1* mystr1 = (MyStr1*)Top_LinkStack(stack);
        printf("%d\n",mystr1->val);
        Pop_LinkStack(stack);
            
        free(mystr1);
            
    }
     
    FreeSpace_LinkStack(stack);
}
