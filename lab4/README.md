### 概述
这一次实验在上一次的基础上，使用`Linktable`模块将`struct`中的链表部分分离出来，并且将`struct`中的代码的链表功能部分改为使用`Linktable`提供的方法实现。

### 文件结构
`lab4`文件夹一共包括以下文件：
- `Linktable.h Linktable.c`
链表功能模块实现部分
- `struct.h struct.c`
命令行程序主体部分，包括建立链表，使用预制的`tDataNode`数组`head`初始化链表，以及查找和执行命令
- `main.c`
主程序，结束时负责回收内存
- `makefile`
供`make`命令使用的`makefile`文件

### 运行程序
直接在命令行下输入`make`即可自动进行编译和运行

### 代码

这里只贴出`Linktable.c`和`struct.c`，其他请自行查看：
`Linktable.c`
```c
#include "Linktable.h"
#include <stdio.h>
#include <stdlib.h>

tLinkTable * CreateLinkTable()
{
    tLinkTable * table=(tLinkTable*)malloc(sizeof(tLinkTable));
    table->pHead=NULL;
    table->pTail=NULL;
    table->SumOfNode=0;
    return table;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    tLinkTableNode *node=pLinkTable->pHead;
    while(node!=NULL)
    {
        tLinkTableNode *to_free=node;
        node=node->pNext;
        free(to_free);
    }
    free(pLinkTable);
    return 1;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
        return 0;
    }
    if(pLinkTable->pHead==NULL)
    {
        pLinkTable->pHead=pNode;
    }
    if(pLinkTable->pTail==NULL)
    {
        pLinkTable->pTail=pNode;
    }
    else
    {
        tLinkTableNode *ptr_tail=pLinkTable->pTail;
        ptr_tail->pNext=pNode;
        pLinkTable->pTail=pNode;
    }
    pLinkTable->SumOfNode+=1;

    return 1;
}

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
        return 0;
    }
    if(pLinkTable->pHead==pNode)
    {
      pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->SumOfNode -= 1 ;
        if(pLinkTable->SumOfNode == 0)
        {
            pLinkTable->pTail = NULL;
        }
        return 1;
    }
    tLinkTableNode * tempNode = pLinkTable->pHead;
    while(tempNode != NULL)
    {
       if(tempNode->pNext == pNode)
       {
            tempNode->pNext = tempNode->pNext->pNext;
            pLinkTable->SumOfNode -= 1 ;
            if(pLinkTable->SumOfNode == 0)
            {
                pLinkTable->pTail = NULL;
            }
            return 1;
       }
       tempNode = tempNode->pNext;
    }
    return 0;
}


tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {
        if(pTempNode == pNode)
        {
            return pTempNode->pNext;
        }
        pTempNode = pTempNode->pNext;
    }
    return NULL;
}

```
`struct.c`
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Linktable.h"
int Help()
{
    printf("usage: input your command and press enter\n");
    tDataNode *p=head;
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p=(tDataNode*)p->next;
    }
    return 0;
}
int Version()
{
    printf("the menu program version 0.1 alphae\n");
    return 0;
}
int Exit()
{
    printf("Exiting the program\n");
    exit(0);
}
tLinkTable* create_table()
{
  tLinkTable* table=CreateLinkTable();
  int i=0;
  for(i=0;i<3;i++)
  {
    AddLinkTableNode(table,(tLinkTableNode*)&head[i]);
  }
  return table;
}
void search_command(tLinkTable* table,char* input)
{
    tDataNode *p=(tDataNode*)GetLinkTableHead(table);
    while(p!=NULL)
    {
        if(strcmp(input,p->cmd)==0)
        {
            printf("command %s\n",p->cmd);
            if(p->handler!=NULL)
            {
                p->handler();
            }
            return;
        }
        p=(tDataNode*)GetNextLinkTableNode(table,(tLinkTableNode*)p);
    }
    if(p==NULL)
    {
        printf("command not found %s",input);
    }
}
void destroy_table(tLinkTable* table)
{
    DeleteLinkTable(table);
}

```

### 运行效果

如图所示：
