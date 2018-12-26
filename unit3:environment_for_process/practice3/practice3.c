#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main (int argc, char *path[])
{
    int tmp = 0;
    int returnValue = 0;

    if (argc == 2)
    {
        tmp = open(path[1],O_RDONLY);
        if (tmp > 0)
        {
            printf ("open successfully!\n");
            returnValue = 0;
        }
        else
        {
            printf ("open not successful!\n");
            returnValue = 1;
        }
    }
    else
    {
        printf ("Invalild argument!\n");
        returnValue = 2;
    }
    return (returnValue);
}