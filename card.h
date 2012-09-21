#ifndef PLAYER_H
#define PLAYER_H

class Card
{
    public:
        enum Face
        {
            Ace,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Ten,
            Jack,
            Queen,
            King
        };

        enum Suit
        {
            Diamonds,
            Hearts,
            Clubs,
            Spades
        };

        Card(Suit s, Face f)
        {
            suit=s;
            face=f;
        }

        Suit get_suit(){ return suit; }
        Face get_face() { return face; }
        bool is_ace(){ return face==Card::Ace; }

        friend std::ostream& operator<<(std::ostream& o, const Card& obj)
        {
            o << FaceStrings[obj.face] << "\t" << SuitStrings[obj.suit] << std::endl;
            return o;
        }
    private:
        static const char * const SuitStrings[];
        static const char * const FaceStrings[];
        Suit suit;
        Face face;
};

const char * const Card::SuitStrings[]=
{
    "Бубн",
    "Черв",
    "Пик",
    "Треф"
};

const char * const Card::FaceStrings[]=
{
    "Туз",
    "Два",
    "Три",
    "Четыре",
    "Пять",
    "Шесть",
    "Семь",
    "Восемь",
    "Девять",
    "Десять",
    "Валет",
    "Дама",
    "Король"
};

inline Card::Suit operator++(Card::Suit &current, int)
{
   Card::Suit oldSuit = current;
   current = (Card::Suit)(current + 1);
   return oldSuit;
}

inline Card::Face operator++(Card::Face &current, int)
{
   Card::Face oldFace = current;
   current = (Card::Face)(current + 1);
   return oldFace;
}

#endif


