#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

int n = 3;
int ulr;
int ulc;
int h;
int w;
int cr;
int cc;
int a;
int b;
int x;
int y;

unsigned char image[SIZE][SIZE];

// Prototypes
void draw_rectangle(int ulr, int ulc, int h, int w);
void draw_ellipse(int cr, int cc, int a, int b);


int main()
{

  // initialize the image to all white pixels
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      image[i][j] = 255;
    }
  }

  // Main program loop here
  while(true)
  {
	cout << "Please enter 0 if you would like a rectangle and 1 if you would like an ellipse. To exit, press 2" << endl;

	cin >> n;
	
	if(n==0)
	{

	     cout << "Upper left row: " <<endl;
	     cin >> ulr;
	     cout << "Upper left column: " <<endl;
	     cin >> ulc;
	     cout << "Height: " <<endl;
	     cin >> h;
	     cout << "Width: " <<endl;
	     cin >> w;



	     draw_rectangle(ulr, ulc, h, w);


	  
	}

	if(n==1)
	{

	     cout << "Upper left row: " <<endl;
	     cin >> cr;
	     cout << "Upper left column: " <<endl;
	     cin >> cc;
	     cout << "Major length: " <<endl;
	     cin >> a;
	     cout << "Minor length: " <<endl;
	     cin >> b;



	     draw_ellipse(cr, cc, a, b);


	}

	if(n==2)
	{
	
		// Write the resulting image to the .bmp file
 		 writeGSBMP("output.bmp", image);
	
		cout << "Your output has been stored!" << endl;
	        cout << "To view it, enter 'firefox output.bmp &'" << endl;
		break;
	}

	
  }
 


  

  return 0;
}

void draw_rectangle(int ulr, int ulc, int h, int w)
{
	for (int x=ulr, y=ulc; y<ulc+w; y++) //top
	{
		image[x][y]=0;
	}
	
	for (int x=ulc, y=ulr+w; x<ulc+h; x++) //left
	{
		image[x][y]=0;
	}

	for (int x=ulr+h, y=ulc; y<ulc+w; y++) //bottom
	{
		image[x][y]=0;
	}

	for (int x=ulr, y=ulr; x<ulc+h; x++) //right
	{ 
		image[x][y]=0;
	}
}

void draw_ellipse(int cr, int cc, int a, int b)
{

  	for(double theta=0.0; theta < 2*M_PI; theta += .01)
	{
   		 int x = (a/2)*cos(theta);
  		 int y = (b/2)*sin(theta);
   		 x += cr;
   		 y += cc;
    		image[y][x] = 0;
  	}

}
