# Algorithms

Esther Ling @ 2018

## Back Story
This is a collection of data structures and algorithms that I've implemented in C++ while embarking on a self-learning endeavour of the topic. My main text of reference is "Introduction to Algorithms", by Cormen, Leiserson, Rivest and Stein, otherwise abbreviated as CLRS.

This may serve as a useful reference for people starting on a similar self-study path, and wondering where to start or whether if it's worth it to start learning. If you've not gone through a rigorous training of advanced data structures and algorithms before and want to clear a coding interview, or do well in a competition like IEEEXtreme, I would argue that CLRS is the best text to start with for the following reasons: (1) It is comprehensive, (2) It is rigorous.

Why comprehensiveness is important: knowing the full scope of topics that you'd need to learn helps in addressing mental inertia when you start. You could, like me, be overwhelmed when you ask friends what topics you'd need to learn (e.g. friend A says: queues, stacks, etc, but friend B said DFS, BFS, etc) or stumble across website teaching x topic (e.g singly linked-lists, but what about doubly-linked lists?) because there is a sense of infiniteness to the amount that you need to cover. With a comprehensive textbook, there is a bound to the amount of topics, and then you can start mapping a plan to cover relevant topics in finite time.

Why rigor is important: you get a thorough and technically sound explanation on why things work, which always help when generalizing to novel situations.

Of course, going through theory is never enough - it needs to be paired with practical coding, which I've done by implementation in C++. And finally, they need to be supplemented with encounters in new situations, which is where LeetCode and HackerRank comes in.

So, in my opinion, this should be the order of learning Algorithm X:
Reading CLRS on Algorithm X -> Implementing Algorithm X in langauge of choice -> Solving questions related to Algorithm X on LeetCode.

In case this should be helpful for anyone, I went through the topics in this order:

1. Chapter 1-2: Role of Algorithms, Design and Analysis of Algorithms

2. Section III: Elementary Data Structures, Hash Tables, Binary Search Trees, Red-Black Trees

3. Section VI: Elementary Graph Algorithms, Minimum Spanning Trees, Single-Source Shortest Paths

4. Section IV: Dynamic Programming, Greedy Algorithms

5. Section II: Sorting

I find that two or three passes are needed for some of the more challenging topics, such as Red-Black Trees and Dynamic Programming, which is normal if you've not encountered this sort of concepts before. But, with a few passes, recognizing them in contexts outside the textbook when you're browsing an article online, or finding their application in LeetCode / HackerRank questions, and you should be on your way to familiarity with them.


## Contents
1. SingleSourceShortestPath
	- Bellman Ford algorithm
	- Dijkstra's algorithm
	- Alternate algorithm for DAGs

2. DataStructures
	- Queue
	- Stack
	- Doubly linked list
	- Binary search tree

3. Graphs
	- Breadth-first search
	- Depth-first search
