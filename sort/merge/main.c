/*归并排序：
 * 将两个有序序列合并成一个有序序列
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


//合并算法
void Merge(int arr[],int start,int end,int mid,int* tmp)
{
    int i;

    int i_start = start;
    int i_end = mid;
    int j_start = mid+1;
    int j_end = end;

    //辅助空间有多少个元素
    int length = 0;

    //合并两个有序序列
    while(i_start<=i_end&&j_start<=j_end)
    {
        if(arr[i_start]<arr[j_start])
        {
            tmp[length] = arr[i_start];
            length++;
            i_start++;
        }
        else
        {
            tmp[length] = arr[j_start];
            length++;
            j_start++;
        }

    }

    while(i_start<=i_end)
    {
        tmp[length] = arr[i_start];
        i_start++;
        length++;
    }
     while(j_start<=j_end)
    {
        tmp[length] = arr[j_start];
        j_start++;
        length++;
    }

     //辅助空间数据覆盖原空间
     for(i = 0;i<length;i++)
     {
        arr[i+start] = tmp[i];
     }

}
//归并排序
void MergeSort(int arr[],int start,int end,int* tmp)
{
    if(start >= end)
        return;
    int mid = (start+end)/2;

    //分组
    MergeSort(arr,start,mid,tmp);
    MergeSort(arr,mid+1,end,tmp);

    //合并
    Merge(arr,start,end,mid,tmp);
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

    int i;
    srand((unsigned int)time(NULL));
    int* arr = (int*)malloc(sizeof(int)*MAX);
    for(i = 0;i<MAX;i++)
        arr[i] = rand()%MAX;

    //辅助空间
    int* tmp = (int*)malloc(sizeof(int)*MAX);
    PrintArray(arr,MAX);
    long t_start = getSystemTime();
    MergeSort(arr,0,MAX-1,tmp);
    long t_end = getSystemTime();
    PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    
    free(arr);
    free(tmp);
    return 0;
}
