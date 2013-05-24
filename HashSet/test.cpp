#include "HashSet.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	srand(time(NULL));
	HashSet<int> hs;
	
	cout << "Insert elements into the HashSet:" <<endl;
	for (int i=0;i< 20; ++i)
	{
		int t = rand() % 100;
		cout << "Inserting " << t << " ..." << endl;
		hs.put(t);
	}

	cout << "Those elements are in the HashSet:" << endl;
	for (int i=0;i< 100; ++i)
	{
		if (hs.contains(i))
			cout << i << endl;
	}
}
