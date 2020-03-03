
#include<iostream>
#include<iomanip>
#include<cstddef>
#include "LinkedListR.h"
using namespace std;

// Prototype functions

void menu();

int main() {

	char command;
	int entry, target, kth;
	bool test = false;
	LinkedListR l1;

	menu();		// Displays menu for first time

	loop: cout << "Enter Command --> ";	// loop anchor to reask for commands
	cin >> command;
	command = tolower(command);

	switch (command)
	{
	case 'e':		// Re-Initialize list
		l1.~LinkedListR();
		break;

	case 'i':		// Insert entry to list
		cout << "Enter entry --> ";
		cin >> entry;
		l1.insert(entry);
		break;

	case 'r':		// Remove target from list
		cout << "Enter target --> ";
		cin >> target;
		l1.remove(target);
		break;

	case 'm':		// Is list empty?
		l1.isEmpty();
		break;

	case 'l':		// Length of list
		cout << "The length of the list is "
			<< l1.getLength() << '.' << endl;
		break;

	case 'p':		// Is value in list?
		cout << "Enter target --> ";
		cin >> target;
		cout << endl;
		if (l1.isInList(target))
			cout << "Value v is in the list." << endl;
		else
			cout << "Value v is NOT in the list." << endl;
		break;

	case 'k':		// K1th value in list
		cout << "Enter kth value --> ";
		cin >> kth;
		l1.findKthItem(kth);
		break;

	case 'w':		// Write out list
		cout << "List: ";
		l1.print();
		break;

	case 'h':		// See menu
		menu();
		break;

	case 'q':		// quit
		return 0;
	}	
	
	goto loop;

	return 0;
}

// Member Functions

void menu()
{
	cout << "This program responds to commands the user enters to" << endl
		<< "manipulate an ordered list of intergers, which is" << endl
		<< "initially empty. In the following commands, k is a " << endl
		<< "position in the list, and v is an integer." << endl << endl;

	cout << "e -- Re-initialize the list to be empty." << endl
		<< "i v -- Insert the value v into the list." << endl
		<< "r v -- Remove the value v from the list." << endl
		<< "m -- Is the list empty?" << endl
		<< "l -- report the length of the list." << endl
		<< "p v -- Is the value v present in the list?" << endl
		<< "k k1 -- What is the value of Node K." << endl
		<< "w -- Write out the list." << endl
		<< "h -- See this menu." << endl
		<< "q -- Quit." << endl << endl;
}