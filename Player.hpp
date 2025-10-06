#pragma once
#include "Card.hpp"
#include <array>
class Player
{
public:
		void SetHand(std::array<Card, 5>);

		std::string Display();
private:
		std::array<Card, 5> hand_cards_;
};

