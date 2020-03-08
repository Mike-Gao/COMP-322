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
Card::Card(Rank r, Type t)
{
        this -> rank = r;
        this -> type = t;
}

int Card::getValue()
{
        return (this->rank >= 10) ? 10 : this->rank;
}

void Card::displayCard()
{
        if (this -> rank == 11)
            cout << 'J' + to_string(this->type);
        if (this -> rank == 12)
            cout << 'Q' + to_string(this->type);
        if (this -> rank == 13)
            cout << 'K' + to_string(this->type);
        else
            cout << to_string(this->rank) + to_string(this->type);
}

Hand::Hand()
{
        vec.reserve(30);
}
void Hand::add(Card c)
{
        vec.push_back(c);
}

void Hand::clear()
{
    vec.clear();
}

int Hand::getTotal() {
    std::vector<Card>::iterator it;
    int total, acc, oneAcc = 0;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        total += it->getValue();
        if (1 == it->getValue()) oneAcc += 1;
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

Deck::Deck()
{
        vec.reserve(60);
        this->populate();
        this->shuffle();
}

void Deck::populate()
{
    for (int i = Card::ACE; i <= Card::KING ; i++)
    {
        for (int j = Card::CLUBS; i <= Card::SPADES; i++)
        {
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>(j)));
        }
    }
}

void Deck::shuffle()
{
    std::shuffle(begin(vec),end(vec), default_random_engine{});
}

void Deck::deal(Hand h)
{
    h.add(vec.back());
    vec.pop_back();
}

bool AbstractPlayer::isBusted()
{
    return (getTotal() > 21) ? true : false;
}


bool ComputerPlayer::isDrawing()
{
        return (getTotal() <= 16) ? true : false;
}

bool HumanPlayer::isDrawing()
{
    bool answer;
    cout << "Do you want to draw another card? (y/n): ";
    cin >> answer;
    cout << endl;
    while (answer != 'y' && answer != 'n')
    {
        cout << "Invalid input! Please enter 'y' or 'n': ";
        cin >> answer;
    }
    return (answer=='y') ? true : false;
}

void HumanPlayer::announce(Hand adversary)
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

void BlackJackGame::play()
{

}
