//producer consumer using semaphore

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* producer(void *arg);
void* consumer(void *arg);
char buff[20];
sem_t full, empty;

int main() {
	pthread_t pid,cid;

	sem_init(&empty,0,1);
	sem_init(&full,0,0);

	pthread_create(&pid,NULL,producer,NULL);
	pthread_create(&cid,NULL,consumer,NULL);

	pthread_join(pid,NULL);
	pthread_join(cid,NULL);
}


void* producer(void*arg) {
	while(1) {
		sem_wait(&empty);

		printf("\nEnter Mes to be add into buffer:");
		scanf("%s",buff);

		if(strncmp(buff,"end",3)==0)
		sem_post(&full);
	}
}


void* consumer(void *arg) {
	while(1) {
	sem_wait(&full);

	printf("\nConsumed item is %s\n",buff);
	if(strncmp(buff,"end",3)==0)

		sem_post(&empty);
		break;
	}
}

