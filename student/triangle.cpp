#include <iostream>

using namespace std;

int main()
{

int numberLines;

cout << "How Many Lines Would You Like In Your Triangle?" << endl;
cin >> numberLines;

for(int y=1; y<=numberLines; y++){
for(int x=0; x<y; x++){
	cout << "*";
	}
	cout << endl;
}

return 0;
}
	
