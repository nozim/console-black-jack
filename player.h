#include <iostream>

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
    public:
        enum PlayerType {USER, DEALER, OPPONENT};
        Player(PlayerType t, Deck *d, std::string n)
        {
            name=n;
            type=t;
            deck=d;
            chips=1000;
        }

        int get_chips(){ return chips; }
        void set_chips(int amount){ chips=amount; }
        std::string get_name(){ return name; }
        void show_cards()
        {
            std::cout << "Карты игрока:" << name << std::endl;
            for(unsigned i=0;i<cards.size();i++)
            {
                std::cout << cards[i];
                if(is_dealer()) break;
            }
            if(!is_dealer())
                std::cout << "Сумма карт: "<< calculate_score() << std::endl;
        }

        bool has_black_jack(){ return 21==calculate_score(); }
        void bet(){}
        void take_card(){ cards.push_back(deck->pick_card()); }
        void stop()
        {
            //nop
        }
        void make_move()
        {
            switch(type)
            {
                case USER: ask_what_to_do(); break;
                case OPPONENT: decide_opponent(); break;
                case DEALER: decide_dealer(); break;
            };
        }

        void decide_opponent()
        {
            int score=calculate_score();
            if(score<19)
            {
                take_card();
            }
            else
            {
                stop();
            }
        }
        void decide_dealer()
        {
            int score=calculate_score();
            if(score<17)
            {
                take_card();
            }else
            {
                stop();
            }
        }

        void ask_what_to_do()
        {
            for(int choice=0;(choice!=1) && (choice!=2);)
            {
                //std::cout << "Ваши карты:" << std::endl;
                //show_cards();
                std::cout << "Вы берете карту(1) или говорите 'стоп'(2): ";
                std::cin >> choice;
                if(choice==1)
                {
                    take_card();
                }
                else if(choice==2)
                {
                    stop();
                }
                else
                {
                    std::cout << "Пожалуйста сделайте выбор(1 или 2)" << std::endl;
                }
            }
        }

        int calculate_score()
        {
            int aces=0;
            int sum=0;
            for(unsigned i=0; i<cards.size();i++)
            {
                if(cards[i].is_ace()) aces++;
                int value=(int)cards[i].get_face()+1;
                sum+=(value<10)?value:10;
            }

            for(int i=0;i<aces;i++)
            {
                if(sum<12) sum+=10;
            }
            return sum;
        }

        unsigned get_cards_count(){ return cards.size(); }
        bool is_user() { return type==USER; }
        bool is_dealer() { return type==DEALER; }
        bool is_opponent() { return type==OPPONENT; }
    private:
        std::vector <Card> cards;
        PlayerType type;
        std::string name;
        int chips;
        Deck *deck;
};

#endif

