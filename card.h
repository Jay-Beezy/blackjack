/*--------------------------------------------------------------
 *
 *@file: card.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Header file for the card class, which works with the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef CARD_H
#define CARD_H
#include <string>

class card
{

public:

  /**
  * @pre N/A
  * @post A card is constructed with the three paramters
  * @return N/A
  **/
  card(std::string face, std::string suit, int value);

  /**
  * @pre A card object exists
  * @post N/A
  * @return A string that provides the information of a card
  **/
  std::string print() const;

  /**
  * @pre N/A
  * @post default constructor
  * @return N/A
  **/
  card();

  /**
  * @pre A card object exists
  * @post N/A
  * @return the value of the card
  **/
  int getValue() const;

  std::string getFace() const;

  std::string getSuit() const;

  bool operator==(const card& rhs) const;

  bool operator!=(const card& rhs) const;

  void operator=(const card& rhs);

private:

  std::string m_face;

  std::string m_suit;

  int m_value;

};
#endif
