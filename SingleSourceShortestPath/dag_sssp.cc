/*
Single-source shortest paths in directed acyclic graphs.

Implementation details:
1. The Graph Class:
	- Uses the adjacency list representation of a graph
	- The adjacency list is implemented using a dynamic vector of vectors 
	- A dynamic vector is used so that we can specify the number of nodes as a variable
	- Since we are considering weighted graphs here, we need to store weights in addition to edges
	- Each vector in the vector is a node. It contains a pair, where the first item stores a node that it points to (edge), and the second item is the weight of the edge. 
	- An edge with its corresponding weight is added using the addWeightedEdge() routine

2. The DAG_SP Class:
	- Has a struct to represent a node
	- The node has a key (key), current shortest-path estimate (d), and a pointer to its predecessor (par).

To do: Make one library with the classes, consider inheritance for common functions

*/

#include<iostream>
#include<vector> // for representing graph with adjacency list
#include "lib.h"
using namespace std;

class Graph{
	// Weighted directed graph
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

class DAG_SP{
	private:
		struct gNode{
			int key;
			int d; // shortest-path estimate
			gNode* par; // predecessor
		};
	public:
		int V; // number of nodes
		int source; // source node
		vector <gNode*> dag_graph;
		DAG_SP(int numNodes, int s){
			/*
			We set up the graph such that each node has a unique key.
			Input:   s: source (key)  
					- specify here to save time, we could also put it in run()
			*/
			V = numNodes;
			source = s;
		}
		void initialize(){
			for(int i=0; i<V; i++){
				// initialize-single-source
				gNode* node = new gNode;
				node->par = NULL;
				node->d = 100000; // infinity
				// node->key = topsort.at(i); // use the results of the topological sort (dont!)
				node->key = i;
				if(i==source){node->d=0;}
				dag_graph.push_back(node);
			}
		}
		void relax(Graph myGraph, int u, int v, int w){
			// w = myGraph.at(u).at(v)->second; // can't do this since pair
			int r = dag_graph[u]->d + w;
			if(dag_graph[v]->d > r){
				dag_graph[v]->d = r;
				dag_graph[v]->par = dag_graph[u];
			}
		}
		void run(Graph myGraph){
			// topologically sort the vertices
			DFS myDFS(V);
			myDFS.topological_sort_w(myGraph.adjlist);

			// print the topologically sorted graph
			cout << "topologically sorted graph: " << endl;
			for(int i=0; i<V; i++){
				cout << myDFS.dfs_forest[topsort.at(i)]->key << "--";
			}
			cout << endl << endl;

			// initialize single-source
			initialize();
		
			//  algorithm
			for(int i = 0; i<V; i++){ // for each vertex in topologically sorted order
				int u = topsort.at(i);
				for(auto v = myGraph.adjlist[u].begin(); v!=myGraph.adjlist[u].end(); v++){ // for each vertex in Adj[u]
					relax(myGraph, u, v->first, v->second);
				}
			}
		}
		void printshortest(int t){
			// t : target
			cout << "Distance between source and target: " << dag_graph[t]->d << endl;
		}
		void printallshortest(){
			cout << "All source shortest paths from Source Node s: " << source << endl;
			for(int i = 0; i<V; i++){
				if(dag_graph[i]->d==100000){
					cout << "Node " << dag_graph[i]->key;
					cout << " d: Inf " << endl;
				}
				else{
					cout << "Node " << dag_graph[i]->key;
					cout << " d: " << dag_graph[i]->d << endl;
				}
			}
		}
};


int main(){
	// Build graph based on Figure 24.5 in CLRS
	int V = 6; // number of nodes in the graph
	Graph myGraph(V);
	myGraph.addWeightedEdge(0,1,5);
	myGraph.addWeightedEdge(0,2,3);
	myGraph.addWeightedEdge(1,2,2);
	myGraph.addWeightedEdge(1,3,6);
	myGraph.addWeightedEdge(2,3,7);
	myGraph.addWeightedEdge(2,4,4);
	myGraph.addWeightedEdge(2,5,2);
	myGraph.addWeightedEdge(3,4,-1);
	myGraph.addWeightedEdge(3,5,1);
	myGraph.addWeightedEdge(4,5,-2);

	int source = 1;
	DAG_SP dag(V, source);
	dag.run(myGraph);
	dag.printallshortest();

	// int target = 3;
	// dag.printshortest(target);

	return 0;
}


