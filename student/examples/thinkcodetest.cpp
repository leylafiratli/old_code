#include <iostream>
#include <cmath>

using namespace std;

int main () {

int num, rem;

string decimal_place = "TEST";

cout << " Enter a number between 0 and 999:  ";
cin >> num;

for (int i = 0; i < 3; i++)
{
	rem = num %10;
	num = num /10;

	if (i == 0)
		decimal_place = "Ones";
	else if(i == 1)
		decimal_place = "Tens";
	else if(i == 2)
		decimal_place = "Hundreds";

	cout<<decimal_place<<"Digit Is:  "<<rem<<endl;
}

return 0;

}
