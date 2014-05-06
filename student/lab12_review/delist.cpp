#include <iostream>
#include "delist.h"
#include <cstddef>

using namespace std;

/// Constructs an empty Double-Ended List
DEList::DEList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

/// Destructor to clean-up memory of current list
DEList::~DEList()
{
	delete head;
	delete tail;
}

/// returns a Boolean 'true' if the list is empty
bool DEList::empty()
{
	if(count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// returns number of items in the list
int DEList::size()
{
	return count;
}

/// returns front item or -1 if empty list
int DEList::front()
{
	if(count == 0)
	{
		return -1;
	}
	else
	{
		return (head->val);
	}
}

/// returns back item or -1 if empty list
int DEList::back()
{
	if(count == 0)
	{
		return -1;
	}
	else
	{
		return (tail->val);
	}
}

/// Adds a new integer to the front of the list
void DEList::push_front(int new_val)
{
	if(count == 0)
	{
		DEItem *newNode;
		newNode = new DEItem;
		newNode -> val = new_val;
		newNode -> next = NULL;
		head = newNode;
		tail = newNode;
		newNode -> prev = NULL;
		count++;
	}
	else
	{
		DEItem *newNode;
		newNode = new DEItem;
		newNode -> val = new_val;
		newNode -> next = head;
		head = newNode;
		newNode -> prev = NULL;
		count++;
	}
		
}

/// Adds a new integer to the back of the list
void DEList::push_back(int new_val)
{

	
	if(count == 0)
	{
		DEItem *newNode = new DEItem;
		newNode -> val = new_val;
		newNode -> next = NULL;
		head = newNode;
		tail = newNode;
		newNode -> prev = NULL;
		count++;
	}
	else
	{
		DEItem *newNode = new DEItem;
		newNode -> val = new_val;
		newNode -> next = NULL;
		newNode -> prev = tail;
		newNode = tail;
		count++;
	}	
}

/// Removes the front item of the list (if it exists)
void DEList::pop_front()
{
	if(count == 0)
	{
		return;
	}
	/*else if(count == 1)
	{
		tail -> val = val;	//stores val? uneeded?
		//delete head;
		head = tail = NULL;
		count--;
	}*/
	else
	{
		DEItem* temp = head;
		head = temp -> next;
		delete temp;		
		//temp -> prev = NULL;
		//temp -> val = val;	//same as above
		//delete head;
		//head = temp;
		count--;
	}
}

/// Removes the back item of the list (if it exists)
void DEList::pop_back()
{
	if(count == 0)
	{
		return;
	}
	/*else if(count == 1)
	{
		tail -> val = val;
		//delete tail;
		tail = head = NULL;
		count--;
	}*/
	else
	{
		DEItem* temp = tail;
		tail = temp -> prev;
		//temp -> next = NULL;
		delete temp;
		//temp -> val = val;
		//delete tail;
		//tail = temp;
		count--;
	}
}




