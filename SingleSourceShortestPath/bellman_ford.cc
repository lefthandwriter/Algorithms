/*
@ Esther Ling, 2018

Bellman-Ford algorithm for computing the single-source shortest path in a graph. 

Implementation details:
1. The Graph Class:
	- Uses the adjacency list representation of a graph
	- The adjacency list is implemented using a dynamic vector of vectors 
	- A dynamic vector is used so that we can specify the number of nodes as a variable
	- Since we are considering weighted graphs here, we need to store weights in addition to edges
	- Each vector in the vector is a node. It contains a pair, where the first item stores a node that it points to (edge), and the second item is the weight of the edge. 
	- An edge with its corresponding weight is added using the addWeightedEdge() routine

2. The Bellman_Ford Class:
	- Has a struct to represent a node
	- The node has a key (key), current shortest-path estimate (d), and a pointer to its predecessor (par).
	- Returns false if the input graph has a negative weight cycle
	- Else, it returns true, and each node in the vector bellman_graph will then have its shortest-path estimate parameter (d)
		updated to contain the solution to the single-source shortest-path problem.

*/

#include<iostream>
#include<vector> // for representing graph with adjacency list
using namespace std;

class Graph{ // Weighted directed graph
	public:
		int V; // number of nodes in the graph
		int E; // number of edges in the graph
		vector< vector< pair<int,int> > > adjlist; // "vector of vectors" - for dynamic size allocation by constructor. pair<> is to store node and weight when making the edge
		Graph(int numNodes){
			E = 0;
			V = numNodes;
			for(int i=0; i<V; i++){
				// vector<int> init;
				vector< pair<int,int> > init;
				adjlist.push_back(init);
			}
		}
		void addWeightedEdge(int u, int v, float w){
			adjlist.at(u).push_back(make_pair(v,w));
			E++;	
		}
};

class Bellman_Ford{
	private:
		struct gNode{
			int key;
			int d; // shortest-path estimate
			gNode* par; // predecessor
		};
	public:
		int V; // number of nodes
		int source; // source node
		vector <gNode*> bellman_graph;
		Bellman_Ford(int numNodes, int s){
			/*
			We set up the graph such that each node has a unique key.
			Input:   s: source (key)  
					- specify here to save time, we could also put it in run()
			*/
			// initialize the nodes
			V = numNodes;
			source = s;
			for(int i=0; i<V; i++){
				// initialize-single-source
				gNode* node = new gNode;
				node->par = NULL;
				node->d = 100000; // infinity
				node->key = i;
				if(i==s){node->d=0;}
				bellman_graph.push_back(node);
			}
		}
		void relax(Graph myGraph, int u, int v, int w){
			int r = bellman_graph[u]->d + w;
			if(bellman_graph[v]->d > r){
				bellman_graph[v]->d = r;
				bellman_graph[v]->par = bellman_graph[u];
			}
		}
		bool run(Graph myGraph){
			for(int i = 1; i<V-1; i++){ // for i=1 to |V|-1
				for(int u = 0; u<V; u++){ // for each edge in the graph
					for(auto itr = myGraph.adjlist[u].begin(); itr!=myGraph.adjlist[u].end(); itr++){
						relax(myGraph, u, itr->first, itr->second);
					}
				}
			}
			for(int u = 0; u<V; u++){ // for each edge in the graph
				for(auto itr = myGraph.adjlist[u].begin(); itr!=myGraph.adjlist[u].end(); itr++){
					if(bellman_graph[itr->first]->d > bellman_graph[u]->d + itr->second)
						return false;
				}				
			}
			return true;
		}
		void printshortest(int t){
			// t : target
			cout << "Distance between source and target: " << bellman_graph[t]->d << endl;
		}
		void printallshortest(){
			cout << "All source shortest paths from Source Node s " << source << endl;
			for(int i = 0; i<V; i++){
				cout << "Node " << bellman_graph[i]->key;
				cout << " d: " << bellman_graph[i]->d << endl;
			}
		}
};

int main(){
	// Build graph based on Figure 24.4 in CLRS
	int V = 5; // number of nodes in the graph
	Graph myGraph(V);
	myGraph.addWeightedEdge(0, 1, 6);
	myGraph.addWeightedEdge(0, 2, 7);
	myGraph.addWeightedEdge(1, 2, 8);
	myGraph.addWeightedEdge(1, 3, 5);
	myGraph.addWeightedEdge(1, 4, -4);
	myGraph.addWeightedEdge(2, 3, -3);
	myGraph.addWeightedEdge(2, 4, 9);
	myGraph.addWeightedEdge(3, 1, -2);
	myGraph.addWeightedEdge(4, 0, 2);
	myGraph.addWeightedEdge(4, 3, 7);

	int source = 0;
	bool checkNegCyc;
	Bellman_Ford bellf(V, source);
	checkNegCyc = bellf.run(myGraph);
	if(checkNegCyc==false){cout<<"Negative weight cycle detected" << endl;}
	bellf.printallshortest();

	int target = 3;
	bellf.printshortest(target);

	return 0;
}


