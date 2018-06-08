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

//和冒泡比减少交换次数
void SelectSort(int arr[],int length)
{

    int i,j ;
    for (i = 0;i<length;i++)
    {
        int min = 0;
        for(j=i+1;j<length;j++)
            if(arr[j]<arr[min])
            {
                min = j;
            }
        if (min!=i)
            Swap(&arr[min],&arr[i]);
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
    SelectSort(arr,MAX);
    long t_end = getSystemTime();
    //PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
