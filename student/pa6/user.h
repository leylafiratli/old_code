#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include <cstdlib>
#include <deque>

using namespace std;

class User {
	public:
		User();
		User(int id, string name, int zip, int year);
		~User();
		void add_friend(int);
		void delete_friend(int);
		int id_prompt();
		string name_prompt();
		int year_prompt();
		int zip_prompt();
		vector<int> return_friends();
		void changeID(unsigned int newID);
		int depth;
		int predecessor;
		int suggestion_score;
		int set_member;
	private:
		int _id;
		string _name;
		int _year;
		int _zip;
		vector<int>_friends;
};


#endif
