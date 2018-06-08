/*插入排序：
 *1元素序列基本有序的情况下
 *2元素个数比较小的时候
 */
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


void QuickSort(int arr[],int start,int end)
{
    int i = start;
    int j = end;
        
    //基准数
    int tmp = arr[start];
    if(i<j)
    {
        while(i<j)
        {
            //从右向左 找比基准数小的数
            while(i<j&&arr[j]>=tmp)
                j--;
            //填坑
            if(i<j)
            {
                arr[i] = arr[j];
                i++;
            }

            //从左向右 找比基准数大的数
            while(i<j&&arr[i]<tmp)
                i++;
            //填坑
            if(i<j)
            {
                 arr[j] = arr[i];
                 j--;
            }
        }

        //把基准数放入
        arr[i] = tmp;
        //对左半部分快排
        QuickSort(arr,start,i-1);
        //对右半部分快排
        QuickSort(arr,i+1,end);
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
    QuickSort(arr,0,MAX-1);
    long t_end = getSystemTime();
    PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
