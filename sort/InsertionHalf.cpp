#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


template<typename T>
int find(T a[], int l, int h)
{
	T key = a[h--];
	while (l <=h ) 
	{
		int mid = l +(h-l) / 2;
		if		(key >= a[mid])	l = mid+1;
		else if (key <  a[mid])	h = mid-1;

	}

	return l;
}

template<typename T>
void InsertionHalf(T a[], int begin ,int end)
{
	for (int i=begin;i < end; ++i)
	{
		int pos = find(a, begin , i);
		T tmp = a[i];
		for (int k=i;k > pos; --k)
			a[k] = a[k-1];
		a[pos] = tmp;
	}
}


const int size = 10;
int main()
{
	srand(time(NULL));
	int a[size];
	
	cout << "Before insertion:" <<endl;
	for (int i=0; i< size; ++i)
	{
		int t = rand() % 500;
		a[i] = t;
		cout << t << ' ';
	}
	cout << endl;
	InsertionHalf(a,0,size);
	cout << "After insertion:" << endl;
	for (int i=0; i< size; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}




