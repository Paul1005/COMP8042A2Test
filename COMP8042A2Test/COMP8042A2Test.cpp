#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include "Expression.h"
#include "CircularQueue.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	/*cout << "***** Q1: Postfix expression" << endl;
	for (int k = 1; k <= 4; k++)
	{
		cout << "Enter a postfix expression:" << endl;
		double result = evalPostFix();
		cout << "Result = " << result << endl;
	}*/
	cout << "Enter a non-valid infix expression:" << endl;
	bool result = isValidExpression(0);
	cout << "Result = " << result << endl;
	result = isValidExpression(1);
	cout << "Result = " << result << endl;
	result = isValidExpression(2);
	cout << "Result = " << result << endl;

	/*cout << endl << endl << "***** Q2: Queue using circular array" << endl;
	queue<int> Q(5);
	cout << "Empty Q:"; Q.print(); cout << endl;
	Q.enque(1);
	Q.enque(2);
	Q.enque(3);
	cout << "Full Q1:"; Q.print(); cout << endl;
	cout << Q.deque() << " " << Q.deque() << " " << Q.deque() << " " << endl;
	cout << Q.deque() << endl;
	Q.enque(10);
	Q.enque(20);
	Q.enque(30);
	Q.enque(40);
	Q.enque(50);
	cout << "Full Q2:"; Q.print(); cout << endl;
	cout << Q.deque() << endl;
	Q.enque(100);
	cout << "Full Q3:"; Q.print(); cout << endl;
	cout << Q.deque() << endl;
	cout << Q.deque() << endl;
	cout << Q.deque() << endl;
	cout << Q.deque() << endl;


	cout << endl << endl << "***** Q3: Binary Search Tree" << endl;
	BinarySearchTree<int> bst;

	int emptyTree = bst.isEmpty();
	cout << "Should be empty: " << emptyTree << endl;
	cout << "Tree (should be empty): "; bst.printTree(); cout << endl;
	bst.insert(78);
	bst.insert(12);
	bst.insert(56);
	bst.insert(34);
	bst.insert(40);
	bst.remove(56);
	bst.insert(56);

	cout << "Tree (should have 5 elements): "; bst.printTree(); cout << endl;
	emptyTree = bst.isEmpty();
	cout << "Should not be empty: " << emptyTree << endl;
	int minVal = bst.findMin();
	int maxVal = bst.findMax();
	bool containsSuccess = bst.contains(12);
	bool containsFail = bst.contains(999);
	cout << "Min (12) = " << minVal << "; Max (78) = " << maxVal << "; Contains 12 (true): " << containsSuccess << "; Contains 999 (false): " << containsFail << endl;

	BinarySearchTree<int> bst2(bst);
	cout << "Tree2 (should have 5 elements): "; bst2.printTree(); cout << endl;
	BinarySearchTree<int> bst3 = bst2;
	cout << "Tree3 (should have 5 elements): "; bst3.printTree(); cout << endl;

	bst.makeEmpty();
	cout << "Tree (should be empty): "; bst.printTree(); cout << endl;

	cout << "Building tree [5, 10, 0, 1, -1, 9, 11]..." << endl;
	BinarySearchTree<int> tree;
	tree.insert(5);
	tree.insert(10);
	tree.insert(0);
	tree.insert(1);
	tree.insert(-1);
	tree.insert(9);
	tree.insert(11);
	cout << "Printing tree..." << endl;
	tree.printTree(cout);
	cout << endl;

	cout << "Removing elements [1, 5, 10] from tree..." << endl;
	tree.remove(1);
	tree.remove(5);
	tree.remove(10);
	cout << "Printing tree..." << endl;
	tree.printTree(cout);
	cout << "Printing tree with deleted nodes..." << endl;
	tree.printTree(cout, true);
	cout << endl;

	cout << "Adding element [10] to tree..." << endl;
	tree.insert(10);
	cout << "Printing tree..." << endl;
	tree.printTree(cout);
	cout << "Printing tree with deleted nodes..." << endl;
	tree.printTree(cout, true);
	cout << endl;*/

	return 0;
}
