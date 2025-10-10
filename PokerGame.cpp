
#include <iostream>
#include "Card.hpp"
#include "Player.hpp"
#include "CheckHand.hpp"
#include "Deck.hpp"
#include <string>

char replay = 'y';

int main()
{
	while (replay == 'y')
	{
		Deck deck;
		deck.Fill();

		Player player1;
		Player player2;

		// Give 5 cards to player 1
		std::array<Card, 5> hand1;

		for (int i = 0; i < 5; i++)
		{
			hand1[i] = deck.Draw();
		}
		player1.SetHand(hand1);

		PokerHand player1Hand = EvaluateHand(hand1);

		// Give 5 cards to player 2
		std::array<Card, 5> hand2;
		for (int i = 0; i < 5; i++)
		{
			hand2[i] = deck.Draw();
		}
		player2.SetHand(hand2);

		PokerHand player2Hand = EvaluateHand(hand2);
		//Display
		std::cout << std::format("Player 1 [{}]\n", player1.Display());
		std::cout << "Hand : " << PokerHandToString(player1Hand) << "\n";
		std::cout << std::format("Player 2 [{}]\n", player2.Display());
		std::cout << "Hand : " << PokerHandToString(player2Hand) << "\n";
		//Winner
		if (static_cast<int> (PokerHand(hand1)) > static_cast<int> (PokerHand(hand2))
		{
			std::cout << "player 1 won !! \n";
		}
		else
		{
			std::cout << "player 2 won !! \n";
		}

		//replay
		std::cout << "Do you wante to replay ?" << "\n";
		std::cin >> replay;
	}
	
}


