/*
Dijkstra's ("Dikestra's") Algorithm for solving shortest-path problem on weighted directed graphs with nonnegative weights.

Uses the min-priority queue implementation.

Edits: 
 - the relax() function in Dijkstra's algorithm needs to update the min-priority queue
 - used a typedef named QPair to represent the type pair<int, int>

Implementation details:
1. The Graph Class:
	- Uses the adjacency list representation of a graph
	- The adjacency list is implemented using a dynamic vector of vectors 
	- A dynamic vector is used so that we can specify the number of nodes as a variable
	- Since we are considering weighted graphs here, we need to store weights in addition to edges
	- Each vector in the vector is a node. It contains a pair, where the first item stores a node that it points to (edge), and the second item is the weight of the edge. 
	- An edge with its corresponding weight is added using the addWeightedEdge() routine

2. The  Class:
	- Has a struct to represent a node
	- The node has a key (key), current shortest-path estimate (d), and a pointer to its predecessor (par).
	- Uses priority_queue from the standard library to implement the min-priority queue
	- Has a set S to maintain the set of vertices whose shortest-paths are finalized
	- The relax() function needs to update (d,v) in the min-priority queue, if a lower min distance is found for vertex v

*/

#include<iostream>
#include<vector> // for representing graph with adjacency list
#include<queue>
using namespace std;

typedef pair<int,int> QPair; // make it easier to insert this type

class Graph{
	// Weighted directed graph
	public:
		int V; // number of nodes in the graph
		int E; // number of edges in the graph
		vector< vector< QPair > > adjlist; // "vector of vectors" - for dynamic size allocation by constructor. pair<> is to store node and weight when making the edge
		Graph(int numNodes){
			E = 0;
			V = numNodes;
			for(int i=0; i<V; i++){
				vector< QPair > init;
				adjlist.push_back(init);
			}
		}
		void addWeightedEdge(int u, int v, float w){
			adjlist.at(u).push_back(make_pair(v,w));
			E++;	
		}
};

class Dijkstra{
	private:
		struct gNode{
			int key;
			int d; // shortest-path estimate
			gNode* par; // predecessor
		};
	public:
		int V; // number of nodes
		int source; // source node
		vector <int> S; // set of vertices whose shortest paths are finalized
		priority_queue < QPair, vector<QPair>, greater<QPair> > Q; // min-priority queue to store d
		vector <gNode*> d_graph;
		Dijkstra(int numNodes, int s){
			/*
			We set up the graph such that each node has a unique key.
			Input:   s: source (key)  
					- specify here to save time, we could also put it in run()
			*/
			V = numNodes;
			source = s;
			for(int i=0; i<V; i++){
				// initialize-single-source
				gNode* node = new gNode;
				node->par = NULL;
				node->d = 100000; // infinity
				node->key = i;
				if(i==source){node->d=0;}
				d_graph.push_back(node);
				Q.push(make_pair(node->d,i)); // initialize priority-queue (store distance, then vertex)
			}
		}
		void relax(Graph myGraph, int u, int v, int w){
			int r = d_graph[u]->d + w;
			if(d_graph[v]->d > r){
				d_graph[v]->d = r;
				d_graph[v]->par = d_graph[u];
				Q.push(make_pair(w,v)); // update the weight in the priority queue
			}
		}
		void run(Graph myGraph){
			while(!Q.empty()){
				QPair q = Q.top(); // Extract-Min(Q), min by distance
				int u = q.second; // get the vertex associated with min-distance
				Q.pop(); // pop it out from the queue
				S.push_back(u); // append to set S
				for(auto v=myGraph.adjlist[u].begin(); v!=myGraph.adjlist[u].end(); v++){ // for each vertex in Adj[u]
					relax(myGraph, u, v->first, v->second);
				}
			}
		}
		void printshortest(int t){
			// t : target
			cout << "Distance between source and target: " << d_graph[t]->d << endl;
		}
		void printallshortest(){
			cout << "All source shortest paths from Source Node s: " << source << endl;
			for(int i = 0; i<V; i++){
				if(d_graph[i]->d==100000){
					cout << "Node " << d_graph[i]->key;
					cout << " d: Inf " << endl;
				}
				else{
					cout << "Node " << d_graph[i]->key;
					cout << " d: " << d_graph[i]->d << endl;
				}
			}
		}
};


int main(){
	// Build graph based on Figure 24.6 in CLRS
	int V = 5; // number of nodes in the graph
	Graph myGraph(V);
	myGraph.addWeightedEdge(0,1,10);
	myGraph.addWeightedEdge(0,2,5);
	myGraph.addWeightedEdge(1,2,2);
	myGraph.addWeightedEdge(1,3,1);
	myGraph.addWeightedEdge(2,1,3);
	myGraph.addWeightedEdge(2,3,9);
	myGraph.addWeightedEdge(2,4,2);
	myGraph.addWeightedEdge(3,4,4);
	myGraph.addWeightedEdge(4,0,7);
	myGraph.addWeightedEdge(4,3,6);

	int source = 0;
	Dijkstra dg(V, source);
	dg.run(myGraph);
	dg.printallshortest();

	// Print the vertices in set S in order
	cout << "Elements in set S, in order of insertion: " << endl;
	for(int i=0; i<V; i++){
		cout << dg.S.at(i) << ",";
	}
	cout << endl;

	// int target = 3;
	// dag.printshortest(target);

	return 0;
}


