using namespace std;

struct node{ // a node to store a queue entry
	int key;
	node* next;
};

class Queue{
	private:
		node* head;
		node* tail;
		int size;
	public:
		void enqueue(int x);
		// node* dequeue();
		int dequeue();
		bool empty();
		int getsize();
		void printqueue();
		Queue(){ // constructor
			head = NULL;
			tail = NULL;
			size = 0;
		} 
};

void Queue::printqueue(){
	// prints out the queue
	node* curr = new node;
	curr = head;
	cout << "Queue is: ";
	while(curr){
		cout << curr->key << "-";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

void Queue::enqueue(int x){
	// Creates a new node at the tail of the queue and puts x as its key
	node* temp = new node;
	temp->next = NULL;
	temp->key = x;
	if(empty()){ // if the queue is empty
		head = temp;
		tail = temp;
	}
	else if(size==1){
		tail = temp;
		head->next = tail;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
	size++;
	cout << "Enqueued key " << x << " into queue" << endl;
}

int Queue::dequeue(){
	// Removes the item from the head position and returns it
	int k;
	if(empty()){
		cout << "Can't dequeue, queue is empty " << endl;
		return -1;
	}
	else{
		node* temp = new node;
		temp = head;
		head = head->next;
		k = temp->key;
		cout << "Dequeued key " << k << " from queue" << endl;
		size--;
		if(size==0){
			tail = head;
		}
		delete temp;
		return k;
	}
}

bool Queue::empty(){
	// Returns true if Queue is empty, otherwise returns false
	if(head==NULL)
		return true;
	else
		return false;
}

int Queue::getsize(){
	// Returns the size of the Queue
	// int k = 0;
	// node* curr = new node;
	// curr = head;
	// while(curr){
	// 	curr = curr->next;
	// 	k++;
	// }
	// delete curr;
	// return k;
	cout << "Size of queue: " << size << endl;
	return size;
}
