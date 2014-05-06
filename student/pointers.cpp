#include <iostream>

using namespace std;

int main() {

int x = 30;
char y = 'a';
double z = 5.375;
int dat[] = {107,43};
int* ptr1 = dat;
int ptr2;

x += *ptr1;
cout <<"x: "<<x<<" ptr1: "<<ptr1<<" *ptr1: "<<*ptr1<<endl;

ptr1++;
cout<<"ptr1: "<<ptr1<<" *ptr1: "<<*ptr1<<endl;

ptr2 = 1;

x += *ptr1++;
cout<<"x: "<<x<<" ptr1: "<<ptr1<<" *ptr1: "<<*ptr1<<endl;

return 0;
}
