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

//enum HandValue
//{
//	high_card = 1,
//	pair,
//	two_pair,
//	three_of_a_kind,
//	straight,
//	flush,
//	full_house,
//	straight_flush,
//	royal_fulsh,
//};

struct Card
{
	Hand _hand;
	Value _value;
	std::string ToString();
		

};

std::string HandToString(Hand _hand);
std::string ValueToString(Value _value);