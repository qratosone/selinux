#include "Linktable.h"
#include <stdio.h>
#include <stdlib.h>

tLinkTable * CreateLinkTable()
{
    tLinkTable * table=(tLinkTable*)malloc(sizeof(tLinkTable));
    table->pHead=NULL;
    table->pTail=NULL;
    SumOfNode=0;
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
    if(pLinkTable->pNext==NULL)
    {
        pLinkTable->pNext=pNode;
    }
    else
    {
        tLinkTableNode *ptr_tail=pLinkTable->pTail;
        ptr_tail->pNext=pLinkTableNode;
        pLinkTable->pTail=pLinkTableNode;
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
    if(pLinkTable->pHead)
}

