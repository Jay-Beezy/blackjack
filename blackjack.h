/*--------------------------------------------------------------
 *
 *@file: blackjack.h
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Header file for the blackjack program
 *
 --------------------------------------------------------------*/

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
#include "deck.h"

class blackjack
{

public:

  /**
  * @pre N/A
  * @post calls the blackjackGame method
  * @return N/A
  **/
  void run();

  /**
  * @pre run() is called
  * @post the blackjack game is executed
  * @return N/A
  **/
  void blackjackGame();

  void dealerStart();

  void playerStart();

  void dealPlayer();

  void dealHouse();

  void fixEmptyCards();

  void initializeHands();

  void superShuffle();

  void printHands();

  void playerAceChecker();

  void houseAceChecker();

  void AceTester();

  deck myDeck;
  int playerValue = 0;
  int houseValue = 0;

  int maximumCards = 10;
  card playerArray[10];
  card houseArray[10];

};
#endif
