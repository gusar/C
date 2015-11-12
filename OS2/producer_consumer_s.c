/*
   Solution to the producer-consumer 
   problem using semaphores and mutex.
   Andrejs Lahs
   C13766231
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int buffer; // buffer size
int number; // resource

sem_t empty,full; // semaphores

void* consumer(void*);
void* producer(void*);

/* Mutex limits access to the resource */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


/* Main  Function*/
int main(int argc, char *argv[]) {
   // Get argument and init resource
   if(argv[1] != NULL) {
      buffer = atoi(argv[1]);
      number = 0;
   }
   else {
      printf("Enter buffer size as an argument when launching program\n");
      return(0);
   }

   // Create two semaphores
   sem_init(&empty, 0, 1);
   sem_init(&full, 0, 0);

   // Create two threads
   pthread_t first, secnd;

   /* Create consumer and producer threads. */
   pthread_create(&first, NULL, consumer, NULL);
   pthread_create(&secnd, NULL, producer, NULL);
  
   /* Wait for threads to exit. */
   pthread_join(first, NULL);
   pthread_join(secnd, NULL);
	printf("All done!\n");
}

/* Increment the number and signal the consumer */
void* producer(void *x) {
   while(1) {
      sem_wait(&empty); 
      pthread_mutex_lock(&mutex);

      number++;
      printf("Producer: %d\n", number);

      pthread_mutex_unlock(&mutex);
      sem_post(&full);

      // End if no more buffers
      if(number >= buffer) {
         printf("Producer done\n");
         break;
      }
      sleep(1);
   }
}

/* Consume the number and signal the producer */
void* consumer(void *x) {
   while(1) {
      sem_wait(&full);
      pthread_mutex_lock(&mutex);
    
      printf("Consumer: %d\n", number);

      /* Unlock the mutex. */
      pthread_mutex_unlock(&mutex);
      sem_post(&empty);

      if(number >= buffer) {
         printf("Consumer done\n");
         break;
      }
   }
}


/*
   Initial credit belongs to http://nirbhay.in/2013/07/producer_consumer_pthreads/
   Modified to include semaphores by Andrejs Lahs.
*/