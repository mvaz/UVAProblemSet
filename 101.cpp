#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


class Table {
	
public:
	
	Table(int numberOfBins)
	:config(), numberOfBins( numberOfBins )
	{
		// this->numberOfBins = numberOfBins;
		this->config = new list<int>[numberOfBins];
		for(size_t i = 0; i < numberOfBins; ++i)
			config[i].push_back(i);
	}
	
	void print()
	{
		// print the lists
	    for(size_t i = 0; i < numberOfBins; ++i)
	    {
			cout << i << ":";
			list<int>::iterator it = config[i].begin();
			while (it != config[i].end())
			{
				cout << " " << *it;
				++it;
			}
			cout << "\n";
	    }
	    
	}
	// void move_onto( int block1, int block2 );
	// void move_over( int block1, int block2 );
	// void pile_onto( int block1, int block2 );
	    void pile_over( int block1, int block2 ) {
		// find block1
		
		// find block2
		
		
	}

private:
	list<int> *config;
	int numberOfBins;

};




void pile_over( int block1, int block2 )
{
	return;
}

int main() {
	
	// read the first line
	int numberOfBins;
	cin >> numberOfBins;
	
	Table table( numberOfBins );
	
	// read each command and parse it
	char com1[5], com2[5];
	int x1, x2;
	while( scanf( "%s %d %s %d\n", com1, &x1, com2, &x2) == 4) {
		// is command invalid? the ignore it
		if ( x1 == x2 )
			continue;
		table.pile_over( x1, x2);
		// cout << com1 << ":" << x1;
	}

    // print the lists
	table.print();

	exit(0);
}