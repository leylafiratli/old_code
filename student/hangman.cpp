#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//prototype
int processGuess(char* word, const char* targetWord, char guess, int length);


const char *wordBank[] = {"computer","president","trojan","program","coffee",
			  "library","football","popcorn","science","engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char word[80];  
  char targetWord[80];
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;
  int num;
  int j;
  int length;

  //choose a word from the word bank
  num=rand()%10;

  strncpy(targetWord, wordBank[num], 80);
  length=strlen(targetWord);

  //initialize game
  for(j=0; j<length; j++)
  {
    word[j] = '*'; 
  }

  word[j]=0;

  cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
  cout << "$$$$$$$$$$$$$$$ Hangman $$$$$$$$$$$$$$$$$" << endl;
  cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
  
  
  //input a letter
  while(!wordGuessed && numTurns != 0) 
  {
   
    cout << endl << "Your word: " <<word << endl;
    cout << "You have " << numTurns << " guesses left." << endl;
    cout  << "Enter a letter to guess: ";
    cin >> guess;
   
  //process the letter 
    int found = processGuess(word, targetWord, guess, length);
  
  //if processed letter returns 0 matches decrement turns
    if(found == 0)
    {
      numTurns--;
    } 

  //if processed letter returns a match, replace star with letter  
    if(strcmp(word, targetWord)==0)
    {
      wordGuessed=true;
    }

  }
  
  //end the game
  if (wordGuessed)
  {
    cout << endl << "Your word: " << word << endl << endl;
    cout << "Congratulations, you win!" << endl;
  }

  else if (numTurns==0)
  {
    cout << endl << "Sorry, you lose." << endl;
    cout << "The word was: " << targetWord << endl;
  }

  cout << "Thank you for playing." << endl;

  return 0;
}

//process the guessed letter for a match(counter is how many matches)
int processGuess(char* word, const char* targetWord, char guess, int length) {

  int counter = 0;
  for (int i=0; i<length; i++)
  {
    if(targetWord[i]==guess)
    {
      word[i]=guess;
      counter++;
    }
  }
  return counter;
}
