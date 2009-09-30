#include <iostream>
#include <cstdlib>
using namespace std;


int *memory;
int *sieve;

int is_even(int n) {
    return !(n & 1);
}

int divide_by_two(int n) {
    return n >> 1;
}


int cycle_length( int n ) {
	int l = 1;
	while(n!=1)
	{
		if( is_even(n) )
			n = divide_by_two( n );
		else
			n = 3 * n + 1;
		l++;
	}
	return l;
}

int next( int n ) {
	return is_even(n) ? divide_by_two(n) : (3*n+1);
}

int cycleLengthMemory( int n, int top ) {
	int k = 0;
	while ( n > top ) {
		n = next(n);
		k = k + 1;
	}
	if(sieve[n] == 0)
		sieve[n] = 1 + cycleLengthMemory( next(n), top );

	return k + sieve[n];
}

int main()
{

	int i = 100;
	int j = 2000;
	
	sieve  = (int*) calloc( j+1, sizeof(int));
	sieve[1] = 1;

	int max = 0;

	for(int n = i; n <= j; ++n)
	{
		sieve[n] = cycleLengthMemory(n, j);
		if( sieve[n] > max )
			max = sieve[n];
	}

	cout << i << " " << j << " " << max;

	delete memory;
	exit(0);
}
