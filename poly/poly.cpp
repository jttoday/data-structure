#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <string.h>

using namespace std;



struct node {

	int coeff , powr;
	node* next;

	node() :coeff(0), powr(0) , next(NULL) {}

	node(int a, int n , node* t = NULL) {
		coeff = a;
		powr = n;
		next = t;
	}

	node* clone(void) {	return new node(coeff , powr ); }

};


node* add(node* exp1, node* exp2)
{
	node* curr1 = exp1 -> next;
	node* curr2 = exp2 -> next;
	node* head = new node();
	node* p = head;
	while (curr1 && curr2) {
		if (curr1->powr < curr2->powr) {
			p->next = curr1->clone();
			curr1 = curr1->next;
		} 
		else if (curr1->powr > curr2->powr) {
			p->next = curr2->clone();
			curr2 = curr2->next;
		}
		else {
			p->next = new node(curr1->coeff + curr2->coeff, curr1->powr);
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		p = p->next;
	}
	node* remain;
	if (curr1) remain = curr1;
	else remain = curr2;

	while (remain !=NULL) {
		p->next = remain->clone();
		remain = remain->next;
		p = p->next;
	}

	return head;
}

template<typename T>
void freeAll(T* head)
{
	while (head->next) {
		delete(head);
		head = head->next;
	}
}


void addElement(int , int , node *);

void process(string& s)
{
	for (int i=0;i< s.length(); ++i)
		if (!isdigit(s[i])) s[i] = ' ';
}

node* readExp(int readMode)
{
	node* head = new node();
	node* p = head;
	int a,n;
	string s;
	getline(cin , s);
	if (readMode) process(s);
	istringstream in(s);
	while (in >> a >>n) {
		addElement(a , n , head);
	}
	return head;
}


void showExp(node* exp)
{
	node* curr = exp->next;
	while (1) {
		cout<< curr->coeff << "*x^" << curr->powr; 
		curr= curr->next;
		if (curr) cout << "+ ";
		else {
			cout << endl;
			break;
		}
	}
}

void addElement(int a, int n, node* head)
{
	if (a==0) return;
	node* p = new node(a , n);
	node* curr = head -> next;
	node* prev = head;

	while (curr && curr->powr < n ) {
		prev = curr;
		curr = curr -> next;
	}
	if (curr && curr->powr == n) throw runtime_error("Same coeffcient has been typed twice!");
	if (prev == NULL) head->next = p;
	else prev->next = p;
	p->next = curr;
}




int main(int argc, char* argv[])
{

	int rm = 0;
	if (argc >=2 && strcmp(argv[1],"x")==0) rm = 1; 
	node* exp1 = readExp(rm);
	node* exp2 = readExp(rm);
	node* result = add(exp1 , exp2);
	showExp(result);
	freeAll(exp1);
	freeAll(exp2);
	freeAll(result);
	return 0;
}
