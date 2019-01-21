#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

unsigned long numCount1 = 0;
unsigned long numCount2 = 0;
unsigned long numCount3 = 0;
unsigned long numCount4 = 0;

char* getTime (void)
{
	time_t timestamp = time(NULL);
	return (ctime(&timestamp));
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

    pthread_create (&tid1, NULL, &count1, &numCount1);
    // pthread_join (tid1, NULL);

	// for (index = 50000000000; index <= 100000000000; index++)
	// {
	// 	if (index%2 != 0)
	// 	{
	// 		numCount2++;
	// 	}
	// }

    pthread_create (&tid2, NULL, &count2, &numCount2);
    // pthread_join (tid2, NULL);
    pthread_create (&tid3, NULL, &count3, &numCount3);
    // pthread_join (tid3, NULL);
    pthread_create (&tid4, NULL, &count4, &numCount4);
    pthread_join (tid4, NULL);
	pthread_join (tid3, NULL);
	pthread_join (tid2, NULL);
	pthread_join (tid1, NULL);

	printf ("%lu\n", (numCount1 + numCount2 + numCount3 + numCount4));
	printf ("%s\n",getTime());
	return 0;	
}
