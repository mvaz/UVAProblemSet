#include <iostream>
#include <sstream>
#include <cstdlib>
#include <set>
#include <list>
#include <limits>
#include <algorithm>

#define NUMBER_COLOURS 3
#define NUMBER_BINS 3


using namespace std;

enum { BROWN, GREEN, CLEAR };



int costMatrix[NUMBER_BINS][NUMBER_COLOURS];

/* Auxiliary function to put the 
 */
void fillCostMatrix( int X[NUMBER_BINS][NUMBER_COLOURS], int C[NUMBER_COLOURS][NUMBER_COLOURS] )
{
	for (size_t x = 0; x < NUMBER_BINS; ++x)
		for (size_t c = 0; c < NUMBER_COLOURS; ++c)
		{
			C[x][c] = 0;		
			for (size_t y = 0; y < NUMBER_COLOURS; ++y)
				if (y!=c) {
					// cout << "C[" << x << "][" << c << "] == " << C[x][c] << "+= X[" << x << "][" << y << "] = " << X[x][y] << endl;
					C[x][c] += X[x][y];
				}
		}
}

template <class T>
inline void PRINT_ELEMENTS (const T& coll, const char* optcstr="")
{
    typename T::const_iterator pos;

    std::cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

//
int S( list<int> &A, set<int> &B, list<int> &result)
{
	if (A.size() == 1)
	{
		int x = A.front();
		int y = *(B.begin());
		result.push_back( y );
		return costMatrix[x][y];
	}

  // define a generic upper limit
	// int q = numeric_limits<int>::infinity();
	int q = numeric_limits<int>::max();
	list<int> tmp;
	
	// iterate over the 
	int x = A.front();
	
  for ( set<int>::iterator it = B.begin() ; it != B.end(); it++ )
	{
		int y = *it;
		list<int> underResult;
		// make tail of A
		list<int> tailA;
		tailA.insert( tailA.end(), ++(A.begin()), A.end() );
		// make new set without y
		set<int> restB;
		for ( set<int>::iterator it2 = B.begin() ; it2 != B.end(); it2++ )
			if ( *it2 != y)
				restB.insert(*it2);

		int cost = costMatrix[x][y] + S( tailA, restB, underResult);
		
		// PRINT_ELEMENTS(  underResult, "underResult:  ");
		
		if (cost < q)
		{
			q = cost;
			// cout << y << " " << cost << endl;
			underResult.push_front(y);
			tmp = underResult;
		}
		
		// PRINT_ELEMENTS(  underResult, "tmp        :  ");
	}

	result = tmp;
	return q;
}

//
int main(int argc, char const *argv[])
{
	// istream is;
	int configMatrix[NUMBER_COLOURS][NUMBER_COLOURS];
	
	set<int> colours;
	list<int> listOfBins;
	char names[4] = "BGC";
	
	for ( int i=0; i < NUMBER_COLOURS; i++ )
	{
		listOfBins.insert( listOfBins.end(), i);
		colours.insert( colours.end(), i );	
	}
	
	// get the pairs of integers
	while ( scanf("%d %d %d %d %d %d %d %d %d\n", &configMatrix[0][BROWN], &configMatrix[0][GREEN], &configMatrix[0][CLEAR],
									                      		 	  &configMatrix[1][BROWN], &configMatrix[1][GREEN], &configMatrix[1][CLEAR],
					                      						  	&configMatrix[2][BROWN], &configMatrix[2][GREEN], &configMatrix[2][CLEAR]) == 9)
	{
		list<int> solution;
		// 1. fill cost matrix
		fillCostMatrix( configMatrix, costMatrix);
		// 2. call the algorithm
		int cost = S( listOfBins, colours, solution);
	  // 3. print the solution
		for (list<int>::iterator col = solution.begin(); col!=solution.end(); ++col)
		{
			cout << names[*col];
		}
		cout << cost << endl;
		// PRINT_ELEMENTS(  solution, "solution   :  ");
	}

	exit(0);
}


//
// int L( list<int> a, set<int> s)
// {
// 	if(s.empty)
// 		return 0;
// 	else {
// 		// for every element in set s
// 	    
// 		for( set<int>::iterator iter = s.begin();  iter != s.end(); ++iter )
// 		{
// 			*iter
// 			s2 = 
// 		}
// 	}
// 		
// }

// int cost( int *bin, int COLOUR)
// {
// 	int cost = 0;
// 	for(size_t i = 0; i < NUMBER_COLOURS; ++i)
// 	{
// 		if ( i == COLOUR )
// 			cost += bin[i];
// 	}
// 	return cost;
// }