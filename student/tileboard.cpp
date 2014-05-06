#include <iostream>

using namespace std;

int main()
{

//Check if the puzzle is finished

bool isSolved(int tiles[]){
	for(int i=0; i<DIM*DIM; i++){
	if(i != tiles[i]{
	return false;
}
else{
	return true;
}
}
}

//Print the tiles and their assignments in a grid
//3 spaces per column

void printBoard(int tiles[]){
	for(int i=0; i<DIM; i++){
		if(i>0){
			for(int j = 0; j<DIM * 5 - 1; j++
