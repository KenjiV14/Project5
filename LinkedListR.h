#ifndef LINKED_LIST_R
#define LINKED_LIST_R
using namespace std;

typedef int Item;

class LinkedListR
{
private:

	// Declarations

	struct Node
	{
		Item data;
		Node* next;
	};

	Node* getNode(Item entry, Node* link)
	{
		Node* temp;

		temp = new Node;
		temp->data = entry;
		temp->next = link;
		return temp;
	}

	Node* first;

public:

	// Delarations

	// Prototype Member Functions

	// Default Constructor
	LinkedListR() { first = NULL; }

	~LinkedListR();

	void printR(Node* p);
	void print() { printR(first); }

	void insertR(Node* &p, Item entry);
	void insert(Item entry) { insertR(first, entry); }

	void removeR(Node* &p, Item target);
	void remove(Item target) { removeR(first, target); }

	void isEmpty();

	int getLengthR(Node* p);
	int getLength() {return getLengthR(first); }

	bool isInListR(Node* p, Item target);
	bool isInList(Item target) {return isInListR(first, target); }

	void findKthItemR(Node* p, Item k);
	void findKthItem(Item k) { findKthItemR(first, k); }

};	// End of Class

// Member Functions

LinkedListR::~LinkedListR()
{
	Node* temp;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
}

void LinkedListR::printR(Node* p)
{

	if (p == NULL)
		cout << "List is Empty" << endl;
	else
	{
		cout << p->data << " ";
		printR(p->next);
	}
}

void LinkedListR::insertR(Node* &p, Item entry)
{

	if (p == NULL || entry < p->data)
		p = getNode(entry, p);
	else
		insertR(p->next, entry);

}   

void LinkedListR::removeR(Node* &p, Item target)
{

	Node* temp;
	if (p->data == target)
	{
		temp = p;
		p = p->next;
	}
	else
		removeR(p->next, target);

}

void LinkedListR::isEmpty()
{
	if (first == NULL)
		cout << "List is Empty." << endl;
	else
		cout << "List is NOT Empty." << endl;
}

int LinkedListR::getLengthR(Node* p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + getLengthR(p->next);
}

void LinkedListR::findKthItemR(Node* p, Item k)
{
	if (k > getLength())
		cout << "The Kth Node does Not Exist." << endl;
	else
	{	
	if (k == 1)
		cout << "The Kth Node Item is " << p->data << "." << endl;
	else
		findKthItemR(p->next, k - 1);
	}
}

bool LinkedListR::isInListR(Node* p, Item target)
{

	if (p == NULL)
		return false;

	if (p->data == target)
		return true;
	else
		isInListR(p->next, target);

}

#endif