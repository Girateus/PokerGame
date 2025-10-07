#pragma once
#include "Card.hpp"
#include <array>

PokerHand EvaluateHand(const std::array<Card, 5>& hand);
std::string PokerHandToString(PokerHand _pokerHand);

