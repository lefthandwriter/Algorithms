# Graph Algorithms

## Graph Representation
A graph consists of a set of vertices / nodes, which may be connected by edges. If the edge has a weight associated with it, we call it a weighted graph. An unweighted graph can be thought of to consist of edges with unit weight.

There are two ways to represent a graph:
1. Adjacency List
2. Adjacency Matrix

### Adjacency List
Better for sparse graphs. 

### Adjacency Matrix
May be better when the graph is dense.

We use the adjacency list representation in the code implementations here.

## Use Cases
Using a graph representation, we can pose problems such as finding the minimum distance between a set of points, or determining if a path exists between two points in a well defined manner. These points could be cities (i.e. what's the shortest distance between city X and city Y, given that there are roads (edges) connecting them?), or people in a social network (i.e. given person A has a set of friends and person B has a set of friends, are they connected through their network?).

We cover one such algorithm here for this problem: Breadth-First Search (BFS), when the graph is unweighted.
(See the folder SingleSourceShortestPath for applications on weighted graphs).

Given the graph representation, it is also useful to find underlying structure. For instance, the vertices in the graph could represent events, and we may be interested in noting down which events precede others. This is also known as sorting the graph topologically. Another structural problem is to separate the graph into its strongly-connected components, which comes into play when we consider directed graphs. In a strongly-connected component, all vertices are reachable from one another. The Depth-First Search (DFS) algorithm is used to solve such problems.

## Algorithms
1. Breadth-First Search.
2. Depth-First Search.

## Reference:
Chapter 22, CLRS.