#include <iostream>
#include <cstdlib>
using namespace std;


int *memory;

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
		// printf(" %d", n);
	}
	return l;
}


int main()
{

	int i = 1;
	int j = 1e6;
	
	// cin >> i;
	// cin >> j;

	// memory = new int[j-i+1];
	memory = (int*) calloc( j - i + 1, sizeof(int));
	// exit(0);
	int max = 0;

	for(int n = i; n <= j; ++n)
	{
		// printf(	":%d: ", n );
		memory[n - i] = cycle_length(n);
		
		if( memory[n-i] > max )
			max = memory[n-i];
		// printf(" -->%d<\n", memory[n-i] );
	}

	cout << i << " " << j << " " << max;

	delete memory;
	exit(0);
}
