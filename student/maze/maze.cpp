#include <iostream>
#include "maze_io.h"

using namespace std;

 	int head;
	int tail;
	int *bfs_queue;
	int *predecessor;

// Prototype for maze_search
int maze_search(char *, int, int);

int main(int argc, char *argv[])
{
  int rows, cols, result;
  char *mymaze;
 
  if(argc < 3){
    cerr << "Usage: ./maze in_filename out_filename" << endl;
    return 1;
  }
  mymaze = read_maze(argv[1], &rows, &cols);
  // For checkpoint 1, just leave maze_search() unedited
  //  and the program should read in the maze, print it
  //  and write it back to the output file
  result = maze_search(mymaze, rows, cols);
  if( result == 1 ){
    cout << "Path successfully found!" << endl;
    print_maze(mymaze,rows,cols);
    write_maze(argv[2],mymaze,rows,cols);
  }
  else if (result == 0) {
    cout << "No path could be found!" << endl;
  }
  else {
    cout << "Error occurred during search!" << endl;
  }
  delete [] mymaze;
  return 0;
}
/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if an error occurred (no start of finish
 *     cell present in the maze)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char *maze, int rows, int cols)
{
  	int head = 0;	//initialize head of array
  	int tail = 0;	//initialize tail of array
	int s = -1;		//initialize start position
  	int f = -1;		//initialize finish position

	for(int i = 0; i < rows*cols; i++)		//find start and finish positions in array
  	{
		if(maze[i] == 'S')
		{
			s = i;							//set start to 'S' position
		}
		if (maze[i] == 'F')
		{
			f = i;							//set finish to 'F' postition
		}	

  	}
  	if(f == -1 || s == -1) 					//either start or finish do not exist return error
  	{ 
		return -1; 							//return error
  	}

  	int* bfs_queue = new int[rows*cols]; 	//initialize breadth fresh search array
 	int* predecessor = new int[rows*cols];	//initialize predecessor array

  	for( int i = 0; i < rows*cols; i++)		//fill the array with -1s
  	{ 
		predecessor[i] = -1; 
  	}

  	predecessor[s] = -2;					//start = -2
  	bfs_queue[tail] = s;					//assign the starting position to tail of bfs
  	tail++;									//increment tail to move into while loop
  	
	while(head != tail)						//bfs for route to finish
  	{
  		int index = bfs_queue[head];		
 		head++;

    	int col = index % cols;				//current col position
		int row = index/cols;				//current row position
    	

    	int checkCol[] = {col, col, col-1, col+1};	//initialize positions: (row-1, col), 														//(row+1, col), (row, col+1), (row, col-1)
		int checkRow[] = {row-1, row+1, row, row};	//north east south west
    	
    
    	for(int i = 0; i < 4; i++)			//for north east south west
		{
			int newIndex = (checkRow[i] * cols) + checkCol[i]; //initialize new position

			if((maze[newIndex] == '.' || maze[newIndex] == 'F') && predecessor[newIndex] == -1 
			&& checkRow[i] > -1 && checkCol[i] > -1 && checkRow[i] < rows && checkCol[i] < cols)
			//check for -1s around the current position, if -1 open space save position			
			{ 
				bfs_queue[tail] = newIndex;
				tail++;
				predecessor[newIndex] = index;
			}
	 	}
  	}
 	
	if (predecessor[f] == -1)	//no finish position could be reached
	{
  		return 0;				//return no path found
  	}
	while(f != s)				//fill path positions with '*' backtrack through path
  	{ 
  		if (maze[f] == '.')
		{
  	    	maze[f] = '*';
  	  	}
    	f = predecessor[f];
    }
        
 	delete [] bfs_queue;		//deallocate
 	delete [] predecessor;
	  
	return 1; 					//return successful
		 
}
