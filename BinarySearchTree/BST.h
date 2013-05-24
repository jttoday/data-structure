#ifndef PLAIN_BST_GUARD_H
#define PLAIN_BST_GUARD_H
#include <iostream>
using namespace std;

template<typename Key,typename Value>
class BST {
	struct Node {
		Key key;
		Value val;
		Node *left, *right;
		
		Node(Key k, Value v) :key(k), val(v){ }
	};

	Node *root;
	
public:

	BST() :root(NULL) { }
	
	void put(Key key, Value val)	{ put(root, key, val); }
	bool contain(Key key) const		{ return contain(root, key) ; }

	void deleteKey(Key key)			{ root = deleteKey(root, key); }
	void deleteMin()				{ root = deleteMin(root);}

	void deleteSmall(Key key)		{ root = deleteSmall(root, key);}
	void deleteLarge(Key key)		{ root = deleteLarge(root, key);}

	void deleteRange(Key low, Key high) { 
		root = deleteRange(root, low , high);
	}

	void showMidOrder() const { 
		showMidOrder(root); 
		cout << endl;
	}

private:

	bool *contain(Node *r, Key k) const {
		if (r == NULL) 
			return false;
		while (r != NULL) {
			if (r->key == k) 
				return true;
			if (r->key < k)
				r = r->right;
			else 
				r = r->left;
		}
		return false;
	}


	void put(Node* r, Key k, Value v)	{
		if (r == NULL) {
			root =  new Node(k, v);
			return;
		}
		Node *p = r;
		while (r != NULL) {
			p = r;
			if (r->key == k) {
				r->val = v;
				return; 
			}
			if (k < r->key) r = r->left;
			else			r = r->right;
		}
		if (k < p->key) p->left = new Node(k , v);
		else			p->right = new Node(k , v);
	}

	Node *deleteMin(Node* x) {
		if (x == NULL)
			return NULL;
		if (x->left == NULL)
			return x->right;
		x -> left = deleteMin(x->left);
		return x;
	}


	Node *deleteKey(Node* r, Key k) {
		if ( r== NULL) 
			return r;
		if		(k > r->key) r->right = deleteKey(r->right, k);
		else if (k < r->key) r->left  = deleteKey(r->left, k);
		else {
			if (r->right == NULL) return r->left;
			if (r->left  == NULL) return r->right;
			Node *t = r;
			r = min(t->right);
			r->right = deleteMin(t->right);
			r->left = t->left;
		}
		return r;
	}

	Node *min (Node* r) {
		if (r == NULL) return NULL;
		if (r->left == NULL) return r;
		else return min(r->left);
	}

	Node *deleteSmall(Node *r, Key k) {
		if (r == NULL) 
			return NULL;
		if (k < r->key)		 r->left = deleteSmall(r->left, k);
		else if (k > r->key) r = deleteSmall(r->right , k);
		else			     r->left = NULL;
		return r;
	}
	
	Node *deleteLarge(Node *r, Key k) {
		if (r == NULL) 
			return NULL;
		if (k > r->key)		 r->right = deleteLarge(r->right, k);
		else if (k < r->key) r = deleteLarge(r->left , k);
		else			     r->right = NULL;
		return r;
	}

	Node *floor(Node *r, Key key) {
		if (r == NULL) return NULL;
		if (r->key == key) return r;
		if (r->key >  key) return floor(r->left, key);
		Node *t = floor(r->right, key);
		if (t == NULL) 
			return r;
		else 
			return t;
	}

	Node *ceiling(Node *r, Key key) {
		if (r == NULL) return NULL;
		if (r->key == key) return r;
		if (r->key <  key) return ceiling(r->right, key);
		Node *t = ceiling(r->left, key);
		if (t == NULL) 
			return r;
		else 
			return t;
	} 
	
	Node *deleteRange(Node *r, Key low, Key high) {
		if (r == NULL) return NULL;
		if (r->key > high)		r->left = deleteRange(r->left, low, high);
		else if(r->key < low)	r->right = deleteRange(r->right, low, high);
		else {
			Node *f = floor(r , low);
			Node *c = ceiling(r, high);
			r->left = deleteLarge(r->left, f->key);
			r->right = deleteSmall(r->right,c->key);
			Node *m = min(r->right);
			if (m == NULL)
				return r->left;
			else 
				m->left = r->left;
			return r->right;
		}
		return r;
	}

	void showMidOrder(Node *r) const {
		if (r == NULL) return;
		showMidOrder(r->left);
		cout << r->key << "-" << r->val << ' ';
		showMidOrder(r->right);
	}

	

	

};

#endif


	
			
