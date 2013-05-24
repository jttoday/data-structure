#ifndef HASHSET_GUARD_JINTIAN
#define HASHSET_GUARD_JINTIAN

template <typename T>
class HashSet {
	struct node{
		T data;
		int state;
		
		node() :state(0) {}
	};
	int M; // The total capacity
	int N; // number of keys
	node* data;
	typedef int (*f)(const T& key) ;
	f keyF;
public:
	HashSet(f keyF = defaultKey);
	HashSet(int capacity, f keyF = defaultKey);
	~HashSet();
	
	int size()				{ return N;			}
	int capacity()			{ return M;			}
	bool isEmpty()			{ return size()==0; }
	bool contains(T key);	
	void put(T key);
	void remove(T key);
	
private:
	static int defaultKey(const int &k) { return k; }
	int hash(T key);
	void rehash();
	void resize(int capacity);
};

#include "HashSet.hpp"

#endif
