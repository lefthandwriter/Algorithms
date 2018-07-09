/*
Binary search tree implementation.

*/

#include<iostream>
using namespace std;

struct node{
	int key;
	node* left;
	node* right;
	node* parent;
};

class bst{
	private:
		node* root;
	public:
		bst(){ // constructor to initialize root
			root = NULL;
		}
		void insert_node(int val);
		void remove_node(node* n);
		node* search_node(int val);
		node* minimum_node();
		node* maximum_node();
		node* minimum_node_subtree(node* n);
		node* maximum_node_subtree(node* n);
		node* predecessor(node* n);
		node* successor(node* n);
		void printtree(); // wrapper function that calls display()
		void display(node* n);
};

void bst::printtree(){
	display(root);
}

void bst::display(node* n){
	// use an inorder-tree walk to display the elements in the tree, which is of order Theta(N)
	if(n!=NULL){
		display(n->left);
		cout << n->key << " " << endl;
		display(n->right);
	}
}

void bst::remove_node(node* n){
	// remove the node n from the tree
	/* Case 1: node has no children (node to be deleted is the leaf, then simply remove it from the tree)
	 Case 2: node has one child (copy the child to the node, then remove the child)
	 Case 3: node has two children (splice out n's successor, which has no left child, and replace n's key 
	 								and satellite data with its successor's).
	*/
	cout << "Removing node with key " << n->key << endl;

	// Version 1: By Cases
	if(n->left==NULL && n->right==NULL){ // Case 1
		if(n->parent->left==n)
			n->parent->left = NULL;
		else
			n->parent->right = NULL;
		delete n;
	}
	else if(n->left==NULL || n->right==NULL){ // Case 2
		node* child = new node;
		if(n->left){
			child = n->left;
		}
		else{
			child = n->right;
		}
		if(n==root){
			// cout << "Is root!" << endl;
			root = child;
		}
		else{
			if(n->parent->left == n){
				n->parent->left = child;
			}
			else{
				n->parent->right = child;
			}
		}
		n = child;
		delete child;
	}
	else{ // Case 3
		node* succ = new node;
		succ = successor(n);
		node* child = new node;

		// Splice out successor, which has no left child
		if(succ->parent->left==succ){
			succ->parent->left = succ->right;
		}
		else{
			succ->parent->right = succ->right;
		}
		if(succ->right)
			succ->right->parent = succ->parent;

		// Replace n's key and its satellite data with that of succ, then delete succ
		n->key = succ->key;
		delete succ;

	}
}
node* bst::successor(node* n){
	// returns the successor of node n, where successor is defined as the smallest node with key larger than n
	/*
	Prove that the successor for case 1 has at most one child.
	Ans: For case 1, the successor is the left-most node in the right sub-tree. It can only have a right child, 
		otherwise, it's left child would be the left-most node in the sub-tree. Thus, it has at most one child.
		If it has no right child, then it has no children.
	*/
	// case 1: when the right tree of n is nonempty
	if(n->right){
		cout << "The successor to " << n->key << " is ";
		return minimum_node_subtree(n->right);
	}
	// case 2: when thr right tree is empty
	node* curr = new node;
	curr = n->parent;
	while(curr && n==curr->right){
		n = curr;
		curr = n->parent;
	}
	cout << "The successor to " << n->key << " is " << curr->key << endl;;
	return curr;
}

node* bst::minimum_node(){
	// the minimum node can be found by traversing down the left child pointers until a NULL is encountered
	node* curr = new node;
	curr = root;
	while(curr->left){
		curr = curr->left;
	}
	cout << "The minimum is: " << curr->key << endl;
	return curr;
}

node* bst::maximum_node(){
	// the maximum node can be found by travesing down the right child pointers until a NULL is encountered
	node* curr = new node;
	curr = root;
	while(curr->right){
		curr = curr->right;
	}
	cout << "The maximum is: " << curr->key << endl;
	return curr;
}

node* bst::minimum_node_subtree(node* n){
	// the minimum node of the subtree from n can be found by traversing down the left child pointers until a NULL is encountered
	while(n->left){
		n = n->left;
	}
	cout << n->key << endl;
	return n;
}

node* bst::maximum_node_subtree(node* n){
	// the maximum node of the subtree from n can be found by travesing down the right child pointers until a NULL is encountered
	while(n->right){
		n = n->right;
	}
	cout << n->key << endl;
	return n;
}

node* bst::search_node(int val){
	// searches for the node that has key val, which is of order O(h)
	// if none such exists, then return NULL
	// can either use recursion or while loop
	node* curr = new node;
	curr = root;
	while(curr!=NULL && val!=curr->key){
		if(val < curr->key){
			curr = curr->left; // search the left sub-tree
			// cout << "Searching left sub-tree" << endl;
		}
		else{
			curr = curr->right; // search the right sub-tree
			// cout << "Searching right sub-tree" << endl;
		}
	}
	if(curr && curr->key == val){
		cout << "Found the node" << endl;
		return curr;
	}
	else{
		cout << "No node found" << endl;
		return NULL; // there was no such key in the tree
	}
}

void bst::insert_node(int val){
	// insert a new node into the tree, which is of order O(h), where h is the height of the tree
	cout << "Inserted node with key " << val << endl;
	node* z = new node;
	z->key = val;
	z->left = NULL;
	z->right = NULL;
	node* prev = new node; // to maintain the parent of curr
	node* curr = new node; // to trace a path down the tree
	prev = NULL;
	curr = root; 
	while(curr!=NULL){
		prev = curr;
		if(z->key < curr->key){ // decide which way to split
			curr = curr->left;
		}
		else{
			curr = curr->right;
		}
	}
	z->parent = prev;
	if(prev==NULL){ // then the tree was empty
		root = z;
	}
	else if(z->key < prev->key){
		prev->left = z;
	}
	else{
		prev->right = z;
	}
}

int main(){
	bst myBST1;
	myBST1.insert_node(10);
	myBST1.insert_node(5);
	myBST1.insert_node(7);
	myBST1.insert_node(9);
	myBST1.insert_node(21);
	myBST1.insert_node(1);
	myBST1.insert_node(11);
	myBST1.printtree();

	node* find = new node;
	find = myBST1.search_node(10);
	myBST1.search_node(20);

	myBST1.minimum_node();
	myBST1.maximum_node();

	myBST1.successor(find);

	bst myBST2;
	myBST2.insert_node(1);
	myBST2.insert_node(2);
	myBST2.insert_node(3);
	myBST2.printtree();
	node* f1 = new node;
	f1 = myBST2.search_node(1); // set to 3 to test case 1, set to 2 to test case 2. set to 1 to test boundary case
	myBST2.remove_node(f1);
	myBST2.printtree();

	bst myBST3;
	myBST3.insert_node(5);
	myBST3.insert_node(3);
	myBST3.insert_node(9);
	myBST3.insert_node(7);
	myBST3.insert_node(10);
	myBST2.printtree();
	node* f2 = new node;
	f2 = myBST3.search_node(9); // case 3
	myBST3.remove_node(f2);
	myBST2.printtree();


	return 0;
}
