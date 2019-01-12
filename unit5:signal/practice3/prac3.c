#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main ()
{
    sigset_t x;

    sigemptyset (&x);
    sigaddset(&x, SIGINT);
    sigprocmask(SIG_BLOCK, &x, NULL);

    while (1);
    
    return 0;
}