#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
    int appPid = 0;

    appPid = getpid();
    system ("sleep 5s");
    printf ("PID of appC: %d\n", getpid());
    printf ("SPID of appC: %d\n", getsid(appPid));

    return 0;
}