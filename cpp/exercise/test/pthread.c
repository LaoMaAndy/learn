/* pthread.c */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread(void *vargp);

void foo()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread, NULL);
	pthread_join(tid, NULL);
	exit(0);
}
void foa()
{
	printf("sizeof pthread_t: %ld\n", sizeof(pthread_t));
	printf("ID is: %ld\n", pthread_self());
}
int main()
{
	foa();
	foo();
}

void *thread(void *vargp)
{
	printf("hello, world\n");
	return NULL;
}

