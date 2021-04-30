/*--------------------------------------------------------------
 *
 *@file: deck.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
 *@description: Implementation file for the deck class, which works with the blackjack program
 *
 --------------------------------------------------------------*/

#include "deck.h"

//Constructor for the deck of cards
deck::deck(){
  m_topOfDeck = 0;
  std::string faces[13] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
  std::string suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
  int values[13] = {11,10,10,10,10,9,8,7,6,5,4,3,2};

  int nextIndex = -1;
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < 13; i++) {
      nextIndex = nextIndex + 1;
      m_deck[nextIndex] = card(faces[i], suits[j], values[i]);
    }
  }
}

//Shuffles the deck of cards
void deck::shuffle(){
  srand(time(0)); //creates a starting point for rand
  for (int i = 0; i < 52; i++){
    int j = i + (rand() % (52 - i));
    card targetCard = m_deck[i];
    card swapCard = m_deck[j];
    m_deck[i] = swapCard;
    m_deck[j] = targetCard;
  }
}

//Prints the entire deck of cards (used for testing)
void deck::printDeck() const{
  for(int i = 0; i < m_totalCards;i++){
    std::cout << m_deck[i].print() << "\n";
  }
}

//Prints the card at the top of the deck
void deck::printCard(){
  std::cout << m_deck[m_topOfDeck].print() << "\n";
}

//Returns the value of the top of the deck
int deck::getValue(){
  return(m_deck[m_topOfDeck].getValue());
}

//Generates an empty card
card deck::dealEmptyCard(){
  emptyCard = card("", "", 0);
  return(emptyCard);
}

//Changes an ace's value from 11 to 11
card deck::dealSpecialAce(std::string aceSuit){
  specialAce = card("Ace", aceSuit, 1);
  return(specialAce);
}

//Draws the next card from the deck
card deck::nextCard(){
  card nextCard = m_deck[m_topOfDeck];
  m_topOfDeck = m_topOfDeck + 1;
  return(nextCard);
}

//Checks the next card of the deck
card deck::peekNextCard(){
  return(m_deck[m_topOfDeck]);
}
