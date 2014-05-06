#include <iostream>
#include <fstream>
#include "maze_io.h"

using namespace std;

/*************************************************
 * Open the file specified by filename, and read the 
 * maze into a dynamically allocated array.
 * 
 * Return the pointer to that array (don't delete it..
 * we'll do that in main() ).  Return NULL if
 * you are unable to open the file or can't read
 * the dimensions.
 *
 * We also pass in two pointers to integers. Fill 
 *  the integers pointed to by these arguments
 *  with the number of rows and columns 
 *  read by from the file (first two value
 *  in the file)
 *
 *************************************************/

char * read_maze(char *filename, int *rows, int *cols )
{
 
 ifstream ifile(filename);
   if ( ifile.fail()) 
   {
   cout<< "Couldn't open file" << endl;
   return NULL;
   }
   ifile>>*rows>> *cols;
    if (ifile.fail()) 
    {
    cout<< "No value for Rows/Columns in file"<< endl;
    return NULL;
    }
   char *maze = new char[(*rows)*(*cols)];

     for(int i=0; i< ((*rows)*(*cols)); i++)
     {
     ifile>>maze[i];
     }

 return maze;
}

/*************************************************
 * Print the maze contents in a 2D format to the
 * screen
 *
 *************************************************/
void print_maze(char *maze, int rows, int cols)
{
	for(int i = 0; i < cols*rows; i++)	//print maze of size rows*cols
	{
	 	if(( i + 1) % cols == 0)		
		{
			cout << maze[i] << endl;
		}
		else
		{
			cout << maze[i];
		}
	}
}
/*************************************************
 * Write maze should open the file specified by 
 * filename and write the contents of the maze
 * array to the file with the dimensions on the first
 * line.
 *
 *************************************************/
void write_maze(char *filename, char *maze, int rows, int cols)
{
	ofstream ifile(filename);

	for(int i = 0; i < cols*rows; i++)	//write maze of size rows*cols
	{	
		if ((i + 1) % cols == 0)
		{
			ifile << maze[i] << endl;
		}
		else
		{
			ifile << maze[i];
		}
	}
}
