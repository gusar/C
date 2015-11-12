#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* producer(void*);
void* consumer(void*);

int  size;
int  buffer[2];

sem_t empty,full;

int main(int argc, char* argv[]) {
	if(argv[1] != NULL) size = atoi(argv[1]);
  	else {
   	printf("Enter buffer size as an argument when launching program\n");
   	return(0);
  	}

	buffer[0] = 0;
	buffer[1] = 0;
	pthread_t first, secnd;

	sem_init(&empty, 0, size);
	sem_init(&full, 0, 0);

	pthread_create(&first,NULL,producer,NULL);
	pthread_create(&secnd,NULL,consumer,NULL);
	
	void *status;
	pthread_join(first,&status);
	printf("%s finished 1st\n",(char*)status);
	pthread_join(secnd,&status);
	printf("%s finished 2nd\n",(char*)status);
	return 0;
}

void* producer(void *x) { 
	printf("Producer started\n"); 

	while(1) {
		sem_wait(&empty); 

		buffer[0]++; 
		printf("Producer: %d\n",buffer[0]); 

		sem_post(&full);

		if(buffer[0] >= size) break;
		sleep(1); 
	} 
	pthread_exit("Producer");
}

void * consumer(void *x) { 
	printf("Consumer started\n"); 

	while(1) {
		sem_wait(&full);

		buffer[1]++;
		printf("Consumer: %d\n", buffer[1]); 

		sem_post(&empty);

		if(buffer[1] >= size) break;
		sleep(2); 
	}
	pthread_exit("Consumer");
}