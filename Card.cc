#include "Card.hpp"

std::string Card::ToString()
{
	return std::format("{} of {}", ValueToString(_value), HandToString(_hand));
}

std::string HandToString(Hand _hand)
{
	switch (_hand)
	{
	case Hand::Club: 
		return " Club";
	case Hand::Hearts:
		return " Hearts";
	case Hand::Spades:
		return " Spades";
	case Hand::Diamonds:
		return " Diamonds";
	}
}

std::string ValueToString(Value _value)
{
	switch(_value)
	{
	case Value::two:
		return " two";
	case Value::three:
		return " three";
	case Value::four:
		return " four";
	case Value::five: 
		return " five";
	case Value::six:
		return " six";
	case Value::seven:
		return" seven";
	case Value::eight:
		return" eight";
	case Value::nine:
		return" nine";
	case Value::ten:
		return" ten";
	case Value::jack:
		return " jack";
	case Value::queen:
		return " queen";
	case Value::king:
		return " king";
	case Value::ace:
		return " ace";
	}
}