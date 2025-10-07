#include "Player.hpp"
void Player::SetHand(std::array<Card, 5> cards)
{
	hand_cards_ = cards;
}

std::string Player::Display()
{
	//ajoute des cartes jusqua 5
	std::string result;
	for (int i = 0; i < hand_cards_.size(); i++)
	{
	    if (i > 0) result += " / "; // séparateur
	    result += hand_cards_[i].ToString();
	}
	return result;
	//return std::format("{} / {}", hand_cards_[0].ToString(), hand_cards_[1].ToString(), hand_cards_[2].ToString(), hand_cards_[3].ToString(), hand_cards_[4].ToString());
}