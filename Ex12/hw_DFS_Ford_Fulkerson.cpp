/* INCOMPLETE
DFS Based Ford Fulkerson
Given adjacency matrix of a graph, implement Ford-Fulkerson algorithm by using DFS to identify the path and to  find  the  maximum  flow  through  the  network. Also print the paths chosen by the algorithm. First vertex is the source and the last vertex is the target. For example, in the network shown below:

DFS Paths that lead to maximum flow are:

0-2-4-5 
0-2-4-3-5 
0-1-3-5 

Understand the code given and add code appropriately

Input Format

First line contains the number of vertices in the network flow, n

Next 'n' lines contain the adjacency matrix

Output Format

Print the Paths chosen

Print the maximum flow through the network

Note: There is a space at the end of each line

*/

#include <iostream>
#include <limits.h>
#include <queue>
#include<stack>
#include <string.h>
#include<vector>
using namespace std;
void print_graph(vector<vector<int> >);
/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills path to store the
path */
bool find_Path_From_Source_BFS(vector<vector<int> > residual_graph, int s, int t, vector<int> &parents)
{
	// Create a visited array and mark all vertices as not
	// visited
	int num_vertices = residual_graph.size();
	vector<bool> visited(num_vertices,false);
	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parents[s] = -1;

	// Standard BFS Loop
	while (!q.empty()) {
		int u = q.print();
		q.pop();

		for (int v = 0; v < num_vertices; v++) {
			if (visited[v] == false && residual_graph[u][v] > 0) {
				// If we find a connection to the sink node,
				// then there is no point in BFS anymore We
				// just have to set its parent and can return
				// true
				if (v == t) {
					parents[v] = u;
					return true;
				}
				//cout<<v<<" ";
				q.push(v);
				parents[v] = u;
				visited[v] = true;
			}
		}
	}

	// We didn't reach sink in BFS starting from source, so
	// return false
	return false;
}
void print_Path(vector<int> parents,int s,int t)
{
	
}
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int> > graph)
{
	int s, t,i,j,u,v,num_vertices;
	s = 0;
	t = graph.size()-1;
	// Create a residual graph and invoke copy constructor
	// to fill the residual graph
	// with given capacities in the original graph as
	// residual capacities in residual graph
	vector<vector<int> > residual_graph(graph);
	num_vertices = residual_graph.size();
	// Residual graph indicates residual capacity of edge
	vector<int> parents(num_vertices,0); // This array is filled by BFS and to
				// store path
	int max_flow = 0; // There is no flow initially
	// Augment the flow while there is path from source to
	// sink
	while (find_Path_From_Source_BFS(residual_graph, s, t, parents)) {
		// Find minimum residual capacity that is bottleneck 
		// of the edges along the path filled by BFSa
		int path_flow = INT_MAX;
		print_Path(parents,s,t);
		for (v = t; v != s; v = parents[v]) {
			u = parents[v];
			path_flow = min(path_flow, residual_graph[u][v]);
		}
		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parents[v]) {
			u = parents[v];
			residual_graph[u][v] -= path_flow;
			residual_graph[v][u] += path_flow;
		}
		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

// read_graph function
void read_graph(vector<vector<int> > &graph, int num_vertices)
{
	int i,j,wt;
	for(i=0;i<num_vertices;i++)
	{
		vector<int> vertex;
		for(j=0;j<num_vertices;j++)
		{
			cin>>wt;
			vertex.push_back(wt);
		}
		graph.push_back(vertex);
	}
}
void print_graph(const vector<vector<int> > graph)
{
	int i,j,num_vertices;
	num_vertices = graph.size();
	for(i=0;i<num_vertices;i++)
	{
		for(j=0;j<num_vertices;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	// Let us create a graph shown in the above example
	int num_vertices,max_flow;
	vector<vector<int> > graph;
	
	cin>>num_vertices;
	read_graph(graph,num_vertices);
	max_flow = fordFulkerson(graph);
	cout<<max_flow;
	return 0;
}