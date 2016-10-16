#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_


typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOfNode;
}tLinkTable;

tLinkTable * CreateLinkTable();

int DeleteLinkTable(tLinkTable *pLinkTable);

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pLinkTableNode);

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pLinkTableNode);

tLinkTableNode* GetLinkTableHead(tLinkTable *pLinkTable);


#endif
