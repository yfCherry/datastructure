/*字典树：
 * 应用---查找字符串
 *      前缀、后缀
 * */
#include <iostream>
#include <string.h>

#define ALNT 26

using namespace std;

struct Node
{
    Node *nxt[ALNT];
    int flag;
    int num;//单词通过的个数
    Node()
    {
        num = 1;
        int i;
        for(i = 0;i<ALNT;i++)
            nxt[i] = NULL;
        flag = 0;
    }

};
Node *root;

void init()
{
    root = new Node();
}

void ins(const char* s)
{
    int len = strlen(s);
    Node* now = root;

    int i;
    for(i=0;i<len;i++)
    {
        int to = s[i] - 'a';
        if(now->nxt[to] == NULL)
            now->nxt[to] = new Node();
        else
            now->nxt[to]->num++;
        now = now->nxt[to];
    }

    now->flag = 1;
}

int find1(const char* s)
{
    if(s == NULL||strlen(s) == 0)
        return -1;
    int len = strlen(s);
    Node* now = root;

    int i;
    for(i=0;i<len;i++)
    {
        int to = s[i] - 'a';
        if(now->nxt[to] == NULL)
            return -1;
        now = now->nxt[to];
    }

    if(now->flag != 1)
        return -1;

    return 0;
}

int count(const char* s)
{
    if(s == NULL||strlen(s) == 0)
        return -1;
    
    int len = strlen(s);
    Node* now = root;

    int i;
    for(i=0;i<len;i++)
    {
        int to = s[i] - 'a';
        if(now->nxt[to] == NULL)
            return 0;
        
            
        now = now->nxt[to];
    }

    return now->num;
}


int main()
{
    init();
    const char *insert[] ={"banana","band","bee","acm"};
    const char *find[] = {"ba","bee","apple"};
    int i;
    for (i=0;i<(sizeof(insert)/sizeof(insert[0]));i++)
        ins(insert[i]);
   
    const char s[] = "be";
    if(find1(s)!= -1)
        cout<<"找到"<<endl;
    else
        cout<<"未找到"<<endl;

    for (i=0;i<(sizeof(find)/sizeof(find[0]));i++)
    {
        int number = count(find[i]);
        cout<<find[i]<<"数量:"<<number<<endl;
    }

    return 0;
}
