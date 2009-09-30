#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


int main() {
	
	// read the first line
	int numberOfBins;
	cin >> numberOfBins;
	
	// create the lists
	list<int> listArray[numberOfBins];
	
	// initialize them
	for(size_t i = 0; i < numberOfBins; ++i)
	{
		listArray[i].push_back(i);
	}
	
	// read each command and parse it
	char com1[5], com2[5];
	int x1, x2;
	while( scanf( "%s %d %s %d\n", com1, &x1, com2, &x2) == 4) {
		// is command invalid? the ignore it
		if ( x1 == x2 )
			continue;

		cout << com1 << ":" << x1;
	}

    // print the lists
    for(size_t i = 0; i < numberOfBins; ++i)
    {
		cout << i << ":";
		// for(size_t j = 0; j < listArray[i]; ++i)
		// {
			/* code */
		// }
    }


	exit(0);
}