/*
28 May 2018

BFS implementation on an undirected graph
- represent graph using adjacency list
- use the queue I implemented

To compile, link and run:
g++ -c -o bfs.o bfs.cc 
g++ -o bfs bfs.o
./bfs

*/

#include <iostream>
#include <vector>
#include "queue.h" // my queue implementation
using namespace std;

struct gNode{ // to represent an element in the BFS tree
	int key;
	int color; // 0 = white, 1 = grey, 2 = black
	int dist;
	gNode* par;
};

class BFS_tree{
	private:
		gNode* root;
	public:
		vector <gNode*> bfs_tree;
		BFS_tree(int V){
			/*	V  : The number of vertices in the graph */
			root = NULL;
			for(int i=0; i<V; i++){
				bfs_tree.push_back(new gNode);
			}
		}
		void doBFS(vector<int> adj[], int s, int V);
		void printpath(gNode* NODE);
};

void BFS_tree::doBFS(vector<int> adj[], int s, int V){
	/*
	Parameters:  
		adj: An array of adjacency lists (i.e. representing the graph)
		s  : The source node
		V  : The number of vertices in the graph
	*/
	cout << "Doing a Breadth-First Search on the graph " << endl;
	Queue myQueue;
	
	// initialization (set all nodes except source to white)
	for(int i = 0; i<V; i++){
		bfs_tree[i]->par = NULL;
		if(i!=s){
			bfs_tree[i]->color = 0; // white
			bfs_tree[i]->dist = 10000;
		}
	}
	// initialize source 
	bfs_tree[s]->color = 1; // grey
	bfs_tree[s]->dist  = 0;

	// BFS!
	myQueue.enqueue(s);
	int u, size_list;
	while(!myQueue.empty()){
		u = myQueue.dequeue();
		size_list = adj[u].size();
		for(int i=0; i<size_list; i++){
			int v = adj[u].at(i);
			if(bfs_tree[v]->color==0){ // if that node is white
				bfs_tree[v]->color = 1; // grey
				bfs_tree[v]->dist  = bfs_tree[u]->dist + 1;
				bfs_tree[v]->par   = bfs_tree[u];
				bfs_tree[v]->key   = v;
				myQueue.enqueue(v);  
			}
		}
		bfs_tree[u]->color = 2; // black
	}
	root = bfs_tree[s];
	root->key = s;
}

void BFS_tree::printpath(gNode* NODE){
	// 	print the shortest path between node v and source s
	if(NODE == root){
		// cout << root->key << endl;
	}
	else if(NODE->par == NULL){
		cout << "No path exists" << endl;
	}
	else{
		printpath(NODE->par);
	}
	cout << NODE->key << "-";
}

void addEdge(vector<int> adj[], int u, int v){
	// utility function to add an edge to the graph
	// this is an undirected graph 
	adj[u].push_back(v);
	adj[v].push_back(u);
}


int main(){
	/*
	Make this graph:

	0-1-2-5
	|	|
	3---4---6

	*/
	// 1. Create the graph (adjacency list representation)
	int V = 7; // V is number of vertices in the graph
	vector<int> adj[V]; // create an array of size 7 of type vector (each array index stores a vector object)
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 5);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 6);
	addEdge(adj, 2, 4);

	// 2. BFS on the graph (we get a BFS tree)
	int source = 1;
	BFS_tree myBFS(V);
	myBFS.doBFS(adj, source, V);

	gNode* v = new gNode;
	v = myBFS.bfs_tree[6];
	cout << "Shortest path from "<< source << " to 6: ";
	myBFS.printpath(v);
	cout << endl;

	return 0;
}
