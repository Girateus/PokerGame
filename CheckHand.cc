#include "CheckHand.hpp"
#include <map>
#include <algorithm>
#include <vector>

PokerHand EvaluateHand(const std::array<Card, 5>& hand)
{
	std::map<Value, int> valueCount;

	//Check number repetition
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
	//check for flush
	bool flush = true;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]._hand != hand[0]._hand)
		{
			flush = false;
			break;
		}


	}
	//createad a vector to check for straight
	std::vector<int> num;
	for (auto& card : hand)
	{
		num.push_back(static_cast<int>(card._value));
		std::sort(num.begin(), num.end());
	}
	
	bool straight = true;
	for (int i = 1; i < num.size(); i++)
	{
		if (num[i] != num[i - 1] +1)
		{
			straight = false;
			break;
		}
	}

	//check if straight with an ace at the start is possible
	bool aceStraight = false;
	if (!straight && num == std::vector<int>{2, 3, 4, 5, 14})
	{
		
		aceStraight = true;
	}

	//check if Straight flush or royal flush and return the correct hand
	if (straight && flush)
	{
		if (num.back() == static_cast<int> (Value::ace))
		{
			return PokerHand::RoyalFlush;
		}
		return PokerHand::StraightFlush;
	}
	if (aceStraight && flush)
	{
		
		return PokerHand::StraightFlush;
	}

	if (four)
	{
		return PokerHand::FourOfAKind;
	}
	if (three && pair)
	{
		return PokerHand::FullHouse;
	}
	if (flush)
	{
		return PokerHand::Flush;
	}
	if (straight || aceStraight)
	{
		return PokerHand::Straight;
	}
	if (three)
	{
		return PokerHand::ThreeOfAKind;
	}
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

//Display the correct hand on screen
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
	case PokerHand::Straight:
		return "Straight";
	case PokerHand::Flush:
		return "Flush";
	case PokerHand::FullHouse:
		return "Full House";
	case PokerHand::FourOfAKind:
		return "Four of a kind";
	case PokerHand::StraightFlush:
		return "Straight Flush";
	case PokerHand::RoyalFlush:
		return "Royal Flush";
	}
}
