/** @file shell.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 1000



/**
 * Starting point for shell.
 */
void prefix()
{
    char* buffer=(char*)malloc(MAX_SIZE);
    getcwd(buffer,MAX_SIZE);
    printf("(pid=%d)%s$ ", getpid(), buffer);
    free(buffer);
}

int split(char *args[],char* str,const char* spl)
{
    int n=0;
    char* result=NULL;
    result=strtok(str,spl);
    while(result!=NULL)
    {
        args[n]=(char*)malloc(strlen(result)+1);
        strcpy(args[n++],result);
        result=strtok(NULL,spl);
    }
    return n;
}
int execute(char* buffer)
{
    int i=0;
    if(strncmp("cd",buffer,2)==0)
    {
        for(i=0;i<strlen(buffer);i++)
        {
            if(buffer[i]==' ')
            {
                break;
            }
        }
        int result=chdir(buffer+i+1);
        if(result<0)
        {
            printf("%s: No such file or directory\n",buffer+i+1);
        }
    }
    else if(strcmp("exit",buffer)==0)
    {
        return 0;
    }
    else if(strcmp("help",buffer)==0)
    {
        printf("Help:\n");
        printf("You can use cd command to enter a directory, use exit command to exit ,or directly input a program name to execute\n");
    }

    else if(strcmp("plus_calc",buffer)==0)
    {
        int numA,numB;
        printf("Input the two number A and B:");
        scanf("%d %d",&numA,&numB);
        printf("A + B = %d \n",numA+numB);
    }
    else if(strcmp("new",buffer)==0){
        char filename[100];
        printf("input new file name: ");
        scanf("%s",filename);
        fopen(filename,"a");
        printf("%s created.\n",filename);
    }
    else if(strlen(buffer))
    {
        char* args[10];
        int i=0;
        for(i=0;i<10;i++){
            args[i]=NULL;
        }
        split(args,buffer," ");
        pid_t pid=fork();
        if(pid>0){//father
            int status;
            waitpid(pid,&status,0);
        }
        else{//child
            //确保子进程被杀死
            if(execv(buffer,args)){
                printf("%s: not found\n",buffer);
            }
            for(i=0;i<10;i++){
                free(args[i]);
            }
            exit(0);

        }
        for(i=0;i<10;i++){
            free(args[i]);
        }

    }
    return 1;

}
int main() {

    prefix(); //显示路径
    size_t len=0;
    char* buffer=NULL;
    while(getline(&buffer,&len,stdin)!=-1){//读取命令
        buffer[strlen(buffer)-1]='\0';//末位设置为0
        if(!execute(buffer)){//执行命令
            break;
        }
        prefix();
        free(buffer);//释放内存
        buffer=NULL;
    }
    if(buffer!=NULL){//意外终止的处理
        free(buffer);
        buffer=NULL;
    }

    return 0;
}

