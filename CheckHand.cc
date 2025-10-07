#include "CheckHand.hpp"
#include <map>

PokerHand EvaluateHand(const std::array<Card, 5>& hand)
{
	std::map<Value, int> valueCount;

	//compte le repetition de chiffre
	for (auto& card : hand)
	{
		valueCount[card._value]++;
	}
	bool pair = false;
	bool twoPairs = false;
	bool three = false;
	bool four = false;

	for (auto& [value, count] : valueCount)
	{
		if (count == 2)
		{
			if (pair) twoPairs = true;
			else pair = true;
		}
		else if (count == 3)
		{
			three = true;
		}			
		else if (count == 4)
		{
			four = true;
		}
			
	}

	if (four)
	{
		return PokerHand::FourOfAKind;
	}
	if (three && pair)
	{
		return PokerHand::FullHouse;
	}
	if (three) 
		return PokerHand::ThreeOfAKind;
	if (twoPairs)
	{
		return PokerHand::TwoPairs;
	}
	if (pair)
	{
		return PokerHand::Pair;
	}
		return PokerHand::HighCard;
}

std::string PokerHandToString(PokerHand _pokerHand)
{
	switch (_pokerHand)
	{
	case PokerHand::HighCard: 
		return "High Card";
	case PokerHand::Pair:
		return "Pair";
	case PokerHand::TwoPairs:
		return "Two Pairs";
	case PokerHand::ThreeOfAKind:
		return "Three of a kind";
	case PokerHand::FullHouse:
		return "Full House";
	case PokerHand::FourOfAKind:
		return "Four of a kind";
	}
}
