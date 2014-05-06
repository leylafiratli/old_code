#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
int theta;
int x;
int y;
int z;

cout << "Enter an angle:  " << endl;
cin >> theta;

for(int y = 0; y<30; y++){
	z=floor(y*tan((theta * 3.1459)/180));
if(z>=20 && z<=30){
	z=20;
}
for(int x = 0; x<z; x++){

cout << "*";
}
cout << endl;
}
return 0;
}
