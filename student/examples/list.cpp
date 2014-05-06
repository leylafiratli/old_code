//Linked List
struct intItem
{
	int value;
	intItem* next;
};

class listInt
{
	private:
		intIntem* head;
}

listInt::listInt()
{
	head = NULL;
}

void listInt::pushFront(int newValue)
{
	intItem* newItem = new intItem;		//creates box and pointer to that box |value|next|
	newItem->value = newValue;
	newItem->next = head;
	head = newItem;
}

int listInt::popFront()
{
	if(head == NULL)					//nothing in the list, cant do anything
	{
		return -1;						//tells user you can never store -1 in my list of ints
	}
	intItem* deleteItem = head;			//points to last box so we can deallocate it
	*head = head->next					//moves through the linked list
										//changes head to the address of the next box
	int saveValue = deleteItem->value	//saves the previous value to an int
	delete deleteItem;					//deallocates the previous box
										//no square brackets in delete because it's not an array
	return saveValue;
}

void listInt::printList()
{
	intItem* current = head				//begin reading list at head
	while(current != NULL)				//output value of current
	{
		cout << current->value << endl;
		current = current->next;		//iterate current position until the list is outputted
	}
}

bool listInt::find(int findValue)
{
	intItem* current = head				//begin reading list at head
	while(current != NULL)				//output value of current
	{
		if(current->value == findValue)	//if current value = wanted value
		{
			return true;				//found value
		}
	current = current->next;			//iterate current position until the list is outputted
	}
	return false;						//value not found
}

void listInt::append(int newItem)
{
	intItem* current = head;			//begin reading list at head
	intItem* trailer = NULL;			//will always lag one position behind current
	while(current != NULL && current->next != NULL)	
	//find last item so we can append onto that last item
	//goes into while loop when the current value is not null and the value in the next box isn't 		NULL either
	{
		trailer = current;
		current = current->next;		//moves to next box
	}									//exits while loop when the next box is NULL
	intItem* newItem = new intItem;
	newItem->value = newValue;
	newItem->next = NULL;
	if(head == NULL)
	{
		head = newItem;
	}
	else
	{
		current->next = newItem;
	}

bool listInt::insert(int index, int newValue)
{
	intItem* current = head;			//points to first item
	for(int i = 1; i < index; i++)		//iterate to point of insertion
										//i=1 shortens for loop by one, ends at correct point
	{
		if(current == NULL)				//nothing to do
		{
			return false;				//return false
		}
		current = current->next;
	}
	intItem* newItem = new intItem;
	newItem->value = newValue;
	newItem->next = current->next;
	current->next = newItem;
	return true;
}

