// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using namespace std;

// constructor sets up empty tree
IntBST::IntBST() { 
	root = nullptr;

}

// destructor deletes all nodes
IntBST::~IntBST() {
	clear(root);
	root = nullptr;

}

// recursive helper for destructor
void IntBST::clear(Node *n) {
	if (n != nullptr){
		clear(n->left);
		clear(n->right);
		delete n;

}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
	if (root == nullptr) {
		root = new Node(value);
		return true;
	}
	else {
		return insert(value, root);
	}
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
	if (value == n-> info) {
		return false;
	}
	else if (value < n->info) {
		if(n->left == nullptr) {
			n->left = new Node(value);
			n->left->parent = n;
			return true;
		}
		else {
			return insert(value, n->left);
		}
	}
	else if {
		if (n->right == nullptr) {
			n->right = new Node(value);
			n->right->parent = n;
			return true;
		}
		else {
			return insert(value, n->right);
		}
	}
}

// print tree data pre-order
void IntBST::printPreOrder() const {
	printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
	if (n != nullptr) {
		cout << n->info << " ";
		printPreOrder(n->left);
		printPreOrder(n->right);
}
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
	printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
	if (n != nullptr) {
		printInOrder(n->left);
		cout << n->info << " ";
		printInOrder(n->right);
	}
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
	printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
	if (n != nullptr) {
		printPostOrder(n->left);
		printPostOrder(n->right);
		cout << n->info << " ";
	}
}

// return sum of values in tree
int IntBST::sum() const {
	return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
	if (n == nullptr) {
		return 0;
	}
	return n->info + sum(n->right) + sum(n->left);
}

// return count of values
int IntBST::count() const {
	return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
	if (n == nullptr) {
		return 0;
	}
	return 1 + count(n->right) + count(n->left);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
	if ((n == nullptr) or (n->info == value) {
			return n;
			}
	if(value < n->info) {
	return getNodeFor(value, n->left);
	}
	else {
	return getNodeFor(value, n->right);
	}
	
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
	Node* node = getNodeFor(value, root);
	return node != nullptr;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
	Node* curr = root;
	Node* predecessorNode = nullptr;

	while(curr != nullptr) {
		if(value <= curr->info){
			curr = curr->left;
		}
		else {
			predecessorNode = curr;
			curr = curr->right;
		}
	}
	return predecessorNode;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
	if(predecessorNode != nullptr) {
		return predecessorNode->info;
	}
	else {
		return 0;
	}

}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
	Node* curr = root;
	Node* successorNode = nullptr;

	while(curr != nullptr) {
		if(value >= curr->info) {
			curr = curr->right;
		}
		else {
			successorNode = curr;
			curr = curr->left;
		}
	}
	return sucessorNode;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
	Node* successorNode = getSuccessorNode(value);

	if(successsorNode == nullptr)
		return 0;
	return successorNode->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
