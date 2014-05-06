#include <iostream>
#include <string>

using namespace std;

int getDiff(int X, int Y) { // Tail Implementation
  X++; // Inc X
  if (X == Y)
    return 1;

  return (1+getDiff(X, Y));
}


void getDiff2(int X, int Y, int Diff = 0) {
  X++;
  Diff++;

  if (X != Y)
    getDiff2(X, Y, Diff);
  else
    cout << "Diff Was: " << Diff << endl;

  return;
}

int main(void) {

  cout << "Difference Between 1 & 7 Is: " << getDiff(1, 7) << endl;
  getDiff2(8, 8);
  return 0;
}
