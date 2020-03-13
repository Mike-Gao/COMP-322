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

// Card Constructor
Card::Card(Rank r, Type t)
{
    this -> rank = r;
    this -> type = t;
}

// Get the value of a card
int Card::getValue()
{
    /* if the rank is bigger than 10 (J,Q,K) , return 10 */
    return (this->rank >= 10) ? 10 : this->rank;
}

// Printout one card
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

// Add a card to a hand
void Hand::add(Card c)
{
    vec.push_back(c);
}

// Clear the hand
void Hand::clear()
{
    vec.clear();
}

// Print out a hand
void Hand::print(){
    /* Iterating through every Card in vec */
    for (Card i : vec)
    {
        i.displayCard();
        cout << " ";
    }
}

// Get total value of a hand
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
    /* You can have a maximum of one ace here,
     * otherwise you'll be bust.
     * So return either total or total+10 */
    return (hasAce && total + 10 < 21) ? total + 10 : total;
}

// Populate the deck
void Deck::populate()
{
    // Simply add every card into the deck
    for (int i = Card::ACE; i <= Card::KING ; i++)
    {
        for (int j = Card::CLUBS; j <= Card::SPADES; j++)
        {
            vec.push_back(Card(static_cast<Card::Rank>(i), static_cast<Card::Type>(j)));
        }
    }
}

// Shuffle: shuffle the cards in a deck
void Deck::shuffle()
{
    // Using std::shuffle to shuffle the deck
    ::shuffle(begin(vec),end(vec), default_random_engine{});
}

// Deal: deal one card to a hand
void Deck::deal(Hand &h)
{
    // Add a card from the deck to a hand
    h.add(vec.back());
    // Remove that card from the deck
    vec.pop_back();
}

// Check if the player is busted
bool AbstractPlayer::isBusted()
{
    return (getTotal() > 21);
}

// Check whether the ComputerPlayer should be drawing
bool ComputerPlayer::isDrawing()
{
    return (getTotal() <= 16);
}

// Ask Human Player if he/she wants to draw again
bool HumanPlayer::isDrawing()
{
    char answer;
    cout << "Do you want to draw another card? (y/n): ";
    cin >> answer;
    return (answer=='y');
}

// Announce winner
void HumanPlayer::announce(Hand adversary)
{
    if ( isBusted() ){ // Player Bust
        cout << "Player busts." << endl;
        cout << "Casino wins!" << endl;
    } else if ( adversary.getTotal() > 21 ) { // Casino Bust
        cout << "Casino busts." << endl;
        cout << "Player wins!" << endl;
    } else if ( adversary.getTotal() == getTotal() ){ // Casino getTotal() == Player getTotal()
        cout << "Push: No one wins." << endl;
    } else if ( getTotal() > adversary.getTotal()){ // Player getTotal() > Casino getTotal()
        cout << "Player wins!" << endl;
    } else { // Casino getTotal() > Player getTotal()
        cout << "Casino wins!" << endl;
    }
}

/* Nice printout for ComputerPlayer and HumanPlayer */
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
    // Initialization
    m_deck.populate();
    m_deck.shuffle();
    m_casino.clear();
    HumanPlayer human;
    m_deck.deal(m_casino);
    m_casino.displayInfo();
    m_deck.deal(human);
    // Player Draw
    do {
        m_deck.deal(human);
        human.displayInfo();
        if (human.isBusted()) {
            human.announce(m_casino);
            return;
        }
    } while (human.isDrawing());
    // Casino Draw
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
