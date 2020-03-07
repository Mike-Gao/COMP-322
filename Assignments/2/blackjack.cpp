//
// Created by Mike Gao on 2020-03-06.
//

#include "blackjack.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

template<class Card, class Allocator = std::allocator<Card>> class vec;

using namespace std;
class Card{
public:
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE,
        SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING } rank;
    enum Type { CLUBS = 'C', DIAMONDS ='D', HEARTS = 'H', SPADES = 'S' } type;
    Card(Rank r, Type t){
        this -> rank = r;
        this -> type = t;
    }
    int getValue(){
        return (this->rank >= 10) ? 10 : this->rank;
    }
    void displayCard(){
        if (this -> rank == 11)
            cout << 'J' + this->type;
        if (this -> rank == 12)
            cout << 'Q' + this->type;
        if (this -> rank == 13)
            cout << 'K' + this->type;
        cout << this->rank + this->type;
    }
};

class Hand{
private:
    std::vector<Card> vec;
public:
    void add(Card c){
        vec.reserve(30);
        vec.push_back(c);
    }
    void clear() {
        vec.clear();
    }
    int getTotal() {
        std::vector<Card>::iterator it;
        int total, total2, oneacc = 0;
        for (it = vec.begin(); it != vec.end(); ++it) {
            total += it->getValue();
            if (1 == it->getValue()) {
                oneacc += 1;
            }
        }
        total2 = total;
        while (oneacc != 0){
            total2 += 10;
            if (total2 == 21) break;
        }
        return (total == 21 || total2 == 21) ? 21 : total;
    }
};

class Deck{
private:
    std::vector<Card> vec;
public:
    void populate()
    {
        vec.reserve(60);
        for (int i = Card::ACE; i != Card::KING; i++){
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>('C')));
        }
        for (int i = Card::ACE; i != Card::KING; i++){
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>('D')));
        }
        for (int i = Card::ACE; i != Card::KING; i++){
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>('H')));
        }
        for (int i = Card::ACE; i != Card::KING; i++){
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>('S')));
        }
    }
    void shuffle()
    {
        shuffle();
    }
    void deal(Hand h){
        h.add(vec.back());
        vec.pop_back();
    }
};

class AbstractPlayer{
private:

public:
    virtual bool isDrawing() const = 0;
    bool isBust();
};


class ComputerPlayer{
private:
public:
    void isDrawing();
};

class BlackJackGame{
private:
    Deck m_deck;
    ComputerPlayer m_casino;
public:
    void play();
};

class humanPlayer{
private:
public:
    void isDrawing()
    {

    }

    void announce()
    {

    }
};