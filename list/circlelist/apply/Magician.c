#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CardNumber 13

typedef struct NODE
{
    int data;
    struct NODE* next;
}sqlist,*linklist;

linklist CreateLinkList()
{
    linklist head = NULL;
    linklist s,r;
    int i;

    r = head;
    for(i=1;i<=CardNumber;i++)
    {
        s = (linklist)malloc(sizeof(linklist));
        s->data = 0;
        
        if(head == NULL)
            head = s;
        else
            r->next = s;

        r = s;
    }

    r->next = head;

    return head;
}

