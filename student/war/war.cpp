#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "warplayer.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cout << "Provide number of games to simulate and 1=debug, 0=no debug " << endl;
    return 1;
  }
  srand(time(0));
  int numSims = atoi(argv[1]);
  bool debug = atoi(argv[2]);
  int numBattles = 0;
  int numWars = 0;
  int p1Wins = 0;
  int p2Wins = 0;
  for(int i=0; i < numSims; i++){

    // Write your single game of War code here (or decompose 
    // the single game into smaller functions that you write)
    // We've started things for you
	
    // Declare and prepare your deck then print it out to double check
    Deck d;
    d.shuffle();
    d.cut();
    if(debug){
      d.printDeck();
    }

    // Declare the two players and deal the cards to the two players
	WarPlayer p1;
	WarPlayer p2;
	for(int i = 0; i < 26; i++)
	{
		p1.addCard(d.getTop());
		p2.addCard(d.getTop());
	}
	
    // Write a loop that plays one turn at a time, until the game is over
    // Remember each player takes their top card, compares them, and the
    //  player with the greater-valued card gets back both
    // If there is a tie, each player flips one more card (provided they have
    //  one more), with the player with the greater-valued 2nd card getting
    //  all the cards.  If they don't have one more to flip, that player 
    //  immediately loses
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	while(p1.checkcards() == false && p2.checkcards() == false)
	{
		numBattles++;
		card1 = p1.removeTopCard();
		card2 = p2.removeTopCard();
		if(card1.compare(card2) == 1)
		{
			p1.addCard(card1);
			p1.addCard(card2);
		}
		else if(card1.compare(card2) == -1)
		{
			p2.addCard(card2);
			p2.addCard(card1);
		}
		else
		{
			numWars++;
			if(p1.checkcards() == false && p2.checkcards() == false)
			{
				card3 = p1.removeTopCard();
				card4 = p2.removeTopCard();
			if(card3.compare(card4) == 1)
			{
				p1.addCard(card1);
				p1.addCard(card3);
				p1.addCard(card2);
				p1.addCard(card4);
			}
			else if(card3.compare(card4) == -1)
			{
				p2.addCard(card2);
				p2.addCard(card4);
				p2.addCard(card1);
				p2.addCard(card3);	
			}
			else
			{
				p1.addCard(card1);
				p1.addCard(card3);
				p2.addCard(card2);
				p2.addCard(card4);
			}
			}
		}							
    // Be sure to update the statistics variables, numBattles, numWars,
    //  p1Wins, p2Wins, etc.
	}
	if(p2.sizereturn()==0)
	{
		p1Wins++;
		if(debug)
		{
			cout << "p1 is winner" << endl;
		}	
	}
	else if(p1.sizereturn() == 0)
	{
		p2Wins++;
		if(debug)
		{
			cout << "p2 wins" << endl;
		}
	}



  } // end for
  // Print statistics
  cout << "Total Battles = " << static_cast<double>(numBattles)/numSims << endl;
  cout << "Total Wars = " << static_cast<double>(numWars)/numSims << endl;
  cout << "P1 wins = " << p1Wins << endl;
  cout << "P2 wins = " << p2Wins << endl;
  return 0;
}
