/*--------------------------------------------------------------
 *
 *@file: card.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Implementation file for the card class, which works with the blackjack program
 *
 --------------------------------------------------------------*/

#include "card.h"

//Constructor for the card class
card::card(std::string face, std::string suit, int value){
  m_face = face;
  m_suit = suit;
  m_value = value;
}

//Returns the information of a card
std::string card::print() const{
  return("| " + m_face + " of " + m_suit + " |");
}

//Default constructor
card::card(){
}

//Returns the value of the card
int card::getValue() const{
  return(m_value);
}

std::string card::getFace() const{
  return(m_face);
}

std::string card::getSuit() const{
  return(m_suit);
}

bool card::operator==(const card& rhs) const{
  if(getFace() == rhs.getFace()){
    if(getValue() == rhs.getValue()){
      return(true);
    }
    else{
      return(false);
    }
  }
  else{
    return(false);
  }
}

bool card::operator!=(const card& rhs) const{
  if(getFace() != rhs.getFace()){
    if(getValue() != rhs.getValue()){
      return(true);
    }
    else{
      return(false);
    }
  }
  else{
    return(false);
  }
}

void card::operator=(const card& rhs)
{
  m_value = rhs.m_value;
  m_face = rhs.m_face;
  m_suit = rhs.m_suit;
}