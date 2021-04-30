/*--------------------------------------------------------------
 *
 *@file: deck.h
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
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
  * @post Returns the value of the current card
  * @return Value of the card
  **/
  int getValue();

  /**
  * @pre N/A
  * @post Creates an empty card
  * @return The empty card
  **/
  card dealEmptyCard();

  /**
  * @pre N/A
  * @post Changes an suited ace's value from 11 to 1
  * @return An ace with a value of 1
  **/
  card dealSpecialAce(std::string aceSuit);

  /**
  * @pre N/A
  * @post Increments the top of the deck by 1
  * @return The next card at the top of the deck
  **/
  card nextCard();

  /**
  * @pre N/A
  * @post N/A
  * @return The card at the top of the deck
  **/
  card peekNextCard();

private:
  int m_totalCards = 52;

  card m_deck[52];

  int m_topOfDeck;

  card emptyCard;
  
  card specialAce;

};
#endif
