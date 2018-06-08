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


void InsertSort(int arr[],int length)
{

    int i,j ;
    for (i = 1;i<length;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int temp = arr[i];
            for (j=i-1;j>=0&&temp<arr[j];j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
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
    InsertSort(arr,MAX);
    long t_end = getSystemTime();
    PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
