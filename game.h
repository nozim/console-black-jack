#include "player.h"
#ifndef GAME_H
#define GAME_H
    class Game
    {
        private:
            int win;

            std::vector <Player*> players;
            std::vector <int> winners;

            Deck *deck;
        public:
            Game(std::vector<Player*> p,Deck *d)
            {
                players=p;
                win=0;
                deck=d;
            }

            int get_win() { return win; }
            Deck* get_deck() { return deck; }
            void make_stakes()
            {
                for(unsigned i=0;i<players.size();i++)
                {
                    players[i]->set_chips(players[i]->get_chips()-STAKE_AMOUNT);
                    win += STAKE_AMOUNT;
                }
            };

            void deal_cards()
            {
                deck->shuffle_cards();
                for(int j=0;j<2;j++)
                {
                    for(unsigned i=0;i<players.size();i++)
                    {
                        players[i]->take_card();
                    }
                }
                declare_cards();
            }

            void declare_cards()
            {
                for(unsigned i=0;i<players.size();i++)
                {
                    players[i]->show_cards();
                }
            }

            bool is_there_black_jack()
            {
                for(int i=0;i<PLAYERS_COUNT;i++)
                {
                    if (players[i]->has_black_jack()) return true;
                }
                return false;
            }

            void declare_winner()
            {
                int dealer=-1;
                std::cout << "Победители:" << std::endl;
                unsigned size=winners.size();
                for(unsigned i=0;i<size;i++)
                {
                    std::cout << players[winners[i]] -> get_name() << std::endl;
                    players[winners[i]]->show_cards();
                    if(players[winners[i]]->is_dealer()) dealer=i;
                }

                std::cout << "**********************************" << std::endl;
                std::cout << "Выигрыш:" << std::endl;
                if((size==1)&&(dealer!=-1))
                {
                    show_winner(players[dealer],win);
                }
                else
                {
                    int prize_winners=(dealer==-1)?size:size-1;
                    int prize_part=win/prize_winners;

                    for(unsigned i=0;i<size;i++)
                    {
                        if(i==dealer) continue;
                        Player* player=players[winners[i]];
                        show_winner(player, prize_part);
                    };
                }
                std::cout << "**********************************" << std::endl;
                for(unsigned i=0;i<players.size();i++)
                {
                    for(unsigned j=0;j<winners.size();j++) if(winners[j]==i) continue;
                    players[i] -> show_cards();
                }
            }
            void show_winner(Player *player,int prize_amount)
            {
                player->set_chips(player->get_chips()+prize_amount);
                std::cout << player->get_name() << "\t" << prize_amount << std::endl;
            }
            void make_move()
            {
                for(unsigned i=0;i<players.size();i++)
                {
                    players[i]->make_move();
                }
            }

            void calculate_scores()
            {
                int max=0;
                for(unsigned i=0;i<players.size();i++)
                {
                    int score=players[i]->calculate_score();
                    if((score>max)&&(score<22)) max=score;
                }

                for(unsigned i=0;i<players.size();i++)
                {
                    if(players[i]->calculate_score()==max)
                    {
                        winners.push_back(i);
                    }
                }
            }
    };
#endif


