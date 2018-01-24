// This program reads in a matrix and finds its reachability matrix using Warshall's Algorithm.
// Each row is handled in a single thread and the matrix is contained in a global array.
// Additionally the following algorithm was is used for Warshall's Algorithm
// for k=0 to n-1
//    for i = 0 to n-1
//        for j = 0 to n-1
//               M[i,j] = M[i,j] || (M[i,k] && M[k,j])

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#define NUM_THREADS 6
#define MATRIX_SIZE 6

using namespace std;

int M[MATRIX_SIZE][MATRIX_SIZE];
int threadCount;

pthread_mutex_t mut;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *processMatrix(void *threadid)
{
	int i = (int)threadid; // Row the thread is working on

	for (int k=0; k < MATRIX_SIZE; k++)
	{
		for(int j=0; j < MATRIX_SIZE; j++) // For the columns of row i
		{
			M[i][j] = M[i][j] || (M[i][k] && M[k][j]);
		}	
		pthread_mutex_lock(&mut); // Lock the mutex
		threadCount++;		 // Increase the count
	
		if ( threadCount < MATRIX_SIZE )        // If not all threads have been processed
			pthread_cond_wait(&cond, &mut); // 	Wait
		else if( threadCount == MATRIX_SIZE )   // Else wake all the threads and reset the count
		{
			pthread_cond_broadcast(&cond);
			threadCount = 0;   
		}		
				
		pthread_mutex_unlock(&mut); // Release the mutex
	}
	
   	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS]; // Array of threads for processMatrix
	pthread_mutex_init(&mut, NULL); // Initialize Matrix
	threadCount = 0;
	ifstream streamin;
	streamin.open("matrix.dat");   // Edit this line to use a datafile for testing

	
	printf("Please enter a 6x6 matrix for Warshall's Algorithm.\n");
	for(int i = 0; i < MATRIX_SIZE; i++)
	{
		for(int j = 0; j < MATRIX_SIZE; j++)
		{
		//	streamin >> M[i][j];  // Uncomment for input from a datafile
			cin >> M[i][j];       // Read in matrix here
		}
	}
	printf("\n");
	streamin.close();
	
	for(int t=0; t < NUM_THREADS; t++) // For all the threads
		pthread_create(&threads[t], NULL, processMatrix, (void *)t); //Process the matrix row
	
	for (int i = 0; i < NUM_THREADS; i++) // Join all the threads back
		pthread_join(threads[i], NULL);
	
	printf("The reachability matrix is...\n");	
 	for(int i = 0; i < MATRIX_SIZE; i++) // Print out the reachability matrix
	{
		for(int j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}	
   	pthread_exit(NULL); 
}
