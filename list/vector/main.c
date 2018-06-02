/*线性表：0或多个数据元素的有限序列
 * 特性：1.数据元素之间有顺序
 * 		 2.数据元素个数有限
 * 		 3.数据元素类型必须相同
 * 操作：1.创建线性表
 * 		 2.销毁线性表
 * 		 3.
 * 存储：1.顺序（动态数组）
 * 			当插入一个新元素时，发现空间内存不足，申请一块更大空间；
 * 			将原空间
 * 		 2.链式
 * 		
 *
 * */
#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

void test01()
{
      int i;
        //初始化动态数组
      Dynamic_Array* myArray = Init_Array();
      //打印容量
      printf("数组容量：%d\n",Capacity_Array(myArray));
      printf("数组大小：%d\n",Size_Array(myArray));
      //插入元素

      for(i=0 ; i<30 ; i++)
      {
          PushBack_Array(myArray,i);
      }
      
      //打印
      PrintArray(myArray);
      //打印容量
      printf("数组容量：%d\n",Capacity_Array(myArray));
      printf("数组大小：%d\n",Size_Array(myArray));
      
      //删除
      RemoveByPos_Array(myArray,0);
      //打印
      PrintArray(myArray);
      
      RemoveByValue_Array(myArray,27);
      //打印
      PrintArray(myArray);

     //查找5个位置
     int pos = Find_Array(myArray,5);
     printf("5查找到：pos:%d\n",pos);
      
      //销毁
      FreeSpace_Array(myArray);
}
int main(void)
{
	test01();
	return 0;
}
