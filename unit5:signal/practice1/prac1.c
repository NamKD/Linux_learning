#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void ctrlC (int signum)
{
    if (2==signum)
    {
        printf ("NamKD da o day!\n");
        exit(0);
    }
    else
    {
        printf ("Invalid signal\n");
        exit(0);
    }
}


int main ()
{
    int error=0;

    signal(2, ctrlC);
    while(1);

    return (error);
}