#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>
#include "Linktable.h"
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
typedef struct DataNode
{
    tLinkTableNode* next;
    char* cmd;
    char* desc;
    int (*handler)();
}tDataNode;

int Help();
int Version();
int Exit();


static tDataNode head[]=
{
    {(tLinkTableNode*)&head[1],"help","this is help cmd!",Help},
    {(tLinkTableNode*)&head[2],"version","menu program v1.0",Version},
    {NULL,"exit","exit the program",Exit}
};
tLinkTable* create_table();
void search_command(tLinkTable* table,char* input);
void destroy_table(tLinkTable* table);
#endif
