#pragma once
#include <string>
#include <print>
#include <cstdint>

enum Hand : uint8_t
{
	Club,
	Hearts,
	Spades,
	Diamonds
};

enum Value : uint8_t
{
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
};

enum PokerHand
{
	HighCard = 1,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalFulsh,
};

struct Card
{
	Hand _hand;
	Value _value;
	PokerHand _pokerHand;
	std::string ToString();
		

};

std::string HandToString(Hand _hand);
std::string ValueToString(Value _value);
std::string PokerHandToString(PokerHand _pokerHand);