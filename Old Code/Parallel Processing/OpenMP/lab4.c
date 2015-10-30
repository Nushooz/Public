// Mark Kaiser
// Lab 4
// CSCI4330
// Dr. Pettey
// This program reads in a matrix and finds its reachability matrix using Warshall's Algorithm.
// Each row is handled in a single thread and the matrix is contained in a global array.
// *NOTE* This program was compiled with the GNU c++ compiler and contains c++ code.
// Additionally the following algorithm was borrowed from the assignment notes for Warshall's Algorithm
// for k=0 to n-1
//    for i = 0 to n-1
//        for j = 0 to n-1
//               M[i,j] = M[i,j] || (M[i,k] && M[k,j])

#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 6
#define MATRIX_SIZE 6

int M[MATRIX_SIZE][MATRIX_SIZE]; // Matrix used for computation

void processMatrix(int i) // Computes row i of Warshall's algorithm
{	
	int k,j; 
	for ( k=0; k < MATRIX_SIZE; k++)
	{
		for( j=0; j < MATRIX_SIZE; j++) // For the columns of row i
		{
			M[i][j] = M[i][j] || (M[i][k] && M[k][j]);
		}	
	}
}

int main (int argc, char *argv[])
{
	int i,j,k;	
	printf("Please enter a 6x6 matrix for Warshall's Algorithm.\n"); // Prompt the user
	for(i = 0; i < MATRIX_SIZE; i++)
	{
		for(j = 0; j < MATRIX_SIZE; j++)
		{
			scanf("%d",&M[i][j]);	// Read in matrix here
		}
	}
	printf("\n");
	
	#pragma omp parallel num_threads(NUM_THREADS) // Perform process matrix in parallel 
	{
		int t;
		for(t=0; t < NUM_THREADS; t++) 
		{
			int id = omp_get_thread_num(); // id is the thread number spawned by openmp
			processMatrix(id);	       
		}
	}

	printf("The reachability matrix is...\n");	
 	for(i = 0; i < MATRIX_SIZE; i++) // Print out the reachability matrix
	{
		for(j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}	
}
