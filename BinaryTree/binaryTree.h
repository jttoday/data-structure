#ifndef BINARYTREE_GUARD
#define BINARYTREE_GUARD

#include <queue>
using std::queue;
#include <deque>
using std::deque;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


template< class T>
class BinaryTree {
private:
	struct Node {
		Node *left, *right;
		T data;

		Node() :left(NULL), right(NULL) {}
		Node(T item, Node *L=NULL, Node *R=NULL)
				:data(item), left(L), right(R) {}
		~Node() {}
	};

	Node *root;

public:
	BinaryTree() :root(NULL)	{}
	BinaryTree(const T& value)	{ root = new Node(value); }

	~BinaryTree()	{ del(root); }

	void buildTree(T flag);

	void delLeft(Node* t)	{ del(t-> left); }
	void delRight(Node* t)	{ del(t-> right);}

	bool isEmpty() const	{ return root == NULL;	}
	int size() const		{ return size(root);	}
	int height() const		{ return height(root);	}

	void swapChildren()		{ swapChildren(root);	}
	bool isComplete() const	{ return isComp(root);	}
	bool isMirror() const	{ return isMirrorEqual(root-> left, root-> right);} 

	queue<T> items;

	void midOrder()			{ clearQueue(); midOrder(root);	}
	void printBranch()		{ branches.push_back(root);findLongest(root , height()); }

private:
	void del(Node *t) {
		if (t == NULL) return;
		del(t-> left);
		del(t-> right);
		delete t;
	}

	int size(Node *t) const {
		if (t == NULL) return 0;
		return 1+ size(t-> left)+ size(t-> right);
	}

	int height(Node *t) const {
		if (t == NULL) return 0;
		int lh = height(t-> left);
		int rh = height(t-> right);
		if (lh < rh) 
			return rh + 1;
		else
			return lh + 1;
	}

	void swapChildren(Node *t) {
		if (t == NULL) return;
		Node* lc = t-> left;
		Node* rc = t-> right;


		swapChildren(t-> left);
		swapChildren(t-> right);
		t->left = rc;
		t->right = lc;
	}
	
	bool isFull(Node *t) const {
		if (t == NULL) return true;
		
		int lh = height(t-> left);
		int rh = height(t-> right);
		return (lh == rh && isFull(t-> left) && isFull(t-> right));
	}

	bool isComp(Node *t) const {
		if (t == NULL) return true;
		bool lf = isFull(t-> left);
		bool rf = isFull(t-> right);
		if (lf && rf) return true;

		int lh = height(t-> left);
		int rh = height(t-> right);
		if (!lf && !rf) return false;
		if (lf && !rf && (lh != rh)) return false;
		if (!lf && rf && (lh != rh+1)) return false;
		return isComp(t-> left) && isComp(t-> right);
	}

	bool isEqual(Node *a, Node *b) const {
		if (a == b)					return true;
		if (a == NULL || b == NULL) return false;
		return (a-> data == b-> data) && isEqual(a->left, b->left) && isEqual(a-> right, b->right);
	}

	bool isMirrorEqual(Node *a, Node *b) const {
		if ( a == NULL && b == NULL) return true;
		if ( (a == NULL || b == NULL) && (a != b)) return false;
		return (a-> data == b-> data) && isMirrorEqual(a->left, b->right) && isMirrorEqual(a->right, b->left);
	}

	void clearQueue() {
		queue<T> tmp;
		items = tmp;
	}

	void midOrder(Node *t) {
		if (t == NULL) return;
		midOrder(t-> left);
		items.push(t-> data);
		midOrder(t-> right);
	}

	deque<Node *> branches;

	void print(deque<Node *> & q) {
		typename std::deque<Node *>::iterator it = q.begin();
		
		while (it != q.end()) {
			cout << " " << (*it)->data;
			it ++;
		}
		cout << endl;
	}
		

	void findLongest(Node *p , int h) {
		if (p == NULL) return;
		if (height(p) != h) return;
		if (h == 1) {
			print(branches);
			return;
		}
		branches.push_back(p->left);
		findLongest(p->left , h - 1);
		branches.pop_back();
		branches.push_back(p->right);
		findLongest(p->right , h - 1);
		branches.pop_back();
	}
};

template<class T>
void BinaryTree<T>::buildTree(T flag)
{
	queue<Node *> q;
	Node* t;
	T x, l, r;

	cout << "Enter the root: ";
	cin >> x;
	cout << endl;
	root = new Node(x);
	q.push(root);

	while (!q.empty()) {
		t = q.front();
		q.pop();
		cout << "Enter the sons of " << t->data <<" (" 
			<< flag << " is NULL node): ";
		cin >> l >> r;
		cout << endl;
		if (l != flag) q.push(t-> left = new Node(l));
		if (r != flag) q.push(t-> right = new Node(r));
	}

	cout << "Tree built successfully." << endl;
}

	
	

#endif
