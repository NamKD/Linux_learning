#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
    int appPid = 0;

    appPid = getpid();
    system ("sleep 5s");
    printf ("PID of appA: %d\n", getpid());
    printf ("GPID of appA: %d\n", getpgid(appPid));

    return 0;
}