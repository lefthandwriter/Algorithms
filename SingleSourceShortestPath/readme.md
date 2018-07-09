# Single-Source Shortest Path

## Description 
The single-source shortest path is as follows:

	"Given a source node S and a target node T, find the shortest path from S to T".

Then, the shortest path between the two nodes S and T is the one that has minimum weight. The path weight is the sum of weights on all the edges in the path. We could of course interpret weights as some metric we want to minimuze, such as distance, time, cost, loss, etc.

In the shortest-paths class of problems, we consider weigthed, directed graphs. (Note that in the case of unweighted (directed or undirected) graphs, we would use breadth-first search (BFS), which runs in O(V+E) time).

There are 3 algorithms we consider in solving the single-source shortest path problem:

1. Bellman-Ford

	- The most general. Can handle graphs with negative weights and cycles.
	- O(VE)

2. Less general case:

	- Considers acyclic graphs (weighted DAGs): handles negative weights, but graph is acyclic.
	- O(V+E)

3. Dijkstra's algorithm:

	- Considers positively-weighted directed graphs. (No negative weights allowed. Cycles are fine)
	- Is an example of a greedy-algorithm
	- O(Elog(V)) using priority-queues
	- O(Vlog(V)+E) using Fibonacci heaps

Note that the single-source shortest path is a subset of the shortest-paths problems. Other types exist, such as single-destination shortest path, single-pair shortest path and all-pairs shortest paths problems.


## Reference:
- Chapter 24, CLRS.

