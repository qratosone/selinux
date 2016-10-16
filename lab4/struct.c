#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
int Help()
{
    printf("usage: input your command and press enter\n");
    tDataNode *p=head;
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p=p->next;
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
void search_command(char* input){
    tDataNode *p=head;
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
        p=p->next;
    }
    if(p==NULL)
    {
        printf("command not found %s",input);
    }
}
