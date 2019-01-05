#include <stdio.h>
#include <stdlib.h>

void foo()
{
    printf("Hello, I'm a shared library\n");
    system("echo PhuThoDien > /home/namkd/Desktop/output.txt");
}
