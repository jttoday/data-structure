#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class blockingSearch {
	struct Index {
		T data;
		int index;
		Index(T t, int i) :data(t),index(i) {}
	};

	vector<T> dataTable;
	vector<Index> indexTable;
	typedef vector<T> data;
public:
	void build(const vector<T>&, const vector<T>&, const vector<int>&);
	bool find(const T&) const;
};

template<typename T>
void blockingSearch<T>::build(const data& d, const data& id, const vector<int>& ii)
{
	if (id.size() != ii.size())
		throw runtime_error("not match!");
	for (int i=0;i < d.size(); ++i)
		dataTable.push_back(d[i]);
	for (int i=0;i < id.size(); ++i)
		indexTable.push_back(Index(id[i] , ii[i]));
}

template<typename T>
bool blockingSearch<T>::find(const T& key) const
{
	int k = 0;
	while (k < indexTable.size()) {
		if (key < indexTable[k].data)
			break;
		k++;
	}
	if (k >= indexTable.size())
		return false;
	int min = 0;
	if (k-1 >=0)
		min = indexTable[k-1].index;
	int max = indexTable[k].index;
	for (int i=min; i <= max; ++i)
		if (key == dataTable[i])
			return true;
	return false;
}

void read_line(istream& is, vector<int>& d)
{
	string s;
	getline(is , s);
	istringstream ss(s);
	int dd;
	while (ss >> dd)
		d.push_back(dd);
}

int main()
{
	vector<int> d , idxD, idxI;
	read_line(cin , d);
	read_line(cin , idxD);
	read_line(cin , idxI);
	blockingSearch<int> bs;
	bs.build(d, idxD , idxI);
	int key;
	while	(cin >> key) {
		if (bs.find(key)) 
			cout << "Find successfully: " << key << endl;
		else
			cout << "Key not found: " << key << endl;
	}
	return 0;
	
}

	




