#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// Global variable
int gVar = 0;


void ctrlC (int signum)
{
    if (12==signum)
    {
        printf ("NamKD da o day!\n");
        gVar = gVar + 1;
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

    signal(12, ctrlC);
    while(gVar == 0);
    printf ("Out of loop!\n");

    return (error);
}