/* thello.c */
#include <pthread.h>
#include <stdio.h>

void *thread(void *id)
{
	printf("my id: %ld\n", (long)id);
	printf("Hello, world\n");
	return NULL;
}
void foo()
{
	pthread_t th;
	pthread_create(&th, NULL, thread, NULL);
	pthread_join(th, NULL);
}

int main()
{
	pthread_t id, id2;
	pthread_create(&id, NULL, thread, (void *)id);
	pthread_create(&id2, NULL, thread, (void *)id2);
	pthread_join(id, NULL);
	pthread_join(id2, NULL);
	return 0;
}

