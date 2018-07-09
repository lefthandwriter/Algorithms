/*
21 May 2018

Implementation of a stack, with three routines:
- empty
- push
- pop

A stack is last-in, first-out. Refer to Ch. 10 of Algorithms textbook. Contains the following field:
- top (integer)

After we pop, the array still has the elements, just that top does not point to it.

Compare with the C++ <stack> implementation. How is this compared with vector?

To compile: g++ -c -o xx.o xx.cc
To link    : g++ -o xx xx.o
To run     : ./xx

*/

#include <stdlib.h>
#include <iostream>
// #include <stack>

using namespace std;

// int n = 10;
int myStack[10]; // An array implementation of a stack
int top = -1; // Initialize top to be the first index of the array

bool empty(int* S){
	if (top == -1)
		return true;
	else
		return false;
}

void push(int* S, int x){
	top++;
	S[top] = x;
}

int pop(int* S){
	if (empty(S)){
		// raise error exception underflow
		cout << "Underflow error" << endl;
		return 0;
	}
	else{
		top--;
		return S[top+1];
	}
}

int main(){
	/* Call routines to add items into the stack and remove items */

	cout << "Is stack empty? " << empty(myStack) << endl;

	// Add items into stack
	cout << "Pushing items into stack " << endl;
	push(myStack, 1);
	push(myStack, 2);
	push(myStack, 3);

	// Print items
	cout << myStack[top-2] << ", " << myStack[top-1] << ", " << myStack[top] << endl;

	// Pop items from stack
	int topItem = pop(myStack);
	cout << "Popped item: " << topItem << endl;

	cout << "Is stack empty? " << empty(myStack) << endl;

	return 0;
}