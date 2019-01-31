#include <string.h>
#include <stdio.h>
#include <pthread.h>

extern void file_write (char *string);

void *sub_thread (void *argu)
{
    char str[1000] = {0};
    int b = 50;

    sprintf (str, "The sub thread is: %d\n", b);
    file_write(str);

    return 0;
}

int main (void)
{
    pthread_t tid;
    char str[1000] = {0};
    int a = 100;

    pthread_create (&tid, NULL, &sub_thread, NULL);
    pthread_join (tid, NULL);
    sprintf (str, "The main thread is: %d\n", a);
    file_write(str);

    return 0;
}
