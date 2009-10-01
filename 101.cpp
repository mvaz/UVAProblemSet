#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


class Table {
	
public:
	Table(int numberOfBins);
	
	~Table();
	
	void move_onto( int block1, int block2 );
	void move_over( int block1, int block2 );
    void pile_onto( int block1, int block2 );
    void pile_over( int block1, int block2 );

protected:
	list<int> *configuration;

};


void pile_over( int block1, int block2 )
{
	return;
}

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
		// cout << com1 << ":" << x1;
	}

    // print the lists
    for(size_t i = 0; i < numberOfBins; ++i)
    {
		cout << i << ":";
		list<int>::iterator it = listArray[i].begin();
		while (it != listArray[i].end())
		{
			cout << " " << *it;
			++it;
		}
		cout << "\n";
    }

	exit(0);
}