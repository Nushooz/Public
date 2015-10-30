#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	MPI_Status status;
	int nproc, myrank;
	

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	
	if ( nproc >= 5 && nproc <= 14 )
	{	
		printf("%s %d\n", "Doing work from process", myrank);
	}
	else if ( myrank == 0 ) 
	{
		printf("%s \n", "Please make sure the number of processes is between 5-14.");
	}

	MPI_Finalize();
	return 0;
}
	
	
