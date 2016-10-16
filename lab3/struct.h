#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;
int Help();
int Version();
int Exit();
static tDataNode head[]=
{
    {"help","this is help cmd!",Help,&head[1]},
    {"version","menu program v1.0",Version,&head[2]},
    {"exit","exit the program",Exit,NULL}
};
void search_command(char* input);
#endif
