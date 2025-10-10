#include "Player.hpp"
void Player::SetHand(std::array<Card, 5> cards)
{
	hand_cards_ = cards;
}

std::string Player::Display()
{
	//add 5 cards
	std::string result;
	for (int i = 0; i < hand_cards_.size(); i++)
	{
	    if (i > 0) result += " / ";
	    result += hand_cards_[i].ToString();
	}
	return result;
}