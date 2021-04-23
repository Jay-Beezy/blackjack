/*--------------------------------------------------------------
 *
 *@file: deck.h
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Header file for the deck class, which works with the card class which works with the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef DECK_H
#define DECK_H
#include <string>
#include <iostream>
#include "card.h"
#include <stdlib.h>

class deck
{

public:

  /**
  * @pre N/A
  * @post A deck of 52 cards with all faces and suits is created
  * @return N/A
  **/
  deck();

  /**
  * @pre N/A
  * @post The deck is randomly shuffled, so that the cards within are randomized
  * @return N/A
  **/
  void shuffle();

  /**
  * @pre N/A
  * @post Prints the current content of the deck
  * @return N/A
  **/
  void printDeck() const;

  /**
  * @pre N/A
  * @post Prints a card from the deck
  * @return N/A
  **/
  void printCard();

  /**
  * @pre N/A
  * @post Increments the top of the deck so that the next card in line is dealt
  * @return N/A
  **/
  void deal();

  /**
  * @pre N/A
  * @post Returns the value of the current card
  * @return N/A
  **/
  int getValue();

  card dealTester();
  card dealEmptyCard();
  card dealSpecialAce(std::string aceSuit);

//private:
  int m_totalCards = 52;

  card m_deck[52];

  int m_topOfDeck;

  card emptyCard;
  
  card specialAce;

};
#endif
