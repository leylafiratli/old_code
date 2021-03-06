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
		void bfs(int id1);
		int Distance(string full1, string full2);
		int Disjoint(int);
		int current_set;
		int Suggestions(int);
	private:
		char* filename;
		vector<User>_users;	
};


#endif


