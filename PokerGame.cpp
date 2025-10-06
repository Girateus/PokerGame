
#include <iostream>
#include "Card.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include <string>

int main()
{
	/*Player player;

	Deck deck;

	deck.Fill();

	std::cout << "Deck Filled\n";

	player.SetHand({ deck.Draw(), deck.Draw(),deck.Draw(),deck.Draw(),deck.Draw() });

	std::cout << std::format("Player 1 [{}] \n", player.Display());
	std::cout << std::format("Player 2 [{}] \n", player.Display());*/
	Deck deck;
	deck.Fill();

	Player player1;
	Player player2;

	// Donner 5 cartes au joueur 1
	std::array<Card, 5> hand1;
	for (int i = 0; i < 5; i++)
	{
	    hand1[i] = deck.Draw();
	}
	player1.SetHand(hand1);

	// Donner 5 cartes au joueur 2
	std::array<Card, 5> hand2;
	for (int i = 0; i < 5; i++)
	{
	    hand2[i] = deck.Draw();
	}
	player2.SetHand(hand2);

	// Affichage
	std::cout << std::format("Player 1 [{}]\n", player1.Display());
	std::cout << std::format("Player 2 [{}]\n", player2.Display());
}


