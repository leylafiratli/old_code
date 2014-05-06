#include <iostream>
#include <cmath>
using namespace std;

int main()

{   
int n;
int twos = 0;
int threes = 0;

cout << "Please Enter A Number" << endl;
cin >> n;

if(n % 3 == 0){
	while (n % 3 == 0){
		threes++;
		n /= 3;
	}
}

if(n % 2 == 0){
	while(n % 2 == 0){
		twos++;
		n /= 2;
	}
}
if(n !=1){
	cout << "Nope" << endl;
return 0;
}
if (threes ==0 && twos == 0){
	cout << "Nope" << endl;
}
else {
	cout << "Yup" << endl << "Twos:  " << twos << endl << "Threes:  "<< threes << endl;
}

return 0;
}
