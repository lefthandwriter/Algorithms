/*
Doubly-linked list
22 May 2018

To compile, link and run:
g++ -c -o doubly-linked-list.o doubly-linked-list.cc
g++ -o doubly-linked-list doubly-linked-list.o
./doubly-linked-list

*/

#include<iostream>
using namespace std;

struct node{ // the node element
	int value;
	node* next;
	node* prev;
};

class dll{ // the linked-list object
	private:
		node* head;
		node* tail;
	public:
		dll(){ // constructor to initialize head and tail
			head = NULL;
			tail = NULL;
		}
		void create_node(int val);
		void insert_start(int val);
		void insert_end(int val);
		void insert_pos(int pos, int val);
		void delete_start();
		void delete_end();
		void delete_pos(int pos);
		void display();
};

void dll::create_node(int val){
	// if list is empty, create a new node.
	// if list is not empty, inserts a new node at the tail, which is the same as insert_end()
	node* temp = new node;
	temp->value = val;
	temp->next = NULL;
	if(head==NULL){ // list is empty
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

void dll::insert_start(int val){
	// insert node at the start of the linked-list. assumes the list is non-empty
	node* temp = new node;
	temp->value = val;
	temp->prev = NULL;
	temp->next = head;
	head = temp;
}

void dll::insert_end(int val){
	// insert node at the end of the linked-list.
	node* temp = new node;
	temp->value = val;
	temp->prev = tail;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
}

void dll::insert_pos(int pos, int val){
	// insert node at position pos
	node* temp = new node;
	node* curr = new node;
	curr = head;
	temp->value = val;
	for(int i=1; i<pos; i++){ // traverse the list till position pos
		curr = curr->next;
	}
	temp->prev = curr;
	temp->next = curr->next;
	curr->next = temp;
	curr = temp;
}

void dll::delete_start(){
	// delete the first node in the list
	cout << "Deleting the start" << endl;
	node* temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

void dll::delete_end(){
	// delete the last node in the list
	cout << "Deleting the end" << endl;
	node* temp = new node;
	temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete temp;
}

void dll::delete_pos(int pos){
	// delete the node at position pos
	cout << "Deleting at position " << pos << endl;
	node* curr = new node;
	node* left = new node;
	node* right = new node;
	curr = head;
	for(int i=1; i<pos; i++){
		left = curr;
		curr = curr->next;
	}
	right = curr->next;
	left->next = right;
	right->prev = left;
	delete curr;
}

void dll::display(){
	// display the nodes in the list
	node* curr = new node;
	curr = head;
	while(curr->next!=NULL){
		cout << curr->value << "--";
		curr = curr->next;
	}
	cout << curr->value << endl;
}

int main(){
	dll doubleList;
	// doubleList.create_node(1);
	// doubleList.insert_start(2);
	// doubleList.insert_start(3);
	// doubleList.display();

	// doubleList.create_node(1);
	// doubleList.create_node(2);
	// doubleList.create_node(3);
	// doubleList.display();

	// doubleList.create_node(1);
	// doubleList.insert_start(2);
	// doubleList.insert_pos(1,3);
	// doubleList.display();

	// doubleList.create_node(1);
	// doubleList.insert_end(2);
	// doubleList.insert_end(3);
	// doubleList.display();

	// doubleList.create_node(1);
	// doubleList.insert_end(2);
	// doubleList.insert_end(3);
	// doubleList.insert_end(4);
	// doubleList.insert_end(5);
	// doubleList.display();
	// doubleList.delete_start();
	// doubleList.display();

	// doubleList.create_node(1);
	// doubleList.insert_end(2);
	// doubleList.insert_end(3);
	// doubleList.insert_end(4);
	// doubleList.insert_end(5);
	// doubleList.display();
	// doubleList.delete_end();
	// doubleList.display();

	doubleList.create_node(1);
	doubleList.insert_end(2);
	doubleList.insert_end(3);
	doubleList.insert_end(4);
	doubleList.insert_end(5);
	doubleList.display();
	doubleList.delete_pos(2);
	doubleList.display();

	return 0;
}

