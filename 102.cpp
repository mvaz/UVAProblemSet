#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

#define BROWN 0
#define GREEN 1
#define CLEAR 2
#define NUMBER_COLOURS 3


int cost( int *bin, int COLOUR)
{
	int cost = 0;
	for(size_t i = 0; i < NUMBER_COLORS; ++i)
	{
		if ( i == COLOUR )
			cost += bin[i];
	}
	return cost;
}


int main() {

	// istream is;
	int i = 0;
	int one[NUMBER_COLOURS], two[NUMBER_COLOURS], three[NUMBER_COLOURS];
	
	// get the pairs of integers
	while( scanf("%d %d %d %d %d %d %d %d %d\n", &one[BROWN], &one[GREEN], &one[CLEAR],
												 &two[BROWN], &two[GREEN], &two[CLEAR],
												 &three[BROWN], &three[GREEN], &three[CLEAR]) == 9) {
		cout << "line" << ++i << ":" << three[GREEN] << endl;
	}

	exit(0);
}
