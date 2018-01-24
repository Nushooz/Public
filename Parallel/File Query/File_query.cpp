// Mark Kaiser
// Lab 2
// CSCI4330
// Dr. Pettey
// This program reads in a user query to process 0. This query is sent to all other available processes to search for the query
// within the .sort files provided. Upon completion of the search the process sends back the list to process 0. Process 0 then
// reports all the incidents of the query and their count. If the word is not present process 0 will say so. The program terminates
// when a -1 is given as the query input. 

#include "mpi.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

void openFile(map<string,set<string> >& myMap, int rank, int nproc)
{
	int count;
	string word, temp;
	stringstream out;
	string index; 
	map<string,set<string> >::iterator it;
	set<string>::iterator its;

	for( int i = 1; i < 13; i++ )
	{
		if ( i % ( nproc-1 ) == rank - 1 ) // Split files over processes
		{
			out << i;	// Convert rank into a string
			temp = out.str();
			temp = temp + ".sort";
			ifstream streamIn;
			streamIn.open( temp.c_str() );
			while ( streamIn ) 
			{
				streamIn >> count;
				streamIn >> word;
			
				for(int i = 0; i < count; i++)
				{
					streamIn >> index;
					myMap[word].insert(index);
				} 
			}
			streamIn.close();
		}
	}
//	for (it=myMap.begin(); it != myMap.end(); it++)
//	{
//		cout << (*it).first << " => "; // << (*it).second << endl;
//		for (its=((*it).second).begin(); its!=((*it).second).end(); its++)
//		{
//			cout << " " << *its;
//		}
//		cout << endl;
//	}
}

void searchFile( string query, map<string,set<string> > myMap )
{
	map<string,set<string> >::iterator it;
	set<string>::iterator its;	
	
	if ( myMap.count(query) > 0 )
	{
		cout << query;
		for (its=myMap[query].begin(); its != myMap[query].end(); its++)
		{
			cout << " " << *its;
		}
		cout << "\n";
	}
}	

int main(int argc, char* argv[])
{
	const int QSIZE = 128;

	MPI_Status status;
	int nproc, myrank;
	string query, temp;
	char cquery[QSIZE];

	map<string,set<string> > myMap;
	map<string,set<string> >::iterator it;
	set<string>::iterator its;
	 	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	if ( myrank == 0 )
	{
		if ( (nproc >= 3 && nproc <= 5) || nproc == 7 || nproc == 13 )
		{
			cout << "Please enter a query(or enter a -1 to quit): "; // Prompt for query
			cin >> query;
			strcpy(cquery, query.c_str()); // Copy the query to a c-string 
			
			MPI_Bcast(&cquery, QSIZE, MPI_CHAR, 0, MPI_COMM_WORLD);  // Send first query to procs 1-n
			for( int i = 1; i < nproc; i++ ) // For process 0, wait for a reply back from all the others
			{			
				MPI_Recv(&cquery, QSIZE, MPI_CHAR, i, 1, MPI_COMM_WORLD, &status);
			//	cout << "Process 0 recieved reply from process " << i <<  endl;
			}			
			
			cout << "\nPlease enter a query(or enter a -1 to quit): "; // Prompt for query
			cin >> query;
			strcpy(cquery, query.c_str()); // Copy the query to a c-string 

			while ( query.find("-1") == string::npos ) // While -1 is not in the query
			{
				MPI_Bcast(&cquery, QSIZE, MPI_CHAR, 0, MPI_COMM_WORLD);  // Broadcast the query				
				for( int i = 1; i < nproc; i++ ) // For process 0, wait for a reply back from all the others
				{			
					MPI_Recv(&cquery, QSIZE, MPI_CHAR, i, 1, MPI_COMM_WORLD, &status);
				//	cout << "Process 0 recieved reply from process " << i <<  endl;
				}
				
				// Need to wait for others to finish before this
				cout << "\nPlease enter a query(or enter a -1 to quit): "; // Prompt for query
				cin >> query; // Read in the next query	
				strcpy(cquery, query.c_str());
			}

			MPI_Bcast(&cquery, QSIZE, MPI_CHAR, 0, MPI_COMM_WORLD); // Final Broadcast to exit
			for( int i = 1; i < nproc; i++ ) // For process 0, wait for a reply back from all the others
			{			
				MPI_Recv(&cquery, QSIZE, MPI_CHAR, i, 1, MPI_COMM_WORLD, &status);
			//	cout << "Process 0 recieved reply from process " << i <<  endl;
			}
		}
		else  // Else the wrong number of processes was used
		{
			cout << "This program must be run on 3, 4, 5, 7, or 13 processes." << endl;
			cout << "Please try again with the appropriate number of processes." << endl;
		}
	}
	else
	{
		if ( (nproc >= 3 && nproc <= 5) || nproc == 7 || nproc == 13 )
		{
			MPI_Bcast(&cquery, QSIZE, MPI_CHAR, 0, MPI_COMM_WORLD); // Get first query
			query = (const char*)cquery;	// // Convert cquery back to std::string to use find function
			openFile( myMap, myrank, nproc );
			searchFile( query, myMap );
				
			MPI_Send(&cquery, QSIZE, MPI_CHAR, 0, 1, MPI_COMM_WORLD); // Send a recieve message back to p0 		
					 	
			while ( query.find("-1") == string::npos )
			{   
				MPI_Bcast(&cquery, QSIZE, MPI_CHAR, 0, MPI_COMM_WORLD);
				searchFile( query, myMap );
				// now query	
				MPI_Send(&cquery, QSIZE, MPI_CHAR, 0, 1, MPI_COMM_WORLD);  // Send a recieve message back to p0	
				
				query = (const char*)cquery; // Convert cquery back to std::string for next query
			}
		}
	}
	
	
	if ( myrank == 1 ) //Final Block, comment out for debug
	{	
		cout << "Exiting..." << endl;
		cout << "myMap contains:\n";
		for (it=myMap.begin(); it != myMap.end(); it++)
  		{
			cout << (*it).first << " => "; // << (*it).second << endl;
		 	for (its=((*it).second).begin(); its!=((*it).second).end(); its++)
    			{
				cout << " " << *its;
			}
			cout << endl;
		}
	}
	
	MPI_Finalize();
	return 0;
}
