
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int sixty = 60;
const int max_min = 80;

int main ()
{
	int song_num;
	int time; 
	int min;
	int sec;
	int a_time;
	int a_min;
	int a_sec;
	int r_time;
	int r_min;
	int r_sec;
	
	string fullName;
	ifstream inFile;
	ofstream outFile;
	string inFileName;
	string outFileName;

	cout << "Please enter the input file name" << endl;
	cin >> inFileName;

	inFile.open(inFileName.c_str());

	while (!inFile)
	{
	cout << "** Can't open input file. Please enter another input file: **" << endl;
	cin >> inFileName;
	inFile.open(inFileName.c_str());
	}


	cout << "Please enter output file name" << endl;
	cin >> outFileName;

	outFile.open(outFileName.c_str());

	song_num = 0;
	a_time = 0;
	inFile >> time;
	while (inFile)
	{
		if (song_num <= 7)
		{
			song_num++;
			outFile << song_num;
		}
	outFile << "Song" << setw(22) << "Song Time" << setw(22) << "Total Time" << endl
           << "Number"<< setw(22) << "Minutes" << setw(3) << "Seconds" << setw(22) << "Minutes"<< setw(2) << "Seconds" << endl
           << "---------" << setw(22) << "---------" << setw(3) << "---------" << setw(22) << "---------" << setw(2) << "---------" << endl;
	}
while (inFile)
{
  
  
  // Calculate the individual times
  min = time / sixty;
  sec = time % sixty;
  outFile << min << setw(10) << sec << setw(13);
  
  // Prepare the final formulas to exacute
  a_sec = a_sec + sec;
  if (a_sec >= sixty)
  {
   r_time = a_sec / sixty;
  }
  else 
   r_time = 0;
  // Calculate the total time
  a_sec = a_sec % sixty;
  a_min = a_min + min + r_time;
  
  // Print the final times
  outFile << a_min << setw(9) << a_sec << endl;
  
  // Set the information for the next loop
  sec = 0;
  inFile >> sec;
  } 
 
 // 4.Calculate for the space remaining 
 min = max_min - a_min -1;
 sec = (sixty - a_sec);

		outFile << "There are " << r_min << " minutes and " << r_sec << " seconds of space left on the 80 minute CD." << endl;
}	
	inFile.close();
	outFile.close();
	return 0;
}
