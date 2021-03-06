#include <algorithm>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

class UnderflowException { };

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() : root{ nullptr }
	{
		numDeleted = 0;
	}

	// Copy constructor
	BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr }
	{
		numDeleted = 0;
		root = clone(rhs.root);
	}

	// Move constructor
	BinarySearchTree(BinarySearchTree&& rhs) : root{ rhs.root }
	{
		numDeleted = 0;
		rhs.root = nullptr;
	}

	// Destructor for the tree
	~BinarySearchTree()
	{
		makeEmpty();
	}

	// Copy assignment
	BinarySearchTree& operator=(const BinarySearchTree& rhs)
	{
		BinarySearchTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	// Move assignment
	BinarySearchTree& operator=(BinarySearchTree&& rhs)
	{
		std::swap(root, rhs.root);
		return *this;
	}


	// Find the smallest item in the tree.
	// Throw UnderflowException if empty.
	const Comparable& findMin() const
	{
		if (isEmpty())
			throw UnderflowException{ };
		return findMin(root)->element;
	}

	// Find the largest item in the tree.
	// Throw UnderflowException if empty.
	const Comparable& findMax() const
	{
		if (isEmpty())
			throw UnderflowException{ };
		return findMax(root)->element;
	}

	// Returns true if x is found in the tree.
	bool contains(const Comparable& x) const
	{
		return contains(x, root);
	}

	// Test if the tree is logically empty.
	// Return true if empty, false otherwise.
	bool isEmpty() const
	{
		return root == nullptr;
	}

	// Print the tree contents in sorted order.
	void printTree(ostream& out = cout, bool printDeleted = false) const
	{
		if (isEmpty())
			out << "Empty tree" << endl;
		else {
			out << "NUM DELETED = " << numDeleted << endl;
			printTree(root, out, printDeleted);
		}
	}

	// Make the tree logically empty.
	void makeEmpty()
	{
		makeEmpty(root);
	}

	// Insert x into the tree; duplicates are ignored.
	void insert(const Comparable& x)
	{
		insert(x, root);
	}

	// Insert x into the tree; duplicates are ignored.
	void insert(Comparable&& x)
	{
		insert(std::move(x), root);
	}

	// Remove x from the tree. Nothing is done if x is not found.
	void remove(const Comparable& x)
	{
		remove(x, root);
	}


private:
#define HEIGHT(n) (((n) == NULL)? -1 : ((n)->height))
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;
		bool isDeleted; // added this flag
		int height; 

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
			: element{ theElement }, left{ lt }, right{ rt }, height(0) {
			isDeleted = false; // set flat to false on create
		}

		BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
			: element{ std::move(theElement) }, left{ lt }, right{ rt }, height(0) {
			isDeleted = false; // set flat to false on create
		}
		
		void updateHeight() {
			height = std::max(HEIGHT(left), HEIGHT(right)) + 1;
		}

		bool balanced() {
			return abs(HEIGHT(left) - HEIGHT(right)) <= 1;
		}
	};

	BinaryNode* root;
	int numDeleted;

	void balance(const Comparable& x, BinaryNode*& t) {

		if (!t->balanced()) {
			int rightHeight = -1;
			if (t->right != NULL) {
				rightHeight = t->right->height;
			}

			int leftHeight = -1;
			if (t->left != NULL) {
				leftHeight = t->left->height;
			}

			int balanceFactor = leftHeight - rightHeight;
			if (balanceFactor > 1 && x < t->left->element) {
				t = singleRightRotation(t);
			}
			else if (balanceFactor < -1 && x > t->right->element) {
				t = singleLeftRotation(t);
			}
			else if (balanceFactor > 1 && x > t->left->element) {
				t = doubleLeftRightRotation(t);
			}
			else if (balanceFactor < -1 && x < t->right->element) {
				t = doubleRightLeftRotation(t);
			}

		}
	}

	/*
		Internal methods to insert into a subtree.
		x is the item to insert.
		t is the node that roots the subtree.
		Set the new root of the subtree.
	 */
	void insert(const Comparable& x, BinaryNode*& t)
	{
		if (t == nullptr)
			t = new BinaryNode{ x, nullptr, nullptr };
		else if (x < t->element) {
			insert(std::move(x), t->left);
			t->updateHeight();
		}
		else if (t->element < x) {
			insert(std::move(x), t->right);
			t->updateHeight();
		}
		else {
			if (t->isDeleted) {
				t->isDeleted = false; // if duplicate, but flag is true, flip to false
				numDeleted--;
			}
		}
		balance(x, t);
	}

	void insert(Comparable&& x, BinaryNode*& t)
	{
		if (t == nullptr)
			t = new BinaryNode{ std::move(x), nullptr, nullptr };
		else if (x < t->element) {
			insert(std::move(x), t->left);
			t->updateHeight();
		}
		else if (t->element < x) {
			insert(std::move(x), t->right);
			t->updateHeight();
		}
		else {
			if (t->isDeleted) {
				t->isDeleted = false; // if duplicate, but flag is true, flip to false
				numDeleted--;
			}
		}
		balance(x, t);
	}

	/*
		Internal method to remove from a subtree.
		x is the item to remove.
		t is the node that roots the subtree.
		Set the new root of the subtree.
	 */
	void remove(const Comparable& x, BinaryNode*& t)
	{
		if (t == nullptr)
			return;   // Item not found; do nothing
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else
		{
			if (!t->isDeleted) {
				t->isDeleted = true; // changed code to set isDeleted to true;
				numDeleted++; // increase number of deletions
			}
		}
	}

	/*
		Internal method to find the smallest item in a subtree t.
		Return node containing the smallest item.
	 */
	BinaryNode* findMin(BinaryNode* t) const
	{
		BinaryNode* minNode = nullptr;

		findMinLazyDelete(t, minNode); //does an inorder traversal until it finds the first non-deleted node
		return minNode;

	}

	// based on https://stackoverflow.com/questions/48895238/how-to-write-findminimum-of-a-lazy-deleted-binary-search-tree-in-java
	void findMinLazyDelete(BinaryNode* t, BinaryNode*& minNode) const
	{
		if (t != nullptr && minNode == nullptr) {
			findMinLazyDelete(t->left, minNode);
			if (!t->isDeleted && minNode == nullptr) {
				minNode = t;
			}
			findMinLazyDelete(t->right, minNode);
		}
	}

	/*
		Internal method to find the largest item in a subtree t.
		Return node containing the largest item.
	 */
	BinaryNode* findMax(BinaryNode* t) const
	{
		BinaryNode* maxNode = nullptr;

		findMaxLazyDelete(t, maxNode); //does a reverse inorder traversal until it finds the first non-deleted node
		return maxNode;
	}

	void findMaxLazyDelete(BinaryNode* t, BinaryNode*& maxNode) const
	{
		if (t != nullptr && maxNode == nullptr) {
			findMaxLazyDelete(t->right, maxNode);
			if (!t->isDeleted && maxNode == nullptr) {
				maxNode = t;
			}
			findMaxLazyDelete(t->left, maxNode);
		}
	}

	/*
		Internal method to test if an item is in a subtree.
		x is item to search for.
		t is the node that roots the subtree.
	 */
	bool contains(const Comparable& x, BinaryNode* t) const
	{
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;    // Match
	}

	// Internal method to make subtree empty.
	void makeEmpty(BinaryNode*& t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	// Internal method to print a subtree rooted at t in sorted order.
	void printTree(BinaryNode* t, ostream& out, bool printDeleted = false) const
	{
		if (t != nullptr)
		{
			printTree(t->left, out, printDeleted);
			if (printDeleted) {
				out << t->element << endl;
			}
			else if (!printDeleted) {
				if (!t->isDeleted) {
					out << t->element << endl;
				}
			}
			printTree(t->right, out, printDeleted);
		}
	}

	// Internal method to clone subtree.
	BinaryNode* clone(BinaryNode* t) const
	{
		if (t == nullptr)
			return nullptr;
		else
			return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
	}

	//based on https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
	BinaryNode* singleRightRotation(BinaryNode* y)
	{
		BinaryNode* x = y->left;
		BinaryNode* T2 = x->right;

		// Perform rotation  
		x->right = y;
		y->left = T2;

		y->updateHeight();
		x->updateHeight();

		// Return new root  
		return x;
	}

	BinaryNode* singleLeftRotation(BinaryNode* x)
	{
		BinaryNode* y = x->right;
		BinaryNode* T2 = y->left;

		// Perform rotation  
		y->left = x;
		x->right = T2;

		x->updateHeight();
		y->updateHeight();

		// Return new root  
		return y;
	}

	BinaryNode* doubleLeftRightRotation(BinaryNode* y)
	{
		y->left = singleLeftRotation(y->left);
		BinaryNode* x = singleRightRotation(y);
		return x;
	}
  
	BinaryNode* doubleRightLeftRotation(BinaryNode* x)
	{
		x->right = singleRightRotation(x->right);
		BinaryNode* y = singleLeftRotation(x);
		return y;
	}
};

#endif
