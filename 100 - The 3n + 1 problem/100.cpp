#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

#define IS_EVEN( __N__ ) ( !(__N__ & 1))
#define DIV_TWO( __N__ ) ( (__N__) >> 1)
#define NEXT(__N__) ( IS_EVEN(__N__) ? DIV_TWO(__N__) : ( 3 * (__N__) + 1) )

using namespace std;



int *sieve;

// int cycle_length( int n ) {
// 	int l = 1;
// 	while(n!=1)
// 	{
// 		if( is_even(n) )
// 			n = divide_by_two( n );
// 		else
// 			n = 3 * n + 1;
// 		l++;
// 	}
// 	return l;
// }

int cycleLengthMemory( int n, int top ) {
	int k = 0;
	while ( n > top ) {
		n = NEXT(n);
		k = k + 1;
	}
	if(sieve[n] == 0)
		sieve[n] = 1 + cycleLengthMemory( NEXT(n), top );

	return k + sieve[n];
}



int determineMaxCycleLength( int i, int j, int top ) {
	int max = 0;

	for(int n = i; n <= j; ++n) {
		
		sieve[n] = cycleLengthMemory(n, top);
		// sieve[n] = cycle_length(n);
		
		if( sieve[n] > max )
			max = sieve[n];
	}
	return max;
}


int main() {

	// get the pairs of integers from the input
	// istream is;
	string line;
	
	vector<int> pairs;

	int x1 = 0, x2 = 0;	
	while( scanf("%d %d\n", &x1, &x2) == 2) {
		pairs.push_back(x1);
		pairs.push_back(x2);
	}

	int top = 0;
	for(int y=0; y<pairs.size(); y++)
	    if ( top < pairs[y] ) top = pairs[y];
	
	// TODO allocate the auxiliary sieve
	sieve = (int*) calloc( top+1, sizeof(int));
	// sieve = (int*) calloc( )
	sieve[1] = 1;

	for(size_t i = 0; i < pairs.size(); i = i + 2)
	{
		int x1 = pairs[i];
		int x2 = pairs[i+1];
		if(x1 > x2) {
			int tmp = x1;
			x1 = x2;
			x2 = tmp;
		}
		
		int max = determineMaxCycleLength( x1, x2, top);
		printf("%d %d %d\n", pairs[i], pairs[i+1], max);
	}

	exit(0);
}
