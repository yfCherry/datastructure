/*希尔排序：
 *分组插入排序
 *元素个数比较大的时候
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


void ShellSort(int arr[],int length)
{
    int increasement = length;
    int i,j,k ;

    do{
        //确定分组的增量
        increasement = increasement/3 +1;
        //分组
        for(i=0;i<increasement;i++)
            //每组插入比较
            for(j=i+increasement;j<length;j+=increasement)
            {
                //元素之间相差增量个单位
                if(arr[j]<arr[j-increasement])
                {
                    int temp = arr[j];
                    for(k=j-increasement;k>=0&&temp<arr[k];k-=increasement)
                        arr[k+increasement] = arr[k];
                    arr[k+increasement] = temp;
                }
            }

    }while(increasement>1);
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
    ShellSort(arr,MAX);
    long t_end = getSystemTime();
    PrintArray(arr,MAX);
    printf("%d个元素排序time:%ldms\n",MAX,t_end-t_start);
    return 0;
}
