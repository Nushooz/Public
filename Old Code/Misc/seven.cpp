#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string temp;
	string::iterator it;
	char myChar;
	
	ifstream inStream;
	inStream.open("example.txt");
	
	inStream.get( myChar );
	while ( inStream != NULL )
	{
		switch ( myChar )
		{
			case ' ': cout << "%20"; break;
			case '!': cout << "%21"; break;
			case '$': cout << "%24"; break;
			case '%': cout << "%25"; break;
			case '(': cout << "%28"; break;
			case ')': cout << "%29"; break;
			case '*': cout << "%2a"; break;
			case '#': ;		 break;
			default: cout << myChar; break;
		}
		inStream.get( myChar );
	} 

	return 0;				
}
