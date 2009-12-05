#include <iostream>
#include <sstream>
#include <cstdlib>

#include <vector>


using namespace std;

// assume that the vectors are sorted
bool fits( vector<int> first, vector<int> second )
{
	// assume they are sorted
	for(size_t i = 0; i < first.size(); ++i)
	{
		if (first[i] >= second[i])
		{
			return false;
		}
	}
	return true;
}


int main (int argc, char const *argv[])
{
	int arr1[3] = {1, 5, 2};
	int arr2[3] = {4, 5, 6};
	vector<int> x( arr1, arr1 + 3);
	sort( x.begin(), x.end() );
	
	vector<int> y( arr2, arr2 + 3);
	sort( y.begin(), y.end() );

	cout << (fits( x, y ) ? "fits" : "no fit") << endl;// = {2, 3, 4};
	return 0;
}
// 
// int main() {
// 
// 	// istream is;
// 	int k, n;
// 	
// 	// get the pairs of integers
// 	while( scanf("%d %d\n", &k, &n) == 2 )
// 	{
// 		for(size_t i = 0; i < k; ++i)
// 		{
// 			// read line
// 			for(size_t i = 0; i < n; ++i)
// 			{
// 
// 			}
// 			
// 		}
// 	}
// 
// 	exit(0);
// }
