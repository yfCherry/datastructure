/*堆排序：
 * 给一个数组，相当于给一个完全二叉树，此时不满足堆的条件。
 *通过调整堆，初始化堆
 *
 * */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

void PrintArray(int arr[],int length);

long getSystemTime()
{
    struct timeb tb;
    ftime(&tb);
    return tb.time*1000+tb.millitm;
}

void Swap(int* i,int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp; 
}
/*
    @param arr 待调整的数组
    @param index 带调整的结点的下标
    @param length 数组的长度
 */
void HeapAdjust(int arr[],int index,int length)
{
    //保存当前结点下标
    int max = index;
    //保存左右孩子结点下标
    int lchild = index*2+1;
    int rchild = index*2+2;

    if(lchild<length&& arr[lchild]>arr[max])
        max = lchild;
    if(rchild<length&& arr[rchild]>arr[max])
        max = rchild;

    if(max!=index)
    {
        Swap(&arr[max],&arr[index]);        
        HeapAdjust(arr,max,length); 
    }

}

//堆排序 大顶堆 从小到大
void HeapSort(int arr[],int length)
{
    int i;
    //初始化堆
    for (i = length/2-1;i>=0;i--)
    {
        HeapAdjust(arr,i,length);
    }

    //交换堆顶元素和最后一个元素
    for(i = length-1;i>=0;i--)
    {
        Swap(&arr[0],&arr[i]);
        HeapAdjust(arr,0,i);
    }
}

void PrintArray(int arr[],int length)
{
    int i;
    for(i=0;i<length;i++)
        printf("%d",arr[i]);
    printf("\n");
}
int main()
{

    int arr[MAX],i;
    srand((unsigned int)time(NULL));
    for(i = 0;i<MAX;i++)
        arr[i] = rand()%MAX;

    PrintArray(arr,MAX);
    long t_start = getSystemTime();
    HeapSort(arr,MAX);
    long t_end = getSystemTime();
    PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
