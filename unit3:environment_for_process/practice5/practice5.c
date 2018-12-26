#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    extern char **environ;
    int indexVar = 0;
    
    while (environ[indexVar] != NULL)
    {
        if (strstr(environ[indexVar], "PWD=") != NULL)
        {
            printf ("%s\n",environ[indexVar]);
        }
        if (strstr(environ[indexVar], "USER=") != NULL)
        {
            printf ("%s\n",environ[indexVar]);
        }
        if (strstr(environ[indexVar], "HOME=") != NULL)
        {
            printf ("%s\n",environ[indexVar]);
        }
        indexVar ++;
    }
    return 0;
}