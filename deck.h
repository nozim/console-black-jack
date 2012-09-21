#ifndef DECK_H
#define DECK_H
class Deck
{
        std::vector<Card> cards;
    public:
        Deck()
        {
            srand(time(NULL));
            for(Card::Suit suit=Card::Diamonds;suit<=Card::Spades;suit++)
            {
                for(Card::Face face=Card::Ace;face<=Card::King;face++)
                {
                   cards.push_back(Card(suit,face));
                }
            }
        };

        unsigned get_cards_number(){ return cards.size(); }

        void shuffle_cards()
        {
            random_shuffle(cards.begin(),cards.end());
        }

        Card pick_card()
        {
            Card card = cards.back();
            cards.pop_back();
            return card;
        }
};
#endif


