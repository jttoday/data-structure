#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename T>
void sort(T* head)
{
	T* curr = head->next;
	while (curr!=NULL)
	{
		T* tmp = head->next;
		while (tmp != curr && tmp->data <= curr->data)
		{
			tmp = tmp->next;
		}
		if (tmp != curr)
		{
			tmp->
			


		curr = curr->next;
	}
