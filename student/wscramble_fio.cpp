// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Prototype
void permute(char items[], int len);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
//const char *wordBank[] = {"computer","president","trojan","program","coffee",
//			  "library","football","popcorn","science","engineer"};

//const int numWords = 10;

int main(int argc, char* argv[])
{
  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;
  int numWords;
  
  if( argc != 2)
  {
    return 1;
  }
  //open worbank.txt
  //read wordbank
  //terminate program if there is a problem
  ifstream ifile(argv[1]);
    if( ifile.fail() )
    { // can't open?
    return 1; 
    }
    
    ifile >> numWords;
    char** wordBank = new char*[numWords];
    for(int i = 0; i < numWords; i++)
    {
      char temp_buf[100];
      ifile >> temp_buf;
      int length = strlen(temp_buf);
      wordBank[i] = new char[length+1];
      strcpy(wordBank[i], temp_buf);
    }

  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // More initialization code
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while ( !wordGuessed && numTurns > 0 ){
    cout << "\nCurrent word:  " << word << endl;
    cin >> guess;
    wordGuessed = (strncmp(guess, wordBank[target], targetLen+1) == 0);
    numTurns--;
  }
  if(wordGuessed){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  delete [] word;
  for(int i = 0; i < numWords; i++)
  {
    delete [] wordBank[i];
    wordBank[i] = NULL;
  }
  delete [] wordBank;
  wordBank = NULL;
  return 0;
}

// Scramble the letters
void permute(char items[], int len)
{
  for(int i=len-1; i > 0; --i){
    int r =  rand() % i;
    int temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }

}

