#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char bwimage[SIZE][SIZE];
unsigned char rgbimage[SIZE][SIZE][RGB];

// Prototypes
void draw_bw_gradient();
void draw_rgb_gradient(unsigned char sr,
		       unsigned char sg,
		       unsigned char sb,
		       unsigned char er,
		       unsigned char eg,
		       unsigned char eb);


int main()
{
  //Initialize bwimage array here

  for(int i = 0; i < SIZE; i++)
  { //Number of rows to output
    for(int j = 0; j <= i; j++)
    { //umber of values to output on a row
      bwimage[i][j] = 0;
    }
  }
  writeGSBMP( "bwgradient.bmp", bwimage);

  return 0;
}


void draw_bw_gradient()
{


}

void draw_rgb_gradient(unsigned char sr,
		       unsigned char sg,
		       unsigned char sb,
		       unsigned char er,
		       unsigned char eg,
		       unsigned char eb)
{

  
}
