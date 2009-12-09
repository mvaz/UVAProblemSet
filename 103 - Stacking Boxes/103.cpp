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
		vector< vector<int> > path_to(this->ne);
		for (int i = 0; i < this->ne; ++i)
			path_to[i].push_back(i);
		
		//   length_to = array with |V(G)| elements of type int with default value 0
		vector<int> length_to(this->ne, 0);
		//   for each vertex v in topOrder(G) do
		for (vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		{
			//   for each edge (v, w) in E(G) do
			int v = *it;
			for (int w = 0; w < this->ne ; w++)
				//             if length_to[w] <= length_to[v] + weight(G,(v,w)) then
				//                 length_to[w] = length_to[v] + weight(G, (v,w))
				if ( graph[v][w] )
					if (length_to[w] <= length_to[v] + 1)
					{
						length_to[w] = length_to[v] + 1;
						path_to[w].assign( path_to[v].begin(), path_to[v].end());
						path_to[w].push_back(w);
					}	
		}
		
		// determine the longest path
		int idx = 0;
		for (int x = 0, max = 0; x < this->ne ; x++)
		{
			int oinc = length_to[x];
			if ( oinc > max) {
				max = oinc;
				idx = x;
			}
		}
		//    return max(length_to[v] for v in V(G))	
		return path_to[idx];
		
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
	int n; // dimensionality of the boxes
	int k; // number of boxes

	// read the configurations
	while ( scanf("%d %d\n", &k, &n) == 2 )
	{
		MyGraph g(k);
		
		// vector< vector<int> > vectors;
		// read each box
		for ( int i = 0 ; i < k ; i++ )
			for (int j = 0; j < n ; j++)
				scanf("%d", &boxes[i][j]);

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
		
		// g.print();
		// compute the longest path
		vector<int> longestPath = g.longestPath();

		// compute the length of the longest path and output it
		cout << longestPath.size() << endl;
		for (size_t z = 0; z < longestPath.size(); z++ )
		{
			cout << longestPath[z] + 1;
			if ( (z+1) < longestPath.size() )
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}
