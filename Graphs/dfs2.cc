/*
3 June 2018

Version 2: Using a class for the graph (works)

DFS Implementation on a Directed Graph
- represent the graph using adjacency list

CLRS Algorithms, Page 542 for test graph, Pg 540 for Depth-First Search, Pg 549 for Topological Sort

Functions:
- topological sort
- (todo) strongly connected components

*/

#include <iostream>
#include <vector>
using namespace std;

struct gNode{
	// Represent a node in the DFS forest
	int key;
	int color; // 0 = white, 1 = grey, 2 = black
	int d; // discovery time
	int f; // finishing time
	gNode* par; // parent
};
int timek; // global variable for time-stamping
vector<int> topsort; // global variable for storing sorted vertices in topological order

class DFS{
	public:
		vector <gNode*> dfs_forest;
		int graphSize;
		DFS(int V){
			/*	
				Constructor to initialize the forest, based on how many nodes are in the graph.
				V  : The number of vertices in the graph 
			*/
			for(int i = 0; i<V; i++){
				dfs_forest.push_back(new gNode);
			}
			graphSize = V;
		}
		void runDFS(vector< vector<int> > adj);
		void DFS_visit(vector< vector<int> > adj, int u);
		void topological_sort(vector< vector<int> > adj);
};

void DFS::topological_sort(vector< vector<int> > adj){
	// Calls DFS(G) and edits the linked list of vertices to be sorted in topological order
	runDFS(adj);
}

void DFS::runDFS(vector< vector<int> > adj){
	// Intialization: colour all vertices white, and set parent to NULL
	for(int i=0; i<graphSize; i++){
		dfs_forest[i]->color = 0;
		dfs_forest[i]->par = NULL;
	}
	// Set time to 0
	timek = 0; 
	for(int u=0; u<graphSize; u++){
		if(dfs_forest[u]->color==0){
			DFS_visit(adj, u);
		}
	}
}

void DFS::DFS_visit(vector< vector<int> > adj, int u){
	dfs_forest[u]->color = 1; // color node grey
	timek++;		
	dfs_forest[u]->d = timek; // discovery time
	int size_list = adj[u].size();
	// cout << "D" << endl;
	for(int i=0; i<size_list; i++){ // explore edge (u,v)
		int v = adj[u].at(i);
		// cout << "E" << endl;
		if(dfs_forest[v]->color==0){
			dfs_forest[v]->par = dfs_forest[u];
			dfs_forest[v]->key = v; // set the key
			DFS_visit(adj, v);
		}
	}
	dfs_forest[u]->color = 2; // blacken u
	timek++;
	dfs_forest[u]->f = timek; // finishing time
	topsort.push_back(u); // insert into linked list as soon as it is finished for topological sort
}

class Graph{
	public:
		int V; // number of nodes in the graph
		vector< vector<int> > adjlist; // "vector of vectors" - for dynamic size allocation by constructor
		void addEdge(int u, int v);
		Graph(int numNodes){
			V = numNodes;
			for(int i=0; i<V; i++){
				vector<int> init;
				adjlist.push_back(init);
			}
		}
};

void Graph::addEdge(int u, int v){
	adjlist.at(u).push_back(v);
	V++;
}

int main(){
	// USING THE CLASS GRAPH REPRESENTATION //

	/*
	Make this graph:
	0 - > 1  4
	|	^ | /|
	v /   vv v
	3 < - 2  5<->

	0 - > 2  4
	|	^ | /|
	v /   vv v
	1 < - 3  5<->

	Both yield the same results. Matches the one in the book (pg 542)

	*/
	// 1. Create the graph (adjacency list representation)
	int V = 6;
	Graph myGraph(V);
	myGraph.addEdge(0, 1);
	myGraph.addEdge(0, 3);
	myGraph.addEdge(1, 2);
	myGraph.addEdge(2, 3);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 5);

	// 2. DFS on the graph (we get a DFS Forest)
	DFS myDFS(V);
	myDFS.topological_sort(myGraph.adjlist);

	// print the start and finishing times of the graph
	cout << "Start and Finishing Times" << endl;
	for(int i=0; i<V; i++){
		cout << "Node: " << myDFS.dfs_forest[i]->key << "  " << myDFS.dfs_forest[i]->d << "/" << myDFS.dfs_forest[i]->f << endl;
	}
	cout << endl << endl;

	// print the topologically sorted graph
	for(int i=0; i<V; i++){
		cout << myDFS.dfs_forest[topsort.at(i)]->key << "--";
	}
	cout << endl << endl;

	return 0;
}
