#include "multiTree.h"
#include <iostream>

int main()
{
	Tree<char> t;
	t.buildTree('#');
	cout << "The size of this tree is " << t.size() << endl;
	cout << "The height of this tree is " << t.height() << endl;
	return 0;
}

