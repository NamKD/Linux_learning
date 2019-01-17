#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* getTime (void)
{
	time_t timestamp = time(NULL);
	return (ctime(&timestamp));
}

int main ()
{
	unsigned long count = 0;
	unsigned long index = 0;

	printf ("%s\n",getTime());
	for (index = 0; index <= 100000000000; index++)
	{
		if (index%2 != 0)
		{
			count++;
		}
	}
	printf ("%lu\n", count);
	printf ("%s\n",getTime());
	return 0;	
}
