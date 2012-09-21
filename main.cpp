#define STAKE_AMOUNT 100
#define PLAYERS_COUNT 3

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"

using namespace std;

int main()
{
    std::cout << "Добро пожаловать в BlackJack!" << std::endl;
    char username[80];
    do
    {
        std::cout << "Введите пожалуйста свое имя:";
        std::cin.getline(username,80);
    }while(strlen(username)==0);

    vector<Player*> players;
    Deck deck;
    Player bot1(Player::OPPONENT, &deck,"Bot1");
    Player bot2(Player::OPPONENT, &deck,"Bot2");
    Player user(Player::USER, &deck, username);
    Player dealer(Player::DEALER, &deck, "Dealer");

    players.push_back(&bot1);
    players.push_back(&bot2);
    players.push_back(&user);
    players.push_back(&dealer);

    Game game(players,&deck);
    game.make_stakes();
    game.deal_cards();

    if(!game.is_there_black_jack())
    {
        game.make_move();
    }

    game.calculate_scores();
    game.declare_winner();

    return 0;
}
