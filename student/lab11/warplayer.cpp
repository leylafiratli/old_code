#include "warplayer.h"

using namespace std;

WarPlayer::WarPlayer()
{

}

void WarPlayer::addCard(Card c)
{
	_cards.push_back(c);
}

Card WarPlayer::removeTopCard()
{
  Card c = _cards.front();
	_cards.pop_front();
  return c;
}

// Add the implementation of your two functions here
bool WarPlayer::checkcards()
{
	if(_cards.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int WarPlayer::sizereturn()
{
	return _cards.size();
}
