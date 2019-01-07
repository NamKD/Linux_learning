#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{
    pid_t pid;
    int error = 0;

    pid = fork();
    if (pid == 0)
    {
        printf ("parent process: %d\n", pid);
    }
    else if (pid > 0)
    {
        printf ("child process: %d\n", pid);
        execl ("./child", "child", NULL);
    }
    else
    {
        printf ("Fork function has error!\n");
        error = 1;
    }

    return (error);
}