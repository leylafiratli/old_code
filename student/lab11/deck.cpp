#include <iostream>
#include <cstdlib>
#include "deck.h"
using namespace std;

Deck::Deck()
{
  	char suits[] = {'C','D','H','S'};

 	for(int i=0;i < 52; i++)
	{
    	_cards.push_back(Card(suits[i/13], i%13));
  	}
}

void Deck::shuffle()
{
  for(int i=51; i > 0; i--){
    int r = rand() % (i+1);
    Card temp = _cards[i];
    _cards[i] = _cards[r];
    _cards[r] = temp;
  }
}

void Deck::cut()
{
  for(int i = 0; i < 26; i++){
    Card temp = _cards[i];
    _cards[i] = _cards[i+26];
    _cards[i+26] = temp;
  }

}
Card Deck::getTop()
{
  Card retval =  _cards.back();
  _cards.pop_back();
  return retval;
}

void Deck::printDeck()
{
  for(int i= 0; i < 52; i++){
    cout << _cards[i].toString() << " " ;
  }
  cout << endl;
}
