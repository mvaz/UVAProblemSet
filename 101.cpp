#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <stack>

using namespace std;


class Table {
	
public:
	
	Table(int numberOfBins)
	:config(numberOfBins), numberOfBins( numberOfBins ), positions(numberOfBins), buffer()
	{
		for(size_t i = 0; i < this->numberOfBins; ++i) {
			config[i].push_back(i);
			positions[i] = i;
		}
	}
	
	void print()
	{
		for(size_t i = 0; i < this->numberOfBins; ++i)
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
		// 
		for (size_t i=0; i< positions.size(); cout << " " << positions[i++]);
	}
	// void move_onto( int block1, int block2 );
	// void move_over( int block1, int block2 );
	void pile_onto( int block1, int block2 ) {
		int p1 = positions[block1];
		int p2 = positions[block2];
		int elem;

		// relocate all blocks on top of p2		
		list<int>::iterator it = config[p2].begin();
		do {
			elem = config[p2].back();
			config[elem].push_back(elem);
			config[p2].pop_back();
			positions[elem] = p2;
			++it;
		} while ( elem != block2 );
		
		// move blocks on top of block1 to pile of block2
		pile_over( block1, block2 );

	}
	
	void pile_over( int block1, int block2 ) {
		int p1 = positions[block1];
		int p2 = positions[block2];
		int elem;
		
		//
		list<int>::iterator it = config[p1].begin();
		do {
			elem = config[p1].back();
			config[p1].pop_back();
			buffer.push(elem);
			++it;
		} while ( elem != block1 );

		while ( !buffer.empty() ) {
			elem = buffer.top();
			buffer.pop();
			config[p2].push_back(elem);
			positions[elem] = p2;
		}
	}
	
	void command( string com1, int block1, string com2, int block2 )
	{
		// cout << com1 << " " << block1 << " " << com2 << " " << block2 << endl;
		// test whether command is worth executing
		if ( positions[block1] == positions[block2] )
			return;
		
		if (com1 == "pile")
		{
			if( com2 == "onto")
				pile_onto(block1,block2);
			else if ( com2 == "over" )
				pile_over(block1,block2);
		}	
		else if ( com1 == "move" )
		{
			if( com2 == "onto")
				pile_onto(block1,block2);
			else if ( com2 == "over" )
				pile_over(block1,block2);
		}
	}

private:
	// list<int> *config;
	int numberOfBins;

	vector< list<int> > config;
	vector<int> positions;
	stack<int>  buffer;

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
	char com1[255], com2[255];
	int x1, x2;
	while( scanf( "%s %d %s %d\n", com1, &x1, com2, &x2) == 4) {
		// is command invalid? the ignore it
		if ( x1 == x2 )
			continue;
		// table.pile_over( x1, x2);
		table.command( string(com1,4), x1, string(com2,4), x2);
		
		// cout << com1 << ":" << x1;
	}

	// print the lists
	table.print();

	exit(0);
}