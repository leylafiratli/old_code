#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;


//constructor
User::User()
{
	_id = 0;
	_year = 0;
	_zip = 0;
	suggestion_score = 0;
	set_member = 0;
}

//overload constructor
User::User(int id, string name, int year, int zip)
{
	_id = id;
	_name = name;
	_year = year;
	_zip = zip;
}
//destructor
User::~User(){
}

void User::add_friend(int user1)
{
	//add user 1 to the back of the friends list
	_friends.push_back(user1);
}

void User::delete_friend(int id)
{
	for (unsigned int i =0; i < _friends.size(); i++)
	{//give an id number check through friends list to delete friend with id
		if ( _friends[i] == id)
		{
				_friends.erase(_friends.begin() + i);
		}
		else
		{
			cout << "Users Are Not Friends Already" << endl;
		}
	}
}
//store user info
int User::id_prompt()
{
	return _id;
}

string User::name_prompt()
{
	return _name;
}

int User::year_prompt()
{
	return _year;
}

int User::zip_prompt()
{
	return _zip;
}

vector<int> User::return_friends()
{
	return _friends; 
}

void User::changeID(unsigned int newID)
{
	_id = newID;
}

