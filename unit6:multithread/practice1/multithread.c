#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>


unsigned long numCount1 = 0;
unsigned long numCount2 = 0;

char* getTime (void)
{
	time_t timestamp = time(NULL);
	return (ctime(&timestamp));
}
void* count1 (void* numOfcount1)
{
	unsigned long index = 0;
	for (index = 0; index <= 50000000000; index++)
	{
		if (index%2 != 0)
		{
			(unsigned long)numOfcount1++;
		}
	}
    return NULL;
}
void* count2 (void* numOfcount2)
{
	unsigned long index = 0;
	for (index = 50000000000; index <= 100000000000; index++)
	{
		if (index%2 != 0)
		{
			(unsigned long)numOfcount2++;
		}
	}
    return NULL;
}

int main ()
{
    pthread_t tid1;
    // pthread_t tid2;

	printf ("%s\n",getTime());

    pthread_create (&tid1, NULL, &count1, &numCount1);
    pthread_join (tid1, NULL);
    // pthread_create (&tid2, NULL, &count2, &numCount2);
    // pthread_join (tid2, NULL);

	printf ("%lu\n", (numCount1 + numCount2));
	printf ("%s\n",getTime());
	return 0;	
}
