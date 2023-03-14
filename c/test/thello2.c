/* thello.c */
#include <pthread.h>
#include <stdio.h>


void *thread(void *);

int main()
{
	pthread_t th;
	
	pthread_create(&th, NULL, thread, NULL);
	pthread_join(th, NULL);
	
	return 0;
}

void *thread(void *p)
{
	printf("hello, world\n");
	return NULL;
}

