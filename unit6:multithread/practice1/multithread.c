#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h> 

unsigned long numCount1 = 0;
unsigned long numCount2 = 0;
unsigned long numCount3 = 0;
unsigned long numCount4 = 0;

char* getTime (void)
{
	time_t timestamp = time(NULL);
	return (ctime(&timestamp));
}

int threadSelectCore(int core_id) 
{
   int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
   if (core_id < 0 || core_id >= num_cores)
      return -1;

   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
   CPU_SET(core_id, &cpuset);

   pthread_t current_thread = pthread_self();    
   return pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset);
}

void* count1 (void* numOfcount1)
{
	unsigned long index = 0;
	for (index = 0; index <= 25000000000; index++)
	{
		if (index%2 != 0)
		{
			(*(unsigned long*)numOfcount1)++;
		}
	}
    return NULL;
}
void* count2 (void* numOfcount2)
{
	unsigned long index = 0;
	for (index = 25000000000; index <= 50000000000; index++)
	{
		if (index%2 != 0)
		{
			(*(unsigned long*)numOfcount2)++;
		}
	}
    return NULL;
}
void* count3 (void* numOfcount3)
{
	unsigned long index = 0;
	for (index = 50000000000; index <= 75000000000; index++)
	{
		if (index%2 != 0)
		{
			(*(unsigned long*)numOfcount3)++;
		}
	}
    return NULL;
}
void* count4 (void* numOfcount4)
{
	unsigned long index = 0;
	for (index = 75000000000; index <= 100000000000; index++)
	{
		if (index%2 != 0)
		{
			(*(unsigned long*)numOfcount4)++;
		}
	}
    return NULL;
}

int main ()
{
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
	unsigned long index = 0;

	printf ("%s\n",getTime());

	threadSelectCore(0);
    pthread_create (&tid1, NULL, &count1, &numCount1);
    pthread_join (tid1, NULL);

	threadSelectCore(1);
    pthread_create (&tid2, NULL, &count2, &numCount2);
    pthread_join (tid2, NULL);

	threadSelectCore(2);
    pthread_create (&tid3, NULL, &count3, &numCount3);
    pthread_join (tid3, NULL);

	threadSelectCore(3);
    pthread_create (&tid4, NULL, &count4, &numCount4);
    pthread_join (tid4, NULL);
	// pthread_join (tid3, NULL);
	// pthread_join (tid2, NULL);
	// pthread_join (tid1, NULL);

	printf ("%lu\n", (numCount1 + numCount2 + numCount3 + numCount4));
	printf ("%s\n",getTime());
	return 0;	
}
