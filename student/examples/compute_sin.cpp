#include <iostream>
#include <cmath>

using namespace std;

// Declaration (function prototype for fact)
int fact(int);
	
int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
	double n;
	double ans;
	double temp;

  // Prompt the user
	cout << "Enter a number, x, in radians:  ";
  // get input
	cin >> n;
  // Do some operations
	for (int i=1; i<8; i+=2){
		temp = (pow(n,i)/fact(i));
		if(i==3 || i==7)
			temp *= -1;
		ans += temp;
}
  // Print the result to the user
	cout << " The Approximation of Sin(x) is " << ans << endl; 
  // You're done
  return 0;
}

int fact(int n)
{
	int i;
	int result=1;
	for(i=1; i<=n; i++){
		result = result * i;
	}
	return result;
}
