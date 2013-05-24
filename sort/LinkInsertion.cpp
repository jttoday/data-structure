#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename T>
struct node {
	T data;
	node* next;
	node(node* n=NULL) :next(n) {}
	node(T d, node* n=NULL) :next(n), data(d) {}
};


template<typename T>
void sort(T* head)
{
	T* curr = head->next;
	T* prev = head;
	while (curr!=NULL)
	{
		T* tmp = head->next;
		T* ptmp = head;
		while (tmp != curr && tmp->data <= curr->data)
		{
			ptmp = tmp;
			tmp = tmp->next;
		}
		if (tmp != curr)
		{
			prev->next = curr->next;
			curr->next = tmp;
			ptmp->next = curr;
			curr = prev;
		}
		prev = curr;
		curr = curr->next;
	}
}

const int size = 20;
int main()
{
	srand(time(NULL));
	node<int> *head = new node<int>();
	cout << "Before sort:" << endl;
	node<int> *curr = head;
	for (int i=0;i < size; ++i)
	{
		int t = rand() % 100;
		cout << t << ' ';
		curr->next = new node<int>(t);
		curr = curr->next;
	}
	cout << endl;
	sort(head);
	cout << "After sort:" << endl;
	for (curr = head->next; curr !=NULL; curr= curr->next)
		cout << (curr->data) << ' ';
	cout << endl;
	return 0;
}




	
