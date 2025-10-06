#pragma once
#include "Card.hpp"
#include <vector>

class Deck
{
public:
	void Fill();

	Card Draw();
private:
	std::vector<Card> cards_;
};

