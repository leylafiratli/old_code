#ifndef WARPLAYER_H
#define WARPLAYER_H

#include <deque>
#include "card.h"

using namespace std;

class WarPlayer
{
 public: 
  WarPlayer();
  void addCard(Card c);
  Card removeTopCard();

  // Add your two functions here
	bool checkcards();
	int sizereturn();

 private:
  deque<Card> _cards;

};

#endif
