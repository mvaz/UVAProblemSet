#include <iostream>
#include <limits>

#define NUMBER_COLOURS 3
#define NUMBER_BINS 3


// using namespace std;

// enum { BROWN, GREEN, CLEAR };

char names[4] = "BGC";
int configurations[3*2*1][3];
int costMatrix[NUMBER_BINS][NUMBER_COLOURS];
int cost[3*2*1];

void generatePermutations()
{
	// configurations[0][0] = 0;
	configurations[0][1] = 1;
	configurations[0][2] = 2;

	// configurations[1][0] = 0;
	configurations[1][1] = 2;
	configurations[1][2] = 1;

	configurations[2][0] = 1;
	// configurations[2][1] = 0;
	configurations[2][2] = 2;

	configurations[3][0] = 1;
	configurations[3][1] = 2;
	// configurations[3][2] = 0;

	configurations[4][0] = 2;
	// configurations[4][1] = 0;
	configurations[4][2] = 1;

	configurations[5][0] = 2;
	configurations[5][1] = 1;
	// configurations[5][2] = 0;
}

/* Auxiliary function to put the 
 */
// void fillCostMatrix( int X[NUMBER_BINS][NUMBER_COLOURS], int C[NUMBER_COLOURS][NUMBER_COLOURS] )
// {
// 	for (size_t x = 0; x < NUMBER_BINS; ++x)
// 		for (size_t c = 0; c < NUMBER_COLOURS; ++c)
// 		{
// 			C[x][c] = 0;		
// 			for (size_t y = 0; y < NUMBER_COLOURS; ++y)
// 				if (y!=c) {
// 					C[x][c] += X[x][y];
// 				}
// 		}
// }
// 
// template <class T>
// inline void PRINT_ELEMENTS (const T& coll, const char* optcstr="")
// {
//     typename T::const_iterator pos;
// 
//     std::cout << optcstr;
//     for (pos=coll.begin(); pos!=coll.end(); ++pos) {
//         std::cout << *pos << ' ';
//     }
//     std::cout << std::endl;
// }


// void computeAllSolutions()
// {
// 	for (size_t s = 0; s < 6; ++s)
// 	{
// 		cost[s] = 0;
// 		for (size_t bin = 0; bin < NUMBER_BINS; ++bin)
// 		{
// 			// cout << bin << "x" << configurations[s][bin] << "=" << costMatrix[bin][ configurations[s][bin] ] << ",";
// 			cost[s] += costMatrix[bin][ configurations[s][bin] ];
// 		}
// 		// cout << cost[s]  << endl;
// 	}
// }

// size_t findBestSolution()
// {
// 	int q = numeric_limits<int>::max();
// 	size_t n;
// 	for (size_t s = 0; s < 6; ++s)
// 	{
// 		// cout << cost[s] << " < " << q << endl;
// 		if (cost[s] < q)
// 		{
// 			n = s;
// 			q = cost[s];
// 		}
// 		else if ( cost[s] == q)
// 		{
// 			for (size_t i = 0 ; i < NUMBER_BINS ; i++)
// 			{
// 				// cout << names[configurations[s][i]] << "< " << names[configurations[n][i]] << endl;
// 				if ( names[configurations[s][i]] < names[configurations[n][i]] )
// 				{
// 					n = s;
// 					break;
// 				} else if ( names[configurations[s][i]] > names[configurations[n][i]] )
// 					break;
// 			}
// 		}
// 		// cout << "n <- " << n << endl;
// 	}
// 	return n;
// }


//
int main(int argc, char const *argv[])
{
	int configMatrix[NUMBER_COLOURS][NUMBER_COLOURS];

	// get the pairs of integers
	while ( scanf("%d %d %d %d %d %d %d %d %d\n", &configMatrix[0][0], &configMatrix[0][1], &configMatrix[0][2],
                                                  &configMatrix[1][0], &configMatrix[1][1], &configMatrix[1][2],
                                                  &configMatrix[2][0], &configMatrix[2][1], &configMatrix[2][2]) == 9)
	{
		// 1. fill cost matrix
		generatePermutations();
		// fillCostMatrix( configMatrix, costMatrix);
		
		for (size_t x = 0; x < NUMBER_BINS; ++x)
			for (size_t c = 0; c < NUMBER_COLOURS; ++c)
			{
				costMatrix[x][c] = 0;		
				for (size_t y = 0; y < NUMBER_COLOURS; ++y)
					if (y!=c) {
						costMatrix[x][c] += configMatrix[x][y];
					}
			}
		
		
		
		// 2. call the algorithm
		// int q = numeric_limits<int>::max();
		int q = 2147483647;
		// cout << q << endl;
		size_t n;
		
		for (size_t s = 0; s < 6; ++s)
		{
			cost[s] = 0;
			for (size_t bin = 0; bin < NUMBER_BINS; ++bin)
			{
				// cout << bin << "x" << configurations[s][bin] << "=" << costMatrix[bin][ configurations[s][bin] ] << ",";
				cost[s] += costMatrix[bin][ configurations[s][bin] ];
				if (cost[s] > q)
					goto next;
			}
			// cout << cost[s] << " < " << q << endl;
			if (cost[s] < q)
			{
				n = s;
				q = cost[s];
			}
			else if ( cost[s] == q)
			{
				for (size_t i = 0 ; i < NUMBER_BINS ; i++)
				{
					// cout << names[configurations[s][i]] << "< " << names[configurations[n][i]] << endl;
					if ( names[configurations[s][i]] < names[configurations[n][i]] )
					{
						n = s;
						break;
					} else if ( names[configurations[s][i]] > names[configurations[n][i]] )
						break;
				}
			}
			next:;
		}
		// 3. print the solution
		printf( "%c%c%c %d\n", names[ configurations[n][0] ],
		                       names[ configurations[n][1] ],
		                       names[ configurations[n][2] ], cost[n]);
	}

	exit(0);
}