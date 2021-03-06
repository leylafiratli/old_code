#include <iostream>
#include "delist.h"
#include <cstddef>

using namespace std;

//constructor destructor
DEList::DEList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

DEList::~DEList()
{
	DEItem *temp;
	while(head != NULL)
	{
		temp = head -> next;
		delete head;
		head = temp;
	}
	while(tail != NULL)
	{
		temp = tail -> next;
		delete tail;
		tail = tamp;
}

/// returns a Boolean 'true' if the list is empty
bool DEList::empty()
{
	if(size() == 0)
	{
		cout << "List Is Empty" << endl;
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
	if(empty() == true)
	{
		return -1;
	}
	else
	{
		return head -> val;
	}
}

/// returns back item or -1 if empty list
int DEList::back()
{
	if(empty() == true)
	{
		return -1;
	}
	else
	{
		return tail -> val;
	}
}

/// Adds a new integer to the front of the list
void DEList::push_front(int new_val)
{
	DEItem* newNode;
	newNode = new DEItem;
	newNode -> val = new_val;

	if(head == tail && size() == 0)
	{
		newNode -> prev = tail;
		head = newNode;
		tail = newNode;
		count++;
	}
	else
	{
		newNode -> next = head;
		tail -> next = newNode;
		head = newNode;
		count++;
	}
}

/// Adds a new integer to the back of the list
void DEList::push_back(int new_val)
{
	DEItem* newNode;
	newNode = new DEItem;
	newNode -> val = new_val;

	if(empty() == true)
	{
		newNode -> prev = tail;
		head = newNode;
		tail = newNode;
		count++;
	}
	else
	{
		newNode -> prev = tail;
		head = newNode;
		tail = newNode;
		count++;
	}
}

/// Removes the front item of the list (if it exists)
void DEList::pop_front()
{
	if(head == NULL)
	{
		return;
	}
	DEItem *temp;
	temp = head;
	head = head -> next;
	delete temp;
	count--;
}

/// Removes the back item of the list (if it exists)
void DEList::pop_back()
{
	if(tail == NULL)
	{
		return;
	}
	DEItem *temp;
	temp = tail;
	tail = tail -> prev;
	delete temp;
	count--;	
}

