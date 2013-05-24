#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
	int k,v;
	BST<int , int> bst;
	while (cin >> k >> v) {
		bst.put(k,v);
	}
	cout << "The Origin Tree: " << endl; 
	bst.showMidOrder();
	
	bst.deleteLarge(43);
	cout << "After delete elements larger than 43:" << endl;
	bst.showMidOrder();
	
	bst.deleteSmall(8);
	cout << "After delete elements smaller than 8:" << endl;
	bst.showMidOrder();

	bst.deleteRange(16 , 29);
	cout << "After delete elements in range(16,29): " << endl;
	bst.showMidOrder();

	return 0;
}
