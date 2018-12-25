#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void prac2_sharedLib(char *path);

int main (int argc, char *path[])
{
    prac2_sharedLib (path[1]);

    return 0;
} 