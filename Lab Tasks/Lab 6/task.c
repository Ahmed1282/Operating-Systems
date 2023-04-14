#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int main () 
{  
    char message[] = "Message", temp[40], acknowledge[] = " Acknowledged", concat[40];
    int status = 0;
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);
    pid_t child_pid = fork();


    if (child_pid>0)
    {
        close(fd1[0]);
        close(fd2[1]);

        write(fd1[1], message, sizeof(message));

        wait(&status);

        read (fd2[0] ,concat ,sizeof(concat)) ;

        printf("Concat String is : %s\n", concat);

        close(fd1[1]);
        close(fd2[0]);
    }
    else if(child_pid==0)
    {
        close(fd1[1]);
        close(fd2[0]);

        read (fd1[0] ,temp ,sizeof(temp)) ;

        strcat(temp, acknowledge);
        
        write(fd2[1], temp, sizeof(temp));
        
        close(fd1[0]);
        
        close(fd2[1]);
        exit(0);
    }
    else
    {
        printf("Fork error \n");
    }
}