// Mark Kaiser
// Lab 3
// CSCI4330
// Dr. Pettey

//for k=0 to n-1
//    for i = 0 to n-1
//        for j = 0 to n-1
//               M[i,j] = M[i,j] || (M[i,k] && M[k,j])

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 6

void *PrintHello(void *threadid)
{
	long tid;
   	tid = (long)threadid;
   	printf("Hello World! It's me, thread #%ld!\n", tid);
   	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		 //pthread_join(		
	}
   	pthread_exit(NULL);
}
