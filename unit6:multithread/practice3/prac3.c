#include <string.h>
#include <stdio.h>
#include <pthread.h>

FILE *file;
int my_index = 0;
pthread_mutex_t mutex_my_index;

void *sub_thread (void *argu)
{
	pthread_mutex_lock(&mutex_my_index);
	my_index++;
	pthread_mutex_unlock(&mutex_my_index);
	printf ("my_thread=%d\n", my_index);
}

int main (void)
{
	pthread_t tid;
	pthread_mutex_init (&mutex_my_index, NULL);
	while (my_index < 100)
	{	
		pthread_create (&tid, NULL, &sub_thread, NULL);
		pthread_join (tid, NULL);
		pthread_mutex_lock(&mutex_my_index);
		my_index++;
		pthread_mutex_unlock(&mutex_my_index);
		printf ("main_thread=%d\n", my_index);
	}
}
