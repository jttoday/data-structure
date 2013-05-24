#include "binaryTree.h"
#include <iostream>

/*
void printTree(BinaryTree<char>& tree)
{
	tree.midOrder();
	queue<char> q = tree.items;

	while (!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}
*/

int main()
{
	BinaryTree<char> tree;
	tree.buildTree('#');
	tree.printBranch();
	return 0;

}
	
