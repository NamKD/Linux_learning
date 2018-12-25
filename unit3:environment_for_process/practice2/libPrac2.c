#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void prac2_sharedLib (char *path)
{
    if (path != NULL)
    {
        printf ("%s\n", path);
    }
    else
    {
        printf ("Invalid argument\n");
    }
}