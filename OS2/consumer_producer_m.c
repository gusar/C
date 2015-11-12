/**
  file producer_consumer.c
  info A sample program to demonstrate the classic consumer/producer problem
  using pthreads.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int buffer;
int number; /* the resource */

void* consumer(void*);
void* producer(void*);

/* Mutex to protect the resource. */
pthread_mutex_t the_mutex = PTHREAD_MUTEX_INITIALIZER;  /* to protect the resource*/
/*
  Condition variable to signal consumer that a new number is available for
  consumption.
*/
pthread_cond_t signalConsumer = PTHREAD_COND_INITIALIZER;
/*
  Condition variable to signal the producer that
  (a) the new number has been consumed,
  (b) generate another one.
*/
pthread_cond_t signalProducer = PTHREAD_COND_INITIALIZER;

/* Main  Function*/
int main(int argc, char *argv[]) {
  if(argv[1] != NULL) buffer = atoi(argv[1]);
  else {
    printf("Enter buffer size as an argument when launching program\n");
    return(0);
  }
  pthread_t first;
  pthread_t secnd;
  number = 0;
  /* Create consumer & producer threads. */
  pthread_create(&first, NULL, consumer, NULL);
  pthread_create(&secnd, NULL, producer, NULL);
  
  /* Wait for consumer/producer to exit. */
  pthread_join(first, NULL);
  pthread_join(secnd, NULL);
	printf("All done!\n");
}

/**
  This function is responsible for incrementing the number and signalling the
  consumer.
*/
void* producer(void *x) {
  while(1) {
    pthread_mutex_lock(&the_mutex);
    number ++;
    printf("Producer: %d\n", number);
    /*
      Signal the consumer that a new number has been generated for its
      consumption.
    */
    pthread_cond_signal(&signalConsumer);
    /*
      Now wait for consumer to confirm. Note, expect no confirmation for
      consumption of buffer from consumer.
    */
    if (number < buffer) {
      pthread_cond_wait(&signalProducer, &the_mutex);
    }
    /* Unlock the mutex. */   
    pthread_mutex_unlock(&the_mutex);

    sleep(1);
    if(number >= buffer) {
      printf("Producer done\n");
      break;
    }
  }
}

/**
  This function is responsible for consuming (printing) the incremented
  number and signalling the producer.
*/
void* consumer(void *x) {
  int printed = 0;
  while(1) {
    pthread_mutex_lock(&the_mutex);
    /* Signal the producer that the consumer is ready. */
    pthread_cond_signal(&signalProducer);
    /* Wait for a new number. */
    pthread_cond_wait(&signalConsumer, &the_mutex);
    /* Consume (print) the number. */
    printf("Consumer: %d\n", number);
    /* Unlock the mutex. */
    pthread_mutex_unlock(&the_mutex);
    /*
      If the buffer number was the last consumed number, the consumer should
      stop.
    */
    if(number >= buffer) {
      printf("Consumer done\n");
      break;
    }
  }
}