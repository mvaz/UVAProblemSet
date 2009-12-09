#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#define BUFFER_SIZE 1024

using namespace std;

//
int boxes[30][10];
// int graph[30][30];

class MyGraph
{
private:
	int ne;
	int graph[30][30];
	int tmp_graph[30][30];
	void initGraph() {
		for (int i=0 ; i < this->ne ; i++)
			for (int j=0 ; j < this->ne ; j++)
				graph[i][j] = 0;
	}
	void fillTmpGraph() {
		for (int i=0 ; i < this->ne ; i++)
			for (int j=0 ; j < this->ne ; j++)
				tmp_graph[i][j] = graph[i][j];		
	}
	
	bool nodeHasIncomingEdges(int node)
	{
		bool hasIncomingEdges = false;
		
		for (int i = 0; i < this->ne ; i++)
			if (this->tmp_graph[i][node]) {
				hasIncomingEdges = true ;
				break;
			}
		return hasIncomingEdges;
	}
public:
	MyGraph() {
		this->ne = 30;
		this->initGraph();
	}
	MyGraph(int n) {
		this->ne = n;
		this->initGraph();
	}
	void setEdge(int v1, int v2) {
		this->graph[v1][v2] = 1;
	}
	void print() {
		for (int i=0 ; i < this->ne ; i++)
		{
			for (int j=0 ; j < this->ne ; j++)
				cout << " " << graph[i][j];
			cout << endl;
		}
	}
	// algorithm dag-longest-path is
	//     input: 
	//          Directed acyclic graph G
	//     output: 
	//          Length of the longest path
	vector<int> longestPath() {
		
		vector<int> sorted = this->topologicalSort();
		vector<int> path = sorted;
		// //     length_to = array with |V(G)| elements of type int with default value 0
		vector<int> length_to(this->ne, 0);
		// // 
		// //     for each vertex v in topOrder(G) do
		for (vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		{
		// 	//         for each edge (v, w) in E(G) do
			int v = *it;
			for (int w = 0; w < this->ne ; w++)
		// 		//             if length_to[w] <= length_to[v] + weight(G,(v,w)) then
		// 		//                 length_to[w] = length_to[v] + weight(G, (v,w))
				if ( graph[v][w] )
					if (length_to[w] <= length_to[v] + 1)
					{
						length_to[v] += 1;
						cout << length_to[v] << " ";
					}
		// 			
		}
		// 
		// // for (vector<int>::iterator it = length_to.begin(); it != length_to.end(); ++it)
		// // 	cout << *it << " ";
		// //     return max(length_to[v] for v in V(G))	
		// path = sorted;
		return path;
		
	}
	
	vector<int> topologicalSort() {
		
		this->fillTmpGraph();
		
		// L ← Empty list that will contain the sorted elements
		vector<int> L;

		// S ← Set of all nodes with no incoming edges
		vector<int> S;
		
		for (int j = 0; j < this->ne ; j++)
		{			
			if ( not this->nodeHasIncomingEdges(j) )
				S.push_back( j );
		}


		// while S is non-empty do		
		while (S.size() > 0)
		{
			// remove a node n from S
			int n = S.back();
			S.pop_back();
			
			// insert n into L
			L.push_back(n);

			//     for each node m with an edge e from n to m do
			for (int m = 0; m < this->ne; m++)
			{
				if (!tmp_graph[n][m])
					continue;
				// remove edge e from the graph
				tmp_graph[n][m] = 0;
				//    if m has no other incoming edges then
				//        insert m into S
				if ( not this->nodeHasIncomingEdges(m) )
					S.push_back(m);
				
			}
		}
		// if graph has edges then
		//     output error message (graph has at least one cycle)
		// else 
		//     output message (proposed topologically sorted order: L)	
		return L;
	}
};



// assume that the vectors are sorted
bool fits( vector<int> first, vector<int> second )
{
	// assume they are sorted
	for (vector<int>::iterator it1 = first.begin(), it2 = second.begin(); it1 != first.end(); ++it1, ++it2)
		if ( *it1 >= *it2)
			return false;
	return true;
}



int main (int argc, char const *argv[])
{
	// int arr1[3] = {1, 5, 2};
	// int arr2[3] = {4, 5, 6};
	// vector<int> x( arr1, arr1 + 3);
	// sort( x.begin(), x.end() );
	// 
	// vector<int> y( arr2, arr2 + 3);
	// sort( y.begin(), y.end() );
	// 
	// cout << (fits( x, y ) ? "fits" : "no fit") << endl;// = {2, 3, 4};
	
	int n; // dimensionality of the boxes
	int k; // number of boxes

	// read the configurations
	while ( scanf("%d %d\n", &k, &n) == 2 )
	{
		MyGraph g(k);
		
		// vector< vector<int> > vectors;
		// read each box
		for ( int i = 0 ; i < k ; i++ )
		{
			for (int j = 0; j < n ; j++)
				scanf("%d", &boxes[i][j]);
				
			// vector<int> v1(boxes[i], boxes[i] + n);
		}

		// populate the graph
		for (int i=0 ; i < k ; i++)
		{
			vector<int> v1(boxes[i], boxes[i] + n);
			sort( v1.begin(), v1.end() );
			for (int j=0; j < k ; j++)
			{
				vector<int> v2(boxes[j], boxes[j] + n);
				sort( v2.begin(), v2.end() );
				
				if ( fits(v1,v2) ) {
					g.setEdge(i, j);
				}
					
			}
		}
		
		g.print();
		// compute the longest path
		vector<int> longestPath = g.longestPath();
		cout << endl;
		// compute the length of the longest path
		
		// output it
		cout << longestPath.size() << endl;
		for (int z = 0; z < longestPath.size(); z++ )
		{
			cout << longestPath[z] + 1;
			if ( (z+1) < longestPath.size() )
				cout << " ";
			else
				cout << endl;
		}
			
 		// printf( "%d\n")
	}


	// fin.getline(buffer, BUFFER_SIZE);
	// 
	// while (strbuffer >> values1[c])
	// {
	// 	ostr2 >> values2[c++];
	// }
	// 
	// for (int i=0;i<c;i++)
	// {
	// 	cout << values1[i] << ":" << values2[i] << endl;
	// }

	
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
