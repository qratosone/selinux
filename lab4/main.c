#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Linktable.h"
#define max_buffer_size 128
int main()
{
    char input[max_buffer_size];
    tLinkTable* table=create_table();
    while(1)
    {
        printf("Please input your command:");
        scanf("%s",input);
        search_command(table,input);
    }
    destroy_table(table);
    return 0;
}
