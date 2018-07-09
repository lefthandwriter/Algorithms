/*
21 May 2018 started

Implementation of queue, using a linked-list. (We could also implement it using an array.)

To compile, link and run:
g++ -c -o queue.o queue.cc
g++ -o queue queue.o
./queue

*/

#include <iostream>
#include "queue.h" // my queue implementation
// #include <queue> // the standard queue library

int main(){
	Queue myQueue;
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.getsize();
	myQueue.printqueue();
	myQueue.dequeue();
	myQueue.printqueue();
	myQueue.getsize();
	myQueue.dequeue();
	myQueue.printqueue();
	myQueue.dequeue();
	myQueue.printqueue();
	myQueue.dequeue();
	myQueue.printqueue();
	myQueue.dequeue();
	myQueue.getsize();
	myQueue.dequeue();


	// Compare with the standard queue library
	
	return 0;
}   



