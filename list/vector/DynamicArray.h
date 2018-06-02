#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

//动态增长内存，策略：将存放数据的内存放到堆上
//动态数组 如果5个元素 申请内存 拷贝数据 释放内存
//capacity 容量 表示这块内存空间一共可以存放多少元素
//size 记录当前数组中具体的元素个数

//动态数组的结构体
typedef struct DYNAMICARRAY
{
	int* pAddr;//存放数据的地址
	int size;//当前元素个数
	int capacity;//容量
}Dynamic_Array;

//一系列相关的对动态数组结构体操作的函数
//初始化
Dynamic_Array* Init_Array();
//插入
void PushBack_Array(Dynamic_Array* arr,int value);
//删除(位置)
void RemoveByPos_Array(Dynamic_Array* arr,int pos);
//删除（值）
void RemoveByValue_Array(Dynamic_Array* arr,int value);
//查找
int Find_Array(Dynamic_Array* arr,int value);
//打印
void PrintArray(Dynamic_Array* arr);
//释放内存
void FreeSpace_Array(Dynamic_Array* arr);
//清空数组
void Clear_Array(Dynamic_Array* arr);
//数组容量
int Capacity_Array(Dynamic_Array* arr);
//数组大小
int Size_Array(Dynamic_Array* arr);
//数组地址
int At_Array(Dynamic_Array* arr,int pos);

#endif
