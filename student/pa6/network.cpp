#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
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
		string name, last;
		int year;
		int zip;

		string friends;
		int nextFriend;
	
		ifile >> id;
		ifile >> name;
		ifile >> last;
		name += ' ';
		name += last;
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
		
		vector <int> friends = _users[i].return_friends();

		for(unsigned int i = 0; i < friends.size(); i++)
		{
			ofile << friends[i] << " ";
		}
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

	cout << endl;

	for(unsigned int i = 0; i < _users.size(); i++)
	{//for each user in the network find an id
		if(_users[i].name_prompt().compare(name)==0)
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

	vector <int> friends = _users[id].return_friends();

	for(unsigned int i = 0; i < friends.size(); i++)
	{
		cout << friends[i] << ".";
    	cout << "\t" << _users[i].name_prompt();
    	cout << "\t\t\t"  << _users[i].year_prompt();
		cout << "\t\t" << _users[i].zip_prompt() << endl;
	}
	cout << endl;
}

void Network::bfs(int id)
{
	
	deque<int>myq;
	for(unsigned int i=0; i < _users.size(); i++)
	{
		_users[i].depth = -1; 
		_users[i].predecessor = -1; 
	}
	_users[id].depth = 0;
	myq.push_back(id);

	while((!myq.empty()))
	{
		int x = myq.front(); 	
		myq.pop_front();
		vector<int> nextFriend = _users[x].return_friends();

		for(unsigned int i = 0; i < nextFriend.size(); i++){
			int currID = nextFriend[i];
			if(_users[currID].depth == -1)
			{
				_users[currID].depth = _users[x].depth + 1;
				_users[currID].predecessor = x;
				_users[currID].set_member = current_set;
				myq.push_back(currID);
			}
		}		
 	}
}

int Network::Distance(string full1, string full2)
{


	int id1 = get_id(full1);
	int id2 = get_id(full2);

	bfs(id1);

	if(_users[id2].depth == -1)
		return 0; // return false because user was not found

	cout << "Distance: " << _users[id2].depth << endl;
	
	deque <int> tempOrder;
	tempOrder.push_front(id2);

	int tempUserID = id2; // holds the current user to find the pred of

	while(_users[tempUserID].depth != 0){
		tempUserID = _users[tempUserID].predecessor;
		tempOrder.push_front(tempUserID);
	}

	for(unsigned int i = 0; i < tempOrder.size(); i++){
		cout << _users[tempOrder[i]].name_prompt();
		if(i != tempOrder.size()-1)
			cout << "->";
	}
		
	return 1;
}

int Network::Disjoint(int)
{
	current_set = 1;
	for(unsigned int i = 0; i < _users.size(); i++)
	{
		_users[i].depth = -1;
		_users[i].set_member = 0;
	}

	for(unsigned int i = 0; i < _users.size(); i++)
	{
		if(_users[i].set_member == 0)
		{
			bfs(i);
			current_set++;
		}
	}
	for(int j = 1; j < current_set; j++)
	{
		cout << endl << "Disjoint Set " << j << ":" <<endl;
		for(unsigned int k = 0; k < _users.size(); k++)
		{
			if(_users[k].set_member == j)
			{
				cout << _users[k].name_prompt() << endl;
			}
		}
	}
	return current_set;
}
int Network::Suggestions(int id)
{

	bfs(id);

	vector<int>Friends = _users[id].return_friends();
	for ( unsigned int i = 0; i < _users.size(); i++)
	{
		_users[i].suggestion_score = 0;
	}

	for(unsigned int i = 0; i < _users.size(); i++)
	{
		if(_users[i].depth == 2)
		{
			vector <int> temp = _users[i].return_friends();
			for(unsigned int j = 0; j < Friends.size(); j++)
			{
				for(unsigned int k = 0; k < temp.size(); k++)
				{
					if(Friends[j] == temp[k])
					{
						_users[i].suggestion_score++;
					}
				}
			}
		}
	}

	int maxValue = -1;

	for(unsigned int i = 0; i < _users.size(); i++)
	{
		if(_users[i].suggestion_score > maxValue)
		{
			maxValue = _users[i].suggestion_score;
		}
	}

	cout << "Suggested Friends: " << endl;
	for(unsigned int i = 0; i < _users.size(); i++)
	{
		if(_users[i].suggestion_score == maxValue)
		{
			cout << _users[i].name_prompt() << "\t" << _users[i].suggestion_score << endl;
		}
	}

	
	return 1;
}
