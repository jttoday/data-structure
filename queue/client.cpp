#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	Queue<int> iq;
	for (int i=0;i < 10; ++i) iq.enqueue(i);
	while (!iq.empty()) {
		cout << iq.dequeue() << ' ';
	}
	cout << endl;
	return 0;
}
