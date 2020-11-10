#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
 char name[20];
 printf("Name: ");
 scanf("%s",name);
 printf("your name : %s\n",name);
}

void parentTask()
{
 printf("Job is Done\n");
}

int main(void)
{
  pid_t pid=fork();
  if(pid==0)
   {
    for(int i=0;i<4;i++)
    {
     childTask();
    }
   }
  else if(pid>0)
   {
    printf("Parent pid =%d\n",getpid());
    wait(NULL);
    parentTask();
   }
  else
   {
    printf("Error occured");
   }
 return 0;
}
