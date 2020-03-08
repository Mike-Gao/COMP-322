//
// Created by Mike Gao on 2020-03-06.
//

#ifndef INC_2_BLACKJACK_H
#define INC_2_BLACKJACK_H


#include <vector>

class Card
{
public:
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE,
        SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING } rank;
    enum Type { CLUBS = 'C', DIAMONDS ='D', HEARTS = 'H', SPADES = 'S' } type;
    Card(Rank r, Type t);
    int getValue();
    void displayCard();
};

class Hand
{
private:
    std::vector<Card> vec;
public:
    Hand();
    void add(Card c);
    void clear();
    int getTotal();
};

class Deck
{
private:
    std::vector<Card> vec;
public:
    Deck();
    void populate();
    void shuffle();
    void deal(Hand h);
};

class AbstractPlayer : public Hand
{
public:
    virtual bool isDrawing() const = 0;
    bool isBusted();
};

class ComputerPlayer : public AbstractPlayer
{
public:
    bool isDrawing();
};
class HumanPlayer : public AbstractPlayer
{
public:
    bool isDrawing();
    void announce(Hand adversary);
};


class BlackJackGame {
private:
    Deck m_deck;
    ComputerPlayer m_casino;
public:
    void play();
};

#endif //INC_2_BLACKJACK_H
