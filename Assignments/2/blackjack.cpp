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
    string arr[] = {"C","D","H","S"};
    if (this -> rank == 11)
        cout << "J" << arr[this->type];
    else if (this -> rank == 12)
        cout << "Q" + arr[this->type];
    else if (this -> rank == 13)
        cout << "K" + arr[this->type];
    else
        cout << to_string(this->rank) + arr[this->type];
}

void Hand::add(Card c)
{
    vec.push_back(c);
}

void Hand::clear()
{
    vec.clear();
}

void Hand::print(){
    for (Card i : vec)
    {
        i.displayCard();
        cout << " ";
    }
}

int Hand::getTotal()
{
    std::vector<Card>::iterator it;
    int total = 0;
    bool hasAce = false;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        total += it->getValue();
        if (1 == it->getValue()) hasAce = true;
    }
    return (hasAce && total + 10 < 21) ? total + 10 : total;
}


void Deck::populate()
{
    for (int i = Card::ACE; i <= Card::KING ; i++)
    {
        for (int j = Card::CLUBS; j <= Card::SPADES; j++)
        {
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>(j)));
        }
    }
}

void Deck::shuffle()
{
    ::shuffle(begin(vec),end(vec), default_random_engine{});
}

void Deck::deal(Hand &h)
{
    h.add(vec.back());
    vec.pop_back();
}

bool AbstractPlayer::isBusted()
{
    return (getTotal() > 21);
}


bool ComputerPlayer::isDrawing()
{
    return (getTotal() <= 16);
}

bool HumanPlayer::isDrawing()
{
    char answer;
    cout << "Do you want to draw another card? (y/n): ";
    cin >> answer;
    cout << endl;
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

void ComputerPlayer::displayInfo()
{
    cout << "Casino : ";
    this->print();
    cout << "[" << to_string(this-> getTotal()) << "]";
    cout << endl;
}
void HumanPlayer::displayInfo()
{
    cout << "Player : ";
    this->print();
    cout << "[" << to_string(this-> getTotal()) << "]";
    cout << endl;
}


void BlackJackGame::play()
{
    m_deck.populate();
    m_deck.shuffle();
    m_casino.clear();
    HumanPlayer human;
    m_deck.deal(m_casino);
    m_casino.displayInfo();
    m_deck.deal(human);
    do {
        m_deck.deal(human);
        human.displayInfo();
        if (human.isBusted()) {
            human.announce(m_casino);
            return;
        }
    } while (human.isDrawing());

    while (m_casino.isDrawing())
    {
        m_deck.deal(m_casino);
        m_casino.displayInfo();
        if(m_casino.isBusted())
        {
            human.announce(m_casino);
            return;
        }
    }

    human.announce(m_casino);

}
