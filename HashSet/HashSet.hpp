
#include <iostream>
using namespace std;

template<typename T>
HashSet<T>::HashSet(f func) :M(97) , keyF(func)
{
	keyF = func;
	data = new node[M];
}

template<typename T>
HashSet<T>::HashSet(int cap, f func) :M(cap), keyF(func)
{
	keyF = func;
	data = new node[M];
}

template<typename T>
HashSet<T>::~HashSet()
{
	delete[] data;
}

template<typename T>
int HashSet<T>::hash(T key)
{
	return (keyF(key)&0x7fffffff) % M;
}

template<typename T>
bool HashSet<T>::contains(T key)
{
//	do{
//		if (data[i].state == 0) return false;
//		if (data[i].data == key) return true;
//		i = (i+a*a) % M;
//	if 
	int i , k;
	for (i= hash(key), k=1; data[i].state!=0 ; i=(i + k*k) % M)
		if (data[i].data == key)
			return true;
	return false;
}


template<typename T>
void HashSet<T>::put(T key)
{
	if (N >= M/2) resize(2*M+1);

	int i , k;
	for (i= hash(key), k=1; data[i].state!=0;i = (i + k*k) % M)
		if (data[i].data ==key)
			return;
	data[i].state = 1;
	data[i].data = key;
	N++;
}

template<typename T>
void HashSet<T>::remove(T key)
{
	if (!contains(key)) return;

	int i = hash(key);
	int k = 1;
	while (!(data[i].data == key))
	{
		i = (i + k*k) % M;
		k++;
	}
	data[i].state = 0;
	rehash();
}

template<typename T>
void HashSet<T>::resize(int cap)
{
	M = cap;
	rehash();
}

template<typename T>
void HashSet<T>::rehash()
{
	node* tmp = data;
	data = new node[M];
	for (int i=0; i < M; i++)
		if (data[i].state != 0)
			put(data[i].data);
	delete[] tmp;
}



			
	


	
