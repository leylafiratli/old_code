#include <iostream>

using namespace std;

void decrement_it(int);

int main()
{
	int a, y = 3;
	decrement_it(y);
	cout <<"y =  "<< y << endl;
	return 0;
}

void decrement_it(int y)
{
	y--;
}
