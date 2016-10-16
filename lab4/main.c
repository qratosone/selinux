#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#define max_buffer_size 128
int main()
{
    char input[max_buffer_size];
    while(1)
    {
        printf("Please input your command:");
        scanf("%s",input);
        search_command(input);
    }
    return 0;
}
