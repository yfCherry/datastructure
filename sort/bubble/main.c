#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10000

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

int flag = 0;//表示没有排序好

//每次找最大值
void BubbleSort(int arr[],int length)
{

    int i,j ;
    for (i = 0;i<length&&flag==0;i++)
    {
        flag = 1;//排好序 提高一点效率
        for(j=0;j<length-i-1;j++)
            if(arr[j]>arr[j+1])
            {
                flag = 0;
                Swap(&arr[j],&arr[j+1]);
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

    //PrintArray(arr,MAX);
    long t_start = getSystemTime();
    BubbleSort(arr,MAX);
    long t_end = getSystemTime();
    //PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
