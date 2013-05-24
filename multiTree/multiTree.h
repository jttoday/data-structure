#ifndef MULTITREEH_GUARD
#define MULTITREEH_GUARD

#define NULL 0
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template< class T>
class Tree {
private:
	struct Node {
		Node *son, *sib;
		T data;

		Node() :son(NULL), sib(NULL) {}
		Node(T item, Node *L=NULL, Node *R=NULL)
				:data(item), son(L), sib(R) {}
		~Node() {}
	};

	Node *root;

public:
	Tree() :root(NULL)	{}
	Tree(const T& value)	{ root = new Node(value); }

	~Tree()	{ del(root); }

	void buildTree(T flag);

	bool isEmpty() const	{ return root == NULL;	}
	int size() const		{ return size(root);	}
	int height() const		{ return height(root);	}

private:
	void del(Node *t) {
		if (t == NULL) return;
		del(t-> son);
		del(t-> sib);
		delete t;
	}

	int size(Node *t) const {
		if (t == NULL) return 0;
		return 1+ size(t-> son)+ size(t-> sib);
	}

	int height(Node *t) const {
		if (t == NULL) return 0;
		Node *son = t->son;
		int sh = 0;
		while (son != NULL) {
			int t;
			if ((t=height(son)) > sh) 
				sh = t;
			son = son->sib;
		}
		return sh + 1;
	}
};

#include <queue>
using std::queue;

template<class T>
void Tree<T>::buildTree(T flag)
{
	queue<Node *> q;
	Node* t;
	T x, l, r;

	cout << "Enter the root: ";
	cin >> x;
	root = new Node(x);
	q.push(root);

	while (!q.empty()) {
		t = q.front();
		q.pop();
		cout << "Enter the first son and next sibling of " << t->data <<" (" 
			<< flag << " is NULL node): ";
		cin >> l >> r;
		if (l != flag) q.push(t-> son = new Node(l));
		if (r != flag) q.push(t-> sib = new Node(r));
	}
	cout << "Tree built successfully." << endl;
}

#endif
