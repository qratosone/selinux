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
