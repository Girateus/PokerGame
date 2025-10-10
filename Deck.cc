#include "Deck.hpp"
#include <iostream>
#include <algorithm>
#include <random>

void Deck::Fill()
{
	cards_.clear();
	for (int h = 0; h < 4; h++)
	{
		for (int v = 2; v <= 14; v++)
		{
			cards_.emplace_back(Card{
				static_cast<Hand>(h),
				static_cast<Value>(v)
				});
		}
	}

	//Shuffle the deck
	std::default_random_engine engine(time(nullptr));
	std::ranges::shuffle(cards_, engine);
	//std::ranges::for_each(cards_, [](Card c) {std::cout << c.ToString() << "\n";});
}

Card Deck::Draw()
{
	Card newCard = cards_.back();
	cards_.pop_back();
	return newCard;
}