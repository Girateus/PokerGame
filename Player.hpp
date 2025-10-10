#pragma once
#include "Card.hpp"
#include <array>
class Player
{
public:
	//set the number of card for each player
		void SetHand(std::array<Card, 5>);

		std::string Display();
private:
		std::array<Card, 5> hand_cards_;
};

