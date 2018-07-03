#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HASHSIZE 12
#define NULLKEY -32768
typedef struct
{
    int *elem; //数据元素的基址，动态分配数组
    int count; //当前元素的个数
}HashTable;

int InitHashTable(HashTable* h)
{
    int i;
    h->count = HASHSIZE;
    h->elem = (int*)malloc(HASHSIZE *sizeof(int));
    
    if( !h->elem )
        return -1;
    for(i=0;i<HASHSIZE;i++)
    {
        h->elem[i] = NULLKEY;
    }

    return 0;

}

//使用除留余数法
int Hash(int key)
{
    return key % HASHSIZE;
}

//插入关键字
void InsertHash(HashTable* h,int key)
{
    int addr;
    addr = Hash(key);
    while(h->elem[addr] != NULLKEY)//如果不为空，冲突出现
    {
        addr = (addr+1) % HASHSIZE;
    }

    h->elem[addr] = key;
}

//查找关键字
int SearchHash(HashTable h,int key,int* addr)
{
    *addr = Hash(key);

    while(h.elem[*addr] != key)
    {
        *addr = (*addr +1)%HASHSIZE;
        if(h.elem[*addr] == NULLKEY || *addr == Hash(key))
            return -1;

    }

    return 0;
}
int main()
{
    HashTable* h = (HashTable*)malloc(sizeof(HashTable));
    
    InitHashTable(h);
    InsertHash(h,10);
    InsertHash(h,22);
    InsertHash(h,3);
    InsertHash(h,1);
    InsertHash(h,11);
    InsertHash(h,9);

    int addr_22;
    int addr_20;
    if(!SearchHash(*h,22,&addr_22))
        printf("%d\n",addr_22);
    if(!SearchHash(*h,20,&addr_20))
        printf("%d\n",addr_20);

    return 0;
}
