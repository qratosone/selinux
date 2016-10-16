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
