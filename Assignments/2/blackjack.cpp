//
// Created by Mike Gao on 2020-03-06.
//

#include "blackjack.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


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
    Hand()
    {
        vec.reserve(30);
    }
    void add(Card c)
    {
        vec.push_back(c);
    }
    void clear() {
        vec.clear();
    }
    int getTotal() {
        std::vector<Card>::iterator it;
        int total, acc, oneAcc = 0;
        for (it = vec.begin(); it != vec.end(); ++it) {
            total += it->getValue();
            if (1 == it->getValue()) {
                oneAcc += 1;
            }
        }
        acc = total;
        while (oneAcc != 0)
        {
            acc += 10;
            if (acc == 21) break;
            if (acc > 21){
                acc -= 10;
                break;
            }
        }
        return acc;
    }
};

class Deck{
private:
    std::vector<Card> vec;
public:
    Deck()
    {
        vec.reserve(60);
        this->populate();
        this->shuffle();
    }
    void populate()
    {
        for (int i = Card::ACE; i <= Card::KING ; i++){
            for (int j = Card::CLUBS; i <= Card::SPADES ; i++)
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>(j)));
        }
    }
    void shuffle()
    {
        std::shuffle(begin(vec),end(vec), default_random_engine{});
    }
    void deal(Hand h){
        h.add(vec.back());
        vec.pop_back();
    }
};

class AbstractPlayer : public Hand {
public:
    virtual bool isDrawing() = 0;
    virtual bool isBusted()
    {
        return (getTotal() > 21) ? true : false;
    }
};


class ComputerPlayer : public AbstractPlayer {
public:
    bool isDrawing()
    {
        return (getTotal() <= 16) ?  true : false;
    }
};

class HumanPlayer : public AbstractPlayer{
public:
    bool isDrawing()
    {
        bool answer;
        cout << "Do you want to draw another card? (y/n): ";
        cin >> answer;
        cout << endl;
        while (answer != 'y' && answer != 'n'){
            cout << "Invalid input! Please enter 'y' or 'n': ";
            cin >> answer;
        }
        return (answer=='y') ? true : false;
    }

    void announce(Hand adversary)
    {
        if ( isBusted() ){
            cout << "Player busts." << endl;
            cout << "Casino wins!" << endl;
        } else if ( adversary.getTotal() > 21 ) {
            cout << "Casino busts." << endl;
            cout << "Player wins!" << endl;
        } else if ( getTotal() > adversary.getTotal()){
            cout << "Player wins!" << endl;
        } else {
            cout << "Casino wins!" << endl;
        }
    }
};

class BlackJackGame {
private:
    Deck m_deck;
    ComputerPlayer m_casino;
public:
    void play(){
        m_deck.populate();
        m_deck.shuffle();
    }
};

