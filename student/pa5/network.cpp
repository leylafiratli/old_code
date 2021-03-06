#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "network.h"
#include "user.h"

using namespace std;

//constructor destructor
Network::Network(){
}

Network::~Network(){
}
//read friends from file(filename)
int Network::read_friends(char* filename)
{
	int numUsers;
	//check for issue opening the file
	ifstream ifile(filename);
	if (ifile.fail()) 
   	{
  		cout<< "Couldn't open file" << endl;
   		return -1;
   	}
	ifile >> numUsers;
	for(int i = 0; i < numUsers; i++)
	{//read in information from each user in the file
		int id;
		string name;
		int year;
		int zip;

		string friends;
		int nextFriend;
	
		ifile >> id;
		getline(ifile, name);
		getline(ifile, name);
		ifile >> year;
		ifile >> zip;

		_users.push_back(User(id, name, year, zip)); //add to the back of the list

		getline(ifile, friends);
		getline(ifile, friends);
		

		stringstream ss;
		ss << friends;
		while(true)
		{//add each friend to users til fail
			ss >> nextFriend;
			if(ss.fail())
			{
				break;
			}
			_users[i].add_friend(nextFriend);
		}
	}
	cout << endl;
	return 0; //end
}

int Network::write_friends(char* filename)
{
	ofstream ofile(filename);
	if (ofile.fail()) 
   	{//check for error with the file
  		cout<< "Couldn't open file" << endl;
   		return 0;
   	}
	//write number of users
	ofile << _users.size() << endl;

	for(unsigned int i = 0; i < _users.size(); i++)
	{//wite user information to the table for each user
		ofile << _users[i].id_prompt() << endl;
		ofile << _users[i].name_prompt() << endl;
		ofile << "\t" << _users[i].year_prompt() << endl;
		ofile << "\t" << _users[i].zip_prompt() << endl;
		ofile << "\t" << _users[i].return_friends() << endl;
		cout << endl;
	}
	return 0;
}

int Network::add_user(User user1)
{
	user1.changeID(_users.size());
	_users.push_back(user1);
	cout << endl;	
	return 0;
}

int Network::add_connection(int id, int id2)
{
	//add id 1 to friend list of id 2 and vice versa
	_users[id].add_friend(id2);
	_users[id2].add_friend(id);
	cout << endl;
	return 0;
}

int Network::remove_connection(int id, int id2)
{
	//same as add connection just delete
	_users[id].delete_friend(id2);
	_users[id2].delete_friend(id);
	cout << endl;	
	return 0;
}

int Network::get_id(string name)
{
	int id = -1;
	for(unsigned int i = 0; i < _users.size(); i++)
	{//for each user in the network find an id
		if(_users[i].name_prompt() == name)
		{//if names are equal
			id = i;
		}
	}
	return id;
}

void Network::print_network()
{
	//print table for user information
  	cout << endl <<  " ID" << "\t\tName (First, Last)" << setw(15) << "Year of Birth" << setw(15) <<  "Zip Code" << endl;
  	cout << " ";
  	for(int i = 0; i < 70; i++ )
	{
    	cout << "*";
  	}

  	cout << endl;

  	for( unsigned int i = 0; i < _users.size(); i++)
	{//fill table with user information
    	cout << _users[i].id_prompt() << ".";
    	cout << "\t" << _users[i].name_prompt();
    	cout << "\t\t"  << _users[i].year_prompt();
		cout << "\t\t" << _users[i].zip_prompt() << endl;
  	}
	cout << endl;
} 
void Network::list_friends(int id)
{
	//similar to print users but only friends
	cout << endl <<  " ID" << "\t\tName (First, Last)" << setw(20) << "Year of Birth" << setw(15) <<  "Zip Code" << endl;
  	cout << " ";
  	for(int i = 0; i < 70; i++ )
	{
    	cout << "*";
  	}

  	cout << endl;

	stringstream ss;

	ss << _users[id].return_friends();

	while(true)
	{
		//read in until fail
		int newfriend;
		ss >> newfriend;
		if(ss.fail()){
			break;
		}
		cout << newfriend << ".";
    	cout << "\t" << _users[newfriend].name_prompt();
    	cout << "\t\t\t"  << _users[newfriend].year_prompt();
		cout << "\t\t" << _users[newfriend].zip_prompt() << endl;
	}
	cout << endl;
}

void Network::search(int id, int id2)
{
	bool found = false;
	vector<User>_users; 
	... // assume users are read-in/initialized
	deque<int>_myq;
	for(int i=0; i < _users.size(); i++)
	{
		users[i].depth = -1; users[i].pred = -1; 
	}
	users[id].depth = 0;
	myq.push_back(users[id1].id);
	while (! myq.empty() || found = false)
	{
		int x = myq.front(); myq.pop_front();
		for(int j=0; j < users[x].friends.size(); j++)
		{
			if( users[users[x].friends[j]].depth == -1)
			{
				users[users[x].friends[j]].depth = users[x].depth + 1;
				users[users[x].friends[j]].pred = x;
				myq.push_back(users[x].friends[j]);
				if(id2 == users[x].friends[j]))
				{
					found = true;
					break;
				}
					
			} 
		}
 	}
	deque<int>path
	unsigned int check = 0; 
	while(myq[check].predecessor != -1)
	{
		check = myq[check].predecessor;
		path[check] = myq[check].predecessor.back();
		myq[check].predecessor.popback();
		cout << path[check].name_prompt() << " -> ";
	}
 		
return 0;
			
		
	
}















