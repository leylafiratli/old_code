#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <string>
#include <cstdlib>
#include "user.h"

using namespace std;

class Network {
	public:
		Network();
		~Network();
		int read_friends(char* filename);
		int write_friends(char* filename);
		int add_user(User user1);
		int add_connection(int id, int id2);
		int remove_connection(int id, int id2);
		int get_id(string name);
		void print_network();
		void list_friends( int id);
		void search(int id, int id2)
	private:
		char* filename;
		vector<User>_users;	
};


#endif


