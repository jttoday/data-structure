#include <stdexcept>
using namespace std;

template <class T>
class Queue {
public:
	Queue();
	bool empty() const;
	T front() const;
	T back() const;
	void push(const T&);
	void pop();
	void enqueue(const T&);
	T dequeue();
	~Queue();

private:
	struct node {
		T data;
		node* next;

		node() :next(NULL) {}
		node(const T& elem ) {
			data = elem;
			next = NULL;
		}
	};
	node *head, *rear;
};

template <class T>
Queue<T>::Queue() :rear(NULL) {
	head = new node();
	head ->next = rear;
}

template <class T>
inline bool Queue<T>::empty() const
{
	return rear == NULL;
}

template <class T>
T Queue<T>::front() const
{
	if (empty()) throw runtime_error("Empty queue!");
	return head->next->data;
}

template <class T>
T Queue<T>::back() const
{
	if (empty()) throw runtime_error("Empty queue!");
	return rear->data;
}


template <class T>
void Queue<T>::push(const T& elem)
{
	if (rear == NULL)
		head->next = rear = new node(elem);
	else {
		rear->next = new node(elem);
		rear = rear->next;
	}
}

template <class T>
void Queue<T>::pop()
{
	if (empty()) throw runtime_error("Empty queue!");
	/*
	 * only one element in the queue
	 */
	if (head -> next==rear) {
		delete rear;
		rear = NULL;
	}else {
		node* t = head;
		head = head->next;
		delete t;
	}
}

template <class T>
void Queue<T>::enqueue(const T& elem)
{
	this->push(elem);
}

template <class T>
T Queue<T>::dequeue()
{
	T t = this->front();
	this->pop();
	return t;
}

template <class T>
Queue<T>::~Queue()
{
	if (empty()) {
		delete head;
		return;
	}
	node *p = head;
	node *q = p->next;
	while (q != NULL){
		delete p;
		p = q;
		q = q->next;
	}
}




