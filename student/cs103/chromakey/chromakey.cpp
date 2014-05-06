//--------------------------------------------------------
// File:     chromakey.cpp
//
// Author:   Your name here
//
//
// Usage:    chromakey colbert_gs.bmp campus1.bmp 80 meth1.bmp meth2.bmp
//
// Notes:
// This program performs the chroma key operation  on an input 
// using two different methods.
//
// Method 1 Utilize a user-defined distance threshold from the
//          chromakey value as a discriminator
//
// Method 2 Devise a method that to determine the chromakey mask
//          that doesn't require a user-input threshold
//
//--------------------------------------------------------

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Image data array
unsigned char inputImage[SIZE][SIZE][RGB];
unsigned char bgrndImage[SIZE][SIZE][RGB];
unsigned char outputImage[SIZE][SIZE][RGB];
bool chromaMask[SIZE][SIZE];

// Prototypes
void method1(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE],
	     int threshold);

void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE]);

void replace(bool mask[][SIZE],
	     unsigned char inImage[][SIZE][RGB],
	     unsigned char bgImage[][SIZE][RGB],
	     unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{
  double distance;
  double threshold;

  if(argc < 6){
    cout << "usage: program_name input.bmp background.bmp dist_threshold output1.bmp output2.bmp" << endl;
    return 0;
  }
	
  if(readRGBBMP(argv[1], inputImage) ){
    cout << "Error reading file: " << argv[1] << endl;
    exit(1);
  }

  if(readRGBBMP(argv[2], bgrndImage) ){
    cout << "Error reading file: " << argv[2] << endl;
    exit(1);
  }
  
  // Write code to convert the threshold (argv[3])
  //  from string format to a double and assign the 'threshold'


  // Call Method 1 Function


  // Produce the output by calling replace()


  // Write the output image to a file using the filename argv[4]
  if (writeRGBBMP(argv[4], outputImage) ){
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }	

  // Call Method 2 Function


  // Produce the output by calling replace()


  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5], outputImage) ){
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }	

  return 0;
}



// Use user-provided threshold for chroma-key distance
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'green'
void method1(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE],
	     int threshold)
{



}

// Devise a method to automatically come up with a threshold
//  for the chroma key determination
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'green'
void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE])  
{


}

// If mask[i][j] = 1 use the input image pixel for the output image
// Else if mask[i][j] = 0 use the background image pixel
void replace(bool mask[SIZE][SIZE],
	     unsigned char inImage[SIZE][SIZE][RGB],
	     unsigned char bgImage[SIZE][SIZE][RGB],
	     unsigned char outImage[SIZE][SIZE][RGB])
{
  // Create the output image using the mask to determine
  //  whether to use the pixel from the Input or Background image



}
