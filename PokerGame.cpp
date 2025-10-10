
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
		if (static_cast<int> (player1Hand) > static_cast<int> (player2Hand))
		{
			std::cout << "player 1 won !! \n";
		}
		else if (static_cast<int>(player1Hand) < static_cast<int>(player2Hand))
		{
			std::cout << "Player 2 won !!\n";
		}
		else
		{
			//same hand check for highest card
			int high1 = 0;
			int high2 = 0;

			for (auto& card : hand1)
			{
				high1 = std::max(high1, static_cast<int>(card._value));
			}

			for (auto& card : hand2)
			{
				high2 = std::max(high2, static_cast<int>(card._value));
			}

			if (high1 > high2)
			{
				std::cout << "Player 1 won by high card !\n";
			}

			else if (high2 > high1)
			{
				std::cout << "Player 2 won by high card !\n";
			}

			else
			{
				std::cout << "Perfect tie!\n";
			}
		}

		//replay systeme
		std::cout << "Do you wante to replay ?" << "\n";
		std::cin >> replay;
	}
	
}


