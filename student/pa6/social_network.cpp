#include "network.h"
#include "user.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{ 
	//establish network
	//check for error in command line arguements
	Network myNetwork;
	if( argc != 2)
  	{
    	return 1;
  	}
	
	int x = myNetwork.read_friends(argv[1]);
	if (x == -1)
	{
		cout << "Error" << endl;
	}

	int n;
	//loop while commands are correct or until exited
	while(true)
	{
		cout << "==============================================================================" << endl;
		cout << "Enter a 1 if you would like to add a user" << endl;
 		cout << "Enter a 2 if you would like to add a friend connection" << endl;
		cout << "Enter a 3 if you would like to remove friend connection" << endl;
		cout << "Enter a 4 if you would like to list users" << endl;
		cout << "Enter a 5 if you would like to list friends" << endl;
		cout << "Enter a 6 if you would like a write to file" << endl;
		cout << "Enter a 7 if you would like to know the distance between two users" << endl;
		cout << "Enter an 8 if you would like the number of disjoint groups" << endl;
		cout << "Enter a 9 if you would like to see a list of suggested friends for a user" <<endl;
		cout << "And anything else if you would like to exit" << endl;
		cout << "==============================================================================" << endl;
		cin >> n;
	
		if(n==1)
		{
			cout << "Please Enter a Name (First, Last)" << endl;
			string firstname;
			string lastname;
			string name;
			int year;
			int zip;
	    	cin >> firstname >> lastname >> year >> zip;
			name += '\t';
			name += firstname;
			name += ' ';
			name += lastname;
			User newuser(0, name, year, zip);
	    	myNetwork.add_user(newuser);
		}

		else if(n==2)
		{
			cout << "Please Enter a Name (First, Last)" << endl;
	    	string a,b,c,d,e,f;
			//first name, last name, first2, last2
			cin >> a >> b >> c >> d;
		
			a += ' ';
			a += b;
			e += '\t';
			e += a;
			c += ' ';
			c += d;
			f += '\t';
			f += c;
			
	    	myNetwork.add_connection(myNetwork.get_id(e),myNetwork.get_id(f));
		}

		else if(n==3)
		{
			cout << "Please Enter Two Names (First, Last)" << endl;
	   		string a,b,c,d,e,f;
		
			cin >> a >> b >> c >> d;
			//first1, last1, first2, last2

			a += ' ';
			a += b;
			e += '\t';
			e += a;
			c += ' ';
			c += d;
			f += '\t';
			f += c;
	    	myNetwork.remove_connection(myNetwork.get_id(e),myNetwork.get_id(f));
		}

		else if(n==4)
		{
			myNetwork.print_network();
		}

		else if(n==5)
		{
			cout << "Please Enter a Name (First, Last)" << endl;
	    	string a, b, c;

			cin >> a >> b;
			//first, last

			a += ' ';
			a += b;
			c += '\t';
			c += a;
			cout << myNetwork.get_id(c) << endl;
			myNetwork.list_friends(myNetwork.get_id(c));
		}

		else if(n==6)
		{
			cout << "Please Enter the Name of the File to Write" << endl;
			char filename[100];
			cin >> filename;
			myNetwork.write_friends(filename);
		}	

		else if(n == 7)
		{
			cout << "Please Enter Two Names (First, Last)" << endl;
	   		string first1, last1, first2, last2, full1, full2;
		
			cin >> first1 >> last1 >> first2 >> last2;
			
			full1 = first1;
			full1 += ' ';
			full1 += last1;

			full2 = first2;
			full2 += ' ';
			full2 += last2;
			myNetwork.Distance(full1, full2);			
	    	myNetwork.bfs(myNetwork.get_id(full1));

		}

		else if(n == 8)
		{
			myNetwork.Disjoint(0);
		}

		else if(n == 9)
		{
			cout << "Please Enter a Name (First, Last)" << endl;
	   		string first1, last1, full1;
		
			cin >> first1 >> last1;
			
			full1 = first1;
			full1 += ' ';
			full1 += last1;

			myNetwork.Suggestions(myNetwork.get_id(full1));
		}

		else
		{
			//exit
	    	cout << "Goodbye..." <<endl;
			return 0;
		}

	}
}
