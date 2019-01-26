#include <string.h>
#include <stdio.h>
#include <pthread.h>

FILE *file;

void file_write (char *string)
{
    pthread_mutex_t mutex_my_file;

    pthread_mutex_init (&mutex_my_file, NULL);
    
    pthread_mutex_lock (&mutex_my_file);
    file = fopen ("./namkd.txt","w");
    fwrite (string, 1, strlen(string), file);
    fclose (file);
    pthread_mutex_unlock (&mutex_my_file);
}