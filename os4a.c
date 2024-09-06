//	PRODUCER CONSUMER PROBLEM
//	compile --> gcc prac4a.c -o prac4a -lpthread
//	run		--> ./prac4a


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>	//	IMPORTANT LIBRARY
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0, NUM_CONSUMERS, NUM_PRODUCERS;
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
	
	int producer_id = *((int *) arg);
	int item;
	while(1)
	{
		item = rand() % 100;
		
		if(count == BUFFER_SIZE)
		{
			printf("\t\t\t\tBUFFER FULL\t\t\t\t\n");
			sleep(1);
		}
		
		sem_wait(&empty);	//	decrementing the empty counter
		pthread_mutex_lock(&mutex);
		
		printf("\n----- Producer Id [ %d ] inside the critical section -----\n", producer_id);
		buffer[count++] = item;
		printf("\n\nProducer %d produced item : %d\n", producer_id, item);
		printf("\nBuffer size : %d\n", count);
		
		
		pthread_mutex_unlock(&mutex);	//	incrementing the full counter
		sem_post(&full);
		sleep(1);
	}
	
	pthread_exit(NULL);

}

void *consumer(void *arg)
{
	int consumer_id = *((int *) arg);
	int item;
	
	while(1)
	{
		if(count == 0)
		{
			printf("\n\t\t\tBUFFER EMPTY\t\t\t\n");
			sleep(1);
		}
		
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		
		printf("\n----- Consumer Id [ %d ] inside the critical section -----\n", consumer_id);
		item = buffer[--count];
		
		printf("\n\nConsumer %d consumed item number = %d\n", consumer_id, item);
		
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		sleep(2);
		
	}
	
	pthread_exit(NULL);

}

int main()
{
	printf("\n\t\t\t\tProducer-Consumer Problem\t\t\t\t\n");
	printf("\t\t\tEnter Consumer and Producer Count [ C P ] : \t\t\t\n");
	scanf("%d%d", &NUM_CONSUMERS, &NUM_PRODUCERS);
	
	pthread_t producer_threads[NUM_CONSUMERS];
	pthread_t consumer_threads[NUM_PRODUCERS];
	
	sem_init(&empty, 0, BUFFER_SIZE);	//	initializing it with buffer size
	sem_init(&full, 0, 0);				//	initializing it with 0
	
	pthread_mutex_init(&mutex, NULL);
	
	int producer_ids[NUM_CONSUMERS];
	int consumer_ids[NUM_PRODUCERS];
	
	
	//	creating the threads using the producer function
	for(int i = 0; i < NUM_PRODUCERS; i++)
	{
		producer_ids[i] = i+1;
		pthread_create(&producer_threads[i], NULL, producer, &producer_ids[i]);
	}
	
	//	creating the threads using the consumer function
	for(int i = 0; i < NUM_CONSUMERS; i++)
	{
		consumer_ids[i] = i+1;
		pthread_create(&consumer_threads[i], NULL, consumer, &consumer_ids[i]);
	}
	
	//	joining the producer threads to the process
	for(int i = 0; i < NUM_PRODUCERS; i++)
	{
		pthread_join(producer_threads[i], NULL);
	}
	
	//	joining the consumer threads to the process
	for(int i = 0; i < NUM_CONSUMERS; i++)
	{
		pthread_join(consumer_threads[i], NULL);
	}
	
	
	//	deleting the semaphore and mutex
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);
	
	
	return 0;
}