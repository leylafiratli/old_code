#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
  double temp;
  double celsius;

  
  // Prompt the user
  cout << "Enter a number:  ";

  // get input  
  cin >> temp;
  // Do some operations
  celsius=(temp-32.0 ) * (5.0/9.0); 
  // Print the result to the user
  cout << "The Temperature In Degrees Celsius Is " << celsius << " Degrees";

  // You're done
  return 0;
  
}

